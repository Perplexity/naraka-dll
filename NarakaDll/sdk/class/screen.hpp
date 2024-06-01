#pragma once

struct Resolution {
	int Width, Height;
};

class Screen : public Object {
public:

	static int Width() {
		return Method::Call<int (*)()>("UnityEngine.CoreModule", "UnityEngine", "Screen", "get_width", 0)();
	}

	static int Height() {
		return Method::Call<int (*)()>("UnityEngine.CoreModule", "UnityEngine", "Screen", "get_height", 0)();
	}

	static Resolution GetResolution() {
		return Resolution(Width(), Height());
	}

};