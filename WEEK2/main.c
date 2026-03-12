#include <stdio.h>
#include "functions.h"

void firstFunction() {
    int a = 2754 , b = 5843 , c = 34975 ;
    int aLength = 0 ;
    int bLength = 0 ;
    int cLength = 0 ;

    int aTemp = a ;
    while(aTemp > 0) {
       aLength++ ;
       aTemp /= 10 ; 
    }   
    int biggestDigitFromA = 0 , biggestDigitFromB = 0 , biggestDigitFromC = 0 ;
    if(aLength == 1) {
        biggestDigitFromA = a ;
    } else if(aLength == 2){
        biggestDigitFromA = maxi(0  , a % 10 , a / 10) ;
    } else {
        while(a > 0) {
            biggestDigitFromA = maxi(biggestDigitFromA , a % 10 , 0) ;
            a /= 10 ;
        }
    }

    int bTemp = b ;
    while(bTemp > 0) {
       bLength++ ;
       bTemp /= 10 ; 
    }
    if(bLength == 1) {
        biggestDigitFromB = b ;
    } else if(bLength == 2){
        biggestDigitFromB = maxi(0  , b % 10 , b / 10) ;
    } else {
        while(b > 0) {
            biggestDigitFromB = maxi(biggestDigitFromB , b % 10 , 0) ;
            b /= 10 ;
        }
    }

    int cTemp = c ;
    while(cTemp > 0) {
       cLength++ ;
       cTemp /= 10 ; 
    }
    if(cLength == 1) {
        biggestDigitFromC = c ;
    } else if(cLength == 2){
        biggestDigitFromC = maxi(0  , c % 10 , c / 10) ;
    } else {
        while(c > 0) {
            biggestDigitFromC = maxi(biggestDigitFromC , c % 10 , 0) ;
            c /= 10 ;
        }
    }

    printf("A vegeredmeny : %i\n" , sum(sum(biggestDigitFromA , biggestDigitFromB) , biggestDigitFromC)) ;

}


void secondFunction() {

    int n = 37 ;
    int* array = allocateMemoryForArray1(n) ;

    fillWithRandomNumbers(n , array , -100 , 100) ;


    printArrayInReverseOrder(n , array , "output.txt") ;
    freopen("/dev/tty", "w", stdout);
    printf("Az elso es utolso elemek atlaga: %f" , avg(array[0] , array[n - 1])) ;
    deallocateMemoryForArray(&array) ;
}

void thirdFunction() {
    int m , p ;

    FILE* file = fopen("grades.txt" , "r") ;
    fscanf(file , "%i %i" , &m , &p) ;
    fclose(file) ;
    int* firstStudentsGrades = allocateMemoryForMatrix1(m , p) ;
    readMatrix(&m , &p , &firstStudentsGrades , "student1.txt") ;


    int* secondStudentsGrades = allocateMemoryForMatrix1(m , p) ;
    readMatrix(&m , &p , &secondStudentsGrades , "student2.txt") ;

    int* thirdStudentsGrades = allocateMemoryForMatrix1(m , p) ;
    readMatrix(&m , &p , &thirdStudentsGrades , "student3.txt") ;

    prinft("Az elso diak legkisebb jegy: ") ;
    int min1 = minimumValueOfMatrix(m , p , firstStudentsGrades) ;
    printf("%i\n" , min1) ;

    printf("A masodik diak legkisebb jegy: ") ;
    int min2 = minimumValueOfMatrix(m , p , secondStudentsGrades) ;
    printf("%i\n" , min2) ;

    printf("A harmadik diak legkisebb jegy: ") ;
    int min3 = minimumValueOfMatrix(m , p , thirdStudentsGrades) ;
    printf("%i\n" , min3) ;

    printf("A diakok legkisebb jegyei kozul a legnagyobb: %i " , maxi(min1 , min2 , min3));

    deallocateMatrix(m , &firstStudentsGrades) ;
    deallocateMatrix(m , &secondStudentsGrades) ;
    deallocateMatrix(m , &thirdStudentsGrades) ;
}
int main() {

    
    ///firstFunction() ;
    ///secondFunction() ;
    //thirdFunction() ;
    return 0 ;
}