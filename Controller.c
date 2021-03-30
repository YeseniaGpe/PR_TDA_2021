#include "DataShell.h"
#include "dataStatics.h"

int main (void)
{
    char* fileName=NULL;
    int numLines = 0, numElements;
    int option;
    int flagOption = 0, flagGraph = 0;
    float median, mean, mode, SD;
    float sum;
    float min, max;

    //Calling function to get name
    menuOne(&fileName);

    numLines = NumberLines(fileName); //Calling function to count how many lines
    numElements = countElements(fileName); //Calling function to count elements in line
    

    float **Matrix = malloc(sizeof(float) * numLines * numElements); //Create Matrix
    
    readDB(Matrix, fileName, numElements); //We read the DB and store it in  Matrix

    float arr[numLines];
    float arr2[numLines];
    float arr3[numLines];

    do{
        option = menuTwo(); 

        switch (option)
        {
            case 1: //case print csv
                /* code */
                printMatrix(Matrix, &numLines, &numElements);

                //Wait:
                printf("\nPress [enter] to go back to the menu.\n");
                __fpurge(stdin);
                getchar();
                break;
            case 2: //case calculate data statics
                /* code */
                flagOption = 1;
                sortArray(Matrix, &numLines, &numElements, arr, 1);
                sum = addData(arr, &numLines);
                mean = calculateMean(&sum, &numLines); 
                median = calculateMedian(arr, &numLines);
                mode = calculateMode(arr, &numLines);
                SD = calculateStandardDeviation(arr, &mean, &numLines);
                //Rango(arr, &numLines, &min, &max);

                //Results
                printf("\tData Statics:\n");
                //printf("Sum: %0.6f\n", sum);
                printf("Media: %.6f\n", mean);
                printf("Mediana: %.6f\n", median);
                printf("Moda: %0.6f\n", mode);
                printf("Desviacion Estandar: %0.6f\n", SD);
                //printf("Rango: min. %0.6f, max.%0.6f\n", min, max);
                writeCSV(&mean, &median, &mode, &SD);
                /* code */ 
                printf("Creating graph...\n"); 
                //createGraph();
                histogram(arr, &numLines, 1);
                /*
                for(int i = 0; i < numLines; i ++)
                {
                    printf("%0.6f\n", arr[i]);
                }*/
                //Wait:
                printf("\nPress [enter] to go back to the menu.\n");
                __fpurge(stdin);
                getchar();

                break;
            case 3: //case second column

                /* code */
                sortArray(Matrix, &numLines, &numElements, arr2, 2);
                sum = addData(arr2, &numLines);
                mean = calculateMean(&sum, &numLines); 
                median = calculateMedian(arr2, &numLines);
                mode = calculateMode(arr2, &numLines);
                SD = calculateStandardDeviation(arr2, &mean, &numLines);

                //Results
                printf("\tData Statics:\n");
                //printf("Sum: %0.6f\n", sum);
                printf("Media: %.6f\n", mean);
                printf("Mediana: %.6f\n", median);
                printf("Moda: %0.6f\n", mode);
                printf("Desviacion Estandar: %0.6f\n", SD);
                writeCSV(&mean, &median, &mode, &SD);
                /*for(int i = 0; i < numLines; i ++)
                {
                    printf("%0.6f\n", arr2[i]);
                }*/

                /* code */ 
                printf("Creating graph...\n"); 
                //createGraph();
                histogram(arr2, &numLines, 2);
                //Wait:
                printf("\nPress [enter] to go back to the menu.\n");
                __fpurge(stdin);
                getchar();
                break;
            case 4: //case column 3
                /* code */
                printf("3\n");
                sortArray(Matrix, &numLines, &numElements, arr3, 3);
                sum = addData(arr3, &numLines);
                mean = calculateMean(&sum, &numLines); 
                median = calculateMedian(arr3, &numLines);
                mode = calculateMode(arr3, &numLines);
                SD = calculateStandardDeviation(arr3, &mean, &numLines);

                //Results
                printf("\tData Statics:\n");
                //printf("Sum: %0.6f\n", sum);
                printf("Media: %.6f\n", mean);
                printf("Mediana: %.6f\n", median);
                printf("Moda: %0.6f\n", mode);
                printf("Desviacion Estandar: %0.6f\n", SD);
                writeCSV(&mean, &median, &mode, &SD);

                /*
                for(int i = 0; i < numLines; i ++)
                {
                    printf("%0.6f\n", arr3[i]);
                }*/

                /* code */ 
                printf("Creating graph...\n"); 
                //createGraph();
                histogram(arr3, &numLines, 3);


                //Wait:
                printf("\nPress [enter] to go back to the menu.\n");
                __fpurge(stdin);
                getchar();

                
                break;

            default:
                break;
        }
    }while(option != 5);


    free(Matrix);
    return 0;
}