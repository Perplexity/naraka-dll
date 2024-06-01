#pragma once
#include "il2cpp_types.h"

#define DO_EXPORT(t, c, e) t = reinterpret_cast<c>(IL2CPP_MEMORY.GetExport(e));

using namespace IL2CPP_API;

namespace IL2CPP_RESOLVER {
	inline void Initialize() {
		DO_EXPORT(domain_get, t_domain_get, L"il2cpp_domain_get");
		DO_EXPORT(thread_attach, t_thread_attach, L"il2cpp_thread_attach");
		DO_EXPORT(domain_assembly_open, t_domain_assembly_open, L"il2cpp_domain_assembly_open");
		DO_EXPORT(assembly_get_image, t_assembly_get_image, L"il2cpp_assembly_get_image");
		DO_EXPORT(class_from_name, t_class_from_name, L"il2cpp_class_from_name");
		DO_EXPORT(class_get_method_from_name, t_class_get_method_from_name, L"il2cpp_class_get_method_from_name");
		DO_EXPORT(compile_method, t_compile_method, L"il2cpp_compile_method");
		DO_EXPORT(class_get_field_from_name, t_class_get_field_from_name, L"il2cpp_class_get_field_from_name");
		DO_EXPORT(field_get_value, t_field_get_value, L"il2cpp_field_get_value");
		DO_EXPORT(field_set_value, t_field_set_value, L"il2cpp_field_set_value");
		DO_EXPORT(field_static_get_value, t_field_static_get_value, L"il2cpp_field_static_get_value");
		DO_EXPORT(field_static_set_value, t_field_static_set_value, L"il2cpp_field_static_set_value");
		DO_EXPORT(class_get_type, t_class_get_type, L"il2cpp_class_get_type");
		DO_EXPORT(type_get_object, t_type_get_object, L"il2cpp_type_get_object");
		DO_EXPORT(string_length, t_string_length, L"il2cpp_string_length");
		DO_EXPORT(string_chars, t_string_chars, L"il2cpp_string_chars");
		DO_EXPORT(class_get_methods, t_class_get_methods, L"il2cpp_class_get_methods");
		DO_EXPORT(method_get_name, t_method_get_name, L"il2cpp_method_get_name");
		DO_EXPORT(class_get_name, t_class_get_name, L"il2cpp_class_get_name");
		DO_EXPORT(field_get_name, t_field_get_name, L"il2cpp_field_get_name");
		DO_EXPORT(object_get_class, t_object_get_class, L"il2cpp_object_get_class");
		DO_EXPORT(string_new, t_string_new, L"il2cpp_string_new");
		DO_EXPORT(object_unbox, t_object_unbox, L"il2cpp_object_unbox");
		DO_EXPORT(runtime_invoke, t_runtime_invoke, L"il2cpp_runtime_invoke");
	}
}