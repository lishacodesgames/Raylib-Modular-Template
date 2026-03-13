# Raylib Modular Template
Modular game template using raylib as a git submodule and CMake. <br>
This repository is intended to be used as a starting point for a new raylib project.

This library-based system is for those who want a distinct separation between the core app, external libraries, and gui code. <br>
This can be used as-is (like I do) or any subdirectories can be added or removed as needed

*I also have a simpler, non-lib-based, template: [check it out](https://github.com/lishacodesgames/Raylib-Template)*

## How to Clone
`git clone --recursive` to get the raylib submodule local

**If you forgot, do:** <br>
`git submodule update --init --recursive` after regular `git clone`

### Build
```bash
mkdir build
cd build
cmake --preset Debug OR Release : (configuration, only needs to be done when CMakeLists.txt has changed)
cmake --build --preset Debug OR Release
```

*Check out [CMakePresets.json](CMakePresets.json) if you're confused* <br>

Executable will appear in `build/` under preset name

## Project Structure
What your project architecture should ideally look like for the CMakeLists.txt I've included (Can change accordingly, otherwise)
```
‖
‖——.git*
‖——CMakeLists.txt
‖——CMakePresets.json
‖——App/
‖  ‖——CMakeLists.txt
‖  ‖——include/
‖     ‖——*.h    → all *your* header files
‖  ‖——src/
‖     ‖——main.cpp
‖     ‖——*.cpp  → all *your* source files
‖
‖——lib/
‖  ‖——raylib/   → raylib submodule
‖  ‖——Engine/   → my own (extremely simple) implementation
‖     ‖——GUI/   → raylib GUI stuff that's not native to your app
‖     ‖——Core/  → veryy simple Layering and Logging system
```

I would love some feedback and suggestions for the Engine!

### Linux Dependencies
Raylib requires a lot of libraries that are built-in on Mac and Windows. <br>
No worries, Linux just requires 1 command to install them all:
```bash
sudo apt install \
    libx11-dev \
    libxcursor-dev \
    libxrandr-dev \
    libxi-dev \
    libxinerama-dev \
    libgl1-mesa-dev \
    libasound2-dev \
    libpulse-dev \
    libxkbcommon-dev
```

## Add New Source Files
Put any new `.cpp` files in `App/src/` <br>
Update App/CMakeLists.txt as needed, example:
```cmake
add_executable(YourProjectName
  src/main.cpp
  src/other_file.cpp
)
```

**Note:** I've made it so that you don't need to touch any CMakeLists.txt other than App/ as you will add your source files there. <br>
If any issues arise, lmk :)

## Updating raylib (the submodule)
```bash
cd lib/raylib
git pull
cd ../..
git add lib/raylib
git commit -m "Updated raylib submodule"
```

## Requirements
* CMake 3.20+
* C++ compiler: GCC / Clang
* Ninja (not *required*, but it's what the presets use)