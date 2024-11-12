#include <iostream>
#include "SoloNumeros.h"
#include <vector>

/** Programa que halla el area de un espacio rectangular en sistema imperial y metrico. Ejercicio 7 del libro
Pragmatic Programmers - 57 exercises for programmer */

const double FACT_CONVERSION = 0.09290304;

std::vector<double> menu_info()
{
    //Muestra al usuario un menu para escoger el tipo de unidad de medida: Metrica o Imperial
    //Pide al usuario registrar el ancho y longitud del rectangulo.
    //Devuelve un vector con la unidad de medida y el area de un espacio recatangular.
    std::vector<double> informacion;
    double unidad, ancho, longitud;

    do
    {
        unidad = solo_decimales_o_enteros("Presione 1 (sistema imperial) - 2 (sistema metrico)");
    }while(unidad < 0 or unidad > 2);
    informacion.push_back(unidad);

    do
    {
        longitud = solo_decimales_o_enteros("Ingrese la longitud del espacio");
    }while(longitud <= 0);

    do
    {
        ancho = solo_decimales_o_enteros("Ingrese el ancho del espacio");
    }while(ancho <= 0);

    informacion.push_back(longitud * ancho);

    return informacion;
}

std::vector<double> extraer_area(std::vector<double> informacion)
{
    //Devuelve un vector con la conversion equivalente del area rectangular de un espacio
    //Parametro es un vector con dos datos sistema de medida y el area
    double area_pies, area_metros;
    std::vector<double> resultados;
    std::vector<double>::iterator it;

    for(it = informacion.begin(); it != informacion.end(); it++)
    {
        if(it == informacion.begin() and *it == 1)
        {
            resultados.push_back(*++it);
            resultados.push_back(*it * FACT_CONVERSION);
        }
        else if(it == informacion.begin() and *it == 2)
        {
            resultados.push_back(*it / FACT_CONVERSION);
            resultados.push_back(*++it);
        }
    }

    return resultados;
}

void mostrar_informacion(std::vector<double> info)
{
    //Muestra el area de un espacio rectangular en sistema imperial y metrico
    std::cout << "El espacio tiene un area de " << info[0] << " pies cuadrados" << std::endl;
    std::cout << "El espacio tiene un area de " << info[1] << " metros cuadrados" << std::endl;
}

int main()
{
    std::vector<double> informacion, areas;

    informacion = menu_info();
    areas = extraer_area(informacion);
    mostrar_informacion(areas);

    return 0;
}
