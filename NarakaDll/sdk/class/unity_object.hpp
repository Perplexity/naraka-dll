#pragma once

struct IntPtr {
	void* m_value;
};

class UObject : public Object {
public:
	IntPtr GetCachedPtr() {
		return Method::Call<IntPtr(*)(UObject*)>("UnityEngine.CoreModule", "UnityEngine", "Object", "GetCachedPtr", 0)(this);
	}
	template <class T>
	static Array<T>* FindObjectsOfType(Object* type, bool includeInactive = false) {
		return Method::Call<Array<T>*(*)(Object*, bool)>("UnityEngine.CoreModule", "UnityEngine", "Object", "FindObjectsOfType", 2)(type, includeInactive);
	}
};