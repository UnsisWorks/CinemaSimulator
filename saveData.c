/******************************************************************************

Jose Angel Marquez Espina
*******************************************************************************/
#include <stdio.h>
#include "struct.h"

int menu (void);
void registrarCliente (libro[], int *);
void imprimirDatosCliente (libro[], int);
libro leerDatos ();
void repoPizza();
void cargar();
void guardar(libro dato);
libro libros[MAXI];
libro dato;
int contador_libros = 0;
int C=0;
int init () {
    int opc;


    cargar();
    imprimirDatosCliente (libros, contador_libros);
    do {
        opc = menu ();
        switch (opc) {
            case 1:
                registrarCliente (libros, &contador_libros);
                break;
            case 2:
                repoPizza();
                guardar( dato);
                break;
            case 3:
                printf ("Salir... \n");
                break;
            default:
                printf ("Opción no válida \n");
        }
    }
  while (opc != 3);

  return 0;
}

int menu () {
    int op;
    printf ("\n\n----Menú: principal----\n\n");
    printf ("1.- Registrar Pedidos\n");
    printf ("2.- Mostrar datos\n");
    printf ("3.- Salir\n\n");
    printf ("Seleccione una opción: ");
    scanf ("%d", &op);
    return op;
}

void registrarCliente (libro lib[], int *cont) {
    libro ejemplar,l;
    char resp;
    printf("---Registro de Pedidos---\n\n");
    do {
        ejemplar = leerDatos ();
        lib[*cont] = ejemplar;
        (*cont)++;// *cont=(*cont)+1;
        guardar(ejemplar);
        printf ("\n ¿Desea capturar otro Pedido S/N? ");
        scanf ("\n%c", &resp);
    } while (resp == 's' || resp == 'S');
}

libro leerDatos () {
    libro dato_libro;

    C++;
    printf ("Número de cliente: %d\n",C);
    //scanf ("%d\n",&dato_libro.ID);
    printf ("Nombre del cliente: ");
    scanf ("\n%[^\n]", dato_libro.cliente);
    printf ("Sabor: ");
    scanf ("\n%[^\n]",dato_libro.dat.sabor);

    return dato_libro;
}

void imprimirDatosCliente (libro libros[], int cont) {
    int i;
    printf ("cont=%d",cont);
    printf("\n");
    printf ("------------------------------------------------------------------------------------\n");
    for (i = 0; i < 3; i++)
        printf ("%s\t%s\n",libros[i].cliente,libros[i].dat.sabor);
    printf("i: %d\n", i);
    printf ("-------------------------------------------------------------------------------------\n");
}


void repoPizza() {
    int i;

    FILE *archivo;
    archivo = fopen("ReportePorMateria.txt", "w");

    if(archivo != NULL){        
        fprintf(archivo, "%ls",&contador_libros);
        fclose(archivo);

    } else {
        puts("No se pudo abrir el archivo");
    }
}


// Funcion que carga los datos existentes.
void cargar() {

    FILE *archivo;
    archivo = fopen("data.dat", "rb");

    if (archivo != NULL) {

        // Llenar el arreglo con los alunmos previamente guardados
        for(int i = 0; i < 100; i++) {
            if(feof(archivo)){
                printf("i: %d Salir\n", i);
                break;
            }
            fread(&libros[i], sizeof(libro), 1, archivo);
        }
    }
}

void guardar(libro dato){

    FILE *archivo;

    archivo = fopen("data.dat", "ab+");

    if (archivo != NULL){

        // Escribir sobre el archivo binario
        fwrite(&dato, sizeof(libro), 1, archivo);
        fclose(archivo);
        imprimirDatosCliente (libros, contador_libros);

    } else {
        puts("Error al abrir el archivo :/");
    }
    
}

