Param()
$ErrorActionPreference = 'Stop'

# Determine directories based on this script's location
$RootDir = Split-Path -Parent $PSScriptRoot
$SrcDir  = Join-Path $RootDir 'src'
$OutExe  = Join-Path $RootDir 'main.exe'

# Detect available C compiler: prefer cc, then gcc, then clang
$CcCmd = $null
foreach ($name in @('cc','gcc','clang')) {
  $cmd = Get-Command $name -ErrorAction SilentlyContinue
  if ($cmd) { $CcCmd = $cmd; break }
}
if (-not $CcCmd) {
  Write-Error 'No C compiler found on PATH. Install MinGW (gcc) or LLVM (clang).'
}
Write-Host "Using compiler: $($CcCmd.Name)"

# Accumulate all .c sources in src
$sources = Get-ChildItem -Path $SrcDir -Filter '*.c' -File | ForEach-Object { $_.FullName }
if (-not $sources -or $sources.Count -eq 0) {
  Write-Error "No .c files found in '$SrcDir'."
}

Write-Host "Building '$OutExe' from sources: $($sources -join ' ')"

# Build arguments and invoke compiler in a single call
$args = @('-std=c99','-Wall',"-I$SrcDir") + $sources + @('-o', $OutExe)
& $CcCmd.Path @args

if ($LASTEXITCODE -ne 0) {
  Write-Error "Build failed with exit code $LASTEXITCODE."
  exit $LASTEXITCODE
}

Write-Host "Build successful: '$OutExe'"

Write-Host "Now I will run the program for you:"
& $OutExe

exit 0