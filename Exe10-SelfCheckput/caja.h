#ifndef CAJA_H
#define CAJA_H

#include <vector>

class Caja
{
    public:
        Caja();
        ~Caja();
        Caja(const Caja& other);
        void ingresarDatos();
        void mostrarInfo();

    private:
        std::vector<double> _valorItems;
        double _valorSinIva = 0.0;
        double _valorTotal = 0.0;
        double _valorImpuesto = 0.0;
        void _sacarImpuestos();
};

#endif // CAJA_H
