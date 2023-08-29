cmake_minimum_required(VERSION 3.10)
project(AP)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenSSL REQUIRED)
find_package(GTest REQUIRED)

include_directories(include/)

add_executable(main
        src/main.cpp
        src/server.cpp
        src/client.cpp
        src/crypto.cpp
        src/unit_test.cpp
)
target_link_libraries(main
        OpenSSL::SSL
        GTest::GTest
        GTest::Main
)