cmake_minimum_required(VERSION 3.20)
project(MyGame LANGUAGES C CXX) # EDIT your project name and languages 
# (DO NOT REMOVE C. RAYLIB IS IN C)

# go to cmakelists in subdirectories
add_subdirectory(lib)
add_subdirectory(App)