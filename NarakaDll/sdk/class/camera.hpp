#pragma once

class Camera : public UObject {
public:
	static Camera* GetMain() {
		return Method::Call<Camera * (*)()>("UnityEngine.CoreModule", "UnityEngine", "Camera", "get_main", 0)();
	}
	static Camera* GetCurrent() {
		return Method::Call<Camera * (*)()>("UnityEngine.CoreModule", "UnityEngine", "Camera", "get_current", 0)();
	}
	static Array<Camera*>* GetAllCameras() {
		return Method::Call<Array<Camera*>*(*)()>("UnityEngine.CoreModule", "UnityEngine", "Camera", "get_allCameras", 0)();
	}
	static Camera* GetCamera() {
		auto arr = GetAllCameras();
		if (!arr) return nullptr;

		return arr->GetValue(1);
	}
	static void IterateCameras() {
		auto arr = Camera::GetAllCameras();
		if (!arr) return;

		for (uint8_t i = 0; i < arr->GetLength(); i++) {
			auto cam = arr->GetValue(i);
			if (!cam) continue;
			std::cout << "Valid Camera at -> " << unsigned int(i) << "\n";
		}
	}
	bool WorldToScreen(Vector3& screen, Vector3 world) {
		Vector3 ret = Method::Call<Vector3(*)(Camera*, Vector3*)>("UnityEngine.CoreModule", "UnityEngine", "Camera", "WorldToScreenPoint", 1)(this, &world);

		screen.x = ret.x;
		screen.y = Screen::Height() - ret.y;
		screen.z = ret.z;

		return true;
	}
};