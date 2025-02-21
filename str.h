/* This header file declares functions for basic string manipulation, including Str_getLength, Str_copy, Str_concat, Str_compare, and 
Str_search */

#ifndef STR_H
#define STR_H

#include <stddef.h>

/* As long as str isn't null, this function returns the length of the string pointed to by str. */
size_t Str_getLength (const char *str);

/* As long as str isn't null, this function copies the string pointed to by str2 into the array pointed by str1 and returns the pointer to 
the updated str1. */
char *Str_copy (char *str1, const char *str2);

/* As long as str1 and str2 aren't null and str1 holds enough space to accommodate the additional characters from str2, this function appends
the string pointed to by str2 to the end of the string pointed to by str1 and returns the pointer to the updated str1. */ 
char *Str_concat (char *str1, const char *str2);

/* As long as str1 and str2 aren't null, this function compares str1 and str2, returning a positive integer if str1 > str2, zero if str1 = 
str2, and a negative integer if str1 < str2. */
int Str_compare (const char *str1, const char *str2);

/* As long as str1 and str2 aren't null, this function returns a pointer to the first occurrence of str2 in str1 or returns null if str2 was 
not found in str1. */
char *Str_search (const char *str1, const char *str2);

#endif
