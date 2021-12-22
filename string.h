#ifndef FLAT_INCLUDES
#include <stddef.h>
#define FLAT_INCLUDES
#include "../range/def.h"
#include "def.h"
#endif

void window_strcat (window_char * dest, const char * str);
void window_strcpy (window_char * dest, const char * str);
void window_strcat_range (window_char * dest, const range_const_char * src);
void window_strcpy_range (window_char * dest, const range_const_char * src);
