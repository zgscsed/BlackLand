﻿# CMakeList.txt: BlackLand 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

INCLUDE_DIRECTORIES (${3RDPARTY_PATH}/glad/include)
INCLUDE_DIRECTORIES (${3RDPARTY_PATH}/glfw/include)
INCLUDE_DIRECTORIES (${3RDPARTY_PATH})

INCLUDE_DIRECTORIES (${CMAKE_SOURCE_DIR}/BlackLand)

message("start camke project main BlackLand")

add_definitions(-DAS_BUILD_DLL=1)
# 包含子项目。
add_subdirectory ("3rdparty")

# 包含子项目。
add_subdirectory ("src")


set (HEAD_FILES
	"BlackLand.hpp"
    "src/abyss.hpp"
)

set (SOURCE_FILES
	"BlackLand.cpp"
	${3RDPARTY_PATH}/glad/src/glad.c)

file(GLOB ABYSS_HEAD_FILES CONFIGUE_DEPENDS "src/Abyss/Core/*.hpp" "src/Abyss/Event/*.hpp" "src/Abyss/Render/*.hpp")
file(GLOB ABYSS_SOURCE_FILES CONFIGUE_DEPENDS "src/Abyss/Core/*.cpp" "src/Abyss/Event/*.cpp" "src/Abyss/Render/*.cpp")

file(GLOB PLATFORM_HEAD_FILES CONFIGUE_DEPENDS "src/Platform/Windows/*.hpp" "src/Platform/OpenGL/*.hpp")
file(GLOB PLATFORM_SOURCE_FILES CONFIGUE_DEPENDS "src/Platform/Windows/*.cpp" "src/Platform/OpenGL/*.cpp")
# 将源代码添加到此项目的可执行文件。
add_executable (BlackLand ${HEAD_FILES} ${SOURCE_FILES} ${ABYSS_SOURCE_FILES} ${PLATFORM_SOURCE_FILES})

target_include_directories( ${PROJECT_NAME}
   PUBLIC ${3RDPARTY_PATH}
   PUBLIC ${GLFW_HEAD}
    ${GLFW_LIB}
	${GLAD_HEAD}
   PUBLIC ${CMAKE_SOURCE_DIR}/BlackLand/src
)
target_link_libraries(BlackLand 
    glad
    minlog
	${GLFW_LIB}/glfw3.lib
)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET BlackLand PROPERTY CXX_STANDARD 20)
endif()

message("end camke project main BlackLand")
# TODO: 如有需要，请添加测试并安装目标。
