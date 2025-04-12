-- 项目设置
add_rules("mode.debug", "mode.release")
set_languages("c++17")

-- 使用 xrepo 管理依赖
add_requires("imgui v1.91.4-docking", {configs = {glfw_opengl3 = true}})
add_requires("glfw")

-- 定义目标
target("node_editor")
    set_kind("binary")
    
    -- 添加源文件
    add_files("src/main.cpp")
    
    -- 添加 imnodes 源文件
    add_files("include/imnodes/imnodes.cpp")
    
    -- 添加头文件路径
    add_includedirs("include")
    add_includedirs("include/imnodes")
    -- 链接依赖
    add_packages("imgui", "glfw")
    
    -- macOS 特定设置
    if is_plat("macosx") then
        add_frameworks("OpenGL", "Cocoa", "IOKit", "CoreVideo")
    end
    
    -- 安装后复制可执行文件
    after_build(function (target)
        os.cp(target:targetfile(), "bin/")
    end)