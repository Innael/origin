cmake_minimum_required(VERSION 3.22.0)
project(ProverkaDvsS2)

find_package(Catch2 REQUIRED)
add_executable(ProverkaDvsS2 ProverkaDvsS2.cpp  "Spisok.cpp")
target_link_libraries(ProverkaDvsS2 PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)