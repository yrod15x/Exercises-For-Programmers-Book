//Programa que calcula los anios que faltan a una persona para jubilarse en Colombia y Estados Unidos.
//Se usa la libreria ctime para hacer los calculos. De la misma manera, se usa una libreria propia solo
//numeros que verifica la entrada de numeros enteros.

#include <iostream>
#include "SoloNumeros.h"
#include <ctime>
#include <string>
#include <ctype.h>

const int JUBILACION_USA = 66;
const int JUBILACION_COL_MASC = 70;
const int JUBILACION_COL_FEM = 65;

void verificar_dato(char &dato, std::string mensaje1, std::string mensaje2, char car_min_valido1, char car_min_valido2)
{   //Verifica si un dato ingresado cumple con los requisitos para su uso dentro del programa

    std::cout << std::endl << "*** " << mensaje1<<" ***" << std::endl;
    while(true)
    {
        std::cout << mensaje2 << " >> ";
        std::cin >> dato;
        dato = (char)tolower(dato);
        if(dato == car_min_valido1 or dato == car_min_valido2)
        {
            break;
        }
        else
        {
            std::cout << "Dato Invalido !!!" << std::endl;
        }
    }
}

void mostrar_mensaje_pension(int edad_restante, const int ANNIO_JUBILACION, int annio_a_pensionarse)
{
    std::cout << std::endl << "A usted le faltan " << edad_restante << " annios para pensionarse a los " << ANNIO_JUBILACION
            << " en el annio " << annio_a_pensionarse << "." << std::endl;
}

void calcular_annio_jubilacion(int edad, char pais, char genero)
{   //Imprime en pantalla el annio de jubilacion y los annios que le restan a una persona de acuerdo al pais

    //el tipo time_t ayuda a obtener la hora actual de acuerdo al sistema (pc)
    time_t ahora = time(0);
    //tm es una estructura  que permite obtener elementos individuales de la hora y fecha
    //tm toma un objeto,  time_t en este caso la hora y fecha del sistema y lo representa con un puntero
    tm *tiempo = localtime(&ahora);
    //tm devuelve el annio actual en forma de entero desde el annio 1900 -- Hasta 2024 han pasado 124 annios.
    int annio_actual = tiempo->tm_year + 1900;
    int edad_restante = 0, annio_a_pensionarse = 0;

    if(pais == 'e')
    {
        if(edad > JUBILACION_USA)
        {
            std::cout << "Usted ya deberia haberse jubilado" << std::endl;
        }
        else
        {
            edad_restante = JUBILACION_USA - edad;
            annio_a_pensionarse = annio_actual + edad_restante;
            mostrar_mensaje_pension(edad_restante, JUBILACION_USA, annio_a_pensionarse);
        }
    }
    else if(pais == 'c')
    {
        if(genero == 'f')
        {
            if(edad > JUBILACION_COL_FEM)
            {
                std::cout << "Usted ya deberia haberse jubilado" << std::endl;
            }
            else
            {
                edad_restante = JUBILACION_COL_FEM - edad;
                annio_a_pensionarse = annio_actual + edad_restante;
                mostrar_mensaje_pension(edad_restante, JUBILACION_COL_FEM, annio_a_pensionarse);
            }
        }
        else
        {
            if(edad > JUBILACION_COL_MASC)
            {
                std::cout << "Usted ya deberia haberse jubilado" << std::endl;
            }
            else
            {
                edad_restante = JUBILACION_COL_MASC - edad;
                annio_a_pensionarse = annio_actual + edad_restante;
                mostrar_mensaje_pension(edad_restante, JUBILACION_COL_MASC, annio_a_pensionarse);
            }
        }
    }
}

int main()
{
    int edad = solo_enteros_positivos("Ingrese su edad");
    char pais, genero;

    verificar_dato(pais, "Verifiquemos su pais", "Presione C para COlombia --- E para USA", 'c', 'e');
    verificar_dato(genero, "Verifiquemos su genero", "Presione M para Masculino --- F para Femenino", 'm', 'f');
    calcular_annio_jubilacion(edad, pais, genero);

    return 0;
}
