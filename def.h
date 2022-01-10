#ifndef FLAT_INCLUDES
#include <stddef.h>
#define FLAT_INCLUDES
#include "../range/def.h"
#endif

/**
   @file window/def.h
   Provides a definition for an arbitrarily resizeable and shiftable array of items. A window here is comprised of two ranges as defined in src/range.h. The 'alloc' range of a window contains the total memory allocated to the window, and the 'region' range of a window describes the used portion of the allocated memory.
*/

#define window_typedef(window_type, window_name, ...)	\
    typedef union { struct { range_##window_name region; range_##window_name alloc; }; __VA_ARGS__; } window_##window_name;
/**<
   @brief Creates a typedef for a window
   @param window_type The type of the window
   @param window_name The name of the window, e.g. if int is given, then the resulting typedef will be called window_int
   @param ... Additional member declarations to be placed in the resulting window type may optionally go here. These will be union members, and so will alias other members of the window.
 */

#define window_remaining(window) ( (window).alloc.end - (window).region.end )
/**<
   @brief Evaluates to the number of unused indices after the window's region
*/

#define window_rewrite(window) ( (window).region.begin = (window).region.end = (window).alloc.begin )
/**<
   @brief Resets the window's region to be 0 indices wide and at the beginning of the window's allocation
*/

window_typedef(void, void);
window_typedef(char, char);
window_typedef(unsigned char, unsigned_char, window_char signed_cast);
window_typedef(char*, string);
window_typedef(const char*, const_string);

/**
   @union window_void
   A window of type void
*/

/**
   @union window_char
   A window of type char
*/

/**
   @union window_unsigned_char
   A window of type unsigned char. This type has a signed_cast member that aliases its parent to a window_char.
*/

/**
   @union window_string
   A window of type char*
*/

/**
   @union window_const_string
   A window of type const char*
*/
