/* String Module Array Notation Implementation:
This function implements the basic string manipulation functions including Str_getLength, Str_copy, Str_concat, Str_compare, and 
Str_search using array notation. 
*/


#include "str.h"
#include <assert.h>

/* As long as the string is not null, this function computes the length of a given string by using an index to iterate through the character 
array and returning the number of characters in the string before the null terminator. */
size_t Str_getLength (const char str[]) 
{
  size_t length = 0;
  assert (str != NULL);
  while (str[length] != '\0')
  {
    length++;
  }
  return length;
}

/* As long as str1 has enough space to hold str2 and str1 and str2 are not null, this function iterates through the character array str2, 
copying each character into str1, and ensures str1 is null-terminated. It returns a pointer to the updated str1. */
char *Str_copy (char str1[], const char str2[])
{
  size_t str2i = 0;
  assert (str1 != NULL && str2 != NULL);
  while (str2[str2i] != '\0')
  {
    str1[str2i] = str2[str2i];
    str2i++;
  }
  str1[str2i] = '\0';
  return str1;
}

/* As long as str1 has enough space to have str2 appended to its contents and str1 and str2 are not null, this function iterates through 
the character arrays using an index, and appending str2 to the end of str1 and returning a pointer to the updated str1. */
char *Str_concat (char str1[], const char str2[])
{
  size_t str1i = 0;
  size_t str2i = 0;
  
  assert (str1 != NULL && str2 != NULL);
  while (str1[str1i] != '\0')
  {
    str1i++;
  }

  while (str2[str2i] != '\0')
  {
    str1[str1i + str2i] = str2[str2i];
    str2i++;
  }
  
  str1[str1i + str2i] = '\0';
  return str1;
}

/* This function compares two strings lexicographically, str1 and str2, by iterating through the character arrays using an index, comparing 
corresponding elements until a difference is found or the null terminator is reached. It returns an integer less than, equal to, or greater 
than zero if str1 is found to be lexographically less than, equal to, or greater than str2. */
int Str_compare (const char str1 [], const char str2 [])
{
  size_t i = 0;
  assert (str1 != NULL && str2 != NULL);

  while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2 [i])
  {
    i++;
  }
  return ((int)(str1[i]) - (int)(str2[i]));
}

/* This function searches for the first occurrence of str2 in str1 by using an index to iterate through str1 and check for a substring  
   match by comparing each character in str2 to the corresponding character of str1. It returns a char pointer to the first occurrence 
   of str2 in str1 or NULL if str2 is not found. */
char *Str_search (const char str1 [], const char str2 [])
{
  size_t str1i = 0;
  size_t str2i;
  assert(str1 != NULL && str2 != NULL);

  if (str2[0] == '\0')
  {
    return (char *) str1;
  }

  while (str1[str1i] != '\0')
  {
    str2i = 0;
    while (str2[str2i] != '\0' && str1[str1i+str2i] == str2[str2i])
    {
      str2i++;
    }
    
    if (str2[str2i] == '\0')
    {
      return (char *)(&str1[str1i]);
    }
    str1i++;
  }
  return NULL;
}
