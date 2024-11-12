/* Programa 8 del libro Pragmatic Programmer 57 exercises. Determinar las rebanadas de pizza que reciben las personas de
acuerdo un numero determinado de pizzas. Se pide la informacion al usuario: numero de usuarios, numero de pizzas y como
opcional un numero de rebanas especificas */

#include <iostream>
#include "SoloNumeros.h"
#include <string>

void entradaDatos(int &numUsuarios, int &numPizzas, int &numRebandas)
{
    while(true)
    {
        numUsuarios = solo_enteros_positivos("Ingrese la cantidad de personas");
        numPizzas = solo_enteros_positivos("Ingrese la cantidad de pizzas");
        std::cout << "Si no sabe el numero de rebandas exactas, digite 1 Se tomaran 8 por defecto. \n";
        numRebandas = solo_enteros_positivos("Ingrese las rebanadas por pizza");
        if(numRebandas == 1)
        {
            numRebandas = 8;
        }
        if((numPizzas * numRebandas / numUsuarios > 0))
        {
            break;
        }
        else
        {
            std::cout << "El numero de rebandas o de pizzas no es suficiente para el numero de usuarios." << std::endl;
        }
    }

    std::cout << std::endl;
}

int *contarRebanas(int numUsuarios, int numPizzas, int numRebanadas = 8)
{
    int *rebanas = new int[2];
    int totalRebanadas = numPizzas * numRebanadas;

    rebanas[0] = totalRebanadas / numUsuarios;
    rebanas[1] = totalRebanadas % numUsuarios;

    return rebanas;
}

const void mostrarInformacion(int *resultados)
{
    std::string plural = "";
    std::cout << std::endl;

    if(resultados[0] <= 0)
    {
        std::cout << "El numero de rebandas escogidas no es sufieciente." << std::endl;
    }
    else
    {
        if(resultados[0] > 1)
        {
            plural = "s";
        }
        std::cout << "Cada usuario debe recibir al menos " << resultados[0] << " rebanada" << plural << " de pizza." << std::endl;
        if(resultados[1] == 1)
        {
            plural = "";
        }
        else
        {
            plural = "s";
        }
        std::cout << resultados[1]  << " rebanada" << plural << " de pizza quedan sobrando" << std::endl;
    }
}

int main()
{
    int numUsuarios, numPizzas, numRebanadas;
    int *resultados;

    entradaDatos(numUsuarios, numPizzas, numRebanadas);
    resultados = contarRebanas(numUsuarios, numPizzas, numRebanadas);
    mostrarInformacion(resultados);

    delete resultados;

    return 0;
}
