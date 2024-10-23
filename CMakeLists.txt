# 指定 CMake 最低版本
cmake_minimum_required(VERSION 3.28)

# 获取当前源码目录的名称作为项目名称
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "." ProjectId ${ProjectId})

# 声明项目名称，使用 C 语言
project(${ProjectId} C)

# 设置 C 标准
set(CMAKE_C_STANDARD 99)

# 查找所有 .c 和 .h 文件
file(GLOB_RECURSE c_files "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
file(GLOB_RECURSE h_files "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

# 提取头文件目录并去除重复
set(HEADER_DIRS "")
foreach (header ${h_files})
    get_filename_component(dir ${header} DIRECTORY)
    list(APPEND HEADER_DIRS ${dir})
endforeach ()
list(REMOVE_DUPLICATES HEADER_DIRS)

# 添加头文件目录
include_directories(${HEADER_DIRS})

# 创建一个哈希表，存储同名的 .h 和 .c 文件
set(SHARED_LIBS "")

# 遍历所有 .h 文件，查找是否有对应的 .c 文件，并编译为共享库
foreach (header ${h_files})
    # 获取头文件名称（不含路径和后缀）
    get_filename_component(header_name ${header} NAME_WE)

    # 在所有 .c 文件中查找是否有同名的 .c 文件
    foreach (source ${c_files})
        get_filename_component(source_name ${source} NAME_WE)
        if (${header_name} STREQUAL ${source_name})
            # 如果找到同名的 .c 文件，编译为静态库
            add_library(${header_name}_lib STATIC ${source})
            list(APPEND SHARED_LIBS ${header_name}_lib)
        endif ()
    endforeach ()
endforeach ()

# 为每个 .c 文件创建独立的可执行文件
foreach (file ${c_files})

    # 获取文件相对路径
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
        get_filename_component(header_name ${header} NAME_WE)

        # 如果当前文件包含这个头文件（假设头文件名出现在源文件内容中）
        file(READ ${file} file_content)
        if (file_content MATCHES "#include[ ]*\"${header_name}\\.h\"")
            # 链接对应的库
            target_link_libraries(${execName} PRIVATE ${header_name}_lib)
        endif ()
    endforeach ()
endforeach ()
