{
    files = {
        "build/.objs/node_editor/macosx/arm64/release/src/main.cpp.o",
        "build/.objs/node_editor/macosx/arm64/release/include/imnodes/imnodes.cpp.o"
    },
    values = {
        "/Library/Developer/CommandLineTools/usr/bin/clang++",
        {
            "-isysroot",
            "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk",
            "-lz",
            "-L/Users/teddy/.xmake/packages/i/imgui/v1.91.4-docking/3836c950eb9948ebac164e3c2525abd6/lib",
            "-L/Users/teddy/.xmake/packages/g/glfw/3.4/3ce34c98157445c898b9d2bf71391976/lib",
            "-Wl,-x",
            "-Wl,-dead_strip",
            "-limgui",
            "-lglfw3",
            "-framework",
            "CoreVideo",
            "-framework",
            "Cocoa",
            "-framework",
            "IOKit",
            "-framework",
            "OpenGL"
        }
    }
}