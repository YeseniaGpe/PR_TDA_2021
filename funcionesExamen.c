//funciones

#include "header.h"

extern FILE *abrirArchivo(char *nombre, char *modo) {
    FILE *fp;
    
    fp= fopen(nombre,modo);

    if(fp =! NULL)
      {
	return fp;
      }
    else
      {
        printf("\nError al abrir el archivo '%s'",nombre);
	return;
      }
}

extern list *leerDatos(list *puntero, FILE *pf)
{
  int i, uno;
  float dos, tres;
  for(i=0;i<=100;i++){
    fscanf(fp, "%d,%f,%f",uno,dos,tres);
    if(uno>=0 && uno<=100){
      puntero->numDato=uno;
      puntero->x=dos;
      puntero->y=tres;
      puntero=puntero->siguiente;
    }
  }
  fclose(fp);
  return;
}



  
