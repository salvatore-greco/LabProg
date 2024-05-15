cmake_minimum_required(VERSION 3.28)
project(LaboratorioProgrammazione)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)
set(SOURCE_FILES Activity.cpp
        Date.cpp
        TodoList.cpp
)


add_executable(TodoList main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(TodoList core)

