cmake_minimum_required(VERSION 3.24)
list(APPEND CMAKE_PREFIX_PATH $ENV{GEODE_SDK})
find_package(Geode REQUIRED)
add_geode_mod(beatap.save_on_crash "1.0.0" src/main.cpp)
