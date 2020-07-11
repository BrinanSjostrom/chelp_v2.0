#ifndef _INPUT_H_
#define _INPUT_H_

#include <stdio.h>
#include <stdlib.h>

char *getInput()
{
    char ch;
    int size = 1;
    char *str = (char*)malloc(1);
    while(1)
    {
        ch = fgetc(stdin);
        if(ch == EOF || ch == '\n')
        {
            *(str + size - 1) = 0;
            break;
        }
        *(str + size - 1) = ch;
        size++;
        str = (char*)realloc(str, size);
    }
return str;
}

#endif