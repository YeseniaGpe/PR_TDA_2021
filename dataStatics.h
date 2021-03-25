//
//  dataStatics.h
//  
//
//  Created by Samantha Morris 25/03/2021.
//

#ifndef dataStatics_h
#define dataStatics_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

/* Set EXTERN macro: */

#ifndef dataStatics_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif


/* Function prototypes. */

EXTERN float addMatrix (float **Matrix, int *numLines, int *numElements);

EXTERN float calculateMean(float *suma, int *numLines);

EXTERN float calculateMode();

EXTERN float calculateMedian(float *array, int *numLines);

EXTERN float calculateStandardDeviation(float *array, float *mean, int *numLines);

EXTERN float addData(float *arr, int *numLines);

EXTERN void sortArray(float **Matrix, int *numLines, int *numElements, float *array, int postition);

EXTERN void writeCSV(float *mean, float *median, float *mode, float *SD);

EXTERN void createGraph(void);

EXTERN void histogram (float *arr, int *numLines, int position);

EXTERN void Rango(float *array, int *numLineas, float *min, float *max);


#endif /* dataStatics.h */