cmake_minimum_required(VERSION 2.8.11)

project(consoler2)

add_subdirectory(libconsoler2-dummy)
add_subdirectory(libconsoler2-webkit)
add_subdirectory(libconsoler2-qtermwidget)

add_subdirectory(consoler2)
