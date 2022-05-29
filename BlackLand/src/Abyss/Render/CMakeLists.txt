# CMakeList.txt: BlackLand 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project("Render")

INCLUDE_DIRECTORIES (${3RDPARTY_PATH})

set(CORE_SOURCE_FILES
	"Render.cpp"
)

# Add a library with the above sources
add_library(${PROJECT_NAME} ${CORE_SOURCE_FILES})


target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}
	${GLFW_HEAD}
	${GLAD_HEAD}
)