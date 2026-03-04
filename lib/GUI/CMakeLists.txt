add_library(GUI STATIC)
target_sources(GUI PRIVATE
   # list .cpp files here as they are added
   src/Button.cpp 
)

target_include_directories(GUI PUBLIC include)
target_link_libraries(GUI PUBLIC raylib)

# silence raylib warnings
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
   target_compile_options(GUI PRIVATE -w)
endif()