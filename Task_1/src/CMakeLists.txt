add_library(libfilm
    "cartoon.cpp"
    "container.cpp"
    "documentary.cpp"
    "fiction.cpp"
    "film.cpp"
)

target_include_directories(libfilm PUBLIC "${PROJECT_SOURCE_DIR}/include")
