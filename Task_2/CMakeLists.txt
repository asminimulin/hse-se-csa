cmake_minimum_required(VERSION 3.16)

project(Task_2 LANGUAGES CXX)

add_subdirectory(src)

add_executable(task_2 main.cpp "film_generator.cpp")

target_link_libraries(task_2 PRIVATE libfilm)

set_target_properties(task_2
    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)
