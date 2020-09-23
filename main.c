#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*16.9.2020
Erstellt von:
Sascha Rutz
Simon Chatziparaskewas


*/

void encode(short key, char Input[]);

char Output[sizeof(long)] = {' '};   //The Output string

int main()
{
    char MEDcoder = 0;//variable mode select En/Decoder

    char String[sizeof(long)] = {' '};

    while((MEDcoder != 'y') && (MEDcoder != 'Y'))
    {
       printf("Wilkommen\n Dies ist ein Encoder/ Decoder.\n Waelen sie\n A fuer Encoder\n B fuer Decoder\n ");
       scanf("%c", &MEDcoder);
       getchar();
       switch(MEDcoder)
       {
        case 'A':
        case 'a'://modus encoder
            printf("Sie haben den Modus Encoder Gewaehlt.\n Bitte geben sie einen gewuenschten Schluessel zwischen 2 und 10 ein.\n Dieser wird zum Decoden des Textes benoetigt.\n ");
            encode(2, "TestTestTestTestTest");
            printf("%s\n", Output);
    /*        scanf("%f", &key); //get variable key
            getchar();
    */
            MEDcoder = 1;
            break;

        case 'B':
        case 'b'://modus Decoder
            printf("Sie haben den Modus Decoder Gewaehlt.\n Bitte geben den zur Nachricht gehoerenden Schluessel ein.\n ");
    /*        scanf("%f", &key); //get variable key
            getchar();
    */
            MEDcoder = 1;
            break;

        case 1:
            printf("Programm beenden = y\n fortfahren = enter\n ");
            scanf("%c", &MEDcoder);
            break;
       }
    }//end while
return 0;
}

void encode(short key, char Input[])   //encoding key is row count, Input is input to encode
{
    long LengthInput = strlen(Input);  //Length of input string
    long RowLength = floor(LengthInput / key);   //Length of Row
    char Output2D[key][RowLength];  //2d Array used for encoding
    memset(Output2D, ' ', key * RowLength * sizeof(char));
    memset(Output, ' ', LengthInput * sizeof(char));

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
            printf("%c\n",Output[stringPos]);
            stringPos++;
        }
    }
}
