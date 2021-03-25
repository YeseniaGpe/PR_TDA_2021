#include "DataShell.h"
#include "dataStatics.h"

float addMatrix (float **Matrix, int *numLines, int *numElements)
{
    float add;
    for(int i = 0; i < *numLines; i++)
    {
        add = add + *((*(Matrix+i))+(*numElements - 1));
        //printf("%0.6f\n", add);
        //printf("%.6f  %d\n", *((*(Matrix+i))+(*numElements - 1)), i);
    }
    printf("%0.6f\n", add);
    return add;
}

float addData (float *arr, int *numLines)
{
    float add;
    for(int i = 0; i < *numLines; i++)
    {
        add = add + arr[i];
    }
    return add;
}

float calculateMean(float *suma, int *numLines) //Media
{
    //printf("Suma= %0.6f, numLines= %d ", *suma, *numLines);
    //printf("%.6f\n", (*suma / *numLines));
    return (*suma / *numLines);
}

float calculateMode (float *myArray, int *numLines)
{
    float maxValue = 0;
    int maxCount = 0;
    int count;

   for (int i = 0; i < *numLines; i++) {
      count = 0;
      
      for (int j = 0; j < *numLines; ++j) 
      {
         if (myArray[j] == myArray[i]){
             count ++;
         }
      }
      
      if (count > maxCount) {
         maxCount = count;
         maxValue = myArray[i];
         //printf("%0.6f, %d\n", maxValue, count);
      }
   }

   return maxValue;
}

float calculateMedian(float *array, int *numLines)
{   
    float median = 0;
    // if number of elements are even
    if(*numLines%2 == 0)
        median = array[*numLines/2];
    // if number of elements are odd
    else
        median = array[*numLines/2];
    
    return median;
}

float calculateStandardDeviation(float *array, float *mean, int *numLines)
{
    float SD;
    for (int i = 0; i < *numLines; i++)
    {
        SD += pow(array[i] - *mean, 2);
    }
    return sqrt(SD / *numLines);
}

void sortArray(float **Matrix, int *numLines, int *numElements, float *array, int postition)
{
    float swap;

    if(postition == 1)
    {
        for(int i = 0; i < *numLines; i++)
        {
            //array[i] = *((*(Matrix+i))+(0));
            array[i] = Matrix[i][0];
        }
    }

    if(postition == 2)
    {
        for(int i = 0; i < *numLines; i++)
        {
            array[i] = Matrix[i][1];
        }
    }

    if(postition == 3)
    {
        for(int i = 0; i < *numLines; i++)
        {
            array[i] = Matrix[i][2];
        }
    }

    

    //Sort array
    for (int c = 0 ; c < *numLines - 1; c++)
    {
        for (int d = 0 ; d < *numLines - c - 1; d++)
        {
            if (array[d] > array[d+1]) /* For decreasing order use '<' instead of '>' */
            {
                swap       = array[d];
                array[d]   = array[d+1];
                array[d+1] = swap;
            }
        }
    }
    
    /*
    for(int i = 0; i < *numLines; i ++)
    {
        printf("%.6f \n", array[i]);
    }*/
}

void writeCSV(float *mean, float *median, float *mode, float *SD)
{

    printf("Writing in: DataStatics.csv ...\n");
    FILE *file = openMyfile("DataStatics.csv", 'w');
    fprintf(file, "Mean,%0.8f\n", *mean);
    fprintf(file, "Median,%0.8f\n", *median);
    fprintf(file, "Mode,%0.8f\n", *mode);
    fprintf(file, "Standard Daviation,%0.8f\n", *SD);
    closeMyfile(file);
}

void createGraph(void)
{
    printf("Creating image Graph as graphDataStatics.png .\n");
    char *fin = "DataStatics.csv";
    char *fout = "graphDataStatics.png";
    FILE * ventanaGnuplot = popen ("gnuplot", "w");
    // Executing gnuplot commands one by one
    fprintf(ventanaGnuplot, "set term png\n");
    fprintf(ventanaGnuplot, "set title \"Data Statics By: Samantha :)\"\n");
    fprintf(ventanaGnuplot, "set autoscale\n");
    fprintf(ventanaGnuplot, "set out \"%s\"\n", fout);
    fprintf(ventanaGnuplot, "plot \"%s\"\n", fin);
    fprintf(ventanaGnuplot, "set out\n");
    fclose(ventanaGnuplot);
}

void histogram (float *arr, int *numLines, int position)
{
    float MAX = arr[*numLines - 1];
    int range1 = 0;
    int range2 = 0;
    int range3 = 0;
    int range4 = 0;
    int range5 = 0;
    int NUM = 3;

    //separate into ranges
    for(int i = 0; i < *numLines; i ++)
    {
        if(arr[i] >= 0 && arr[i] < (MAX/NUM))
            range1 ++;
        if(arr[i] >= (MAX/NUM) && arr[i] < 2*(MAX/NUM))
            range2 ++;
        if(arr[i] >= 2*(MAX/NUM) && arr[i] < 3*(MAX/NUM))
            range3 ++; 
        if(arr[i] >= 3*(MAX/NUM) && arr[i] < 4*(MAX/NUM))
            range4 ++;
        if(arr[i] >= 4*(MAX/NUM) && arr[i] <= 5*(MAX/NUM))
            range5 ++; 
    }

    //Write in file
    FILE *file;
    if(position == 1)
    {
        file = openMyfile("Histogram.csv", 'w');
    }
    else if(position == 2)
    {
        file = openMyfile("Histogram2.csv", 'w');
    }
    else{
        file = openMyfile("Histogram3.csv", 'w');
    }

    fprintf(file,"1,%d\n", range1);
    fprintf(file,"2,%d\n", range2);
    fprintf(file,"3,%d\n", range3);
    fprintf(file,"4,%d\n", range4);
    fprintf(file,"5,%d\n", range5);

    closeMyfile(file);

    //Plot
    printf("Creating image Histogram Graph as Histogram.png .\n");
    char *fin = "Histogram.csv";
    char *fout = "Histogram.png";
    FILE * ventanaGnuplot = popen ("gnuplot", "w");
    // Executing gnuplot commands one by one
    fprintf(ventanaGnuplot, "set term png\n");
    fprintf(ventanaGnuplot, "set title \"Histogram By: Samantha :)\"\n");
    fprintf(ventanaGnuplot, "set out \"%s\"\n", fout);
    fprintf(ventanaGnuplot, "set style data histograms\n");
    fprintf(ventanaGnuplot, "set style fill solid 1-0 border -1\n");
    fprintf(ventanaGnuplot, "set xrange [0:%d]\n", (int)round(MAX));
    fprintf(ventanaGnuplot, "set yrange [0:%d]\n", (int)round(MAX));
    fprintf(ventanaGnuplot, "plot \"%s\"\n", fin);
    fprintf(ventanaGnuplot, "set out\n");

    fclose(ventanaGnuplot);
}

void Rango(float *array, int *numLineas, float *min, float *max)
{
    *max = array[*numLineas];
    *min = array[0];
}