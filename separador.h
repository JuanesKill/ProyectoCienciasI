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
 * @param delim    Las palabras vendrán delimitadas por uno de los 
 *                 caracteres de esta cadena            
 * @param args     Array donde separaremos cada palabra
 * @param max_args Número de palabras como máximo a extraer (tamaño
 *                 del array)
 *
 * @return Número de palabras extraídas. (max_args+1) si en la 
 *         cadena hay más de max_args palabras.
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
    return max_args+1;  /* Si hemos extraído más cadenas que palabras devolvemos */
                /* El número de palabras máximo y salimos */

      strcpy(args[num], tmp);   /* Copiamos la palabra actual en el array */
      num++;

      /* Extraemos la siguiente palabra */
      tmp=strtok(NULL, delim);
    } while (tmp!=NULL);

  return num; 
}

#endif
