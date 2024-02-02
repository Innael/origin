cmake_minimum_required(VERSION 3.22.0)
project(ProverkaDvusvyaznogoSpiska)

find_package(Catch2 REQUIRED)
add_executable(ProverkaDvusvyaznogoSpiska ProverkaDvusvyaznogoSpiska.cpp  "Spisok.cpp")
target_link_libraries(ProverkaDvusvyaznogoSpiska PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)