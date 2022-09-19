cmake_minimum_required(VERSION 3.20)
project(Tests)

set(CMAKE_CXX_STANDARD 17)

include_directories("${PROJECT_BINARY_DIR}")

# Logger dependency:
include_directories("/usr/local/include/Logger-1.0.0") # Access to shared library header files
link_directories("/usr/local/lib/Logger-1.0.0") # Link shared library
link_libraries(Logger-1.0.0)

# Tester dependency:
include_directories("/usr/local/include/Tester-1.0.0") # Access to shared library header files
link_directories("/usr/local/lib/Tester-1.0.0") # Link shared library
link_libraries(Tester-1.0.0)

set(EXTRA_LIBS ${EXTRA_LIBS})

file(
        GLOB APP_SRC
        "*.h"
        "*.cpp"
)

add_executable(Tests ${APP_SRC})
