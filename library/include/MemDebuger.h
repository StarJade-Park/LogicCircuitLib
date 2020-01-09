#pragma once

#include <crtdbg.h>

#ifdef NDEBUG

#define DEBUG_BUILD_MEMORY_START
#define DEBUG_BUILD_MEM_LEAK_CHECK(LeakLineNumber) ((void)LeakLineNumber)

#else // _DEBUG

#define DEBUG_BUILD_MEMORY_START _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#define DEBUG_BUILD_MEM_LEAK_CHECK(LeakLineNumber) _CrtSetBreakAlloc(LeakLineNumber);

#endif // NDEBUG
