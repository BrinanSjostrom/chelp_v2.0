#ifndef _GETARGS_H_
#define _GETARGS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************************
Function will return the index
of the argument in the argv
variable by using the
identifiers chArg and strArg to
find them.
******************************/

int getArgs(char chArg, char *strArg, int argc, char *argv[])
{
  if(!(argc > 1))  //checks the amount of CLI args
  {
    fprintf(stderr, "[!] No arguments found\n");
    exit(1);
  }

  for(int i = 1; i < argc; i++)  //searches for args matching description 
  {
    if(argv[i][1] == chArg || strcmp(argv[i], strArg) == 0)
    {
      return i;
    }
  }
  return 0; //returns a 0 if the CLI arg wasn't found
}

#endif
