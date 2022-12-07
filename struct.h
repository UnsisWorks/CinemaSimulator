#include <stdio.h>
#define MAXI 100
struct estructura_pizza{

    char sabor[24];
};

typedef struct estructura_pizza pizza;

struct estructura_libro{
    int ID;
    char cliente[30];
    pizza dat;
    
};

typedef struct estructura_libro libro;