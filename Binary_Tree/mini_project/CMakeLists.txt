add_executable(mini_project
    Binary_Tree/mini_project/main.cpp.cpp
)
target_include_directories(mini_project
    PRIVATE ${CMAKE_SOURCE_DIR}Binary_Tree/mini_project
)