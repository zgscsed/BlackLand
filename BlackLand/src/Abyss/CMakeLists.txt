# CMakeList.txt: BlackLand 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project("Abyss")

INCLUDE_DIRECTORIES (${CMAKE_SOURCE_DIR}/BlackLand/src)
INCLUDE_DIRECTORIES (${CMAKE_SOURCE_DIR}/BlackLand/src/Platform)

AUX_SOURCE_DIRECTORY(./Core ABYSS_SOURCE_FILES)
AUX_SOURCE_DIRECTORY(./Render ABYSS_SOURCE_FILES)
AUX_SOURCE_DIRECTORY(./Event ABYSS_SOURCE_FILES)

# Add a library with the above sources
add_library(${PROJECT_NAME} STATIC ${ABYSS_SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}
    Platform)

# 该目录文件需要使用三方库，需要将库目录加入
target_include_directories( ${PROJECT_NAME}
   PUBLIC ${3RDPARTY_PATH}
    ${GLFW_HEAD}
	${GLAD_HEAD}
   PUBLIC ${CMAKE_SOURCE_DIR}/BlackLand/src
)