#include <limits.h>
#include "functions.h"
#include <math.h>

int sum(int number1, int number2)
{
    return number1 + number2;
}
float minimum(float number1, float number2, float number3)
{
    float min = (number1 < number2) ? (number1) : (number2);
    /* Ha number1 kisebb, akkor min = number1, különben number2 */
    if (min > number3)
    {
        min = number3;
    }
    return min;
}
int *allocateMemoryForArray1(int n)
{
    int *pArray = (int *)malloc(n * sizeof(int));
    if (!pArray)
    {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    return pArray;
}
void allocateMemoryForArray2(int n, int **dpArray)
{
    // int* -> int** => &
    // int** -> int* => *
    *dpArray = (int *)malloc(n * sizeof(int));
    if (!(*dpArray))
    {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}
void readArray(int *pn, int **dpArray, const char *input)
{
    if (!freopen(input, "r", stdin))
    {
        printf(FILE_OPENING_ERROR_MESSAGE);
        printf("1");
        exit(FILE_OPENING_ERROR_CODE);
    }
    scanf("%i", pn);
    allocateMemoryForArray2(*pn, dpArray);
    for (int i = 0; i < *pn; ++i)
    {
        // scanf("%i", &((*dpArray)[i])); // alternatív megoldás
        scanf("%i", *dpArray + i);
    }
    freopen("CON", "r", stdin);
}
void printArray(int n, int *pArray, const char *output)
{
    freopen(output, "w", stdout);
    for (int i = 0; i < n; ++i)
    {
        printf("%i\n", pArray[i]);
    }
    printf("\n");
    freopen("CON", "w", stdout);
}
void deallocateMemoryForArray(int **dpArray)
{
    free(*dpArray);
    *dpArray = NULL;
}
float avg(float number1, float number2)
{
    return (number1 + number2) / 2;
}
float maximum(float number1, float number2, float number3)
{
    float max = (number1 > number2) ? (number1) : (number2);
    if (max < number3)
    {
        max = number3;
    }
    return max;
}
void fillWithRandomNumbers(int n, int *pArray, int start, int end)
{
    srand(time(NULL));
    for (int i = 0; i < n; ++i)
    {
        pArray[i] = start + rand() % (end - start + 1);
    }
}
void printArrayInReverseOrder(int n, int *pArray, const char *output)
{
    freopen(output, "w", stdout);
    printf("A tömb elemei fordított sorrendben:");
    for (int i = n - 1; i >= 0; --i)
    {
        printf("%i ", pArray[i]);
    }
    printf("\n");
    freopen("CON", "w", stdout);
}
int numberOfEvenNumbers(int n, const int *pArray)
{
    int counter = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!(pArray[i] % 2))
        {
            counter++;
        }
    }
    return counter;
}
int sumOfPositiveNumbers(int n, const int *pArray)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (pArray[i] > 0)
        {
            sum += pArray[i];
        }
    }
    return sum;
}
int **allocateMemoryForMatrix1(int rows, int cols)
{
    int **matrix = (int **)calloc(rows, sizeof(int *));
    if (!matrix)
    {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = (int *)calloc(cols, sizeof(int));
        if (!matrix[i])
        {
            printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
            exit(MEMORY_ALLOCATION_ERROR_CODE);
        }
    }
    return matrix;
}
void allocateMemoryForMatrix2(int rows, int cols, int ***dpMatrix)
{
    *dpMatrix = (int **)calloc(rows, sizeof(int *));
    if (!(*dpMatrix))
    {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    for (int i = 0; i < rows; ++i)
    {
        (*dpMatrix)[i] = (int *)calloc(cols, sizeof(int));
        if (!(*dpMatrix)[i])
        {
            printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
            exit(MEMORY_ALLOCATION_ERROR_CODE);
        }
    }
}
void readMatrix(int *pRows, int *pCols, int ***dpArray, const char *input)
{
    if (!freopen(input, "r", stdin))
    {
        printf(FILE_OPENING_ERROR_MESSAGE);
        exit(FILE_OPENING_ERROR_CODE);
    }
    scanf("%i%i", pRows, pCols);
    allocateMemoryForMatrix2(*pRows, *pCols, dpArray);
    for (int i = 0; i < *pRows; ++i)
    {
        for (int j = 0; j < *pCols; ++j)
        {
            scanf("%i", &((*dpArray)[i][j]));
        }
    }
    freopen("CON", "r", stdin);
}
void printMatrix(int rows, int cols, int **pMatrix, const char *output)
{
    freopen(output, "w", stdout);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            printf("%5i ", pMatrix[i][j]);
        }
        printf("\n");
    }
    freopen("CON", "w", stdout);
}
int minimumValueOfRow(int cols, const int *pRow)
{
    int minimum = INT_MAX;
    for (int i = 0; i < cols; ++i)
    {
        if (pRow[i] < minimum)
        {
            minimum = pRow[i];
        }
    }
    return minimum;
}
int *rowMinimums(int rows, int cols, int **pMatrix)
{
    int *minimums;
    allocateMemoryForArray2(rows, &minimums);
    for (int i = 0; i < rows; ++i)
    {
        minimums[i] = minimumValueOfRow(cols, pMatrix[i]);
    }
    return minimums;
}
int minimumValueOfMatrix(int rows, int cols, int **pMatrix)
{
    return minimumValueOfRow(rows, rowMinimums(rows, cols, pMatrix));
}
float averageOfMatrixElements(int rows, int cols, int **pMatrix)
{
    if (rows * cols == 0)
    {
        printf(DIVISION_BY_ZERO_ERROR_MESSAGE);
        return -1;
    }
    float avg = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            avg += pMatrix[i][j];
        }
    }
    return avg / (rows * cols);
}
void deallocateMatrix(int rows, int ***dpMatrix)
{
    for (int i = 0; i < rows; ++i)
    {
        free((*dpMatrix)[i]);
    }
    free(*dpMatrix);
    *dpMatrix = NULL;
}



int intigerNumbersOfArray(int n, float *pArray) {
    int sum = 0 ;
    for(int i = 0 ; i < n ; i++) {
        if(*(pArray + i) == floor(*(pArray + i))) {
            sum += (int)*(pArray + i) ;
        }
    }

    return sum ;
}