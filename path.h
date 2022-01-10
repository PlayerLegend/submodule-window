#ifndef FLAT_INCLUDES
#include <stddef.h>
#define FLAT_INCLUDES
#include "../range/def.h"
#include "def.h"
#endif

/**
   @file window/path.h
   Provides functions for working with paths contained in windows
*/

void window_path_cat (window_char * target, char sep, const range_const_char * append);
/**<
   @brief Appends the given path to the given window. Repeated separators between target and append will be resolved into a single separator. Appending to an empty window will result in a path beginning with the separator.
   @param target The target window
   @param sep The path separator
   @param append The path to append
*/

void window_path_resolve (window_char * target, char sep);
/**<
   @brief Simplifies a path as much as possible, i.e., a path a/b/../c would turn into a/c
   @param target The target path
   @param sep The path separator
*/
