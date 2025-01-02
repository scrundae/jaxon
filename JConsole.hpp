#include "include/imgui.h"
#include "include/rlImGui.h"
#include <string>

static char consoleText[256];
std::string consoleHistory;

void DoConsole() {
        ImGui::SetNextWindowPos(ImVec2(10, 10), ImGuiCond_FirstUseEver);
        ImGui::Begin("Console");

        if (ImGui::InputText("##console", consoleText, ImGuiInputTextFlags_EnterReturnsTrue)) {
            if (true) {
                consoleHistory += consoleText + std::string("\n") + consoleHistory;
            }
        }

        ImGui::Text(consoleHistory.c_str());

        ImGui::End();
}