set(InventoryEmulator_SOURCES
        "command_line_options.cpp"
        "generator/generate_books_distribution.cpp"
        "library/catalog.cpp"
        "main.cpp"
        )

add_executable(inventory "${InventoryEmulator_SOURCES}")

target_include_directories(inventory PUBLIC ".")

target_link_libraries(inventory PRIVATE "pthread")
target_compile_features(inventory PRIVATE cxx_std_20)

set_target_properties(inventory PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
