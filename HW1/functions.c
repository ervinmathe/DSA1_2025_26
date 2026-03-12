#include <stdio.h>
#include <string.h>
#include "functions.h"

char firstChar ( char * szo ) {
    return szo[0] ;
}

void homework() {
    char fullName[100] ;
    printf("Add meg a teljes nevedet: ") ;

    fgets(fullName , sizeof(fullName), stdin) ;

    char *word = strtok(fullName , " \n") ;
    
    while(word != NULL) {
        printf("%c " , firstChar(word)) ;
        word = strtok(NULL , " \n") ;
    }
}



