#ifndef _STD_H_
#define _STD_H

#include <string.h>

char *add(char *baseStr, char *addStr)
{

  int baseLength = strlen(baseStr);
  int addLength = strlen(addStr);

  baseStr = (char*)realloc(baseStr, baseLength + addLength + 1);

  strcat(baseStr, addStr);
return baseStr;
}

#endif
