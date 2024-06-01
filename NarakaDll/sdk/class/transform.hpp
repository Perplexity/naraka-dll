#pragma once

class Transform : public UObject {
public:
	int ChildCount() {
		return Method::Call<int(*)(Transform*)>("UnityEngine.CoreModule", "UnityEngine", "Transform", "get_childCount", 0)(this);
	}
	Vector3 GetPosition() {
		return Method::Call<Vector3(*)(Transform*)>("UnityEngine.CoreModule", "UnityEngine", "Transform", "get_position", 0)(this);
	}
	Vector3 GetForward() {
		return Method::Call<Vector3(*)(Transform*)>("UnityEngine.CoreModule", "UnityEngine", "Transform", "get_forward", 0)(this);
	}
	void LookAt(Vector3 pos) {
		return Method::Call<void(*)(Transform*, Vector3, Vector3)>("UnityEngine.CoreModule", "UnityEngine", "Transform", "Internal_LookAt", 2)(this, pos, Vector3::GetUp());
	}
	void SetRotation(Quaternion rot) {
		return Method::Call<void(*)(Transform*, Quaternion)>("UnityEngine.CoreModule", "UnityEngine", "Transform", "set_rotation", 1)(this, rot);
	}
};
