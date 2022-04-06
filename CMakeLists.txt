cmake_minimum_required(VERSION 3.14)

project(ChessBoard)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

set(PROJECT_INCLUDE_DIR 
${PROJECT_SOURCE_DIR}/Board/include
${PROJECT_SOURCE_DIR}/Piece/include
)

include_directories("${PROJECT_INCLUDE_DIR}")

set(PROJECT_SRCS 
${PROJECT_SOURCE_DIR}/Board/src/board.cc
${PROJECT_SOURCE_DIR}/Board/src/cell.cc
${PROJECT_SOURCE_DIR}/Piece/src/piece.cc
)

add_executable(ChessBoard ${PROJECT_SRCS} ${PROJECT_SOURCE_DIR}/main.cc)

enable_testing()
find_package(GTest REQUIRED)
if(NOT GTest_FOUND)
    FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        703bd9caab50b139428cea1aaff9974ebee5742e # release-1.10.0
    )
    FetchContent_MakeAvailable(googletest)
    endif()
include(GoogleTest)

add_executable(ChessBoardTest ${PROJECT_SRCS} ${PROJECT_SOURCE_DIR}/Test/test.cc)
target_link_libraries(ChessBoardTest gtest gtest_main pthread)
gtest_discover_tests(ChessBoardTest)
