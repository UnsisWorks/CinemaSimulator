/*
 * Cola.c
 * Por: Dr. Víctor Alberto Gómez Pérez
 * Universidad de la Sierra Sur
 */


#include <stdio.h>
#include "Cola.h"


void Crear_Cola(Cola *c)
{
	c->Frente=-1;
	c->Final=-1;
}

void Insertar(Cola *c, int e)
{
	if(Cola_Llena(c))
	   printf ("Cola LLena\n");
	else
	{
	    c->Final++;
	    c->Arreglo[c->Final]=e;
	} 
}

int Eliminar(Cola *c)
{
	if (Cola_Vacia(c))
	  {
	   printf ("Cola Vacia\n");
	   return -9999;
	  }	
	else 
            { 	
             c->Frente++;
             return c->Arreglo[c->Frente];
            }
}

int Cola_Vacia(Cola *c)
{
	if ((c->Final == c->Frente))
		return 1;
	else
		return 0;
}

int Cola_Llena (Cola *c)
{
	if (c->Final==MAX-1)
		return 1;
	else
		return 0;
}

int Frente (Cola *c)
{
		if (Cola_Vacia(c))
		{
			printf("Cola Vacia\n");
			return -9999;
		}
		else
			return c->Arreglo[(c->Frente+1)];
}

