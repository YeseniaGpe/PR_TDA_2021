/*#include "DataShell.h"
#include "dataStatics.h"

void Rango(float *array, int *numLineas, int *min, int *max)
{
    *max = array[*numLineas];
    *min = array[0];
}

void DistanciaIntercuantil(float *arr, int *numLineas)
{
    float maxValue = 0;
    int maxCount = 0;
    int count[*numLines];

    for(int l = 0; l < *numLines; l++)
    {
        count[l] = 0;
    }

   for (int i = 0; i < *numLines; i++) {
      count = 0;
      
      for (int j = 0; j < *numLines; ++j) 
      {
         if (myArray[j] == myArray[i]){
             count[i] ++;
         }
      }
      
      if (count > maxCount) {
         maxCount = count;
         maxValue = myArray[i];
         //printf("%0.6f, %d\n", maxValue, count);
      }
   }

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

   return maxValue;
}
*/