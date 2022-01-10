#ifndef FLAT_INCLUDES
#include <stddef.h>
#include <assert.h>
#define FLAT_INCLUDES
#include "../range/def.h"
#include "../window/def.h"
#endif

/**
   @file window/alloc.h
   Provides basic memory allocation functions for windows described in window/def.h
*/

void _window_alloc (window_void * window, size_t member_size, size_t new_count);
void _window_clear (window_void * window);

#define window_alloc(window, count)		\
    _window_alloc ( (window_void*) &(window), sizeof( *(window).alloc.begin ), count )
/**<
   Allocates at least the given number of indices in the window
   @param window The target window
   @param count The number of indices to allocate
*/

#define window_clear(window)						\
    _window_clear ( (window_void*) &(window) )
/**<
   @brief Frees the memory allocated to the given window and sets all pointers in the window to NULL
*/

#define window_push(window) ( (window).region.end < (window).alloc.end ? (window).region.end++ : (window_alloc (window, (window).alloc.end - (window).alloc.begin + 1), (window).region.end++) )
/**<
   @brief Adds an item to the end of the window's region and evaluates to a pointer to the new item. The new item will have the highest index of all the window's items. To initialize the resulting item, one may either store the address given by this macro and set it up later, or dereference the macro invocation.
*/

void window_append_bytes (window_unsigned_char * window, const unsigned char * begin, size_t size);
/**<
   @brief Adds the given bytes to the end of an unsigned char window's region.
   @param window The target window
   @param begin A pointer to the bytes to be added
   @param size The number of bytes to be added
*/

inline static void window_append_bytes_range (window_unsigned_char * window, const range_const_unsigned_char * bytes)
{
    window_append_bytes (window, bytes->begin, range_count (*bytes));
}
/**<
   @brief Similar to window_append_bytes, but this function uses a range to indicate the bytes to be added
*/

inline static unsigned char * window_grow_bytes (window_unsigned_char * window, size_t size)
{
    window_alloc (*window, range_count(window->region) + size);
    unsigned char * retval = window->region.end;
    window->region.end += size;
    return retval;
}
/**<
   @brief Resizes the window's region to hold an additional number of bytes at the end, and returns a pointer to the beginning of the new bytes
   @param window The target window
   @param size The number of bytes to added
   @return A pointer to the new bytes
*/

inline static void window_resize_bytes (window_unsigned_char * window, size_t size)
{
    window_alloc (*window, size);
    window->region.end = window->region.begin + size;
    assert (window->region.end <= window->alloc.end);
}
/**<
   @brief Resizes the window's region to exactly the given size
*/
