#pragma once
#include "../../imgui/imgui.h"

namespace Fonts {
    // Global or static variable for the larger font
    extern ImFont* RegularFont;
    extern ImFont* LargeFont;

    void LoadFonts();
}
