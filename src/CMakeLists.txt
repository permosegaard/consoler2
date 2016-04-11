set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -std=c++11 -Wall -Werror -pedantic")

find_package(Qt5Widgets REQUIRED)
find_package(Qt5WebEngineWidgets REQUIRED)

include_directories(/usr/local/src/qtermwidget/lib)
link_directories(/usr/local/src/qtermwidget/build)

add_executable(consoler2 Application.cpp MainView.cpp TaskBrowser.cpp TaskConsole.cpp TaskConsoleTmux.cpp Task.cpp Utils.cpp ViewControl.cpp View.cpp ViewTask.cpp)

target_link_libraries(consoler2 Qt5::Widgets Qt5::WebEngineWidgets qtermwidget5)
