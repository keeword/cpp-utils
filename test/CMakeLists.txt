add_executable(utils_test main.cc fnv1a.cc strings.cc)
target_link_libraries(utils_test utils)
add_test(utils utils_test)