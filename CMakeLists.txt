cmake_minimum_required(VERSION 3.5)

project(1C_Contest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (ADDR_SAN)
    message("\n==============================\nCompile with address sanitizer\n==============================\n")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
endif()

add_executable(1C_Contest
    ForwardDeclaration.h

    DataBase/DataBase.h
    DataBase/DataBase.cpp

    Solution/Solution.h

    main.cpp
)
