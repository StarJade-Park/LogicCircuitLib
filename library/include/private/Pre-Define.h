#pragma once

#ifndef _WIN64
#error compilation target is not Windows 64-bit ARM or x64
#else

#include <Windows.h>

	#if !defined(_MSVC_LANG)
	#error C++ compiler is not MSVC
	#endif
#endif // !_WIN64

#ifndef C_XX_VERSION
#define C_XX_VERSION _MSVC_LANG
#define C_XX_11_BEFORE 199711L
#define C_XX_11_AFTER  201103L
#define C_XX_14_AFTER  201402L
#define C_XX_17_AFTER  201703L

#if C_XX_VERSION < C_XX_14_AFTER
#error C++ compiler version is low(must after C++14)
#endif

#endif // !C_XX_VERSION

#if defined(_ATL_VER) || defined(_MFC_VER)
#error This library is not support MFC or ATL
#else
	#ifndef WIN32_LEAN_AND_MEAN
	#define WIN32_LEAN_AND_MEAN
	#endif // !WIN32_LEAN_AND_MEAN
#endif

#define POPUP_ASSERT_WINDOW // If you use "popup assertion", enable it.

#define _STR_(s) #s 
#define _STR(s) _STR_(s)

#define _WIDE_STR_(s) L ## s
#define _WIDE_STR(s) _WIDE_STR_(s)

#define MUST_TODO(msg) static_assert(false, msg)

#define FORCE_INLINE    __forceinline
#define FORCE_NO_INLINE __declspec(noinline)

#ifndef FALSE
#define FALSE 0
#endif // !FALSE

#ifndef TRUE
#define TRUE 1
#endif // !TRUE

template<size_t N, class T>
constexpr size_t ARRAY_SIZE(T(&)[N]) { return N; }
