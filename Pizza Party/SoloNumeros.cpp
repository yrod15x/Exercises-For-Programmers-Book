#include <iostream>
#include <vector>
#include <string>
#include "SoloNumeros.h"


int solo_enteros(std::string mensaje)
{
    int entero = 0;
    std::string entrada;
    bool suiche = false;

    while(!suiche)
    {
        std::cout << mensaje << " >> ";
        getline(std::cin, entrada);
        for(int i = 0; i < entrada.size(); i++)
        {
            if(i == 0 and entrada[i] == '-')
            {
                continue;
            }

            if(entrada[i] == '0' and i == 0)
            {
                return 0;
            }
            if(entrada[i] == ' ')
            {
                std::cout << "El dato de entrada tiene un espacio." << std::endl;
                break;
            }
            if(int(entrada[i]) < 48 or int(entrada[i] > 57))
            {
                std::cout << "El dato de entrada tiene un carcater que no es un digito." << std::endl;
                break;
            }
            if(i == entrada.size() -1)
            {
                    suiche = true;
            }
        }
    }

    entero = stoi(entrada);

    return entero;
}

int solo_enteros_positivos(std::string mensaje)
{
    int entero = 0;
    std::string entrada;
    bool suiche = false;

    while(!suiche)
    {
        std::cout << mensaje << " >> ";
        getline(std::cin, entrada);
        for(int i = 0; i < entrada.size(); i++)
        {
            if(entrada[i] == '0' and i == 0)
            {
                std::cout << "El primer digito no puede ser 0." << std::endl;
                break;
            }

            if(entrada[i] == '-' and i == 0)
            {
                std::cout << "El dato no puede ser un numero negativo." << std::endl;
                break;
            }
            if(int(entrada[i]) < 48 or int(entrada[i] > 57))
            {
                std::cout << "El dato de entrada tiene un carcater que no es un digito." << std::endl;
                break;
            }
            if(i == entrada.size() -1)
            {
                    suiche = true;
            }
        }
    }

    int factor = 1;
    for(int i = 0; i < entrada.size() - 1; i++)
    {
        factor *= 10;
    }

    for(int i = 0; i < entrada.size(); i++)
    {
        entero += (int(entrada[i]) - 48) * factor;
        factor /= 10;
    }

    return entero;
}

double solo_decimales_o_enteros(std::string mensaje)
{
    double dec_entero = 0;
    std::string entrada;
    bool suiche = false;
    bool negativo = false;

    while(!suiche)
    {
        std::cout << mensaje << " >> ";
        getline(std::cin, entrada);
        for(int i = 0; i < entrada.size(); i++)
        {
            if(i == 0 and entrada[i] == '-')
            {
                continue;
            }
            if(entrada[i] == ' ')
            {
                std::cout << "El dato de entrada tiene un espacio." << std::endl;
                break;
            }
            if((int(entrada[i]) < 48 or int(entrada[i] > 57)))
            {
                if(entrada[i] == '.' and i < entrada.size() - 1)
                {
                    continue;
                }
                else
                {
                    std::cout << "El dato de entrada tiene un carcater que no es un digito." << std::endl;
                    break;
                }
            }
            if(i == entrada.size() -1)
            {
                    suiche = true;
            }
        }
    }

    dec_entero = std::stod(entrada);
    return dec_entero;
}
