cmake_minimum_required(VERSION 3.10)
project(UniversityLibrary)

set(CMAKE_CXX_STANDARD 17)

# Создаем библиотеку (статическую) из исходников
add_library(university_lib STATIC
    student.cpp
    application.cpp
    deanery.cpp
)

# Исполняемый файл для демонстрации
add_executable(demo main.cpp)
target_link_libraries(demo university_lib)
