#ifndef INTRODUCTION_FUNCTIONS_H
#define INTRODUCTION_FUNCTIONS_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "constants.h"
/**
* Kiszámítja két egész szám összegét.
* @param number1 - az első szám
* @param number2 - a második szám
* @return az összeg értéke
*/
int sum(int number1, int number2);
/**
* Meghatározza három szám közül a minimumot.
* @param number1 - az első szám
* @param number2 - a második szám
* @param number3 - a harmadik szám
* @return a legkisebb érték
*/
float minimum(float number1, float number2, float number3);
/**
* Memóriát foglal egy egydimenziós tömb számára, és visszaadja a pointert.
* @param n - a tömb hossza
* @return pointer egy egész típusú tömbhöz
*/
int* allocateMemoryForArray1(int n);
/**
* Memóriát foglal egy tömb számára.
* @param n - a tömb hossza
* @param dpArray - pointer egy int pointerre (a lefoglalt tömb címét adja
vissza)
*/
void allocateMemoryForArray2(int n, int **dpArray);
/**
* Beolvassa az adatokat egy megadott bemeneti forrásból.
* Meghívja a memóriakezelő függvényt.
* @param pn - pointer a tömb méretére
* @param dpArray - pointer egy int pointerre (a lefoglalt tömb címét adja
vissza)
* @param input - a bemeneti forrás neve
*/
void readArray(int *pn, int **dpArray, const char *input);
/**
* Kiírja a tömb összes elemét.
* @param n - a tömb hossza
* @param pArray - pointer a tömb elemeire
* @param output - a kimeneti fájl neve vagy "CON" konzol esetén
*/
void printArray(int n, int *pArray, const char *output);
/**
* Felszabadítja a memóriát.
* @param dpArray - a felszabadítandó tömb pointere
*/
void deallocateMemoryForArray(int **dpArray);
/**
* Kiszámítja két szám átlagát.
* @param number1 - az első szám
* @param number2 - a második szám
* @return az átlag
*/
float avg(float number1, float number2);
/**
 * * Meghatározza három szám közül a maximumot.
* @param number1 - az első szám
* @param number2 - a második szám
* @param number3 - a harmadik szám
* @return a legnagyobb érték
*/
float maximum(float number1, float number2, float number3);
/**
* Feltölti a tömböt véletlenszerű számokkal adott tartományban.
* @param n - a tömb mérete
* @param pArray - pointer a tömbre
* @param start - az alsó határérték
* @param end - a felső határérték
*/
void fillWithRandomNumbers(int n, int *pArray, int start, int end);
/**
* Kiírja a tömb elemeit fordított sorrendben.
* @param n - a tömb hossza
* @param pArray - pointer a tömb elemeire
* @param output - a kimeneti fájl neve vagy "CON" konzol esetén
*/
void printArrayInReverseOrder(int n, int *pArray, const char* output);
/**
* Megszámolja a páros számokat a tömbben.
* @param n - a tömb mérete
* @param pArray - pointer a tömb elemeire
* @return a páros számok száma
*/
int numberOfEvenNumbers(int n, const int *pArray);
/**
* Kiszámítja a pozitív számok összegét a tömbben.
* @param n - a tömb mérete
* @param pArray - pointer a tömb elemeire
* @return a pozitív számok összege
*/
int sumOfPositiveNumbers(int n, const int *pArray);
/**
* Memóriát foglal egy mátrix számára és visszaadja a pointert.
* @param rows - a mátrix sorainak száma
* @param cols - a mátrix oszlopainak száma
* @return pointer a mátrixra
*/
int** allocateMemoryForMatrix1(int rows, int cols);
/**
* Memóriát foglal egy mátrix számára.
* @param rows - a mátrix sorainak száma
* @param cols - a mátrix oszlopainak száma
* @param dpMatrix - a mátrix pointere
*/
void allocateMemoryForMatrix2(int rows, int cols, int ***dpMatrix);
/**
* Felszabadítja a mátrix memóriahelyeit.
* @param rows - a mátrix sorainak száma
* @param dpMatrix - a felszabadítandó mátrix pointere
*/
void deallocateMatrix(int rows, int ***dpMatrix);
/**
* Beolvassa a mátrix elemeit fájlból vagy konzolról.
* @param pRows - pointer a sorok számához
* @param pCols - pointer az oszlopok számához
* @param dpArray - a mátrix pointere
* @param input - a bemeneti forrás neve
*/
void readMatrix(int *pRows, int *pCols, int ***dpArray, const char *input);
/**
* Kiírja a mátrix elemeit egy megadott kimeneti forrásba.
* @param rows - a mátrix sorainak száma
* @param cols - a mátrix oszlopainak száma
* @param pMatrix - a mátrix elemei
* @param output - a kimeneti forrás neve
*/
void printMatrix(int rows, int cols, int **pMatrix, const char *output);
/**
* Egy adott sor minimumértékét adja vissza.
* @param cols - az oszlopok száma
* @param pRow - pointer az adott sor elemeire
* @return a minimum érték
*/
int minimumValueOfRow(int cols, const int *pRow);
/**
* Visszaadja a sorok minimumértékeit egy tömbben.
* @param rows - a sorok száma
* @param cols - az oszlopok száma
* @param pMatrix - a mátrix elemei
* @return a sorok minimumai
*/
int* rowMinimums(int rows, int cols, int **pMatrix);
/**
* A mátrix legkisebb elemének értékét adja vissza.
* @param rows - a mátrix sorainak száma
* @param cols - a mátrix oszlopainak száma
* @param pMatrix - a mátrix elemei
* @return a minimum érték
*/
int minimumValueOfMatrix(int rows, int cols, int **pMatrix);
/**
* A mátrix elemeinek átlagát számítja ki
* @param rows - a mátrix sorainak száma
* @param cols - a mátrix oszlopainak száma
* @param pMatrix - a mátrix elemei
* @return az átlagérték
*/
float averageOfMatrixElements(int rows, int cols, int **pMatrix);

int intigerNumbersOfArray(int n , float *pArray) ;


#endif