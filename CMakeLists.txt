file(GLOB imgui_src CONFIGURE_DEPENDS "./libs/imgui/*.cpp")
set(imgui_backends "./libs/imgui/backends/imgui_impl_glfw.cpp"
                   "./libs/imgui/backends/imgui_impl_opengl3.cpp"
                   "./libs/imgui/backends/imgui_impl_opengl3_loader.h")

file(GLOB_RECURSE engine_src CONFIGURE_DEPENDS "./src/Engine/*.cpp")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(Carbon SHARED ${engine_src}
                          ${imgui_src}
                          ${imgui_backends})

set_target_properties(Carbon PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

target_include_directories(Carbon PUBLIC ./libs/imgui/)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# -------- GLFW AND OPENGL --------

add_subdirectory(./libs/glfw/)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

find_package(OpenGL REQUIRED)
target_link_libraries(Carbon PUBLIC OpenGL::GL)

target_include_directories(Carbon PUBLIC ./libs/glfw/include/)
target_link_libraries(Carbon PUBLIC glfw)

# ---------- GLAD ----------

add_subdirectory(./libs/glad-4.4/)
target_include_directories(Carbon PUBLIC ./libs/glad-4.4/include/)
target_link_libraries(Carbon PUBLIC glad)

add_compile_definitions(PLATFORM_WINDOWS)
add_compile_definitions(CARBON_BUILD_DLL)
