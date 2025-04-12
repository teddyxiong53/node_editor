# ImNodes 节点编辑器示例项目

基于ImGui和ImNodes构建的节点编辑器演示项目，包含基本的节点连接、拖拽布局功能。

## 功能特性
- 可视化节点编辑界面
- 支持节点拖拽和连线
- 可定制的节点样式
- 基于ImGui的实时界面渲染

## 快速开始
```bash
git clone https://github.com/teddyxiong53/node_editor.git
cd node_editor
xmake f -p macosx -a arm64
xmake
./bin/node_editor
```

## 依赖项
- [ImGui](https://github.com/ocornut/imgui)
- [ImNodes](https://github.com/Nelarius/imnodes)

## 项目结构
```
imgui-test/
├── node_editor/     # 节点编辑器实现
├── include/         # 头文件
├── src/             # 源代码
└── xmake.lua        # 构建配置
```