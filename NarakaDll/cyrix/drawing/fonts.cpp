#include "fonts.h"

// Definition of the global or static variables
ImFont* Fonts::RegularFont = nullptr;
ImFont* Fonts::LargeFont = nullptr;

void Fonts::LoadFonts() {
    ImGuiIO& io = ImGui::GetIO();
    RegularFont = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\verdana.ttf", 14.0f);
    LargeFont = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\verdana.ttf", 24.0f);
}
