
add_executable("Editia" "main.cpp" "log.h" "log.cpp"
	"Application.h" "Application.cpp"
	"Window.h" "Window.cpp"
)

target_precompile_headers("Editia" PRIVATE "edpch.h")
target_include_directories("Editia" PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_BINARY_DIR})