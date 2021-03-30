#include "DataShell.h"

void menuOne(char **fileName)
{
    system("clear");
    printf("Hi! :)\n");
    printf("Name of File you want to open: ");
    scanf("%m[^\n]", fileName); //Reads until it finds a \n
    printf("Reading from: %s...\n", *fileName);
}

int menuTwo(void)
{
    int option;
    
    system("clear");
    printf("\nWhat do you wanna do?\n[1] Print data in terminal. \n[2] Calculate Data Statics of first column.\n[3] Calculate Data Statics of second column.\n[4] Calculate Data Statics of third column.\n[5] Exit.\nAnswer: ");
    scanf("%d", &option);
    printf("\n");
    system("clear");
    return(option);
}