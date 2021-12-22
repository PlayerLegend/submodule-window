#include <stddef.h>
#define FLAT_INCLUDES
#include "../range/def.h"
#include "def.h"
#include "path.h"
#include "string.h"
#include "alloc.h"

void window_path_cat (window_char * target, char sep, const range_const_char * append)
{
    if (!range_is_empty (target->region) && target->region.end[-1] == sep)
    {
	*window_push (*target) = sep;
    }

    window_strcat_range (target, append);
}
