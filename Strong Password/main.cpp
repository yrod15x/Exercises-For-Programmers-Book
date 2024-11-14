/** Ejercicio 15 del libro Exercises for programmers (57 Challenges to develop your skills)
Validador de contraseña. Verifica que tenga cierto tamaño, numeros no consecutivos,
caracteres especiales
 */

#include <iostream>
#include <string>
#include <windows.h>

const int TAMMINIMO = 8;
const int TAMMAXIMO = 16;

bool verificarTamano(std::string contrasena)
{
    if(contrasena.size() < TAMMINIMO || contrasena.size() > TAMMAXIMO)
    {
        std::cout << "La contrasena debe tener de 8 a 16 caracteres.\n";
        return false;
    }
    return true;
}

bool verificarNums_CarEspecial(std::string contrasena)
{
    int contNums = 0;
    int contEspec = 0;
    int contMayus = 0;
    //Para convertir de un string a ascii se debe usar una variable tipo char
    char car;

    for(int i = 0; i < contrasena.size(); i++)
    {
        car = contrasena[i];
        if(int(car) >= 48 && int(car) <= 57)
        {
            contNums++;
        }
        if(int(car) >= 65 && int(car) <= 90)
        {
            contMayus++;
        }
        if((int(car) >= 33 && int(car) <= 47)
           || (int(car) >= 58 && int(car) <= 64)
           || (int(car) >= 91 && int(car) <= 96)
           || (int(car) >= 123 && int(car) <= 126))
        {
            contEspec++;
        }
    }
    if(contEspec == 0 || contNums == 0 || contMayus == 0)
    {
        std::cout << "Se debe tener al menos un numero, una mayuscula y un caracter especial.\n";
        return false;
    }
    if(contEspec + contNums > static_cast<int>(contrasena.size() / 2))
    {
        std::cout << "No puede haber mas numeros y/o caracteres especiales que letras.\n";
        return false;
    }
    return true;
}

bool verificarConsecutivos(std::string contrasena, int numConsecutivos)
{
    //No tenga mas de tres números consecutivos
    int nums[numConsecutivos];
    int contConsec = 0, nums_consec = 1;
    char car;

    for(int i = 0; i < contrasena.size() - numConsecutivos; i++)
    {
        car = contrasena[i];

        if(int(car) >= 48 && int(car) <= 57)
        {
            nums[contConsec] = int(car) - 48;
            contConsec++;
        }
    }

    for(int i = 0; i < contConsec - 1; i++)
    {
        if(nums[i] == nums[i+1] - 1)
        {
            nums_consec++;
            if(nums_consec == numConsecutivos)
            {
                std::cout << "La contrasena no puede tener " << numConsecutivos <<
                " digitos consecutivos.\n";
                return false;
            }
        }
        else
        {
            nums_consec = 1;
        }
    }
    return true;
}

void entradaDatos(std::string &contrasena)
{
   while(true)
   {
       //Estas 4 lineas ocultan la contrasena de la vista
       HANDLE hStdInput = GetStdHandle(STD_INPUT_HANDLE);
       DWORD mode = 0;
       GetConsoleMode(hStdInput, &mode);
       SetConsoleMode( hStdInput, mode & (~ENABLE_ECHO_INPUT));

        std::cout << "Ingrese su contrasena >> ";
        std::getline(std::cin, contrasena);
        if(verificarTamano(contrasena) && verificarNums_CarEspecial(contrasena)
           && verificarConsecutivos(contrasena, 3))
        {
//            //Reinicia la consola modo normal
            SetConsoleMode(hStdInput, mode);
            break;
        }
   }
}

int main()
{

    std::string contrasena;
    entradaDatos(contrasena);
    //std::cout << contrasena;

    return 0;
}
