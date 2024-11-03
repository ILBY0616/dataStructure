# 指定 CMake 最低版本
cmake_minimum_required(VERSION 3.28)

# 获取当前源码目录的名称作为项目名称
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# 将项目名称中的空格替换为点（.）
string(REPLACE " " "." ProjectId ${ProjectId})

# 声明项目名称，使用 C 语言
project(${ProjectId} C)

# 设置 C 标准为 C99
set(CMAKE_C_STANDARD 99)

# 查找当前目录及其子目录下所有的 .c 和 .h 文件
file(GLOB_RECURSE c_files "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
file(GLOB_RECURSE h_files "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

# 提取头文件目录并去除重复项
set(HEADER_DIRS "")
foreach (header ${h_files})
    # 获取头文件所在的目录
    get_filename_component(dir ${header} DIRECTORY)
    # 将目录添加到列表中
    list(APPEND HEADER_DIRS ${dir})
endforeach ()
# 移除重复的目录
list(REMOVE_DUPLICATES HEADER_DIRS)

# 添加头文件目录到 include 路径
include_directories(${HEADER_DIRS})

# 为每个 .c 文件创建独立的可执行文件
foreach (file ${c_files})
    # 获取文件相对于当前源码目录的路径
    file(RELATIVE_PATH relPath ${CMAKE_CURRENT_SOURCE_DIR} ${file})

    # 将路径中的分隔符替换为小点，作为可执行文件的名称
    string(REPLACE "/" "." execName ${relPath})
    string(REPLACE "\\" "." execName ${execName})
    string(REPLACE ".c" "" execName ${execName})

    # 为当前 .c 文件创建可执行文件
    add_executable(${execName} ${file})

    # 设置每个可执行文件为控制台应用程序
    set_target_properties(${execName} PROPERTIES LINK_FLAGS "-mconsole")

    # 遍历所有头文件，检查当前文件是否包含某个头文件，如果包含则链接对应的库
    foreach (header ${h_files})
        # 获取头文件名称（不含路径和后缀）
        get_filename_component(header_name ${header} NAME_WE)

        # 读取当前源文件的内容
        file(READ ${file} file_content)
        # 如果当前文件中包含该头文件的引用
        if (file_content MATCHES "#include[ ]*\"${header_name}\\.h\"")
            # 包含该头文件的路径
            include_directories(${HEADER_DIRS})
        endif ()
    endforeach ()
endforeach ()
