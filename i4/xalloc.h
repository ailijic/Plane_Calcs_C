#pragma once

#include "type.h"

#define xsizeof(m) ((IntPtr)sizeof(m))

void* xmalloc(IntPtr a_num_bytes);
void  xfree(void* a_ptr);
void* xcalloc(IntPtr a_nmemb, IntPtr a_size);
void* xrealloc(void* a_ptr, IntPtr a_size);
void* xreallocarray(void* a_ptr, IntPtr a_nmemb, IntPtr a_size);