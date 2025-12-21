Param()
$ErrorActionPreference = 'Stop'

# Determine directories based on this script's location
$RootDir = Split-Path -Parent $PSScriptRoot
$OutExe  = Join-Path $RootDir 'main.exe'

if (-not (Test-Path -Path $OutExe)) {
  Write-Error "Executable '$OutExe' not found. Please run 'build.ps1' first."
  exit 1
}

Write-Host "Running '$OutExe'..."
& $OutExe