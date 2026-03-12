#include "functions.h" ;
#include "main.c" ;

void readNyelvekDetailsFromKeyboard(Nyelvek *pNyelvek) {

    printf("Neve: ") ;
    scanf("%s" , pNyelvek->neve) ;

    printf("Megjelenesi ev: ") ;
    scanf("%d" , &pNyelvek->megjelenesiEv) ;

    printf("Forditasi mod (1=Compiler, 2=Interpreter): ") ;
    int mod ;
    scanf("%d" , &mod) ;
    pNyelvek->mod = (ForditasiMod)mod ;

    printf("Platform (1=Web, 2=OS, 3=Mobil, 4=Multiplatform): ") ;
    int platform ;
    scanf("%d" , &platform) ;
    pNyelvek->platform = (Platform)platform ;
}

void readNyelvekDetailsFromFile(Nyelvek *pNyelvek , const char *file) {
    FILE *fp = fopen(file , "r") ;
    if (fp == NULL) {
        printf("Hiba: A fajl nem nyithato meg: %s\n" , file) ;
        return 1 ; 
    }

    fscanf(fp , "%s" , pNyelvek->neve) ;
    fscanf(fp , "%d" , &pNyelvek->megjelenesiEv) ;

    int mod ;
    fscanf(fp , "%d" , &mod) ;
    pNyelvek->mod = (ForditasiMod)mod ;

    int platform ;
    fscanf(fp , "%d" , &platform) ;
    pNyelvek->platform = (Platform)platform ;

    fclose(fp) ;
}