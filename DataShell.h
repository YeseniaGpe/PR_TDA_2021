//
//  DataShell.h
//  
//
//  Created by Samantha Morris 25/03/2021.
//

#ifndef DataShell_h
#define DataShell_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Set EXTERN macro: */

#ifndef DataShell_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif


/* Function prototypes. */


typedef uint8_t BYTE;

EXTERN int NumberLines(char *fileName);
/*
 *
 * The function NumberLines sees how many lines there are in a csv.
 *
 * @params
 *      char *fileName
 *          Name of file
 *
 *       
 * @returns
 *      int
*/

FILE* openMyfile (char *fileName, const char mode);
/*
 *
 * The function openMyfile opens a file.
 *
 * @params
 *      char *fileName
 *          Name of file
 *
 *       
 * @returns
 *      FILE*
*/

void closeMyfile(FILE *file);
/*
 *
 * The function closeMyfile close a file.
 *
 * @params
 *      char *fileName
 *          Name of file
 *
 *       
 * @returns
 *      void
*/

void readDB (float **Matrix, char *fileName, int numElements);
/*
 *
 * The function readDB reads a Data Base.
 *
 * @params
 *      float **Matrix
 *          Matrix where the DB is gonna be store
 *      char *fileName
 *          Name of file
 *      int numElements
 *          Number of elements in a line
 *
 *       
 * @returns
 *      void
*/

int countElements(char *fileName);
/*
 *
 * The function countElements counts the number of elements in a line from a csv.
 *
 * @params
 *      char *fileName
 *          Name of file
 *
 *       
 * @returns
 *      int
*/

void printMatrix (float **Matrix, int *numLines, int *numElements);
/*
 *
 * The function printMatrix prints the matrix that contains all data from a csv file.
 *
 * @params
*      float **Matrix
 *          Matrix where the DB is gonna be store
 *      int numLines
 *          Number of lines in a csv file.
 *      int numElements
 *          Number of elements in a line
 *
 *       
 * @returns
 *      void
*/

void menuOne(char **fileName);
/*
 *
 * The function menuOne asks user for the name of the csv file that wants to open.
 *
 * @params
 *      char *fileName
 *          Name of file
 *
 *       
 * @returns
 *      void
*/

int menuTwo(void);
/*
 *
 * The function menuTwo asks user if he wants to print data.
 *
 * @params
 *      void
 *
 *       
 * @returns
 *      int
*/


#endif /* DataShell.h */