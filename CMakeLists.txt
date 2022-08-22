file(GLOB_RECURSE engine_src CONFIGURE_DEPENDS "./src/Engine/*.cpp")
add_library(Carbon SHARED ${engine_src})

add_compile_definitions(PLATFORM_WINDOWS)
add_compile_definitions(CARBON_BUILD_DLL)
