#include <stdio.h>
#include <string.h>

typedef enum {
    FOLYOSZAMLA = 0 ,
    MEGTAKARITASI_SZAMLA = 1 ,
    HITELSZAMLA = 2 ,
    EGYEB = 3
} AccountType ;

typedef struct {
    int accountNumber ;
    char ownerName[100] ;
    double balance ;
    AccountType accountType ;
} BankAccount ;

const char* accountTypeToString(AccountType type) {
    switch (type) {
        case FOLYOSZAMLA:          return "Folyoszamla" ;
        case MEGTAKARITASI_SZAMLA: return "Megtakaritasi szamla" ;
        case HITELSZAMLA:          return "Hitelszamla" ;
        case EGYEB:                return "Egyeb" ;
        default:                   return "Ismeretlen" ;
    }
}

void readBankAccountDetails(BankAccount *pAccount) {
    printf("Szamlaszam: ") ;
    scanf("%d" , &pAccount->accountNumber) ;

    printf("Tulajdonos neve: ") ;
    scanf(" %[^\n]" , pAccount->ownerName) ;

    printf("Egyenleg: ") ;
    scanf("%lf" , &pAccount->balance) ;

    printf("Szamla tipusa (0=Folyoszamla, 1=Megtakaritasi, 2=Hitelszamla, 3=Egyeb): ") ;
    int type ;
    scanf("%d" , &type) ;
    pAccount->accountType = (AccountType)type ;
}

void printBankAccount(BankAccount account) {

    printf("\nSzamlaszam    : %d\n" , account.accountNumber) ;
    printf("Tulajdonos    : %s\n" , account.ownerName) ;
    printf("Egyenleg      : %.2f Ft\n" , account.balance) ;
    printf("Szamla tipusa : %s\n" , accountTypeToString(account.accountType)) ;
}

int readBankAccountFromFile(BankAccount *pAccount , const char *filename) {
    FILE *fp = fopen(filename , "r") ;
    if (fp == NULL) {
        printf("Hiba: A fajl nem nyithato meg: %s\n" , filename) ;
        return 0 ;
    }

    char firstName[50] , lastName[50] ;
    int type ;
    if (fscanf(fp , "%d %49s %49s %lf %d" ,
               &pAccount->accountNumber ,
               firstName ,
               lastName ,
               &pAccount->balance ,
               &type) != 5) {
        printf("Hiba: A fajl formatum nem megfelelo.\n") ;
        fclose(fp) ;
        return 0 ;
    }
    snprintf(pAccount->ownerName , sizeof(pAccount->ownerName) , "%s %s" , firstName , lastName) ;
    pAccount->accountType = (AccountType)type ;

    fclose(fp) ;
    return 1 ;
}

int main() {
    BankAccount account1 ;
    account1.accountNumber = 1001 ;
    strcpy(account1.ownerName , "Kiss Peter") ;
    account1.balance = 250000.00 ;
    account1.accountType = FOLYOSZAMLA ;
    printBankAccount(account1) ;

    BankAccount account2 ;
    readBankAccountDetails(&account2) ;
    printBankAccount(account2) ;

    BankAccount account3 ;
    if (readBankAccountFromFile(&account3 , "account.txt")) {
        printBankAccount(account3) ;
    }

    return 0 ;
}