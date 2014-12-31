#ifndef STRINGCOMPAT_H
#define STRINGCOMPAT_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdarg.h>
#include <stdio.h>
#include <windows.h>

#ifndef snprintf
#define snprintf _snprintf
#endif

#ifndef strncasecmp
#define strncasecmp strnicmp
#endif

#ifndef strcasecmp
#define strcasecmp stricmp
#endif

// libimobiledevice/include/asprintf.h
static int vasprintf(char **PTR, const char *TEMPLATE, va_list AP)
{
    int res;
    char buf[16000];
    res = vsnprintf(buf, 16000, TEMPLATE, AP);
    if (res > 0) {
        *PTR = (char*)malloc(res+1);
        res = vsnprintf(*PTR, res+1, TEMPLATE, AP);
    }
    return res;
}

// libimobiledevice/include/asprintf.h
static int asprintf(char **PTR, const char *TEMPLATE, ...)
{
    int res;
    va_list AP;
    va_start(AP, TEMPLATE);
    res = vasprintf(PTR, TEMPLATE, AP);
    va_end(AP);
    return res;
}

static char *strnstr(const char *s1, const char *s2, size_t n) {
  size_t len = strlen(s2);
  if (n >= len) {
    char c = *s2;
    const char *end = s1 + (n - len);
    const char *s;
    for (s = s1; *s && s <= end; s++) {
      if (*s == c && !strncmp(s, s2, len)) {
        return (char *)s;
      }
    }
  }
  return NULL;
}

// https://www.opensource.apple.com/source/gcc/gcc-5666.3/libiberty/strndup.c
static char* strndup(const char *s, size_t n) 
{
  char *result;
  size_t len = strlen (s);

  if (n < len)
    len = n;

  result = (char *) malloc (len + 1);
  if (!result)
    return 0;

  result[len] = '\0';
  return (char *) memcpy (result, s, len);
}

// http://ftp-archive.freebsd.org/pub/FreeBSD-Archive/old-releases/i386/1.0-RELEASE/ports/textutils/lib/stpcpy.c
static char* stpcpy (char *dest, const char *source)
{
  while ((*dest++ = *source++) != '\0')
    /* Do nothing. */ ;
  return dest - 1;
}

// stpncpy from https://code.google.com/p/iphone-gcc/source/browse/trunk/gcc-4.2.3/libiberty/stpncpy.c?spec=svn4&r=4
static char* stpncpy (char *dst, const char *src, size_t len)
{ 
  size_t n = strlen (src);
  if (n > len)
    n = len;
  return strncpy (dst, src, len) + n;
}  

// http://www.opensource.apple.com/source/Libc/Libc-320/string/FreeBSD/strcasestr.c
static char* strcasestr(const char *s, const char *find)
{
    char c, sc;
    size_t len;

    if ((c = *find++) != 0) {
        c = tolower((unsigned char)c);
        len = strlen(find);
        do {
            do {
                if ((sc = *s++) == 0)
                    return (NULL);
            } while ((char)tolower((unsigned char)sc) != c);
        } while (strncasecmp(s, find, len) != 0);
        s--;
    }
    return ((char *)s);
}

#ifdef __cplusplus
}
#endif

#endif STRINGCOMPAT_H