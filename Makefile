# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.

CC = gcc
SRC: ejercicio.c

# Reglas explicitas

all:
	$(CC) ejercicio -o $(SRC)
clean:
	$(RM) $(OBJ) main

# Reglas implicitas

Cola.o: Cola.c Cola.h
Proyecto.o: Proyecto.c Cola.h
ejercicio.c: ejercicio.c
