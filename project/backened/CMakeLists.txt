# 指定版本
cmake_minimum_required(VERSION 3.24)
# 项目名
project(main)
# 使用指定源文件来生成目标可执行文件
add_executable(main  main.cpp)
# 引入外部依赖包
find_package(Crow REQUIRED)
# 目标文件与库文件进行链接
target_link_libraries(main PUBLIC Crow::Crow)