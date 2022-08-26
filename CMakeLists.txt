# CMakeList.txt : CMake project for Editia, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.19)

project ("Editia")

# subdirectories
add_subdirectory("vendor/spdlog")
add_subdirectory("vendor/glfw")
add_subdirectory("vendor/glad")
add_subdirectory("vendor/imgui")
add_subdirectory("src")

# Config
configure_file(Helpers.h.in Helpers.h)
set_property(TARGET "Editia" PROPERTY CXX_STANDARD 20)
target_compile_definitions("Editia" PRIVATE "-DGLFW_INCLUDE_NONE")
target_link_libraries("Editia" PRIVATE spdlog glfw glad imgui)