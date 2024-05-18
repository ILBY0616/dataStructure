# 指定 CMake 最低版本要求为 3.28
cmake_minimum_required(VERSION 3.28)

# 获取当前源码目录的名称
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# 将目录名称中的空格替换为下划线，作为项目名称
string(REPLACE " " "_" ProjectId ${ProjectId})

# 声明项目名称为动态生成的 ProjectId，语言为 C
project(${ProjectId} C)

# 指定 C 语言的标准为 C11
set(CMAKE_C_STANDARD 11)

# 使用文件通配符获取当前目录下所有的 .c 文件
file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

# 遍历每个 .c 文件，并为每个文件创建对应的可执行文件
foreach (file ${files})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file})
endforeach ()
