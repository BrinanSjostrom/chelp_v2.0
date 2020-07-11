#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input/getArgs.h"
#include "input/getInput.h"
#include "input/getFileExtention.h"
#include "add/add.h"
#define TRUE 1

int main(int argc, char *argv[])
{
  char *baseStr = (char*)malloc(1);
  char *baseInclude = (char*)malloc(1);
  char *filePath;
  int fileArgLoc;


  strcpy(baseStr, "");
  strcpy(baseInclude, "");

  if(getArgs('t', "--std", argc, argv))   // Add the standard/basic header files for a basic C program
  {
    baseStr = add(baseStr, "#include <stdio.h>\n#include <stdlib.h\n#include <string.h>\n");
  }


  if(getArgs('s', "--socket", argc, argv))    // Add socket based header files into file
  {
    baseStr = add(baseStr, "#include <sys/types.h>\n#include <sys/socket.h>\n#include <netinet/in.h>\n#include <unistd.h>\n");
  }

  if(getArgs('c', "--custom", argc, argv))
  {
    while(TRUE)
    {
      char incBrackets[2] = {'<', '>'};
      char include[] = "#include   ";
      if(getArgs('q', "--quotes", argc, argv))
      {
        incBrackets[0] = '"';
	incBrackets[1] = '"';
      }
      include[10] = incBrackets[0];
      printf("[!] Add custom header files: ");
      char *header = getInput();
      if(!strcmp(header, ""))
      {
	baseStr = add(baseStr, baseInclude);
        break;
      }
      char *fullInclude = (char*)malloc(strlen(include) + strlen(header) + 3);
      strcpy(fullInclude, include);
      strcat(fullInclude, header);
      char tempStr[] = {incBrackets[1], '\n', '\0'};
      strcat(fullInclude, tempStr);
      free(header);
      baseInclude = add(baseInclude, fullInclude);
    }
  
  }

  fileArgLoc = getArgs('f', "--file", argc, argv);

  if(!fileArgLoc) // Get file path from CLI arguments
  {
    printf("[!] Need file location!\n");
    return 1;
  }
  else
  {

    if(fileArgLoc + 2 > argc)
    {
      printf("[!] Not enough arguments");
      return 1;
    }
    filePath = (char*)malloc(strlen(argv[fileArgLoc + 1] + 1));
    strcpy(filePath, argv[fileArgLoc + 1]);

  }

  if(getFileExtention(filePath) == 'c')
  {
    baseStr = add(baseStr, "\nint main(int argc, char *argv[])\n{\n\nreturn 0;\n}");
  }
  printf("BaseStr:\n%s", baseStr);

  free(baseStr);
  free(filePath);
return 0;
}

