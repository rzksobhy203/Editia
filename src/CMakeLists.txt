
add_executable("Editia" "main.cpp" "log.h" "log.cpp")

target_precompile_headers("Editia" PRIVATE "edpch.h")
target_include_directories("Editia" PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_BINARY_DIR})