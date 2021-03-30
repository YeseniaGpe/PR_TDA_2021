#include "DataShell.h"

/*
void read (float *arr1, float *arr2, floar *arr3)
{
    
    char buff[255];
    char * value;
    float *ptr = NULL;
    int cont = 0, n =0;
    int flag =0;

    FILE *file = openMyfile(fileName, 'r');

    while(!feof(file))
    {
        fscanf(file, "%s", buff);
        value = strtok(buff, ",");

        while(value != NULL)
        {
            ptr[cont] = atof(value); //Stores value into ptr 
            cont ++;
            value = strtok(NULL, ",");
        }

        if(flag == 0)
        {
            //free(ptr);
            flag = 1;
        }
        else
        {
            Matrix[n] = ptr; //Matrix now points to ptr
            n ++;
        }
        cont = 0;
        

    }
    closeMyfile(file);

}*/
//Function that prints a Matrix
void printMatrix (float **Matrix, int *numLines, int *numElements)
{
    for(int i = 0; i < *numLines; i++)
    {
        for(int j = 0; j < *numElements; j ++)
        {
            printf("%.6f ", *((*(Matrix+i))+j));
        }
        printf("\n");
    }
}

//Function that reads DB and stores it in a Matrix
void readDB (float **Matrix, char *fileName, int numElements)
{
    char buff[255];
    char * value;
    float *ptr = NULL;
    int cont = 0, n =0;
    int flag =0;

    FILE *file = openMyfile(fileName, 'r');

    while(!feof(file))
    {
        fscanf(file, "%s", buff);

        //numElements = countElements(buff);
        float *ptr = malloc(sizeof(float) * numElements);
        value = strtok(buff, ",");

        while(value != NULL)
        {
            ptr[cont] = atof(value); //Stores value into ptr 
            cont ++;
            value = strtok(NULL, ",");
        }

        if(flag == 0)
        {
            //free(ptr);
            flag = 1;
        }
        else
        {
            Matrix[n] = ptr; //Matrix now points to ptr
            n ++;
        }
        cont = 0;
        

    }
    closeMyfile(file);

    return;
}

//Function that tells how many elements does a csv line has
int countElements(char *fileName)
{
    int numElements = 1;
    char buff[255];

    FILE *file = openMyfile(fileName, 'r');
    fscanf(file, "%s", buff);
    char* value = strtok(buff, ",");

    while(value != NULL)
    {
        numElements ++;
        value = strtok(NULL, ",");
    }
    //printf("num = %d ", numElements);
    closeMyfile(file);
    return numElements;
}

//Function that opens a file
FILE* openMyfile (char *fileName, const char mode)
{
    FILE *file = fopen(fileName, &mode);

    if(file == NULL)
    {
        printf("Couln´t open file\n");
        exit(0);
    }
    return file;
}

//Function that closes a file
void closeMyfile(FILE *file)
{
    fclose(file);
}

//Function that return number of lines
int NumberLines(char *fileName)
{
    int numLines = -2;
    char buff[255];

    FILE *file = openMyfile(fileName, 'r');

    while(!feof(file))
    {
        fscanf(file, "%s", buff);
        numLines ++;
    }

    closeMyfile(file);

    return numLines;
}


