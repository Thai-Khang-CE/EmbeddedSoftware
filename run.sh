#!/bin/bash

# Dừng script ngay lập tức nếu có bất kỳ lệnh nào bị lỗi
set -e

echo "======================================"
echo "    C/C++ Build Automation Script     "
echo "======================================"

echo "[1] Cleaning old build files..."
make clean

echo "[2] Building for HOST environment..."
make build PLATFORM=HOST

echo "[3] Analyzing Executable Memory (Size)..."
# Tìm file đầu ra .out và dùng lệnh size tiêu chuẩn của Linux để phân tích
SIZE_EXEC=$(find . -name "*.out" | head -n 1)
if [ -n "$SIZE_EXEC" ]; then
    size $SIZE_EXEC
else
    echo "No .out file found to analyze."
fi

echo "======================================"
echo "          BUILD SUCCESSFUL!           "
echo "======================================"