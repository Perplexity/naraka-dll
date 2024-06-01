#include "drawing.h"
#include "fonts.h"

void Drawing::DrawPlayers(ImDrawList* draw)
{
	if (!Cyrix::bEsp) return;

	auto cm = CharacterManager::Instance();
	if (!cm) return;

	ActorModel* localPlayer = cm->GetLocalPlayer();
	if (!localPlayer) return;
	auto myPos = localPlayer->GetPosition();

	Camera* mCam = Camera::GetMain();
	if (!mCam) return;

	auto list = engine.Client.World.GetPlayers();
	if (list.empty()) return;


	auto screenHeight = static_cast<float>(Screen::Height());
	auto screenWidth = static_cast<float>(Screen::Width());

	ImGui::PushFont(Fonts::LargeFont);
	std::string nearbyEnemyString = "[" + std::to_string(list.size()) + "] ENEMIES NEARBY";
	auto textSize = ImGui::CalcTextSize(nearbyEnemyString.c_str());
	draw->AddText({ (screenWidth / 2) - (textSize.x / 2), screenHeight - 200 }, ImColor(255, 0, 0), nearbyEnemyString.c_str());
	ImGui::PopFont();

	ImGui::PushFont(Fonts::RegularFont);
	for (ActorModel* p : list) {
		auto enemyPos = p->GetPosition();
		Vector3 enemyScreen;
		Vector3 myScreen;

		if (!mCam->WorldToScreen(enemyScreen, enemyPos) || !mCam->WorldToScreen(myScreen, myPos)) continue;
		if (enemyScreen.z > 0.01f) {
			std::string str = "[" + std::to_string(static_cast<int>(p->Distance(localPlayer->GetPosition()))) + "m]" +
				(p->GetCharacterType() == CharacterType::Robot ? "[AI][Bot]" : "[Player]");
			auto textSize = ImGui::CalcTextSize(str.c_str());
			draw->AddText({ enemyScreen.x - (textSize.x / 2), enemyScreen.y }, ImColor(0, 255, 0), str.c_str());
			draw->AddLine({ myScreen.x, myScreen.y }, { enemyScreen.x, enemyScreen.y }, ImColor(255, 0, 0), 2.0f);
		}
	}
	ImGui::PopFont();
}

void Drawing::Render(ImDrawList* draw)
{
	Drawing::DrawPlayers(draw);
}
