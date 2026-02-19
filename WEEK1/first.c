#include <stdio.h>
#include "functions.h"



void firstFunction() {
    int n ;
    printf("Hany lemet szertenel a tombe?\n") ;
    scanf("%d", &n) ;
    int* array = allocateMemoryForArray1(n) ; 

    for(int i = 0 ; i < n ; i++ ) {
        array[i] = i + 1 ;
        printf("%d ", array[i]) ;
    }

    deallocateMemoryForArray(&array) ;
}

void secondFunction() {
    int n ;
    int* array = NULL ;
    readArray(&n, &array, "input.txt") ;
    printf("A szamsorozat elemei egymas alatt:\n") ;
    printArray(n, array, "CON") ;
    printf("\n Az egesz szamok osszege: \n") ;
    
    deallocateMemoryForArray(&array) ;
}


int main() {

    //firstFunction() ;
    secondFunction() ;
    return 0 ;
}