#pragma once
#include "il2cpp_memory.h"

#define IL2TYPE(n) typedef class n{}n;
#define IL2FUNC(r, n, b, ...) typedef r(*n)(__VA_ARGS__); inline n b;
#define IL2FUNCT(r, n, b) typedef r(*n)(); inline n b;
#define DO_EXPORT(t, c, e) IL2CPP_API::t = reinterpret_cast<IL2CPP_API::c>(IL2CPP_MEMORY.GetExport(e));

namespace IL2CPP_API {
	IL2TYPE(Il2CppDomain);
	IL2TYPE(Il2CppAssembly);
	IL2TYPE(Il2CppImage);
	IL2TYPE(Il2CppClass);
	IL2TYPE(Il2CppMethod);
	IL2TYPE(Il2CppField);
	IL2TYPE(Il2CppString);
	IL2TYPE(Il2CppObject);
	IL2TYPE(Il2CppType);

	IL2FUNCT(Il2CppDomain*, t_domain_get, domain_get);
	IL2FUNC(void, t_thread_attach, thread_attach, Il2CppDomain*);
	IL2FUNC(Il2CppAssembly*, t_domain_assembly_open, domain_assembly_open, Il2CppDomain*, const char*);
	IL2FUNC(Il2CppImage*, t_assembly_get_image, assembly_get_image, Il2CppAssembly*);
	IL2FUNC(Il2CppClass*, t_class_from_name, class_from_name, Il2CppImage*, const char*, const char*);
	IL2FUNC(Il2CppMethod*, t_class_get_method_from_name, class_get_method_from_name, Il2CppClass*, const char*, int);
	IL2FUNC(void*, t_compile_method, compile_method, Il2CppMethod*);
	IL2FUNC(Il2CppField*, t_class_get_field_from_name, class_get_field_from_name, Il2CppClass*, const char*);
	IL2FUNC(void*, t_field_get_value, field_get_value, Il2CppObject*, Il2CppField*, void*);
	IL2FUNC(void*, t_field_set_value, field_set_value, Il2CppObject*, Il2CppField*, void*);
	IL2FUNC(void*, t_field_static_get_value, field_static_get_value, Il2CppField*, void*);
	IL2FUNC(void*, t_field_static_set_value, field_static_set_value, Il2CppField*, void*);
	IL2FUNC(Il2CppClass*, t_object_get_class, object_get_class, Il2CppObject*);
	IL2FUNC(Il2CppType*, t_class_get_type, class_get_type, Il2CppClass*);
	IL2FUNC(Il2CppObject*, t_type_get_object, type_get_object, Il2CppType*);
	IL2FUNC(size_t, t_string_length, string_length, Il2CppString*);
	IL2FUNC(wchar_t*, t_string_chars, string_chars, Il2CppString*);
	IL2FUNC(Il2CppMethod*, t_class_get_methods, class_get_methods, Il2CppClass*, void**);
	IL2FUNC(const char*, t_method_get_name, method_get_name,Il2CppMethod*);
	IL2FUNC(const char*, t_class_get_name, class_get_name, Il2CppClass*);
	IL2FUNC(const char*, t_field_get_name, field_get_name, Il2CppField*);
	IL2FUNC(Il2CppString*, t_string_new, string_new, const char*);
	IL2FUNC(Il2CppObject*, t_object_unbox, object_unbox, Il2CppObject*)
	IL2FUNC(Il2CppObject*, t_runtime_invoke, runtime_invoke, Il2CppMethod*, Il2CppObject*, void**, void**)
}
