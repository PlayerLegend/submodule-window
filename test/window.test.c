#include <stddef.h>
#include <assert.h>
#define FLAT_INCLUDES
#include "../../range/def.h"
#include "../def.h"
#include "../alloc.h"

#include "../../log/log.h"
#include "../../debug/debug.h"

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

int main()
{
    test_push();

    return 0;
}
