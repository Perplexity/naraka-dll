#pragma once
#include <corecrt_math.h>

struct Color {
	float r, g, b, a;
	void ToRGB() {
		this->r *= 255; this->g *= 255; this->b *= 255;
	}
};

struct Vector2 {
	float x, y;

	float Distance(Vector2 to) {
		float val = ((this->x - to.x) * (this->x - to.x) + ((this->y - to.y) * (this->y - to.y)));

		return sqrt(val);
	}

	Vector2 operator+(Vector2 b) { return Vector2(x + b.x, y + b.y); }
	Vector2 operator-(Vector2 b) { return Vector2(x - b.x, y - b.y); }
	Vector2 operator-() { return Vector2(-x, -y); }
	Vector2 operator*(float d) { return Vector2(x * d, y * d); }
	Vector2 operator/(float d) { return Vector2(x / d, y / d); }

	operator bool() { return bool(this->x || this->y); }
	friend bool operator	==(const Vector2& a, const Vector2& b) { return a.x == b.x && a.y == b.y; }
	friend bool operator	!=(const Vector2& a, const Vector2& b) { return !(a == b); }
};

struct Vector3 {
	float x, y, z;

	Vector3(float _x, float _y, float _z) {
		x = _x;
		y = _y;
		z = _z;
	};

	Vector3() = default;

	void Scale(Vector3 scale) {
		return Method::Call<void(*)(Vector3*, Vector3)>("UnityEngine.CoreModule", "UnityEngine", "Vector3", "Scale", 1)(this, scale);
	}
	static Vector3 Cross(Vector3 lhs, Vector3 rhs) {
		return Method::Call<Vector3(*)(Vector3, Vector3)>("UnityEngine.CoreModule", "UnityEngine", "Vector3", "Scale", 2)(lhs, rhs);
	}
	static Vector3 GetUp() {
		return Method::Call<Vector3(*)()>("UnityEngine.CoreModule", "UnityEngine", "Vector3", "get_up", 0)();
	}

	static Vector3 Empty() {
		return { 0,0,0 };
	}

	bool isEmpty() {
		return this->x == 0 && this->y == 0 && this->z == 0;
	}

	float Distance(Vector3 to) {
		return sqrt(((to.x - this->x) * (to.x - this->x)) + ((to.y - this->y) * (to.y - this->y)) + ((to.z - this->z) * (to.z - this->z)));
	}

	Vector3 operator+(Vector3 b) { return Vector3(x + b.x, y + b.y, z + b.z); }
	Vector3 operator-(Vector3 b) { return Vector3(x - b.x, y - b.y, z - b.z); }
	Vector3 operator-() { return Vector3(-x, -y, -z); }
	Vector3 operator*(float d) { return Vector3(x * d, y * d, z * d); }
	Vector3 operator/(float d) { return Vector3(x / d, y / d, z / d); }

	Vector3 operator+=(Vector3 b) { return Vector3(x += b.x, y += b.y, z += b.z); }
	Vector3 operator-=(Vector3 b) { return Vector3(x -= b.x, y -= b.y, z -= b.z); }
	float& operator[](const int& index) { switch (index) { case 0: return x; case 1: return y; case 2: return z; } }
																 operator bool() { return bool(this->x || this->y || this->z); }
																 friend bool operator	== (const Vector3& a, const Vector3& b) { return a.x == b.x && a.y == b.y && a.z == b.z; }
																 friend bool operator	!= (const Vector3& a, const Vector3& b) { return !(a == b); }
};

struct Quaternion {
	float x, y, z, w;
	static Quaternion LookRotation(Vector3 Direction) {
		return Method::Call<Quaternion(*)(Vector3)>("UnityEngine.CoreModule", "UnityEngine", "Quaternion", "LookRotation", 1)(Direction);
	}
};