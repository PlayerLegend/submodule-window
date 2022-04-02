#include <stddef.h>
#include <assert.h>
#include <stdbool.h>
#define FLAT_INCLUDES
#include "../range/def.h"
#include "../range/string.h"
#include "def.h"
#include "path.h"
#include "string.h"
#include "alloc.h"
#include "../log/log.h"
#include <stdlib.h>

void window_path_cat (window_char * target, char sep, const range_const_char * append)
{
    while (!range_is_empty (target->region) && target->region.end[-1] == sep)
    {
	target->region.end--;
    }
    
    range_const_char append_mod = *append;

    while (!range_is_empty (append_mod) && *append_mod.begin == sep)
    {
	append_mod.begin++;
    }

    *window_push (*target) = sep;

    window_strcat_range (target, &append_mod);

}

void window_path_resolve (window_char * target, char sep)
{
    if (range_is_empty (target->region))
    {
	return;
    }

    bool is_absolute_path = *target->region.begin == sep;
    
    range_char copy;

    range_strdup (&copy, &target->region.const_cast);

    char * copy_free = copy.begin;
    
    range_const_char token;

    range_typedef (range_const_char, token);
    window_typedef (range_const_char, token);

    window_token path = {0};

    while (range_string_tokenize(&token, sep, &copy.const_cast))
    {
	if (range_is_empty (token) || range_streq_string (&token, "."))
	{
	    continue;
	}

	if (!range_is_empty (path.region) && !range_streq_string(path.region.begin, "..") && range_streq_string(&token, ".."))
	{
	    path.region.end--;
	}
	else
	{
	    *window_push(path) = token;
	}
    }

    window_rewrite (*target);
    
    range_const_char * add_token;
    
    for_range (add_token, path.region)
    {
	*window_push (*target) = sep;
	window_strcat_range (target, add_token);
    }

    if (!is_absolute_path)
    {
	target->region.begin++;
    }

    assert (is_absolute_path == (*target->region.begin == sep));

    window_clear(path);
    free(copy_free);
}
