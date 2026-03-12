#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 31
#define MAX_CAPACITY 20

typedef enum
{
    NORMAL = 0,
    EXPRESS = 1,
    SAME_DAY = 2,
    OTHER = 3
} Priority_t;

typedef struct
{
    char recipientName[MAX_NAME_LENGTH];
    int weight;
    Priority_t priority;
    int fragile;
} Package_t;

typedef Package_t *PackageArray;

char *getPriorityDescription(Priority_t type)
{
    switch (type)
    {
    case NORMAL:
        return "NORMAL";
    case EXPRESS:
        return "EXPRESS";
    case SAME_DAY:
        return "SAME_DAY";
    default:
        return "OTHER";
    }
}

void readPackageDetails(Package_t *pPackage)
{
    int priority, fragile;
    scanf(" %30[^;];%d;%d;%d",
          pPackage->recipientName,
          &pPackage->weight,
          &priority,
          &fragile);
    pPackage->priority = (Priority_t)priority;
    pPackage->fragile = fragile;
}

void printPackage(Package_t package)
{
    printf("Nev: %-30s | Suly: %3d kg | Prioritas: %-8s | Torekeny: %s\n",
           package.recipientName,
           package.weight,
           getPriorityDescription(package.priority),
           package.fragile ? "Igen" : "Nem");
}

void allocateMemoryForPackages(Package_t **dpPackages, int numberOfPackages)
{
    *dpPackages = (Package_t *)malloc(numberOfPackages * sizeof(Package_t));
    if (*dpPackages == NULL)
    {
        fprintf(stderr, "Hiba: nem sikerult memoriat foglalni!\n");
        exit(EXIT_FAILURE);
    }
}

void readAllPackagesDetails(Package_t **dpPackages, int *pNumberOfPackages, const char *input)
{
    FILE *fp = fopen(input, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Hiba: nem sikerult megnyitni a(z) '%s' fajlt!\n", input);
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%d\n", pNumberOfPackages);

    if (*pNumberOfPackages > MAX_CAPACITY)
    {
        fprintf(stderr, "Figyelmeztetes: a fajlban %d csomag van, de a max. kapacitas %d. Csak %d csomag kerul beolvasasra.\n",
                *pNumberOfPackages, MAX_CAPACITY, MAX_CAPACITY);
        *pNumberOfPackages = MAX_CAPACITY;
    }

    allocateMemoryForPackages(dpPackages, *pNumberOfPackages);

    for (int i = 0; i < *pNumberOfPackages; i++)
    {
        int priority, fragile;
        fscanf(fp, " %30[^;];%d;%d;%d",
               (*dpPackages)[i].recipientName,
               &(*dpPackages)[i].weight,
               &priority,
               &fragile);
        (*dpPackages)[i].priority = (Priority_t)priority;
        (*dpPackages)[i].fragile = fragile;
    }

    fclose(fp);
}

void printAllPackages(Package_t *pPackages, int numberOfPackages, const char *destination)
{
    FILE *fp = NULL;
    int toFile = (strcmp(destination, "stdout") != 0);

    if (toFile)
    {
        fp = fopen(destination, "w");
        if (fp == NULL)
        {
            fprintf(stderr, "Hiba: nem sikerult megnyitni a(z) '%s' fajlt irasra!\n", destination);
            return;
        }
    }
    else
    {
        fp = stdout;
    }

    fprintf(fp, "=== Csomagok listaja (%d db) ===\n", numberOfPackages);
    for (int i = 0; i < numberOfPackages; i++)
    {
        fprintf(fp, "%2d. Nev: %-30s | Suly: %3d kg | Prioritas: %-8s | Torekeny: %s\n",
                i + 1,
                pPackages[i].recipientName,
                pPackages[i].weight,
                getPriorityDescription(pPackages[i].priority),
                pPackages[i].fragile ? "Igen" : "Nem");
    }

    if (toFile)
        fclose(fp);
}

int countExpressPackages(const Package_t *pPackages, int numberOfPackages)
{
    int count = 0;
    for (int i = 0; i < numberOfPackages; i++)
    {
        if (pPackages[i].priority == EXPRESS)
        {
            count++;
        }
    }
    return count;
}

int compareWeights(const void* a , const void* b) {
    Package_t* pa = (Package_t*) a ;
    Package_t* pb = (Package_t*) b ;

    if (pa->weight < pb->weight) return -1;
    if (pa->weight > pb->weight) return  1;
    return 0;

}


void sortPackegesByWeight(Package_t *packages , int numberOfPackages) {
    qsort(packages , numberOfPackages , sizeof(Package_t) , compareWeights) ;
}


int compareNames(const void* a , const void* b) {
    Package_t* pa = (Package_t*) a ;
    Package_t* pb = (Package_t*) b ;

    return strcmp(pa->recipientName , pb->recipientName) ;

}

void sortPackegesBySenderName(Package_t *packages , int numberOfPackages) {
    qsort(packages , numberOfPackages , sizeof(Package_t) , compareNames) ;
}

int main()
{
    Package_t *packages = NULL;
    int numberOfPackages = 0;

    readAllPackagesDetails(&packages, &numberOfPackages, "csomag.txt");
    ///sortPackegesBySenderName(packages , numberOfPackages) ;
    printAllPackages(packages, numberOfPackages, "stdout");

    int expressCount = countExpressPackages(packages, numberOfPackages);
    printf("\nEXPRESS prioritasu csomagok szama: %d\n", expressCount);

    free(packages);
    packages = NULL;

    return 0;
}



