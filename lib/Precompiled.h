// THESE ARE ALL THE LARGE HEADERS THAT TAKE UP COMPILE TIME
// THAT DON'T NEED TO AS THEY CAN BE READY PRECOMPILED.
// THIS INCREASES COMPILE SPEED A LOT
// ONLY ADD HEADERS THAT YOU'RE SURE YOU'RE NOT GOING TO CHANGE

// CMAKE DOES THE PRECOMPILATION FOR US

// ---- STL ----
#include <vector>
#include <array>
#include <unordered_map>

// ---- LOGGING ----
#include <iostream>
#include <cstdio>

// ---- RAYLIB ----
#include <raylib.h>

// ---- OTHER ----
#include <algorithm>