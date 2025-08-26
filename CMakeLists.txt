# Minimum CMake versiyonunu belirtir.
cmake_minimum_required(VERSION 3.10)

# Projenin adını belirtir.
project(MyMalloc C)

# Başlık dosyalarının aranacağı dizini ekler.
# Böylece #include "my_malloc.h" satırı doğru çalışır.
include_directories(include)

# Eğer test dosyanızın adı simple_usage.c ise aşağıdaki gibi kullanın:
# add_executable(my_malloc_test src/my_malloc.c test/simple_usage.c)

# Eğer test dosyanızın adı test.c ise aşağıdaki gibi kullanın:
add_executable(example src/my_malloc.c test/simple_usage.c)