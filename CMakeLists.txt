cmake_minimum_required(VERSION 3.5)

project(gsrenderer LANGUAGES CXX)

find_package(OpenImageIO REQUIRED)

add_subdirectory(thirdparty)
add_subdirectory(tests)
add_subdirectory(src)
