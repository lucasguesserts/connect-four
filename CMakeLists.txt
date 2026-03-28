cmake_minimum_required(VERSION 3.20)

# Setup project

project(connect_four VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(CONNECT_FOUR_BUILD_TESTS "Build unit tests" ON)

# Dependencies

add_subdirectory(dependencies/fmt)

# Library

add_library(connect_four_lib
    src/board.cpp
    src/game.cpp
)

target_include_directories(connect_four_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(connect_four_lib
    PUBLIC
        fmt::fmt
)

# Apps

add_executable(play_game
    apps/play_game.cpp
)
target_link_libraries(play_game
    PRIVATE
        connect_four_lib
)

add_executable(example
    apps/example.cpp
)
target_link_libraries(example
    PRIVATE
        connect_four_lib
)

# Tests

if(CONNECT_FOUR_BUILD_TESTS)
    include(CTest)

    add_library(doctest INTERFACE)
    target_include_directories(doctest
        INTERFACE
            ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/doctest
    )

    add_executable(connect_four_tests
        tests/main_test.cpp
        tests/board_tests.cpp
        tests/fmt_tests.cpp
    )

    target_link_libraries(connect_four_tests
        PRIVATE
            connect_four_lib
            doctest
            fmt::fmt
    )

    add_test(NAME connect_four_tests COMMAND connect_four_tests)
endif()
