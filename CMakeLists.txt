cmake_minimum_required(VERSION 3.15)
project(source_sdk_emscripten)

# Check if Emscripten is being used
if(NOT EMSCRIPTEN)
    message(FATAL_ERROR "This project requires Emscripten.")
endif()

# Recursively add all .cpp files from selected folders
file(GLOB_RECURSE TIER0_SRC "src/tier0/*.cpp")
file(GLOB_RECURSE TIER1_SRC "src/tier1/*.cpp")
file(GLOB_RECURSE TIER2_SRC "src/tier2/*.cpp")
file(GLOB_RECURSE GAME_SHARED_SRC "src/game/shared/*.cpp")

# Combine sources
set(SOURCES
    ${TIER0_SRC}
    ${TIER1_SRC}
    ${TIER2_SRC}
    ${GAME_SHARED_SRC}
    src/main.cpp  # keep this for now until the real entry is ready
)

# Create the WASM target
add_executable(source_sdk_emscripten ${SOURCES})

# Include directories (adjust as you add more)
target_include_directories(source_sdk_emscripten PRIVATE
    src/public
    src/tier0
    src/tier1
    src/tier2
    src/game/shared
)

# Emscripten settings
set_target_properties(source_sdk_emscripten PROPERTIES
    LINK_FLAGS "--bind -s USE_SDL=2 -s USE_WEBGL2=1 -s ALLOW_MEMORY_GROWTH=1 -s EXIT_RUNTIME=0"
)
