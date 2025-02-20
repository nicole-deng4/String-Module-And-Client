#include "str.h"
#include <assert.h>

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

char *Str_search (const char str1 [], const char str2 [])
{
  size_t str1i = 0;
  size_t str2i;

  if (*str2 == '\0')
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
