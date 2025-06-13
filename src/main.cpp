#include <emscripten/emscripten.h>
#include <cstdio>

int main() {
    printf("Hello, Half-Life 2 WebAssembly!\n");
    emscripten_exit_with_live_runtime();
    return 0;
}
