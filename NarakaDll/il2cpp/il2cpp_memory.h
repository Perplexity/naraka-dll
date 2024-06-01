#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <TlHelp32.h>
#include <Psapi.h>
#include "../kiero/minhook/include/MinHook.h"
#include <unordered_map>

const std::unordered_map<std::wstring, uintptr_t> offsetTable = {
{L"il2cpp_domain_get", 0x191940},
{L"il2cpp_resolve_icall", 0x192d00},
{L"il2cpp_string_chars", 0x193180},
{L"il2cpp_string_length", 0x1931b0},
{L"il2cpp_domain_get_assemblies", 0x191950},
{L"il2cpp_class_from_name", 0x1915c0},
{L"il2cpp_class_get_method_from_name", 0x1916a0},
{L"il2cpp_method_is_instance", 0x192b70},
{L"il2cpp_method_is_inflated", 0x192b60},
{L"il2cpp_runtime_class_init", 0x192d10},
{L"il2cpp_class_get_field_from_name", 0x191660},
{L"il2cpp_field_get_flags", 0x191990},
{L"il2cpp_field_static_get_value", 0x191a20},
{L"il2cpp_field_get_type", 0x1919b0},
{L"il2cpp_type_get_type", 0x193400},
{L"il2cpp_class_get_type", 0x1532c0},
{L"il2cpp_array_class_get", 0x1c9410},
{L"il2cpp_class_get_interfaces", 0x1cd580},
{L"il2cpp_class_get_name", 0x1916c0},
{L"il2cpp_object_get_class", 0x191550},
{L"il2cpp_field_get_offset", 0x1919a0},
{L"il2cpp_method_get_return_type", 0x192b20},
{L"il2cpp_type_get_name", 0x193340},
{L"il2cpp_method_get_param_count", 0x192b00},
{L"il2cpp_class_from_type", 0x1915b0},
{L"il2cpp_method_get_param_name", 0x192b10},
{L"il2cpp_class_is_valuetype", 0x1d9330},
{L"il2cpp_class_is_enum", 0x1917d0},
{L"il2cpp_method_get_class", 0x1916d0},
{L"il2cpp_method_get_param", 0x192af0},
{L"il2cpp_array_length", 0x1021e0},
{L"il2cpp_string_new", 0x1931c0},
{L"il2cpp_class_enum_basetype", 0x191590},
{L"il2cpp_class_array_element_size", 0x191580},
{L"il2cpp_class_get_parent", 0x1916f0},
{L"il2cpp_class_get_assemblyname", 0x1915e0},
{L"il2cpp_class_is_interface", 0x191800},
{L"il2cpp_class_get_fields", 0x191670},
{L"il2cpp_class_get_methods", 0x1916b0},
{L"il2cpp_field_get_name", 0x191550},
{L"il2cpp_method_get_name", 0x1916c0},
{L"il2cpp_domain_assembly_open", 0x191930},
{L"il2cpp_class_value_size", 0x191850},
{L"il2cpp_class_instance_size", 0x191790},
{L"il2cpp_object_new", 0x192c10},
{L"il2cpp_thread_attach", 0x1931f0},
{L"il2cpp_thread_detach", 0x193210},
{L"il2cpp_assembly_get_image", 0x191550},
{L"il2cpp_field_get_value", 0x1919c0},
{L"il2cpp_field_set_value", 0x191a00},
{L"il2cpp_field_static_set_value", 0x191a30},
{L"il2cpp_type_get_object", 0x1d2ba0},
{L"il2cpp_object_unbox", 0x192c30},
{L"il2cpp_runtime_invoke", 0x192d20},
};

class Il2CppMemory {
public:
	MODULEENTRY32W GetModule(const wchar_t* modName) {
		uintptr_t modBaseAddr = 0;
		HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, GetCurrentProcessId());
		if (hSnap != INVALID_HANDLE_VALUE)
		{
			MODULEENTRY32W modEntry;
			modEntry.dwSize = sizeof(modEntry);
			if (Module32FirstW(hSnap, &modEntry))
			{
				do
				{
					if (!_wcsicmp(modEntry.szModule, modName))
					{
						return modEntry;
					}
				} while (Module32NextW(hSnap, &modEntry));
			}
		}
		CloseHandle(hSnap);
		return MODULEENTRY32W();
	}
	uintptr_t GetExport(const wchar_t* wAPIName) {
		auto it = offsetTable.find(wAPIName);
		if (it != offsetTable.end()) {
			return reinterpret_cast<uintptr_t>(this->GameAssembly.modBaseAddr) + it->second;
		}
		return 0;
	}

	MODULEENTRY32W GetModuleEntry() {
		return this->GameAssembly;
	}
	void Initialize() {
		this->GameAssembly = this->GetModule(L"GameAssembly.dll");
	}
private:
	bool isEqual(char* names, const wchar_t* API) {
		std::wstring wc(API);
		std::string tmp(names);
		std::wstring wc2(tmp.begin(), tmp.end());

		return wc.compare(wc2) == 0;
	}
	MODULEENTRY32W GameAssembly;
}inline IL2CPP_MEMORY;