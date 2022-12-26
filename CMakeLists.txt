cmake_minimum_required(VERSION 3.25.0)

project(Application)

include_directories(
    dependencies/include
)
link_directories(
    dependencies/lib/
)
add_library(currentLib
    dependencies/lib/String.cpp
)


add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} currentLib)
