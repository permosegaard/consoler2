set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -std=c++11 -Wall -Werror -pedantic")

find_package(Qt5Widgets REQUIRED)
find_package(Qt5OpenGL REQUIRED)

file(GLOB SOURCES "*.cpp")
add_executable(consoler2 ${SOURCES})

target_link_libraries(consoler2 Qt5::Widgets Qt5::OpenGL)
