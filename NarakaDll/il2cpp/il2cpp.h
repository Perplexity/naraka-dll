#pragma once
#include "il2cpp_resolver.h"

namespace IL2CPP {
	inline Il2CppDomain* Domain = nullptr;

	class Class;
	class Method;
	class Object;
	class Field;
	class Type;

	class Assembly : public Il2CppAssembly {
	public:
		static Assembly* Resolve(const char* Assembly);
		Il2CppImage* GetImage();
	};
	class Class : public Il2CppClass {
	public:
		static Class* Resolve(const char* Asm, const char* Namespace, const char* Klass);
		Method* GetMethod(const char* Name, int pCount);
		Field* GetField(const char* Name);
		Type* GetType();
		const char* GetName();
	};

	class Method : public Il2CppMethod {
	private:
		void* MethodAddress;
	public:
		static Method* Resolve(const char* Asm, const char* Namespace, const char* Klass, const char* Name, int pCount);

		void* GetAddress();
		const char* GetName();
		void Hook(void* vHk, void* vOrg);

		template <class T>
		T InternalCall() {
			return reinterpret_cast<T>(this->GetAddress());
		}

		template <class T>
		static T Call(const char* Asm, const char* Namespace, const char* Klass, const char* Name, int pCount) {
			return reinterpret_cast<T>(Method::Resolve(Asm, Namespace, Klass, Name, pCount)->GetAddress());
		}

		template<class T, class... P>
		static T CallVT(const char* Asm, const char* Namespace, const char* Klass, const char* Name, int pCount, Object* object, P... params) {
			void* args[] = { &params... };
			return *reinterpret_cast<T*>(object_unbox(runtime_invoke(Method::Resolve(Asm, Namespace, Klass, Name, pCount), object, args, nullptr)));
		}
	};
	class Field :public Il2CppField {
	public:
		const char* GetName();
		template <class T>
		T GetValue(Object* obj) {
			T val;
			field_get_value(obj, this, &val);
			return val;
		}
		template <class T>
		void SetValue(Object* obj, T val) {
			field_set_value(obj, this, &val);
		}
		template <class T>
		T GetStaticValue() {
			T val;
			field_static_get_value(this, &val);
			return val;
		}
		template <class T>
		void SetStaticValue(T val) {
			field_static_set_value(this, &val);
		}
	};
	class Object :public Il2CppObject {
	public:
		Class* GetClass();
		Field* GetField(const char* Name);
	};
	class Type : public Il2CppType {
	public:
		static Type* Resolve(const char* Asm, const char* Namespace, const char* Klass);
		Class* GetClass();
		Object* GetTypeObject();
	};
	class String : public Il2CppString {
	public:
		static String* New(const char* Text);
		size_t GetLength();
		const wchar_t* GetChars();
		std::string GetString();
	};
	template <class T>
	struct Array : public Object {
	public:
		T GetValue(int index) {
			return Method::Call<T(*)(Array<T>*, int)>("mscorlib", "System", "Array", "GetValue", 1)(this, index);
		}
		T GetValueVT(int index) {
			return *Method::CallVT<T*>("mscorlib", "System", "Array", "GetValue", 1, this, index);
		}
		int GetLength() {
			return Method::Call<int(*)(Array<T>*)>("mscorlib", "System", "Array", "get_Length", 0)(this);
		}
		int GetLowerBound(int bound) {
			return Method::Call<int(*)(Array<T>*, int)>("mscorlib", "System", "Array", "GetLowerBound", 1)(this, bound);
		}
		bool isEmpty() {
			return this->GetLength() == 0;
		}
	};

	inline void Attach() {
		Domain = domain_get();
		thread_attach(Domain);
	}

	inline void Initialize() {
		IL2CPP_MEMORY.Initialize();
		IL2CPP_RESOLVER::Initialize();

		MH_Initialize();

		Attach();
	}
}

using namespace IL2CPP;