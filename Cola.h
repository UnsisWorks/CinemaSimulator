/*
 * Cola.h
 * Por: Dr. Víctor Alberto Gómez Pérez
 * Universidad de la Sierra Sur
 */

#include <stdio.h>
# define MAX 100


typedef struct
{
   int Arreglo[MAX];
   int Frente;
   int Final;
} Cola;

void Crear_Cola (Cola *c);
void Insertar (Cola *c, int e);
int Eliminar (Cola *c);
int Cola_Vacia(Cola *c);
int Cola_Llena(Cola *c);
int Frente (Cola *c);


