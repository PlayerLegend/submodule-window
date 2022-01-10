#ifndef FLAT_INCLUDES
#include <stddef.h>
#include <stdarg.h>
#define FLAT_INCLUDES
#include "../range/def.h"
#include "def.h"
#endif

/**
   @file window/vprintf.h
   This file provides vprintf-like functions that write to windows.
*/

long int window_vprintf(window_char * window, const char * format, va_list ap);
/**<
   @brief A vprintf-like function that overwrites the contents of the given window.
*/

long int window_vprintf_append(window_char * window, const char * format, va_list ap);
/**<
   @brief A vprintf-like function that appends its result to the given window.
*/
