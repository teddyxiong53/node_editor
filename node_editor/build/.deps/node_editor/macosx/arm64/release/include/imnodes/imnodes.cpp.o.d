{
    values = {
        "/Library/Developer/CommandLineTools/usr/bin/clang",
        {
            "-Qunused-arguments",
            "-isysroot",
            "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk",
            "-fvisibility=hidden",
            "-fvisibility-inlines-hidden",
            "-O3",
            "-std=c++17",
            "-Iinclude",
            "-Iinclude/imnodes",
            "-DGLFW_INCLUDE_NONE",
            "-DGL_SILENCE_DEPRECATION",
            "-framework",
            "CoreVideo",
            "-framework",
            "Cocoa",
            "-framework",
            "IOKit",
            "-framework",
            "OpenGL",
            "-isystem",
            "/Users/teddy/.xmake/packages/i/imgui/v1.91.4-docking/3836c950eb9948ebac164e3c2525abd6/include",
            "-isystem",
            "/Users/teddy/.xmake/packages/i/imgui/v1.91.4-docking/3836c950eb9948ebac164e3c2525abd6/include/imgui",
            "-isystem",
            "/Users/teddy/.xmake/packages/i/imgui/v1.91.4-docking/3836c950eb9948ebac164e3c2525abd6/include/backends",
            "-isystem",
            "/Users/teddy/.xmake/packages/i/imgui/v1.91.4-docking/3836c950eb9948ebac164e3c2525abd6/include/misc/cpp",
            "-isystem",
            "/Users/teddy/.xmake/packages/g/glfw/3.4/3ce34c98157445c898b9d2bf71391976/include",
            "-DNDEBUG"
        }
    },
    files = {
        "include/imnodes/imnodes.cpp"
    },
    depfiles_format = "gcc",
    depfiles = "build/.objs/node_editor/macosx/arm64/release/include/imnodes/__cpp_imnodes.cpp.cpp:   include/imnodes/imnodes.cpp include/imnodes/imnodes_internal.h   include/imnodes/imnodes.h\
"
}