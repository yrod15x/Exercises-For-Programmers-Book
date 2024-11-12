#include "caja.h"
#include <vector>
#include <iostream>
#include "SoloNumeros.h"
#include <ctype.h>

const double IVA = 0.18;

Caja::Caja()
{
    //ctor
    _valorItems.clear();
}

Caja::~Caja()
{
    //dtor
}

Caja::Caja(const Caja& other)
{
    //copy ctor
    _valorItems = other._valorItems;
}

void Caja::ingresarDatos()
{
    char salir = 'n';
    int cantItems = 0;
    double valorUnitario = 0.0;

    while(salir != 's')
    {
        valorUnitario = solo_decimales_o_enteros("Ingrese el valor unitario del producto ");
        cantItems = solo_enteros_positivos("Ingrese la cantidad del producto ");
        _valorItems.push_back(valorUnitario * cantItems);
        std::cout << "Para salir presione s >> ";
        std::cin >> salir;
        salir = (char) tolower(salir);
        std::cin.ignore();
        std::cin.clear();
    }
}

void Caja::_sacarImpuestos()
{
    for(double i:_valorItems)
    {
        _valorSinIva += i;
    }

    _valorImpuesto = _valorSinIva * IVA;
    _valorTotal = _valorSinIva + _valorImpuesto;
}

void Caja::mostrarInfo()
{
    _sacarImpuestos();
    std::cout << "Subtotal >> " << _valorSinIva << std::endl;
    std::cout << "Impuesto >> " << _valorImpuesto << std::endl;
    std::cout << "Total >> " << _valorTotal << std::endl;
}
