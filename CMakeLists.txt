cmake_minimum_required(VERSION 3.24.3)

project(project3)

add_executable(${PROJECT_NAME} ./src/main.c)
add_subdirectory(./src/)

target_link_libraries(${PROJECT_NAME} PUBLIC utility)

target_include_directories(${PROJECT_NAME} PUBLIC ./build/ ./src/)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)