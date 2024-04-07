project(main)
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main main.cpp)
add_library(main_lib
    include/input_stream.cpp
    include/parse_exception.cpp
    include/parser.cpp
    include/token.cpp
    include/tree.cpp
    include/tree_node.cpp
)
target_include_directories(main_lib PUBLIC include)
target_link_libraries(main main_lib)