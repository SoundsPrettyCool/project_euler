cmake_minimum_required(VERSION 3.20)
project(project_euler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # -std=c++20, not -std=gnu++20

# Default to a Debug build (-g, no optimization) so gdb works out of the box.
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Put every executable in build/bin/ instead of scattering them through the build tree.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Let editors and tools (e.g. clangd) see the exact compile flags.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# One executable per problem, named after its .cpp file (e.g. 022_names_scores).
# CONFIGURE_DEPENDS re-runs the glob on each build, so new problems are picked up
# without re-running cmake by hand.
file(GLOB PROBLEM_SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/problems/*/*.cpp)

foreach(source IN LISTS PROBLEM_SOURCES)
    get_filename_component(name ${source} NAME_WE)
    add_executable(${name} ${source})
    target_compile_options(${name} PRIVATE -Wall -Wextra -Wpedantic)
endforeach()
