#include <stddef.h>
#define FLAT_INCLUDES
#include "../range/def.h"
#include "def.h"
#include "path.h"
#include "string.h"
#include "alloc.h"

void window_path_cat (window_char * result, const range_const_char * a, char sep, const range_const_char * b)
{
    window_rewrite (*result);
    window_strcpy_range (result, a);
    if (!range_is_empty (result->region) && result->region.end[-1] != sep)
    {
	*window_push (*result) = sep;
    }
    window_strcat_range (result, b);
}
