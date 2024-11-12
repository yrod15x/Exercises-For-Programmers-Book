#include "madlibs.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

MadLibs::MadLibs()
{
    //ctor
    texto_historia = "Cocinas a tu NON ADJ1 ADV? Eso es ADJ2 !!!";
}

MadLibs::~MadLibs()
{
    //dtor
}

MadLibs::MadLibs(const MadLibs& other)
{
    //copy ctor
    texto_historia = other.texto_historia;
}

void MadLibs::mostrar_historia_inicial()
{
    std::cout << texto_historia << std::endl;
}

//Separo el string en palabras en un vector para luego poder insertar los elementos del usuario en sus correpondientes claves NON ...
void MadLibs::dividir_historia()
{
    std::string texto = "";
    for(int i = 0; i < texto_historia.size(); i++)
    {
        if(texto_historia[i] != ' ')
        {
            texto += texto_historia[i];
        }
        else
        {
            historia_dividida.push_back(texto);
            texto = "";
        }
    }
}

void MadLibs::entrada_datos()
{
    std::string entrada;
    for(int i = 0; i < num_elementos; i++)
    {
        switch (i)
        {
        case 0:
            std::cout << "Ingrese un substantivo >> ";
            std::cin >> entrada;
            elementos_oracion.push_back(entrada);
            break;
        case 1:
            std::cout << "Ingrese un adjetivo >> ";
            std::cin >> entrada;
            elementos_oracion.push_back(entrada);
            break;
        case 2:
            std::cout << "Ingrese un adverbio >> ";
            std::cin >> entrada;
            elementos_oracion.push_back(entrada);
            break;
        case 3:
            std::cout << "Ingrese un adjetivo >> ";
            std::cin >> entrada;
            elementos_oracion.push_back(entrada);
            break;
        default:
            std::cout << "Opcion no valida!!! ";
            break;
        }
        entrada.clear();
    }
}

void MadLibs::mostrar_madlibs()
{
    dividir_historia();
    std::string historia = "";
    int cont = 0;
    std::ofstream archivo;
    archivo.open("historia.txt");

    for(int i = 0; i < historia_dividida.size(); i++)
    {
        if(historia_dividida[i] == "NON")
        {
            historia += elementos_oracion[cont] + " ";
            cont++;
        }
        else if(historia_dividida[i] == "ADJ1")
        {
            historia += elementos_oracion[cont] + " ";
            cont++;
        }
        else if(historia_dividida[i] == "ADV?")
        {
            historia += elementos_oracion[cont] + "? ";
            cont++;
        }
        else if(historia_dividida[i] == "ADJ2")
        {
            historia += elementos_oracion[cont] + " ";
            cont++;
        }
        else
        {
                historia += historia_dividida[i] + " ";
        }
    }
    historia[historia.size() - 1] = '!';
    std::cout << std::endl << historia << std::endl;
    archivo << historia;
    archivo.close();

}


