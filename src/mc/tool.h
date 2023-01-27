#pragma once
#pragma execution_character_set("utf-8")
#pragma warning(disable:4996)
#pragma warning(disable:4819)
#pragma comment(lib,"../lib/LiteLoader.lib")
#include <iostream>
#include "Level.h"
#include "NetWork.h"

//#define Dereference<type>( ptr) (*reinterpret_cast<type*>(ptr))
template <typename T>
inline T& Dereference(void* ptr, uintptr_t offset) {
	return *reinterpret_cast<T*>(uintptr_t(ptr) + offset);
}
template <typename T>
inline T& Dereference(uintptr_t ptr, uintptr_t offset) {
	return *reinterpret_cast<T*>(uintptr_t(ptr) + offset);
}
template <typename T>
inline T& Dereference(void* ptr) {
	return *reinterpret_cast<T*>(ptr);
}
template <typename T>
inline T& Dereference(uintptr_t ptr) {
	return *reinterpret_cast<T*>(ptr);
}
#define SYM dlsym_real
#define THOOK(name, ret, sym, ...)		\
struct name {							\
	using func = ret(__VA_ARGS__);		\
	static func _hook;					\
	inline static func* original;		\
	inline static HookRegister _reg =	\
		{ sym,&original,&_hook };	\
};										\
ret name::_hook(__VA_ARGS__)

extern "C" {
	// provide Detours API
	_declspec(dllimport) int HookFunction(void* orifunc, void* orifuncptr, void* newfunc);
	// get address from symbol string
	_declspec(dllimport) void* dlsym_real(const char* symbol);
}
// call a virtual function
// _this: this ptr, off: offsetof function
template<typename ReturnType = void, typename... Args>
inline ReturnType VirtualCall(uintptr_t off, void* _this, Args... args) {
	return (*reinterpret_cast<ReturnType(**)(void*, Args...)>(Dereference<uintptr_t>( _this) + off))(_this, args...);
}
// call a function by symbol string
template<typename ReturnType = void, typename... Args>
inline ReturnType SymCall(const char* sym, Args... args) {
	static auto func = SYM(sym);
	if (func == nullptr) {
		std::cerr << "SymbolNotFound: " << sym << std::endl;
	}
	return reinterpret_cast<ReturnType(*)(Args...)>(func)(std::forward<Args>(args)...);
}
// replace the function
struct HookRegister {
	HookRegister(const char* sym, void* org, void* hook) {
		void* func = SYM(sym);
		if (func == nullptr) {
			std::cerr << "FailedToHook: " << sym << std::endl;
			return;
		}
		auto ret = HookFunction(func, org, hook);
		if (ret != 0) {
			std::cerr << "FailedToHook: " << func << std::endl;
			return;
		}
	}
};
//È«¾Ö±äÁ¿
template <typename T>
inline T* global = nullptr;

