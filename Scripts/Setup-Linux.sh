#!/bin/bash

# Navigate to repo root
cd "$(dirname "$0")/.."

# Ensure premake is executable
chmod +x ./Vendor/premake/premake5

# Generate GNU Makefiles
./Vendor/premake/premake5 gmake2