import io
import os
import random as cold

def main():
    data = open("elements.txt", "w")
    
    limit = 10
    os.system("clear")
    generateLast = ["1"]
    people = ""
    coincidencias = 0
    
    # Base the firts names and seconds names 
    ftName = ["Juan", "Arturo", "Marlen", "Jesus", "Vanessa", "Orlando", "Socorro", "Julian", "Fernanda", "Diana", "Selena", "Ortencia", "Lupita", "Arnold", "Rolando", "Angel", "Noemy", "Sara", "Roberto", "Maribel", "Sury"]
    
    ndName = ["Perez", "Ramirez", "Cantaros", "Flores", "Garcia", "Hernandez", "Dias", "Hipolito", "Gomez", "Rojas", "Ortiz", "Ortega", "Villa Garza", "Bolaños"]
        
    for i in range(limit):
        # Generate name atoi
        firts = cold.randrange(0, len(ftName), 1)
        second = cold.randrange(0, len(ndName), 1)
        
        people = ftName[firts] + " " + ndName[second]
        
        # Comparation name ganetation with names afters
        for name in generateLast:
            # print(f"{name} == {people}: {name == people}")
            if (name == people):
                coincidencias += 1
                break
            
        # Discart or continue
        if(coincidencias == 0):
            print(f"Nombre {i}: {people}")
            data.write(people + " º" + "\n")
            generateLast.append(people)
                
        else:
            print("Repetido\n")
            i -= 2
        coincidencias = 0
    
    print("******* Ingredientes *******")
    size = ["Mediana", "Grande", "Pequeña", "Sarten"]
    ingredientes = ["Peperoni", "Carnes frìas", "Hawayana"]
    
    for i in range(limit):
        firts = cold.randint(0, len(size))
        second = cold.randint(0, len(ingredientes))
        
        print(f"Tamaño: {size[firts]} de: {ingredientes[second]}")

if __name__ == '__main__':
    main()