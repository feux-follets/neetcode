cmake_minimum_required(VERSION 4.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_COMPILE_WARNING_AS_ERROR OFF)
set(CMAKE_COLOR_DIAGNOSTICS ON)
# set(CMAKE_CXX_CLANG_TIDY clang-tidy)

include(${CMAKE_SOURCE_DIR}/cmake/StdModule.cmake)

set(WARNINGS
		-Wall
		-Wextra
		-Wpedantic
		-Wconversion
		-Wnon-virtual-dtor
		-Wshadow
)
add_compile_options(${WARNINGS})


project(neetcode CXX)
add_subdirectory(cpp)