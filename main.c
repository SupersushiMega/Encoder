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
void decode(short key, char Input[]);

char Output[256] = {0};   //The Output string

short d = 0;

int main()
{
    char MEDcoder = 0;//variable mode select En/Decoder
    short Key = 0;
    char Input[256] = {' '};   //The Input string

    while((MEDcoder != 'y') && (MEDcoder != 'Y'))
    {
        if(MEDcoder != 1){
            MEDcoder = 0;
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
            printf("Bitte geben sie die zu encodierende Nachricht ein\n");
            fgets(Input, 256, stdin);   //get message from user

            encode(Key, Input); //Encode Message

            for(d = 0; d < 256; d++)
            {
                printf("%c", Output[d]);
            }
            printf("\n-------------------------------------------\n");
            printf("Ihre Encodierte Nachricht:\n%s\n", Output);

            getchar();

            MEDcoder = 1;
            break;

        case 'B':
        case 'b'://modus Decoder
            printf("Sie haben den Modus Decoder Gewaehlt.\n Bitte geben den zur Nachricht gehoerenden Schluessel ein.\n ");
            scanf("%d", &Key); //get variable key
            getchar();
            printf("Bitte geben sie die zu decodierende Nachricht ein\n");
            fgets(Input, 256, stdin);   //get Encoded message from user

            decode(Key, Input);
            printf("Ihre Decodierte Nachricht:\n%s\n", Output);

            //decode(Key, Input);
            getchar();

            MEDcoder = 1;
            break;

        case 1:
            printf("Programm beenden = y\n fortfahren = enter\n ");
            scanf("%c", &MEDcoder);
            getchar();
            break;
       }//end switch case
    }//end while
return 0;
}

void encode(short key, char Input[])   //encoding key is row count, Input is input to encode
{
    short LengthInput = strlen(Input);  //Length of input string
    short RowLength = ceil(LengthInput / key);   //Length of Row
    char Output2D[key][RowLength + 1];  //2d Array used for encoding
    memset(Output2D, 0, key * RowLength * sizeof(char));  //define Output2D array
    memset(Output, 0, 256 * sizeof(char));    //Empty global string Output

    short Row = 0;   //Counting variable for Rows
    short RowPos = 0;    //Counting variable for Position in a row
    short stringPos = 0;     //Counting variable for Position in a string

    //Encoding
    //===============================================================================================
    for (RowPos = 0; RowPos <= RowLength; RowPos++)  //each char in Input is written in the Output2D Array.
    {
        for(Row = 0; Row < key && (stringPos <= LengthInput); Row++)
        {
            while((Input[stringPos] >= 0) && (Input[stringPos] <= 31))  //Filter out non printable characters
            {
                stringPos++;
            }
            Output2D[Row][RowPos] = Input[stringPos];
            printf("Output2D[%d][%d] %c    Input[%d] %c\n", Row, RowPos, Output2D[Row][RowPos], stringPos, Input[stringPos]);
            stringPos++;
        }
        printf("\n");
    }
    printf("LengthInput %d\n", LengthInput);
    printf("Stringpos %d\n", stringPos);
    printf("RowPos %d\n", RowPos);
    printf("RowLength %d\n", RowLength);
    printf("Row %d\n", Row);
    printf("Key %d\n", key);
    printf("\n");
    //===============================================================================================

    //Write 2D array to global string Output
    //===============================================================================================
    stringPos = 0;
    for(Row = 0; Row < key; Row++)
    {
        for(RowPos = 0; (RowPos <= RowLength) && (Output2D[Row][RowPos] != 0); RowPos++)
        {
            Output[stringPos] = Output2D[Row][RowPos];
            printf("Output2D[%d][%d] %c    Output[%d] %d\n", Row, RowPos, Output2D[Row][RowPos], stringPos, Output[stringPos]);
            stringPos++;
        }
        printf("\n");
    }
    //===============================================================================================
}

void decode(short key, char Input[])   //encoding key is row count, Input is input to encode
{
    short LengthInput = strlen(Input);  //Length of input string
    short RowLength = ceil(LengthInput / key);   //Length of Row
    char Output2D[key][RowLength + 1];  //2d Array used for encoding
    memset(Output2D, 0, key * RowLength * sizeof(char));  //define Output2D array
    memset(Output, 0, 256 * sizeof(char));    //Empty global string Output

    short Row = 0;   //Counting variable for Rows
    short RowPos = 0;    //Counting variable for Position in a row
    short stringPos = 0;     //Counting variable for Position in a string

    //Encoding
    //===============================================================================================
    for (Row = 0; Row < key; Row++)  //each char in Input is written in the Output2D Array.
    {
        for(RowPos = 0; (RowPos <= RowLength) && (stringPos <= LengthInput); RowPos++)
        {
            while((Input[stringPos] >= 0) && (Input[stringPos] <= 31))  //Filter out non printable characters
            {
                stringPos++;
            }
            Output2D[Row][RowPos] = Input[stringPos];
            printf("Output2D[%d][%d] %c    Input[%d] %c\n", Row, RowPos, Output2D[Row][RowPos], stringPos, Input[stringPos]);
            stringPos++;
        }
        printf("\n");
    }
    printf("LengthInput %d\n", LengthInput);
    printf("Stringpos %d\n", stringPos);
    printf("RowPos %d\n", RowPos);
    printf("RowLength %d\n", RowLength);
    printf("Row %d\n", Row);
    printf("Key %d\n", key);
    printf("\n");
    //===============================================================================================

    //Write 2D array to global string Output
    //===============================================================================================
    stringPos = 0;
    for(RowPos = 0; RowPos <= RowLength ; RowPos++)
    {
        for(Row = 0; Row < key; Row++)
        {
            Output[stringPos] = Output2D[Row][RowPos];
            printf("Output2D[%d][%d] %c    Output[%d] %d\n", Row, RowPos, Output2D[Row][RowPos], stringPos, Output[stringPos]);
            stringPos++;
        }
        printf("\n");
    }
    //===============================================================================================
}
