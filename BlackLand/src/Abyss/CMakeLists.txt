# CMakeList.txt: BlackLand 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project("Abyss")
INCLUDE_DIRECTORIES (${CMAKE_SOURCE_DIR}/BlackLand/src)
add_subdirectory("Core")

add_subdirectory("Render")