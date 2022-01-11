cmake_minimum_required(VERSION 3.5)

project(gsrenderer-tests LANGUAGES CXX)

add_executable(Test
    test.cpp
    ../src/core/evaluation.cpp
    ../src/core/output_node.cpp
    ../src/core/renderer.cpp
    ../src/node/node.cpp
)
