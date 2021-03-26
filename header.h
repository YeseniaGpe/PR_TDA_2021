//header.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datosCSV {
  int numDato;
  float x;
  float y;
};
typedef struct datosCSV datos;


struct listado{
  int numDat;
  float equis;
  float ye;
  struct listado *siguiente;
};
typedef struct listado list;
