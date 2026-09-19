add_subdirectory(Engine)

set(BUILD_EXAMPLES OFF CACHE BOOL "Build raylib examples" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "Build raylib games" FORCE)
add_compile_definitions(SUPPORT_FILEFORMAT_JPG)

add_subdirectory(raylib)