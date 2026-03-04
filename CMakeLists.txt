# add_executable( ${PROJECT_NAME}
#    src/main.cpp
#    src/Game.cpp # can delete. I've just added a test loop in there to test your build system immediately. Add all other source files here, separated by whitespaces or newlines
# )

# # our preocompiled header pile
# target_precompile_headers( ${PROJECT_NAME} PRIVATE include/Precompiled.h)

# # where #include "" or <> jumps to. replace with src if you want both .h and .c or .hpp and .cpp in src/
# # remove this if your headers are not in a subdirectory
# target_include_directories( ${PROJECT_NAME} PRIVATE include )

# # external libraries
# target_link_libraries( ${PROJECT_NAME} PRIVATE raylib )

cmake_minimum_required(VERSION 3.20)
project(MyGame LANGUAGES C CXX) # EDIT your project name and languages (DO NOT REMOVE C. RAYLIB IS IN C)

# Raylib uses C99, can update to any version after that
set(CMAKE_C_STANDARD 99) # raylib
set(CMAKE_CXX_STANDARD 20) # project
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# disable raylib examples
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(lib/raylib)
add_subdirectory(lib/GUI)
add_subdirectory(App)