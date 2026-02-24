#!/bin/bash

set -e  # Exit immediately if a command exits with a non-zero status

# Determine directories based on this script's location
RootDir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)/.."
SrcDir="$RootDir/src"
OutExe="$RootDir/main"

# Detect available C compiler: prefer cc, then gcc, then clang
CcCmd=""
for name in cc gcc clang; do
  if command -v "$name" &> /dev/null; then
    CcCmd="$name"
    break
  fi
done

if [ -z "$CcCmd" ]; then
  echo "No C compiler found on PATH. Install GCC or Clang." >&2
  exit 1
fi
echo "Using compiler: $CcCmd"

# Accumulate all .c sources in src
sources=("$SrcDir"/*.c)
if [ ! -e "${sources[0]}" ]; then
  echo "No .c files found in '$SrcDir'." >&2
  exit 1
fi

echo "Building '$OutExe' from sources: ${sources[*]}"

# Build arguments and invoke compiler in a single call
args=(-std=c99 -Wall -I"$SrcDir" "${sources[@]}" -o "$OutExe")
"$CcCmd" "${args[@]}"

if [ $? -ne 0 ]; then
  echo "Build failed." >&2
  exit 1
fi

echo "Build successful: '$OutExe'"

echo "Now I will run the program for you:"
"$OutExe"

exit 0