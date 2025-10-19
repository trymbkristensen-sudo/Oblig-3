#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int STRLEN = 80;
    const int
        BROOK   =  'r',
        BBISHOP =  'b',
        BHORSE  =  'h',
        BQUEAN  =  'q',
        BKING   =  'k',
        BPAWN   =  'p';

    const int
        WROOK   =  'R',
        WBISHOP =  'B',
        WHORSE  =  'H',
        WQUEAN  =  'Q',
        WKING   =  'K',
        WPAWN   =  'P';

    int brett[8][8] = {
        {BROOK, BBISHOP, BHORSE, BQUEAN, BKING,  BHORSE, BBISHOP, BROOK},
        {BPAWN, BPAWN,   BPAWN,  BPAWN,  BPAWN,  BPAWN,  BPAWN,   BPAWN},
        {' ',   ' ',     ' ',    ' ',    ' ',    ' ',    ' ',     ' '  },
        {' ',   ' ',     ' ',    ' ',    ' ',    ' ',    ' ',     ' '  },
        {' ',   ' ',     ' ',    ' ',    ' ',    ' ',    ' ',     ' '  },
        {' ',   ' ',     ' ',    ' ',    ' ',    ' ',    ' ',     ' '  },
        {WPAWN, WPAWN,   WPAWN,  WPAWN,  WPAWN,  WPAWN,  WPAWN,   WPAWN},
        {WROOK, WBISHOP, WHORSE, WKING,  WQUEAN, WHORSE, WBISHOP, WROOK}
    };

void PrintBrett(){
    int bredde = 8;
    int height = 8;

    const int
    TOPL = 218, TOPM = 194, TOPR = 191,
    MIDL = 195, MIDM = 197, MIDR = 180,
    BOTL = 192, BOTM = 193, BOTR = 217,

    BARH = 196, BARV = 179;
    printf("    A   B   C   D   E   F   G   H\n");
    printf("  %c%c%c%c", TOPL, BARH, BARH, BARH);
    for (int i = 0; i < 6; i++){
        printf("%c%c%c%c", TOPM, BARH, BARH, BARH);
    }
    printf("%c%c%c%c%c\n", TOPM, BARH, BARH, BARH, TOPR);

    //Skriver ut posisjon og side vegger
    for (int j = 0; j < bredde; j++){
        printf("%i ",j+1);
        for (int i = 0; i < height; i++){
            printf("%c %c ",BARV, brett[j][i]);
            }
        printf("%c",BARV);

        //Bot til top mellomrom
        if (j != 7){
            printf("\n  %c%c%c%c", MIDL, BARH, BARH, BARH);
            for (int i = 0; i < 6; i++){
                printf("%c%c%c%c", MIDM, BARH, BARH, BARH);
            }
            printf("%c%c%c%c%c\n", MIDM, BARH, BARH, BARH, MIDR);
        }else{
           printf("\n  %c%c%c%c", BOTL, BARH, BARH, BARH);
            for (int i = 0; i < 6; i++){
                printf("%c%c%c%c", BOTM, BARH, BARH, BARH);
            }
            printf("%c%c%c%c%c\n", BOTM, BARH, BARH, BARH, BOTR);
        }
    }
}

int BokstavTilTall(int bokstav){
    //Gjer Bokstaver fra A til H om til tall
        int bredde;
        switch(toupper(bokstav)){
        case 'A':
            bredde = 0;
            break;
        case 'B':
            bredde = 1;
            break;
        case 'C':
            bredde = 2;
            break;
        case 'D':
            bredde = 3;
            break;
        case 'E':
            bredde = 4;
            break;
        case 'F':
            bredde = 5;
            break;
        case 'G':
            bredde = 6;
            break;
        case 'H':
            bredde = 7;
            break;
        default:
            printf("Ikkje eit gyldig move\n");
    }
    return bredde;
}

void flytt(){
    char brikkeFlytting[80];
    char brikkePlassering[80];
    char splitte_1;
    int splitte_2;
    int brikkeSomFlyttast;
    int bredde;

    printf("Velg brikke flytting eks(D2): ");
    scanf("%s", &brikkeFlytting);

    printf("Velg brikke plassering eks(D4): ");
    scanf("%s", &brikkePlassering);

    //Brikke som skal flyttest
    splitte_1 = brikkeFlytting[0];
    splitte_2 = brikkeFlytting[1] - '0';

    bredde = BokstavTilTall(splitte_1);

    //Lagrer Brikken som skal flyttast
    brikkeSomFlyttast = brett[splitte_2-1][bredde];

    //Gjør forje plassen tom
    brett[splitte_2-1][bredde] = '0  ';

    splitte_1 = brikkePlassering[0];
    splitte_2 = brikkePlassering[1] - '0';

    bredde = BokstavTilTall(splitte_1);

    brett[splitte_2-1][bredde] = brikkeSomFlyttast;

}

int main(){
    //PrintBrett();
    for(int frode = 0; frode < 1;){
    PrintBrett();
    flytt();
    }
}
