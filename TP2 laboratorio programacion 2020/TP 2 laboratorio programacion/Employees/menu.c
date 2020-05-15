#include <stdio.h>

#include "Functions.h"

int menu(char message[],char errorMessage[],int min, int max,int retries)
{
    int result = -1;

    UTN_getNumberInt(&result,message,errorMessage,min,max,retries);

    return result;
}
