# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License.

cmake_minimum_required(VERSION 3.10)  # Specify the minimum version for CMake

project(OnnxJuce)  # Specify the name of your project

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)  # Make sure that the compiler exits if C++17 support is not available
set(CMAKE_CXX_EXTENSIONS OFF)  # Turn off compiler-specific extensions like gnu++17


#find_package(onnxruntime REQUIRED)

# set these up for your system if onnxruntime and header are not 
# in standard search paths, e.g. for mac homebrew setup
#include_directories(/opt/homebrew/include/onnxruntime/)
include_directories(/home/matthewyk/src/sw/onnxruntime-linux-x64-1.18.0/include/)
#link_directories(/opt/homebrew/lib/)
link_directories(/home/matthewyk/src/sw/onnxruntime-linux-x64-1.18.0/lib/)

add_executable(onnx-model-loader src/main.cpp)

target_link_libraries(onnx-model-loader PRIVATE onnxruntime)
