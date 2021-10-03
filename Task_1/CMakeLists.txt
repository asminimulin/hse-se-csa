cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

Project(libfilm
    VERSION 1.0
    LANGUAGES CXX
)

# Build the library target
add_subdirectory(src)

# Temporary workaround for testing linkage is successfull
add_executable(main main.cpp "include/libfilm/container.hpp")

target_link_libraries(main PRIVATE libfilm)
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
