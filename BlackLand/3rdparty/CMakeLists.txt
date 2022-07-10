CMAKE_MINIMUM_REQUIRED(VERSION 3.8)
PROJECT(3rdparty)

# 设置全局变量， 可以在各个目录下共享
set (3RDPARTY_PATH ${CMAKE_SOURCE_DIR}/BlackLand/3rdparty CACHE INTERNAL "ICD Library location" )

set (GLAD_HEAD ${CMAKE_SOURCE_DIR}/BlackLand/3rdparty/glad/include CACHE INTERNAL "ICD Library location" )
set (GLFW_HEAD ${CMAKE_SOURCE_DIR}/BlackLand/3rdparty/glfw/include CACHE INTERNAL "ICD Library location" )
set (GLFW_LIB ${CMAKE_SOURCE_DIR}/BlackLand/3rdparty/glfw/lib-vc2022 CACHE INTERNAL "ICD Library location" )
set(GladSourceDir ${CMAKE_SOURCE_DIR}/BlackLand/3rdparty/glad)

file(GLOB GladSrc 
    "${GladSourceDir}/include/glad/glad.h"
    "${GladSourceDir}/include/KHR/khrplatform.h"
    "${GladSourceDir}/src/glad.c"
)

add_library(glad STATIC ${GladSrc})
target_include_directories(glad PUBLIC "${GladSourceDir}/include")

add_subdirectory ("minlog")
