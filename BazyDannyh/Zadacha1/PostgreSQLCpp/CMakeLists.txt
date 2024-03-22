cmake_minimum_required(VERSION 3.20)

set (PostgreSQL_ADDITIONAL_VERSIONS "16")

project (PostgreSQLCpp)

add_executable (PostgreSQLCpp main.cpp)

target_compile_features(PostgreSQLCpp PRIVATE cxx_std_17)

add_subdirectory ("L:\\Prog\\LibPqxx\\libpqxx-7.9.0" pqxx-build)

target_link_libraries (PostgreSQLCpp pqxx)

