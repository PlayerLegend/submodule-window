#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#define FLAT_INCLUDES
#include "../../range/def.h"
#include "../def.h"
#include "../printf.h"

#include "../../debug/debug.h"

void test_window_printf()
{
    window_char window = {0};

    window_printf (&window, "ab %s %d", "cd", 10);

    assert (0 == strcmp (window.region.begin, "ab cd 10"));

    assert (strlen ("ab cd 10") == range_count (window.region));
    
    window_printf (&window, "ab %s %d", "cd", 53);

    assert (0 == strcmp (window.region.begin, "ab cd 53"));
    assert (strlen ("ab cd 53") == range_count (window.region));
}

void test_window_printf_append()
{
    window_char window = {0};

    window_printf_append (&window, "ab %s %d", "cd", 10);

    assert (0 == strcmp (window.alloc.begin, "ab cd 10"));
    assert (strlen ("ab cd 10") == range_count (window.region));
    
    window_printf_append (&window, "ab %s %d", "cd", 64);

    assert (0 == strcmp (window.alloc.begin, "ab cd 10ab cd 64"));
    assert (strlen ("ab cd 10ab cd 64") == range_count (window.region));
}

int main()
{
    test_window_printf();
    test_window_printf_append();
    return 0;
}
