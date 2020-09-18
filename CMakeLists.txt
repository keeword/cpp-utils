cmake_minimum_required(VERSION 3.12)

project(utils VERSION 1.0.0 LANGUAGES CXX)

add_library(utils INTERFACE)

target_include_directories(utils INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    )

target_compile_features(utils INTERFACE cxx_std_17)

enable_testing()
add_subdirectory(test)
