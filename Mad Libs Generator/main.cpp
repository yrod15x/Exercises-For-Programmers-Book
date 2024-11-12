#include <iostream>
#include "madlibs.h"
#include <string>

//Programa que genera una actividad de MADLIBS. Introduce nuevos elementos a una historia, todos ellos ingresados por el usuario

int main()
{
    MadLibs historia;

    historia.entrada_datos();
    historia.mostrar_madlibs();

    return 0;
}
