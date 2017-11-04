#ifndef SEPARADOR_H     
#define SEPARADOR_H  

#include <string.h>
#include <stdlib.h>
#define MAX_CADENA 100

/**
 ******************************************************************
 * @brief Extrae palabras de una cadena y las coloca en un array
 *
 * @param orig     Cadena inicial
 * @param delim    Las palabras vendr�n delimitadas por uno de los 
 *                 caracteres de esta cadena            
 * @param args     Array donde separaremos cada palabra
 * @param max_args N�mero de palabras como m�ximo a extraer (tama�o
 *                 del array)
 *
 * @return N�mero de palabras extra�das. (max_args+1) si en la 
 *         cadena hay m�s de max_args palabras.
 *
 ******************************************************************/
int extrae_argumentos(char *orig, char *delim, char args[][MAX_CADENA], int max_args)
{
  char *tmp;
  int num=0;
  /* Reservamos memoria para copiar la candena ... pero la memoria justa */
  char *str = malloc(strlen(orig)+1);
  strcpy(str, orig);

  /* Extraemos la primera palabra */
  tmp=strtok(str, delim);
  do
    {
      if (num==max_args)
    return max_args+1;  /* Si hemos extra�do m�s cadenas que palabras devolvemos */
                /* El n�mero de palabras m�ximo y salimos */

      strcpy(args[num], tmp);   /* Copiamos la palabra actual en el array */
      num++;

      /* Extraemos la siguiente palabra */
      tmp=strtok(NULL, delim);
    } while (tmp!=NULL);

  return num; 
}

#endif
