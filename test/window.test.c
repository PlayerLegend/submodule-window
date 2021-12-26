#include <stddef.h>
#include <assert.h>
#include <stdbool.h>
#define FLAT_INCLUDES
#include "../../range/def.h"
#include "../../range/string.h"
#include "../def.h"
#include "../alloc.h"
#include "../string.h"
#include "../path.h"

#include "../../log/log.h"

range_typedef(int, int);
window_typedef(int, int);

void test_push ()
{
    window_int window = {0};

    int test_size = 100;
    
    window_alloc(window, test_size);

    for (int i = 0; i < test_size; i++)
    {
	*window_push(window) = i;
    }

    assert (window.region.begin + test_size == window.region.end);

    for (int i = 0; i < test_size; i++)
    {
	assert (window.region.begin[i] == i);
    }
}

void test_path_cat()
{
    window_char path = {0};

    range_const_char arg;

    window_strcat (&path, "asdf////");

    range_string_init (&arg, "///bcle");

    window_path_cat (&path, '/', &arg);

    assert (range_streq_string(&path.region.const_cast, "asdf/bcle"));

    window_clear (path);
}

int main()
{
    test_push();

    test_path_cat();

    return 0;
}
