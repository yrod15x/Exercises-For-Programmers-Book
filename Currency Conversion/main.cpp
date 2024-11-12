#include <iostream>
#include "SoloNumeros.h"


void entrada(double &cantConvertir, double &tasaCambio, std::string monedaConvertir)
{
    cantConvertir = solo_decimales_o_enteros("Ingrese la cantidad de " + monedaConvertir + " a convertir");
    tasaCambio = solo_decimales_o_enteros("Ingrese la tasa de cambio");
}

double convertirEuroDolar(double cantConvertir, double tasaCambio)
{
    return (cantConvertir * tasaCambio);
}

void mostrarInfo(double cantConvertir, double tasaCambio, double dineroConvertido, std::string monedaCambiar, std::string monedaProducida)
{
    std::cout << cantConvertir << " " << monedaCambiar << " a una tasa de cambio de " << tasaCambio << " son "
    << dineroConvertido << " " << monedaProducida << std::endl;
}

int main()
{
    double cantConvertir, tasaCambio, dineroConvertido;

    entrada(cantConvertir, tasaCambio, "euros");
    dineroConvertido =  convertirEuroDolar(cantConvertir, tasaCambio);
    mostrarInfo(cantConvertir, tasaCambio, dineroConvertido, "euros" , "dolares");

    return 0;
}
