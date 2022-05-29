CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

include_directories(${PROJECT_BINARY_DIR}/include)

link_libraries(${lib_name})
link_libraries(${DEPENDENT_LIBRARIES})

#add_executable(log_test test_log.cpp)
