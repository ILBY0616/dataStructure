# 指定 CMake 最低版本要求为 3.28
cmake_minimum_required(VERSION 3.28)

# 获取当前源码目录的名称
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# 将目录名称中的空格替换为小点，作为项目名称
string(REPLACE " " "." ProjectId ${ProjectId})

# 声明项目名称为动态生成的 ProjectId，语言为 C
project(${ProjectId} C)

# 指定 C 语言的标准为 C11
set(CMAKE_C_STANDARD 11)

# 使用文件通配符递归获取当前目录及子目录下所有的 .c 和 .h 文件
file(GLOB_RECURSE c_files "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
file(GLOB_RECURSE h_files "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

# 遍历所有的头文件，提取出目录并添加到头文件搜索路径中
set(HEADER_DIRS "")
foreach (header ${h_files})
    get_filename_component(dir ${header} DIRECTORY)
    list(APPEND HEADER_DIRS ${dir})
endforeach ()

# 去除重复的目录
list(REMOVE_DUPLICATES HEADER_DIRS)

# 添加头文件目录
include_directories(${HEADER_DIRS})

# 遍历每个 .c 文件，并为每个文件创建对应的可执行文件
foreach (file ${c_files})

    # 获取文件相对路径
    file(RELATIVE_PATH relPath ${CMAKE_CURRENT_SOURCE_DIR} ${file})

    # 将相对路径中的目录分隔符替换为小点，作为可执行文件的名称
    string(REPLACE "/" "." execName ${relPath})
    string(REPLACE "\\" "." execName ${execName})
    string(REPLACE ".c" "" execName ${execName})

    # 创建可执行文件
    add_executable(${execName} ${file})

endforeach ()
