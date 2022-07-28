cmake_minimum_required(VERSION 3.22)

include(${CMAKE_CURRENT_SOURCE_DIR}/../Versionable/CMake/CMakeLists.txt)

project(${VERSIONABLE_NAME})

file(
        GLOB LIB_SRC
        "*.h"
        "*.cpp"
)
add_library(${PROJECT_NAME} ${LIB_SRC})

# Install library
install(TARGETS ${PROJECT_NAME} DESTINATION lib/${PROJECT_NAME})

# Install library headers
file(GLOB HEADERS *.h)
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})
