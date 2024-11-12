/**< Prograama que calcula el preciop total de un articulo respecto a los impuestos de venta de cada estado en USA*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "SoloNumeros.h"
#include <bits/stdc++.h>

struct estados
{
    std::string nombre;
    std::string abreviacion;
    double impuesto;
};

estados crearEstado(std::string texto, char separador)
{
    estados state;
    std::string dato = "";
    int contSepar = 0;

    for(int i = 0; i < texto.size(); i++)
    {
        dato += texto[i];
        if(texto[i] == separador)
        {
            if(contSepar == 0)
            {
                state.nombre = dato;
            }
            else if(contSepar == 1)
            {
                state.abreviacion = dato;
            }
            contSepar++;
            dato.clear();
        }
    }
    //Este último toca hacerlo afuera porque siempre va a ver un separador menos que el número de datos: es el dato que sobra
    if(!dato.empty())
    {
        state.impuesto = stod(dato);
    }

    //std::cout << state.nombre << " " << state.abreviacion << " " << state.impuesto << '\n';

    return state;
}

double encontrarImpuestoEstado(std::string &nombreOabreviacion, std::vector<estados> datos)
{
    //Devuelve el impuesto de un determinado estado(argumento nombre o abreviacion)
    //Se convierten las cadenas de texto a minúsculas para permitir que el usuario ingrese el nombre o la abreviación en la forma deseada
    double impuesto = -1;
    std::vector<estados>::iterator it;
    std::string nombreMinuscula, abreviMinuscula;

    //Convertir los nombres y las abreviaciones a minusculas
    transform(nombreOabreviacion.begin(), nombreOabreviacion.end(), nombreOabreviacion.begin(), ::tolower);

    for(it = datos.begin(); it < datos.end(); it++)
    {
        //Quitar el caracter tabulador del final
        it->nombre.erase(it->nombre.begin() + (it->nombre.size() - 1));
        it->abreviacion.erase(it->abreviacion.begin() + (it->abreviacion.size() - 1));

        //Convertir los nombres y las abreviaciones a minusculas
        transform(it->nombre.begin(), it->nombre.end(), it->nombre.begin(), ::tolower);
        nombreMinuscula = it->nombre;
        transform(it->abreviacion.begin(), it->abreviacion.end(), it->abreviacion.begin(), ::tolower);
        abreviMinuscula = it->abreviacion;

        if(nombreMinuscula == nombreOabreviacion || abreviMinuscula == nombreOabreviacion)
        {
            impuesto = it->impuesto;
        }
        //std::cout << it->nombre.size() << it->abreviacion << it->impuesto << '\n';
    }
    return impuesto;
}

std::vector<estados> extraerInfoArchivo(char *nombre)
{
    std::ifstream archivo;
    std::string linea;
    std::vector<estados> lineas;

    archivo.open(nombre);

    if(!archivo.is_open())
    {
        std::cout << "El archivo no se puedo abrir" << '\n';
        exit(1);
    }

    while(!archivo.eof())
    {
        std::getline(archivo, linea);
        lineas.push_back(crearEstado(linea, '\t'));
    }

    archivo.close();

    return lineas;
}

void entradaDatos(double &precio, double &impuesto,std::string &nombreEstado, std::vector<estados> datos)
{
    //Verifica que los datos ingresados por el usuario sean los correctos

    std::cout << "*** Calculadora de Impuestos en Estados Unidos ***" << '\n' << '\n';

    precio = solo_decimales_positivos("Ingrese el total de la orden ");
    while(true)
    {
        std::cout << "Ingrese el nombre o la abreviacion del estado >> ";
        std::cin >> nombreEstado;
        impuesto = encontrarImpuestoEstado(nombreEstado, datos);
        if(impuesto >= 0)
        {
            break;
        }
        else
        {
            std::cout << "Nombre del estado incorrecto." << '\n';
        }
    }

}

double calcularPrecio(double precio, double impuesto)
{
    double total = 0.0;
    total = precio + (precio * impuesto);

    return total;

}

void mostrarFactura(double precio, double impuesto, double total)
{
    std::cout << "El subtotal es $" << precio << std::endl;
    std::cout << "El impuesto es $" << total - precio << std::endl;
    std::cout << "El total es $" << total << std::endl;
}

int main()
{

    std::vector<estados> datos;
    datos = extraerInfoArchivo("salesTax.txt");
    double precio, impuesto, total;
    std::string nombreEstado;

    entradaDatos(precio, impuesto, nombreEstado, datos);
    total = calcularPrecio(precio, impuesto);

    mostrarFactura(precio, impuesto, total);

    return 0;
}
