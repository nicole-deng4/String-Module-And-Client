/* String Module Pointer Notation Implementation:
This file implements the basic string manipulation functions including Str_getLength, Str_copy, Str_concat, Str_compare, and 
Str_search using pointer notation. 
*/

#include "str.h"
#include <assert.h>

/* As long as the str is not null, this function computes the length of a given string using pointer notation by initializing a pointer 
to traverse the character sequence and returning the number of characters before it reaches the null terminator. */
size_t Str_getLength (const char *str)
{
  const char *pc;
  assert (str != NULL);
  pc = str;
  while (*pc != '\0')
  {
    pc++;
  }
  return (size_t)(pc-str);
}

/* Assuming that str1 has enough space to store str2, this function copies the contents of str2 into str1 using pointer notation by moving
a pointer through str2, copying each character into str1 until the null terminator is reached. It returns a pointer to the beginning of 
str1. */
char *Str_copy (char *str1, const char *str2)
{
  char *newStr1;
  assert (str1 != NULL && str2 != NULL);
  newStr1 = str1;
  while (*str2 != '\0')
  {
    *str1 = *str2;
    str1++;
    str2++;
  }
  *str1 = '\0';
  return newStr1;
}

/* Assuming that str1 has enough space to accommodate str2, this function appends str2 to the end of str1 using pointer notation by moving 
a pointer to the null terminator of str1, then copying characters from str2 into str1 until the null terminator of str2 is reached. It 
returns a pointer to the beginning of str1. */
char *Str_concat (char *str1, const char *str2)
{
  char *newStr1;
  assert (str1 != NULL && str2 != NULL);
  newStr1 = str1;
  while (*str1 != '\0')
  {
    str1++;
  }

  while (*str2 != '\0')
  {
    *str1 = *str2;
    str1++;
    str2++;
  }
  *str1 = '\0';
  return newStr1;
}

/* This function compares str1 and str2 lexicographically using pointer notation by traversing two character pointers, comparing 
corresponding characters of str1 and str2 until a difference is found or the null terminator is reached. It returns a negative, zero, or 
positive integer based on lexicographic order. */
int Str_compare (const char *str1, const char *str2)
{
  assert (str1 != NULL && str2 != NULL);
  while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
  {
    str1++;
    str2++;
  }
  return (int)((unsigned char)(*str1) - (unsigned char)(*str2)); /* Unsigned char? */
}

/* This function searches for the first occurrence of str2 in str1 by using pointer notation to iterate through str1, checking for a 
substring match by comparing characters in str2 to corresponding characters of str1. It returns a pointer to the first occurrence of str2 
in str1, or NULL if not found. */
char *Str_search (const char *str1, const char *str2)
{
  assert(str1 != NULL && str2 != NULL);

  if (*str2 == '\0')
  {
    return (char *)str1;
  }

  while (*str1 != '\0')
  {
    const char *pc1 = str1;
    const char *pc2 = str2;
    while (*pc2 != '\0' && *pc1 == *pc2)
    {
      pc1++;
      pc2++;
    }
    
    if (*pc2 == '\0')
    {
      return (char *)str1;
    }
    str1++;
  }
  return NULL;
}
