import io
import os
import random as cold

def main():
    data = open("elements.txt", "w")
    limit = 25
    os.system("clear")
    generateLast = ["1"]
    people = ""
    coincidencias = 0
    
    # Base the firts names and seconds names 
    ftName = ["Juan", "Arturo", "Marlen", "Jesus", "Vanessa", "Orlando", "Socorro", "Julian", "Fernanda", "Diana", "Selena", "Ortencia", "Lupita", "Arnold", "Rolando", "Angel", "Noemy", "Sara", "Roberto", "Maribel", "Sury"]
    
    ndName = ["Perez", "Ramirez", "Cantaros", "Flores", "Garcia", "Hernandez", "Dias", "Hipolito", "Gomez", "Rojas", "Ortiz", "Ortega", "Villa Garza", "Bolaños"]
    
    size = ["Mediana", "Grande", "Pequeña", "Sarten", "Familiar", "Rebanada"]
    ingredientes = ["Peperoni", "Carnes frìas", "Hawayana"]
        
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
            data.write(people + "\n")
            generateLast.append(people)
                
        else:
            print("Repetido\n")
            i -= 2
        coincidencias = 0
    
    print("******* Ingredientes *******")
    data.write("\nº\n\n")
    
    for i in range(limit):
        
        ftIng = cold.randrange(0, len(size), 1)
        ndIng = cold.randrange(0, len(ingredientes), 1)
        
        print(f"Tamaño: {size[ftIng]} de: {ingredientes[ndIng]}")
        data.write(size[ftIng] + " " + ingredientes[ndIng] + "\n")
        
    data.close()
   
if __name__ == '__main__':
    main()