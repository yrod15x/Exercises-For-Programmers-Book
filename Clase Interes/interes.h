#ifndef INTERES_H
#define INTERES_H


class Interes
{
    public:
        Interes();
        Interes(double cantidadInicial, double tasaInteres, int tiempoAnnios);
        Interes(double cantidadInicial, double tasaInteres, int tiempoAnnios, int numInteresCompuesto);
        ~Interes();
        Interes(const Interes& other);
        Interes& operator=(const Interes& other);

        double GetcantidadInicial() { return _cantidadInicial; }
        void SetcantidadInicial(double val) { _cantidadInicial = val; }
        double GettasaInteres() { return _tasaInteres; }
        void SettasaInteres(double val) { _tasaInteres = val; }
        double GetcantidadFinal() { return _cantidadFinal; }
        double GettiempoAnnios() { return _tiempoAnnios; }
        void SettiempoAnnios(double val) { _tiempoAnnios = val; }
        int GetnumInteresCompuesto() { return _numInteresCompuesto; }
        void SetnumInteresCompuesto(int val) { _numInteresCompuesto = val; }

        void setDatosInteresSimple(double cantidadInicial, double tasaInteres, int tiempoAnnios);
        void setDatosInteresCompuesto(double cantidadInicial, double tasaInteres, int tiempoAnnios, int numInteresCompuesto);
        void calculaInteres();
        void calcularInteresSimple();
        void calcularInteresCompuesto();
        void mostrarInteresSimple() const;
        void mostrarInteresCompuesto() const;


    protected:

    private:
        double _cantidadInicial;
        double _tasaInteres;
        double _cantidadFinal;
        int _tiempoAnnios;
        int _numInteresCompuesto;
};

#endif // INTERES_H
