#include <stdio.h>
#include "functions.h" ;

typedef enum {
    COMPILER = 1,
    INTERPRETER = 2,
} ForditasiMod;

typedef enum {
    WEB = 1,
    OS = 2,
    MOBIL = 3,
    MULTIPLATFORM = 4
} Platform ;

typedef struct {
    char neve[20] ;
    int megjelenesiEv ;
    ForditasiMod mod ;
    Platform platform ;

} Nyelvek ;




int main() {
    Nyelvek nyelv ;
    readNyelvekDetails(&nyelv) ;
    return 0 ;
}