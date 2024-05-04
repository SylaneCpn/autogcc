//----------------------------------------------------------------------------

#ifndef STRUTILS_H
#define STRUTILS_H

#include <stdbool.h>

void
Str_upper(char *str);

void
Str_lower(char *str);

char * // new dynamic-string
Str_repeat(char symbol,
           int repeat);

char * // new dynamic-string
Str_create(const char *str,
           int length);

char * // new dynamic-string
Str_add(const char *str1,
        const char *str2);

void
Str_append(char **inout_str,
           const char *tail);

bool // success
Str_findWord(const char *str,
             int *out_begin,
             int *out_length);

#endif // STRUTILS_H

//----------------------------------------------------------------------------