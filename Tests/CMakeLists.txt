cmake_minimum_required(VERSION 3.22)
project(Tests)

set(CMAKE_CXX_STANDARD 17)

include_directories("${PROJECT_BINARY_DIR}")

# Logger dependency:
include_directories("/usr/local/include/Logger") # Access to shared library header files
link_directories("/usr/local/lib/Logger") # Link shared library
link_libraries(Logger)

# Tester dependency:
include_directories("/usr/local/include/Tester") # Access to shared library header files
link_directories("/usr/local/lib/Tester") # Link shared library
link_libraries(Tester)


set(EXTRA_LIBS ${EXTRA_LIBS})

file(
        GLOB APP_SRC
        "*.h"
        "*.cpp"
)

add_executable(Tests ${APP_SRC})
