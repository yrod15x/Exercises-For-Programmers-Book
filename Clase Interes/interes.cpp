#include "interes.h"
#include <iostream>
#include "SoloNumeros.h"
#include <cmath>

Interes::Interes()
{
    //ctor
    _cantidadInicial = 0.0;
    _tasaInteres = 0.0;
    _tiempoAnnios = 0;
    _numInteresCompuesto = 0;
}

Interes::~Interes()
{
    //dtor
}

Interes::Interes(double cantidadInicial, double tasaInteres, int tiempoAnnios)
{
    setDatosInteresSimple(cantidadInicial, tasaInteres, tiempoAnnios);
}

Interes::Interes(double cantidadInicial, double tasaInteres, int tiempoAnnios, int numInteresCompuesto)
{
    setDatosInteresCompuesto(cantidadInicial, tasaInteres, tiempoAnnios, numInteresCompuesto);
}

Interes::Interes(const Interes& other)
{
    //copy ctor
    _cantidadInicial = other._cantidadInicial;
    _tasaInteres = other._tasaInteres;
    _tiempoAnnios = other._tiempoAnnios;
    _numInteresCompuesto = other._numInteresCompuesto;
}

Interes& Interes::operator=(const Interes& rhs)
{
    if (this == &rhs)
    {
        // handle self assignment
        return *this;
    }
    //assignment operator
    return *this;
}

void Interes::setDatosInteresSimple(double cantidadInicial, double tasaInteres, int tiempoAnnios)
{
    if(cantidadInicial < 0)
    {
        _cantidadInicial = 0.0;
    }
    if(tasaInteres < 0)
    {
        _tasaInteres = 0.0;
    }
    if(tiempoAnnios < 0)
    {
        _tiempoAnnios = 0;
    }
    _cantidadInicial = cantidadInicial;
    _tasaInteres = tasaInteres;
    _tiempoAnnios = tiempoAnnios;
}

void Interes::setDatosInteresCompuesto(double cantidadInicial, double tasaInteres, int tiempoAnnios, int numInteresCompuesto)
{
    if(cantidadInicial < 0)
    {
        _cantidadInicial = 0.0;
    }
    if(tasaInteres < 0)
    {
        _tasaInteres = 0.0;
    }
    if(tiempoAnnios < 0)
    {
        _tiempoAnnios = 0;
    }
    if(numInteresCompuesto < 0)
    {
        _numInteresCompuesto = 0;
    }
    _cantidadInicial = cantidadInicial;
    _tasaInteres = tasaInteres;
    _tiempoAnnios = tiempoAnnios;
    _numInteresCompuesto = numInteresCompuesto;
}

void Interes::calcularInteresSimple()
{
    _cantidadFinal = _cantidadInicial * (1 + _tasaInteres * _tiempoAnnios);
}

void Interes::calcularInteresCompuesto()
{
    _cantidadFinal = _cantidadInicial * pow((1 + (_tasaInteres / _numInteresCompuesto)), _numInteresCompuesto * _tiempoAnnios);
}

void Interes::calculaInteres()
{
    int opcion = 0;

    std::cout << "****************************" << std::endl;
    std::cout << "* Calculadora de Intereses *" << std::endl;
    std::cout << "****************************" << std::endl;
    std::cout << "*                          *" << std::endl;
    std::cout << "*   1. Interes Simple      *" << std::endl;
    std::cout << "*   2. Interes Compuesto   *" << std::endl;
    std::cout << "*                          *" << std::endl;
    std::cout << "****************************" << std::endl;
    std::cout << std::endl;
    opcion = solo_enteros_positivos("Presione el numero de su opcion");

    _cantidadInicial = solo_decimales_positivos("Ingrese la inversion inicial");
    _tasaInteres = solo_decimales_positivos("Ingrese la tasa de interes") / 100;
    _tiempoAnnios = solo_enteros_positivos("Ingrese el numero de anios");
    if(opcion == 1)
    {
        calcularInteresSimple();
        mostrarInteresSimple();
    }
    else if(opcion == 2)
    {
        _numInteresCompuesto = solo_enteros_positivos("Ingrese el numero de veces que el interes es compuesto");
        calcularInteresCompuesto();
        mostrarInteresCompuesto();
    }

}

void Interes::mostrarInteresSimple() const
{
    std::cout << "Despues de " << _tiempoAnnios << " annios, a una tasa de " << _tasaInteres * 100 <<
    ", la inversion final sera de $" << _cantidadFinal  << std::endl;
}

void Interes::mostrarInteresCompuesto() const
{
    std::cout << _cantidadInicial << " invertidos a una tasa de " << _tasaInteres * 100 << " por cada " <<
      _tiempoAnnios << " annios, con interes compuesto " << _numInteresCompuesto << " veces por annio es de $" <<
      _cantidadFinal  << std::endl;
}
