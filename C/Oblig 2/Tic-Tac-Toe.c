/**
 *  Programmering oblig 3 - Tic Tac Toe
 * 
 *  Printer spill brett, tar bruker input og
 *  sjekker om bruker har tre på rad
 *
 * @file    Oblig3.c
 * @author  Trym Kristensen 
 *          skjellet av (Malin Foss, William Eide Seiner & FrodeH)
 */


#include <stdio.h>          //  printf, scanf
#include <stdbool.h>        //  bool
#include <ctype.h>          //  toupper


#define  ANTRUTER    9      ///<  Antall ruter på brettet
const int STRLEN  = 80;     ///<  Tekstlengde

void nullstillBrett();
bool sjekkBrett(const int n);
bool sjekkVinner(const int spiller);
void skrivBrett();
int  spillSpillet();


char gBrett[ANTRUTER];     ///<  Spillebrettet.


/**
 * Hovedprogrammet.
 */
int main() {
    char spiller1[STRLEN];           //  Begge spillernes navn.
    char spiller2[STRLEN];
    char nyttSpill;                  //  Kjøre programmet/spillet EN gang til.
	int  vinner;                 //  Evt. spillernummer som har vunnet.

    //Gjør hvert tomme element til mellomrom
    for (int i = 0; i < ANTRUTER; i++){
        if (gBrett[i] == '\0'){ 
            gBrett[i] = ' ';
        }
    } 
    
    do  {
      nullstillBrett();

      skrivBrett();

      printf("\n\nNavn på spiller 1(X):  ");     gets(spiller1);
      printf("Navn på spiller 2(O):  ");         gets(spiller2);  printf("\n");

      vinner = spillSpillet();

      if      (vinner == 1) printf("\nGratulerer %s!!\n\n", spiller1);
      else if (vinner == 2) printf("\nGratulerer %s!!\n\n", spiller2);
                                     //  'vinner' == 0:
      else    printf("\nIngen vinner denne gangen dessverre.\n\n");

      printf("\n\nEn ny runde (N/j):  ");
      scanf(" %c", &nyttSpill);  nyttSpill = toupper(nyttSpill);
      getchar();

    }  while (nyttSpill == 'J');

    return 0;
}


/**
 *  Nullstiller/blanker ut alle brettets ruter.
 */
void nullstillBrett() {
    //Går gjennom ANTRUTER og gjer til mellomrom
    for (int i = 0; i < ANTRUTER; i++)
    {
        gBrett[i] = ' ';
    }
    
}


/**
 *  Finner ut om et trekk er gyldig eller ei.
 *
 *  @param    n   - Ruten (0-8) det forsøkes å sette en brikke i
 *  @return	  Om det var mulig å sette brikken der (true) eller ei (false)
 */
bool sjekkBrett(const int n) {
    if (gBrett[n-1] == ' ' && n >= 1 && n <= 9){ 
        return false;
    } else{
        return true;
    }
}


/**
 *  Sjekker om noen har tre på rad i en eller annen retning.
 *
 *  @param    spiller   - Tar impot "X" eller "O"
 *  @return   Om noen har tre på rad (true) eller ei (false) i noen retning
 */
bool sjekkVinner(const int spiller) {
    //Sjekker om det er tre på rad
    if  (
        (gBrett[0] == spiller && gBrett[1] == spiller && gBrett[2] == spiller) || // row 1
        (gBrett[3] == spiller && gBrett[4] == spiller && gBrett[5] == spiller) || // row 2
        (gBrett[6] == spiller && gBrett[7] == spiller && gBrett[8] == spiller) || // row 3
        (gBrett[0] == spiller && gBrett[3] == spiller && gBrett[6] == spiller) || // col 1
        (gBrett[1] == spiller && gBrett[4] == spiller && gBrett[7] == spiller) || // col 2
        (gBrett[2] == spiller && gBrett[5] == spiller && gBrett[8] == spiller) || // col 3
        (gBrett[0] == spiller && gBrett[4] == spiller && gBrett[8] == spiller) || // diag \.
        (gBrett[2] == spiller && gBrett[4] == spiller && gBrett[6] == spiller)    // diag /
        )
        {
            return true;  //Om ja
        }
    return false;  //Om nei
}


/**
 *  Skriver ut spillebrettet.
 */
void skrivBrett() {
    //Enkel å simpel måte å printe ut brett
    printf("---1-----2-----3---\n");
    printf("|  %c  |  %c  |  %c  |\n", gBrett[0], gBrett[1], gBrett[2]);
    printf("---4-----5-----6---\n");
    printf("|  %c  |  %c  |  %c  |\n", gBrett[3], gBrett[4], gBrett[5]);
    printf("---7-----8-----9---\n");
    printf("|  %c  |  %c  |  %c  |\n", gBrett[6], gBrett[7], gBrett[8]);
    printf("-------------------\n");
}



/**
 *  Lar spillerne sette brikker, og finner evt en vinner.
 *
 *  @return   Spillernummeret som har vunnet (1, 2), evt. 0 (ingen vinner)
 *  @see      sjekkBrett(...)
 *  @see      skrivBrett(...)
 *  @see      sjekkVinner(...)
 */
int spillSpillet() {
    int bps; //brikke plassering
    bool tur = true;
    int spiller;

    //Går for antal ruter i spill
    for (int i = 0; i < ANTRUTER; i++){
        do{  //Passer på at input er gyldig
            if (tur){  //Deller opp hvem sin tur det er, X starter alltid
                spiller = 1;
            }else{
                spiller = 2;
            }
            printf("Spiller %i, ditt trekk(1-9): ", spiller);
            scanf("%i", &bps);
            if (sjekkBrett(bps)){  //Printer ut om trekket er ugyldig
                printf("%i er eit ugyldig tall\n", bps);
            }
        }while(sjekkBrett(bps)); 
        
        if (tur){  //if som gjør spillers trekk
            gBrett[bps-1] = 'X';  //Plasserer tegn
            tur = false;  //Gjør det til den andres tur
            skrivBrett();  //Printer ut det oppdaterte brettet
            if (sjekkVinner('X')){  //Sjekker om denne spiller har vunnet
                return 1;
            }
        }else{
            gBrett[bps-1] = 'O';
            tur = true;
            skrivBrett();
            if (sjekkVinner('O')){
                return 2;
            }
            }
        printf("\n\n");
    }
    return 0;  //Om ingen vinner
}
