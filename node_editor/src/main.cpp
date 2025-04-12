#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h> // macOS 特定 OpenGL 头文件
#include <imnodes.h>
#include <vector>
#include <utility>
#include <string>

static void glfw_error_callback(int error, const char* description) {
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

int main(int, char**) {
    // 初始化 GLFW
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) return 1;

    // macOS OpenGL 设置
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE); // 使用 GLFW_TRUE

    // 创建窗口
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Node Editor", nullptr, nullptr);
    if (window == nullptr) return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // 启用垂直同步

    // 初始化 Imgui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    // 设置 Imgui 样式
    ImGui::StyleColorsDark();

    // 初始化 Imgui 后端
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 150");

    // 初始化 imnodes
    ImNodes::CreateContext();
    // 自定义 imnodes 样式（使用 Colors 适配旧版 imnodes）
    ImNodesStyle& style = ImNodes::GetStyle();
    style.Colors[ImNodesCol_GridBackground] = IM_COL32(50, 50, 50, 255);
    style.Colors[ImNodesCol_NodeBackground] = IM_COL32(60, 60, 60, 255);

    // 节点和连接数据
    struct Node {
        int id;
        std::string title;
        std::vector<int> input_pins;
        std::vector<int> output_pins;
    };
    std::vector<Node> nodes;
    std::vector<std::pair<int, int>> links; // 连接：(start_pin, end_pin)

    // 添加示例节点
    nodes.push_back({1, "Node A", {10}, {11}});
    nodes.push_back({2, "Node B", {12}, {13}});
    int next_pin_id = 14;

    // 主循环
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // 开始 Imgui 帧
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // 创建节点编辑器窗口
        ImGui::Begin("Node Editor");
        ImNodes::BeginNodeEditor();

        // 绘制节点
        for (const auto& node : nodes) {
            ImNodes::BeginNode(node.id);
            ImNodes::BeginNodeTitleBar();
            ImGui::TextUnformatted(node.title.c_str());
            ImNodes::EndNodeTitleBar();

            // 输入引脚
            for (int pin_id : node.input_pins) {
                ImNodes::BeginInputAttribute(pin_id);
                ImGui::Text("In");
                ImNodes::EndInputAttribute();
            }

            // 输出引脚
            for (int pin_id : node.output_pins) {
                ImNodes::BeginOutputAttribute(pin_id);
                ImGui::Indent(40.0f);
                ImGui::Text("Out");
                ImNodes::EndOutputAttribute();
            }

            ImNodes::EndNode();
        }

        // 绘制连接
        for (size_t i = 0; i < links.size(); ++i) {
            ImNodes::Link(static_cast<int>(i), links[i].first, links[i].second);
        }

        // 处理连接创建
        int start_pin, end_pin;
        if (ImNodes::IsLinkCreated(&start_pin, &end_pin)) {
            links.emplace_back(start_pin, end_pin);
        }

        // 处理右键菜单（添加新节点）
        if (ImGui::IsWindowHovered() && ImGui::IsMouseClicked(1)) {
            ImGui::OpenPopup("AddNode");
        }
        if (ImGui::BeginPopup("AddNode")) {
            if (ImGui::MenuItem("Add Node")) {
                int new_node_id = static_cast<int>(nodes.size()) + 1;
                nodes.push_back({new_node_id, "Node " + std::to_string(new_node_id), {next_pin_id++}, {next_pin_id++}});
            }
            ImGui::EndPopup();
        }

        ImNodes::EndNodeEditor();
        ImGui::End();

        // 渲染
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    // 清理
    ImNodes::DestroyContext();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}