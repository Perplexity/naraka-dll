#include "menu.h"

namespace Menu {
	bool bMenuOpened = true;
	void Menu::Draw() {
		ImGui::SetNextWindowSize({ 685,350 });
		ImGui::Begin("Naraka", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
		static BYTE tab = 0;

		if (ImGui::Button("Visuals", ImVec2(125, 25))) tab = VISUALS;
		ImGui::SameLine();/*
		if (ImGui::Button("Movement", ImVec2(125, 25))) tab = MOVEMENT;
		ImGui::SameLine();
		if (ImGui::Button("Weapon", ImVec2(125, 25))) tab = WEAPON;
		ImGui::SameLine();
		if (ImGui::Button("Exploits", ImVec2(125, 25))) tab = EXPLOITS;*/

		switch (tab) {
		case VISUALS:
			ImGui::Checkbox("Player Esp", &Cyrix::bEsp);
			break;
		//case MOVEMENT:
		//	break;
		//case WEAPON:
		//	break;
		//case EXPLOITS:
		//	Exploits();
		//	break;
		}

		ImGui::End();
	}
	void Exploits()
	{
		/*if (ImGui::Checkbox("Can Vent", &Cyrix::bCanVent)) { engine.Client.LocalPlayer.SetCanVent(Cyrix::bCanVent); }
		if (ImGui::InputText("Set Name", Cyrix::sNameBuffer, 255, ImGuiInputTextFlags_EnterReturnsTrue)) { engine.Client.LocalPlayer.SetName(Cyrix::sNameBuffer); }
		if (ImGui::InputText("Send To Chat", Cyrix::sChatBuffer, 255, ImGuiInputTextFlags_EnterReturnsTrue)) { engine.Client.LocalPlayer.SendToChat(Cyrix::sChatBuffer); }
		if (ImGui::Combo("Set Role", &Cyrix::iRole, "Crewmate\0Imposter\0Scientist\0Engineer\0Guardian Angel\0Shape Shifter\0Crewmate Ghost\0Impostor Ghost\0")) { engine.Client.LocalPlayer.SetRole(static_cast<RoleTypes>(Cyrix::iRole)); }*/
	}
}