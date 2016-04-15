set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -std=c++11 -Wall -Werror -pedantic")

find_package(Qt5Widgets REQUIRED)

add_library(consoler2-dummy SHARED Plugin.cpp)

target_link_libraries(consoler2-dummy Qt5::Widgets)
