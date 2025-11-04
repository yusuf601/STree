cmake_minimum_required(VERSION 3.25)
project(tree LANGUAGES CXX)
# set
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) # hasil binary ke build/bin

# subdirectory
add_subdirectory(Fundamental)
add_subdirectory(Binary_Tree)