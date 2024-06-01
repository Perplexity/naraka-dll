#pragma once

struct Rect {
	Rect(float x, float y, float z, float w) {
		this->m_XMin = x; this->m_YMin = y; this->m_Width = z; this->m_Height = w;
	}
	float m_XMin, m_YMin, m_Width, m_Height;
};

class GUIStyle : public Object {
public:
	static GUIStyle* GetDefault() {
		return Class::Resolve("UnityEngine.IMGUIModule", "UnityEngine", "GUIStyle")->GetField("s_None")->GetStaticValue<GUIStyle*>();
	}
};

class GUI : public Object {
public:
	static void Label(Rect rect, const char* Text) {
		return Method::Call<void(*)(Rect, String*, GUIStyle*)>("UnityEngine.IMGUIModule", "UnityEngine", "GUI", "Label", 3)(rect, String::New(Text), GUIStyle::GetDefault());
	}
};
