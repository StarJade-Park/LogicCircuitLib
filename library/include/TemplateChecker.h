/**
* Check what type T is.
*/

#pragma once

#include "private/Pre-Define.h"

// Pointer
template <typename T> struct TIsPointer                     { enum { Value = false }; };
template <typename T> struct TIsPointer<                T*> { enum { Value = true }; };
template <typename T> struct TIsPointer< const          T > { enum { Value = TIsPointer<T>::Value }; };
template <typename T> struct TIsPointer<       volatile T > { enum { Value = TIsPointer<T>::Value }; };
template <typename T> struct TIsPointer< const volatile T > { enum { Value = TIsPointer<T>::Value }; };

// Enum
template <typename T>
struct TIsEnum { enum { Value = __is_enum(T) }; };

template <typename T>
struct TIsUnion { enum { Value = __is_union(T) }; };

// Const
template <typename T>
struct TIsConst { static constexpr bool Value = false; };

template <typename T>
struct TIsConst<const T> { static constexpr bool Value = true; };

// Class & struct
template <typename T>
struct TIsClass { enum { Value = __is_class(T) }; };

// No member variable in class/struct
template <typename T>
struct TIsNotHaveMember { enum { Value = __is_empty(T) }; };

// Abstract class, struct
template <typename T>
struct TIsAbstract { enum { Value = __is_abstract(T) }; };

// POD
template <typename T>
struct TIsPOD { enum { Value = __is_pod(T) }; };
