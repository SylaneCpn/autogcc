//----------------------------------------------------------------------------

#include "strUtils.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void
Str_upper(char *str)
{
  int length=(int)strlen(str);
  for(int i=0; i<length; ++i)
  {
    str[i]=(char)toupper(str[i]);
  }
}

void
Str_lower(char *str)
{
  int length=(int)strlen(str);
  for(int i=0; i<length; ++i)
  {
    str[i]=(char)tolower(str[i]);
  }
}

char * // new dynamic-string
Str_repeat(char symbol,
           int length)
{
  char *dst=(char *)malloc(length+1); // '\0' included
  if(dst==NULL)
  {
    abort();
  }
  for(int i=0; i<length; ++i) // '\0' excluded
  {
    dst[i]=symbol;
  }
  dst[length]='\0'; // ensure termination
  return dst;
}

char * // new dynamic-string
Str_create(const char *str,
           int length)
{
  if(length<0)
  {
    length=(int)strlen(str);
  }
  char *dst=(char *)malloc(length+1); // '\0' included
  if(dst==NULL)
  {
    abort();
  }
  strncpy(dst, str, length); // '\0' excluded
  dst[length]='\0'; // ensure termination
  return dst;
}

char * // new dynamic-string
Str_add(const char *str1,
        const char *str2)
{
  int length1=(int)strlen(str1); // '\0' excluded
  int size2=1+(int)strlen(str2); // '\0' included
  char *dst=(char *)malloc(length1+size2); // '\0' included
  if(dst==NULL)
  {
    abort();
  }
  strncpy(dst, str1, length1); // '\0' excluded
  strncpy(dst+length1, str2, size2); // '\0' included
  return dst;
}

void
Str_append(char **inout_str,
           const char *tail)
{
  //-- load inout-parameters --
  char *str=*inout_str;
  //-- perform work --
  int length1=(int)strlen(str); // '\0' excluded
  int size2=1+(int)strlen(tail); // '\0' included
  str=(char *)realloc(str,length1+size2); // '\0' included
  if(str==NULL)
  {
    abort();
  }
  strncpy(str+length1, tail, size2); // '\0' included
  //-- store out-parameters --
  *inout_str=str;
}

static // internal use
bool // c is a valid character for a word
Str_validInWord(int c)
{
  return c&&!ispunct(c)&&!isspace(c);
}

bool // success
Str_findWord(const char *str,
             int *out_begin,
             int *out_length)
{
  int length=(int)strlen(str);
  int begin=-1;
  for(int i=0; i<length; ++i)
  {
    if(Str_validInWord(str[i]))
    {
      begin=i;
      break;
    }
  }
  if(begin==-1)
  {
    return false;
  }
  int end=begin;
  for(int i=begin; i<=length; ++i) // reach '\0' to detect word end
  {
    if(!Str_validInWord(str[i]))
    {
      end=i;
      break;
    }
  }
  //-- store out-parameters --
  *out_begin=begin;
  *out_length=end-begin;
  return true;
}

//----------------------------------------------------------------------------