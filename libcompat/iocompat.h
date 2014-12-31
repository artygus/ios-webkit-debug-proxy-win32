#ifndef IOCOMPAT_H
#define IOCOMPAT_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// http://www.w3.org/Library/src/vms/getline.c
int getline(char **lineptr, size_t *n, FILE *stream)
{
  static char line[256];
  char *ptr;
  unsigned int len;

   if (lineptr == NULL || n == NULL)
   {
      errno = EINVAL;
      return -1;
   }

   if (ferror (stream))
      return -1;

   if (feof(stream))
      return -1;
     
   fgets(line,256,stream);

   ptr = strchr(line,'\n');   
   if (ptr)
      *ptr = '\0';

   len = strlen(line);
   
   if ((len+1) < 256)
   {
      ptr = (char *)realloc(*lineptr, 256);
      if (ptr == NULL)
         return(-1);
      *lineptr = ptr;
      *n = 256;
   }

   strcpy(*lineptr,line); 
   return(len);
}

#ifdef __cplusplus
}
#endif

#endif IOCOMPAT_H