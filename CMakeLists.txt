file(GLOB_RECURSE engine_src CONFIGURE_DEPENDS "./src/Engine/*.cpp")
add_library(Carbon SHARED ${engine_src})

# SERIAL LIBRARY
add_subdirectory(./libs/serial/)
target_include_directories(Carbon ./libs/serial/include/)
target_link_libraries(Carbon PUBLIC serial)

add_compile_definitions(PLATFORM_WINDOWS)
add_compile_definitions(CARBON_BUILD_DLL)
