#ifndef FLAT_INCLUDES
#include <stddef.h>
#define FLAT_INCLUDES
#include "../range/def.h"
#include "def.h"
#endif

/**
   @file window/printf.h
   This file provides printf-like functions that write to windows.
*/

long int window_printf(window_char * window, const char * str, ...);
/**<
   @brief A printf-like function that overwrites the contents of the given window.
*/

long int window_printf_append(window_char * window, const char * str, ...);
/**<
   @brief A printf-like function that appends its result to the given window.
*/
