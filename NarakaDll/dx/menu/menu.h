#pragma once
#include "../../cyrix/drawing/drawing.h"

namespace Menu {
	extern bool bMenuOpened;
	enum Tabs {
		NONE,
		VISUALS,
	};
	void Draw();
	void Exploits();
}