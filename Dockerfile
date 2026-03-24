# Sử dụng Ubuntu làm môi trường gốc
FROM ubuntu:22.04

# Tránh các câu hỏi tương tác khi cài đặt gói trên Ubuntu
ENV DEBIAN_FRONTEND=noninteractive

# Cài đặt các công cụ biên dịch (Make, GCC, ARM-GCC)
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc-arm-none-eabi \
    make \
    && rm -rf /var/lib/apt/lists/*

# Thiết lập thư mục làm việc trong Container
WORKDIR /app

# Copy toàn bộ mã nguồn vào Container
COPY . .

# Lệnh mặc định khi chạy container: dọn dẹp và build cho MSP432
CMD ["sh", "-c", "make clean && make build PLATFORM=MSP432"]