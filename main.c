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

char Output[256] = {' '};   //The Output string

int main()
{
    char MEDcoder = 0;//variable mode select En/Decoder
    short Key = 0;
    char Input[256] = {' '};   //The Input string

    while((MEDcoder != 'y') && (MEDcoder != 'Y'))
    {
        if(MEDcoder != 1){
            printf("Wilkommen\n Dies ist ein Encoder/ Decoder.\n Waelen sie\n A fuer Encoder\n B fuer Decoder\n ");
            scanf("%c", &MEDcoder);
            getchar();
        }
       switch(MEDcoder)
       {
        case 'A':
        case 'a'://modus encoder
            printf("Sie haben den Modus Encoder Gewaehlt.\n Bitte geben sie einen gewuenschten Schluessel zwischen 2 und 10 ein.\n Dieser wird zum Decoden des Textes benoetigt.\n ");
            scanf("%d", &Key); //get variable key
            getchar();
            printf("Bitte geben sie die zu decodierende Nachricht ein\n");
            fgets(Input, 256, stdin);   //get message from user

            encode(Key, Input); //Encode Message
            printf("%s\n", Output);

            MEDcoder = 1;
            break;

        case 'B':
        case 'b'://modus Decoder
            printf("Sie haben den Modus Decoder Gewaehlt.\n Bitte geben den zur Nachricht gehoerenden Schluessel ein.\n ");
            scanf("%d", &Key); //get variable key
            getchar();
            printf("Bitte geben sie die Nachricht ein\n");
            fgets(Input, 256, stdin);   //get Encoded message from user

            //decode(Key, Input);
            printf("%s\n", Output);

            MEDcoder = 1;
            break;

        case 1:
            printf("Programm beenden = y\n fortfahren = enter\n ");
            scanf("%c", &MEDcoder);
            break;
       }//end switch case
    }//end while
return 0;
}

void encode(short key, char Input[])   //encoding key is row count, Input is input to encode
{
    short LengthInput = strlen(Input);  //Length of input string
    short RowLength = floor(LengthInput / key);   //Length of Row
    char Output2D[key][RowLength];  //2d Array used for encoding
    memset(Output2D, ' ', key * RowLength * sizeof(char));  //define Output2D array
    memset(Output, ' ', 256 * sizeof(char));    //Empty global string Output

    short Row = 0;   //Counting variable for Rows
    short RowPos = 0;    //Counting variable for Position in a row
    short stringPos = 0;     ////Counting variable for Position in a string

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

    //Write 2D array to global string Output
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
    //===============================================================================================
}


