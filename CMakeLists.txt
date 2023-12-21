cmake_minimum_required(VERSION 3.5)

project("1.4.1")

include_directories(include)

aux_source_directory(src CPP/C)     # 设置变量 CPP/C 为所有源文件的值

add_executable(main ${CPP/C} main.cpp)

target_link_libraries(main glfw)