#ifndef _GETFILEEXTENTION_H_
#define _GETFILEEXTENTION_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getInput.h"
#define TRUE 1

char getFileExtention(char *filePath)  // returns the file extention and makes the user make one if needed
{
  int length = strlen(filePath);
  if(*(filePath + length - 1) == 'c' && *(filePath + length - 2) == '.')
  {
    return 'c';
  }
  else if(*(filePath + length - 1) == 'h' && *(filePath + length - 2) == '.')
  {
    return 'h';
  }
  else
  {
    while(TRUE)
    {
      printf("[!] Need a proper file extention (c/h): ");
      char extention = getInput()[0];
      if(extention == 'c')
      {
	filePath = (char*)realloc(filePath, length + 3);
	strcat(filePath, ".c");
        return extention;
      }
      else if(extention == 'h')
      {
        filePath = (char*)realloc(filePath, length + 3);
        strcat(filePath, ".h");
        return extention;
      }
    }
  }
}

#endif
