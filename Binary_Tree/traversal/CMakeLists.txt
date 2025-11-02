add_subdirectory(breadth_first)
add_subdirectory(deep_first)
add_executable(all_traversal
    Binary_Tree/traversal/all_traversal.cpp
)
target_include_directories(all_traversal
    PRIVATE ${CMAKE_SOURCE_DIR}/Binary_Tree/traversal
)