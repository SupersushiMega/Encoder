#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    const long StringSize = 10000;  //MaxSize of input String
    char InputString[StringSize];    //Define InputString
    fgets(InputString, StringSize, stdin);   //Get User Input
    printf("%s", InputString);
    return 0;
}
