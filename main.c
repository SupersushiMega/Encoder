#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*16.9.2020
Erstellt von:
Sascha Rutz
Simon Chatziparaskewas


*/
int main()
{
    char MEDcoder = 0;//variable mode select En/Decoder
    while((MEDcoder != y) | (MEDcoder != Y))
    {

       printf("Wilkommen\n Dies ist ein Encoder/ Decoder.\n Waelen sie\n A fuer Encoder\n B fuer Decoder\n ");
       scanf("%c", &MEDcoder);
       getchar();
       switch(MEDcoder)
       {
        case 'A':
        case 'a'://modus encoder
            printf("Sie haben den Modus Encoder Gewaehlt.\n Bitte geben sie einen gewuenschten Schluessel zwischen 2 und 10 ein.\n Dieser wird zum Decoden des Textes benoetigt.\n ");
    /*        scanf("%f", &key); //get variable key
            getchar();
    */

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
