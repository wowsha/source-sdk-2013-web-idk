cmake_minimum_required(VERSION 3.15)
project(source_sdk_emscripten)

# Use Emscripten toolchain
if(NOT EMSCRIPTEN)
    message(FATAL_ERROR "This project requires Emscripten")
endif()

# Add source files (you'll want to add more from SDK later)
set(SOURCES
    # example source file; adjust as needed
    src/main.cpp
)

add_executable(source_sdk_emscripten ${SOURCES})

# Linker flags for web
set_target_properties(source_sdk_emscripten PROPERTIES
    LINK_FLAGS "--bind -s USE_SDL=2 -s USE_WEBGL2=1 -s ALLOW_MEMORY_GROWTH=1"
)

# Include paths (adjust)
target_include_directories(source_sdk_emscripten PRIVATE src)
