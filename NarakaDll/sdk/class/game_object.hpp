#pragma once

class GameObject : public UObject {
public:
	template <class T>
	Array<T>* GetComponentsInternal(Type* type) {
		return Method::Call<Array<T>*(*)(GameObject*, Object*, bool, bool, bool, bool, Object*)>("UnityEngine.CoreModule", "UnityEngine", "GameObject", "GetComponentsInternal", 6)(this, type->GetTypeObject(), false, true, false, false, nullptr);
	}
	template <class T>
	T GetComponent(Type* type) {
		return Method::Call<T(*)(GameObject*, Object*)>("UnityEngine.CoreModule", "UnityEngine", "GameObject", "GetComponent", 1)(this, type->GetTypeObject());
	}
	String* GetTag() {
		return Method::Call<String * (*)(GameObject*)>("UnityEngine.CoreModule", "UnityEngine", "GameObject", "get_tag", 0)(this);
	}
	int GetLayer() {
		return Method::Call<int(*)(GameObject*)>("UnityEngine.CoreModule", "UnityEngine", "GameObject", "get_layer", 0)(this);
	}
};