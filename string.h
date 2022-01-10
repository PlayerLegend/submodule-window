#ifndef FLAT_INCLUDES
#include <stddef.h>
#define FLAT_INCLUDES
#include "../range/def.h"
#include "def.h"
#endif

/**
   @file window/string.h
   This file provides functions for working with strings contained in windows
*/

void window_strcat_string (window_char * dest, const char * str);
/**<
   Concatenates a null terminated string to a window
*/

void window_strcpy_string (window_char * dest, const char * str);
/**<
   Copies a null terminated string into a window, overwriting any existing contents in the window
*/

void window_strcat_range (window_char * dest, const range_const_char * src);
/**<
   Similar to window_strcat_string, but the string argument is a range string rather than a null terminated string
*/

void window_strcpy_range (window_char * dest, const range_const_char * src);
/**<
   Similar to window_strcpy_string, but the string argument is a range string rather than a null terminated string
*/
