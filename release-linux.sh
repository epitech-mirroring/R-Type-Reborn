#!/bin/bash

# Set script to exit on any errors.
set -e

# Function to print info messages in yellow color
info() {
  echo -e "\033[1;33m[info] $1\033[0m"
}

# Check if the script is run as root
if [[ $EUID -ne 0 ]]; then
   echo "This script must be run as root. Please run with sudo or as root user."
   exit 1
fi

# Variables for dependency directories
BUILD_DIR="build"
CONAN_PROFILE="default"

# Build the project
info "Building the project..."
./build-linux.sh

# Step: Check if rpmbuild is installed
info "Checking if rpmbuild is installed..."
if ! command -v rpmbuild &> /dev/null
then
    info "Rpmbuild not found, installing Rpmbuild..."
    $package_manager install -y rpm-build
fi
info "Rpmbuild is installed."

# Step: Run cpack to generate the package
info "Running CPack to generate the package..."
cd $BUILD_DIR
cpack

# Step : Move the package to the root directory
info "Moving the package to the root directory..."
