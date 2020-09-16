#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*16.9.2020
Erstellt von:
Sascha Rutz
Simon Chatziparaskewas


*/

void encode(short key, char string[]);

int main()
{
   printf("Wilkommen \n");


    encode(10, "Hello Test Test abcdefghijklmnopqrstuvwxyz");



}

void encode(short key, char Input[])   //encoding key is row count, Input is input to encode
{
    long LengthInput = strlen(Input);  //Length of input string
    long RowLength = ceil(LengthInput / key);   //Length of Row
    char Output2D[key][RowLength];  //2d Array used for encoding
    char Output[LengthInput];   //The Output string

    long Row = 0;   //Counting variable for Rows
    long RowPos = 0;    //Counting variable for Position in a row
    long stringPos = 0;     ////Counting variable for Position in a string

    //Encoding
    //===============================================================================================
    for (RowPos = 0; RowPos < RowLength; RowPos++)  //each char in Input is written in the Output2D Array.
    {
        for(Row = 0; Row < key; Row++)
        {
            Output2D[Row][RowPos] = Input[stringPos];
            stringPos++;
        }
    }
    //===============================================================================================

    stringPos = 0;
    for (Row = 0; Row < key; Row++)
    {
        for(RowPos = 0; RowPos < RowLength; RowPos++)
        {
            Output[stringPos] = Output2D[Row][RowPos];
            stringPos++;
        }
    }
    printf("%s", Output);
}
