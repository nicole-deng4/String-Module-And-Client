# include "str.h"
# include <assert.h>

size_t Str_getLength (const char *str)
{
  const char *pc = str;
  assert (str != NULL);
  while (*pc != \'0')
  {
    pc++;
  }
  return (size_t)(pc-str);
}

char *Str_copy (char *str1, const char *str2)
{
  char *newStr1 = str1;
  assert (str1 != NULL && str2 != NULL);
  while (*str2 != '\0')
  {
    *str1 = *str2;
    str1++;
    str2++;
  }
  return newStr1;
}

char *Str_concat (char *str1, const char *str2)
{
  char *newStr1 = str1;
  
  assert (str1 != NULL && str2 != NULL);
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
  
  return newStr1;
}

int Str_compare (const char *str1, const char *str2)
{
  
  assert (str1 != NULL && str2 != NULL);
  while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
  {
    str1++;
    str2++;
  }
  return (int)((*str1) - (*str2)); /* Unsigned char? */
}

char *Str_search (const char *str1, const char *str2)
{
  
  assert(str1 != NULL && str2 != NULL);

  if (*str2 == '\0')
  {
    return str1;
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
      return pc1;
    }
    str1++;
  }
  return NULL;
}
