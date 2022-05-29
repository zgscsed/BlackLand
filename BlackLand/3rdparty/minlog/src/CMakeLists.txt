CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

# include(CheckFunctionExists)
# check_function_exists(accept4 HAVE_ACCEPT4)

link_libraries(${DEPENDENT_LIBRARIES})

set(SOURCE_FILES
        logger.cpp
        logFile.cpp
        )

set(target_name ${lib_name})

add_library(${target_name} STATIC ${SOURCE_FILES})

set_target_properties(${target_name}
        PROPERTIES
        OUTPUT_NAME_DEBUG ${target_name}d
        OUTPUT_NAME ${target_name}
        )

set(HEAD_FILES
        logger.hpp
        logFile.hpp
        )

# INSTALL(FILES ${HEAD_FILES} DESTINATION ${PROJECT_BINARY_DIR}/include/)

#ADD_CUSTOM_COMMAND(TARGET ${target_name}
#        POST_BUILD
#        COMMAND make install
#        )
