
add_executable("Editia" "main.cpp")

target_include_directories("Editia" PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_BINARY_DIR})