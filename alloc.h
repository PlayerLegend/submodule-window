#ifndef FLAT_INCLUDES
#include <stddef.h>
#include <assert.h>
#define FLAT_INCLUDES
#include "../range/def.h"
#include "../window/def.h"
#endif

void _window_alloc (window_void * window, size_t member_size, size_t new_count);
void _window_clear (window_void * window);

#define window_alloc(window, count)		\
    _window_alloc ( (window_void*) &(window), sizeof( *(window).alloc.begin ), count )

#define window_clear(window)						\
    _window_clear ( (window_void*) &(window) )

#define window_push(window) ( (window).region.end < (window).alloc.end ? (window).region.end++ : (window_alloc (window, (window).alloc.end - (window).alloc.begin + 1), (window).region.end++) )

void window_append_bytes (window_unsigned_char * window, const unsigned char * begin, size_t size);
inline static void window_append_bytes_range (window_unsigned_char * window, const range_const_unsigned_char * bytes)
{
    window_append_bytes (window, bytes->begin, range_count (*bytes));
}

inline static void * window_grow_bytes (window_unsigned_char * window, size_t size)
{
    window_alloc (*window, range_count(window->region) + size);
    void * retval = window->region.end;
    window->region.end += size;
    return retval;
}

inline static void window_resize_bytes (window_unsigned_char * window, size_t size)
{
    window_alloc (*window, size);
    window->region.end = window->region.begin + size;
    assert (window->region.end <= window->alloc.end);
}
