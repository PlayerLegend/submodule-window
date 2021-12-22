#include <stddef.h>
#include <string.h>
#include <assert.h>
#define FLAT_INCLUDES
#include "../range/def.h"
#include "def.h"
#include "alloc.h"
#include "string.h"

inline static void add_terminator (window_char * dest)
{
    *window_push (*dest) = '\0';
    dest->region.end--;
}

void window_strcat (window_char * dest, const char * str)
{
    window_append_bytes ( (window_unsigned_char*) dest, (const unsigned char*)str, strlen (str));
    add_terminator (dest);
}

void window_strcpy (window_char * dest, const char * str)
{
    window_rewrite (*dest);
    window_strcat (dest, str);
}

void window_strcat_range (window_char * dest, const range_const_char * src)
{
    window_append_bytes ( (window_unsigned_char*) dest, (const unsigned char*) src->begin, range_count (*src));
    add_terminator (dest);
}

void window_strcpy_range (window_char * dest, const range_const_char * src)
{
    window_rewrite (*dest);
    window_strcat_range (dest, src);
}
