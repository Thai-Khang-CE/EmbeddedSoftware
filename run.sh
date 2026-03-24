#!/bin/bash

# Dừng script nếu có lỗi xảy ra
set -e

echo "======================================"
echo "    C/C++ Build Automation Script     "
echo "======================================"

echo "[1] Cleaning old build files..."
make clean

echo "[2] Building for HOST environment..."
make build PLATFORM=HOST

echo "[3] Building for Target MSP432..."
make build PLATFORM=MSP432

echo "[4] Analyzing Linker Map Memory (Size)..."
# Giả sử file đầu ra là c1m2.out hoặc tên tương tự tùy cấu hình Makefile
SIZE_EXEC=$(find . -name "*.out" | head -n 1)
if [ -n "$SIZE_EXEC" ]; then
    arm-none-eabi-size $SIZE_EXEC
else
    echo "No .out file found to analyze."
fi

echo "======================================"
echo "          BUILD SUCCESSFUL!           "
echo "======================================"