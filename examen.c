//principal

#include "header.h"

int main (int argc, char *argv[])
{
  listado *lista=NULL;
  datos datosArchivo;
  
  abrirArchivo("data.csv","r");
  lista=anadirDatos(&datosArchivo,lista);
  
  return 0;
}
