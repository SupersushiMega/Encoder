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

unsigned char Output[260] = {0};   //The Output string

short d = 0;

int main()
{
    char MEDcoder = 0;//variable mode select En/Decoder
    short Key = 0;
    unsigned char Input[270] = {0};   //The Input string

    while((MEDcoder != 'y') && (MEDcoder != 'Y'))
    {
        if(MEDcoder != 1){
            MEDcoder = 0;
            printf("Wilkommen\n Dies ist ein Encoder/ Decoder.\n Waelen sie\n A fuer Encoder\n B fuer Decoder\n ");

            do
            {
                scanf("%c", &MEDcoder);
                getchar();
                if(!(MEDcoder == 'A' || MEDcoder == 'a' || MEDcoder == 'B' || MEDcoder == 'b')) //Check if the input is a allowed Letter
                {
                    printf("Eingabe muss entweder A oder B sein\n");    //Tell User that his input was a illegal letter
                }
            }while(!(MEDcoder == 'A' || MEDcoder == 'a' || MEDcoder == 'B' || MEDcoder == 'b'));    //Repeat if input is a illegal letter
        }
       switch(MEDcoder)
       {
        case 'A':
        case 'a'://modus encoder
            printf("Sie haben den Modus Encoder Gewaehlt.\n Bitte geben sie einen gewuenschten Schluessel zwischen 2 und 10 ein.\n Dieser wird zum Decoden des Textes benoetigt.\n ");
            do
            {
                scanf("%d", &Key); //get variable key
                getchar();
                if(Key < 2 || Key > 10) //Check if the input is inside allowed Range
                {
                    printf("Schluessel auserhalb des erlaubten Bereichs Zahl muss zwischen 2 und 10 sein\n");   //Tell User that his input was outside the allowed area
                }
            }while(Key < 2 || Key > 10);    //Repeat if the input is outside allowed Range

            printf("Bitte geben sie die zu encodierende Nachricht ein\n");
            fgets(Input, 257, stdin);   //get message from user
            printf("%s", Input);
            encode(Key, Input); //Encode Message

            printf("\n-------------------------------------------\n");
            printf("Ihre Encodierte Nachricht:\n%s\n", Output); //Output encoded Message

            getchar();

            MEDcoder = 1;
            break;

        case 'B':
        case 'b'://modus Decoder
            printf("Sie haben den Modus Decoder Gewaehlt.\n Bitte geben den zur Nachricht gehoerenden Schluessel ein.\n ");
            do
            {
                scanf("%d", &Key); //get variable key
                getchar();
                if(Key < 2 || Key > 10) //Check if the input is inside allowed Range
                {
                    printf("Schluessel auserhalb des erlaubten Bereichs Zahl muss zwischen 2 und 10 sein\n");   //Tell User that his input was outside the allowed area
                }
            }while(Key < 2 || Key > 10);    //Repeat if the input is outside allowed Range

            printf("Bitte geben sie die zu decodierende Nachricht ein\n");
            fgets(Input, 270, stdin);   //get Encoded message from user
            printf("%s", Input);
            decode(Key, Input); //Decode Message

            printf("\n-------------------------------------------\n");
            printf("Ihre Decodierte Nachricht:\n%s\n", Output); //Output decoded Message

            getchar();

            MEDcoder = 1;
            break;

        case 1:
            printf("Programm beenden = y\n fortfahren = enter\n ");
            do
            {
                MEDcoder = 1;
                scanf("%c", &MEDcoder);
                getchar();
                if(!(MEDcoder == 'y' || MEDcoder == '\n'))  //Check if the input is a allowed
                {
                    printf("Eingabe muss entweder y oder nichts sein\n");   //Tell User that his input was a illegal letter
                }
            }while(!(MEDcoder == 'y' || MEDcoder == '\n')); //Repeat if input is a illegal letter
            break;
       }//end switch case
    }//end while
return 0;
}

void encode(short key, char Input[])   //encoding key is row count, Input is input to encode
{
    short LengthInput = strlen(Input);  //Length of input string
    short RowLength = (short)ceil((float)LengthInput / (float)key) + 1;   //Length of Row
    unsigned char Output2D[key][RowLength];  //2d Array used for encoding
    memset(Output2D, ' ', key * RowLength * sizeof(char));  //define Output2D array
    memset(Output, ' ', 260 * sizeof(char));    //Empty global string Output

    short Row = 0;   //Counting variable for Rows
    short RowPos = 0;    //Counting variable for Position in a row
    short stringPos = 0;     //Counting variable for Position in a string

    //Encoding
    //===============================================================================================
    for (RowPos = 0; RowPos < RowLength; RowPos++)  //each char in Input is written in the Output2D Array.
    {
        for(Row = 0; Row < key && (stringPos <= LengthInput); Row++)
        {
            while((Input[stringPos] >= 0) && (Input[stringPos] <= 31) && (stringPos <= LengthInput))  //Filter out non printable characters
            {
                stringPos++;
            }
            if(stringPos <= LengthInput)    //Check if the entire string has been written
            {
                Output2D[Row][RowPos] = Input[stringPos];   //Write Letter to Output string
                stringPos++;
            }
        }
    }
    //===============================================================================================

    //Write 2D array to global string Output
    //===============================================================================================
    stringPos = 0;
    for(Row = 0; Row < key; Row++)
    {
        for(RowPos = 0; (RowPos < RowLength); RowPos++)
        {
            while((Output2D[Row][RowPos] >= 0) && (Output2D[Row][RowPos] <= 31) && (Row < key))  //Filter out non printable characters
            {
                RowPos++;
                if(RowPos > RowLength)  //Check if row is finished
                {
                    RowPos = 0; //set row position start
                    Row++;  //go to next row
                }
            }
            if (Row < key)  //Check if Row is not to high
            {
                Output[stringPos] = Output2D[Row][RowPos];  //Write Character to Output String
                stringPos++;
            }

            if(stringPos < LengthInput) //Check if the entire string has been written
            {
                Output[stringPos] = Output2D[Row][RowPos];  //Write Letter to Output string
            }
            else
            {
                Output[stringPos] = 0;  //Write null to Output string to define end of string
            }
        }
    }
    //===============================================================================================
}

void decode(short key, char Input[])   //decoding key is row count, Input is input to encode
{
    short LengthInput = strlen(Input);  //Length of input string
    short RowLength = ceil((float)LengthInput / (float)key);   //Length of Row
    unsigned char Output2D[key][RowLength];  //2d Array used for encoding
    memset(Output2D, ' ', key * RowLength * sizeof(char));  //define Output2D array
    memset(Output, ' ', 260 * sizeof(char));    //Empty global string Output

    short Row = 0;   //Counting variable for Rows
    short RowPos = 0;    //Counting variable for Position in a row
    short stringPos = 0;     //Counting variable for Position in a string

    //Encoding
    //===============================================================================================
    for (Row = 0; Row < key; Row++)  //each char in Input is written in the Output2D Array.
    {
        for(RowPos = 0; (RowPos < RowLength); RowPos++)
        {
            while((Input[stringPos] >= 0) && (Input[stringPos] <= 31) && (stringPos <= LengthInput))  //Filter out non printable characters
            {
                stringPos++;
            }
            if(stringPos <= LengthInput)    //Check if the entire string has been written
            {
                Output2D[Row][RowPos] = Input[stringPos];
                stringPos++;
            }
        }
    }
    //===============================================================================================

    //Write 2D array to global string Output
    //===============================================================================================
    stringPos = 0;
    for(RowPos = 0; RowPos < RowLength ; RowPos++)
    {
        for(Row = 0; Row < key; Row++)
        {
            while((Output2D[Row][RowPos] >= 0) && (Output2D[Row][RowPos] <= 31))  //Filter out non printable characters
            {
                Row++;
                if(Row == key)  //Check if last row has been reached
                {
                    Row = 0;    //Go to Roq 0
                    RowPos++;   //Go to next row position
                }
            }
            if(stringPos < LengthInput) //Check if the entire string has been written
            {
                Output[stringPos] = Output2D[Row][RowPos];  //Write Letter to Output string
            }
            stringPos++;
        }
    }
    //===============================================================================================
}
