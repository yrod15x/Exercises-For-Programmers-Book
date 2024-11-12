#ifndef MADLIBS_H
#define MADLIBS_H
#include <string>
#include <vector>

class MadLibs
{
    public:
        MadLibs();
        ~MadLibs();
        MadLibs(const MadLibs& other);
        void entrada_datos();
        void mostrar_madlibs();

    private:
        void mostrar_historia_inicial();
        std::string texto_historia;
        std::vector<std::string> historia_dividida;
        int num_elementos = 4;
        std::vector<std::string> elementos_oracion;
        void dividir_historia();
};

#endif // MADLIBS_H
