#include "dx/hook/present.h"
#include "cyrix/drawing/fonts.h"

HMODULE g_hModule;

DWORD WINAPI MainThread(LPVOID lpReserved)
{
	AllocConsole();
	FILE* file;
	freopen_s(&file, "CONOUT$", "w", stdout);

	IL2CPP::Initialize();
	Hooks::Initialize();

	/*bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)&Present::oPresent, Present::hkPresent);
			init_hook = true;
		}
	} while (!init_hook);

	Fonts::LoadFonts();*/

	while (true) {
		if (GetAsyncKeyState(VK_F1) & 1) {
			auto em = EntityManager::Instance();
			if (em) {
				std::cout << "EM: " << em << std::endl;
				auto entities = em->GetEntities();
				if (em) {
					std::cout << "Entities: " << entities << std::endl;
					std::cout << "Count: " << entities->Count() << std::endl;
					auto slots = entities->GetSlots();
					if (slots) {
						std::cout << "Slots: " << slots << std::endl;
						std::cout << "Length: " << slots->GetLength() << std::endl;
						for (size_t i = 0; i < slots->GetLength(); i++)
						{
							auto slot = slots->GetValueVT(i);
							auto val = slot.value;
							/*if (val) {
								std::cout << "GOOD!\n";
							}*/
						}
						/*auto buckets = entities->GetBuckets();
						if (buckets) {
							std::cout << "Buckets: " << buckets << std::endl;
							std::cout << "Length: " << buckets->GetLength() << std::endl;
						}*/
					}
				}
			}
		}
		if (GetAsyncKeyState(VK_INSERT) & 1)
			Menu::bMenuOpened = !Menu::bMenuOpened;
		if (GetAsyncKeyState(VK_DELETE) & 1) {
			kiero::shutdown();
			if (file) {
				fclose(file);
				file = nullptr;
			}
			FreeConsole();
			FreeLibraryAndExitThread(g_hModule, EXIT_SUCCESS);
		}
		Sleep(10);
	}

	return TRUE;
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		g_hModule = hMod;
		DisableThreadLibraryCalls(hMod);
		CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
		break;
	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}
	return TRUE;
}