cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)

project(Tester)

set(TESTER_VERSION_MAJOR 1)
set(TESTER_VERSION_MINOR 0)

configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/TesterConfig.h.in"
        "${CMAKE_CURRENT_SOURCE_DIR}/TesterConfig.h"
)

file(
        GLOB LIB_SRC
        "*.h"
        "*.cpp"
)
add_library(Tester ${LIB_SRC})

# Install library
install(TARGETS ${PROJECT_NAME} DESTINATION lib/${PROJECT_NAME})

# Install library headers
file(GLOB HEADERS *.h)
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})