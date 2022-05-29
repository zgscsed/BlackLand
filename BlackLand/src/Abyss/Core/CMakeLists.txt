# CMakeList.txt: BlackLand 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project("Core")

INCLUDE_DIRECTORIES (${CMAKE_SOURCE_DIR}/BlackLand/src)
#set(CORE_SOURCE_FILES
#	"Application.cpp"
#)

AUX_SOURCE_DIRECTORY(. CORE_SOURCE_FILES)

# Add a library with the above sources
add_library(${PROJECT_NAME} ${CORE_SOURCE_FILES})

# 该目录文件需要使用三方库，需要将库目录加入
target_include_directories( ${PROJECT_NAME}
    PUBLIC ${3RDPARTY_PATH}
)

# target_link_libraries(minlog)
