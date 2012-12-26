#include <iostream>

using namespace std;


/**
 * @class Figura
 * @brief Es la clase principal del programa y es abstracta.
 */

class Figura {
public:
    virtual void Dibujar(void) = 0;
};


/**
 * @class Triangulo
 * @brief Hereda de la clase Figura a la que implementa.
 */

class Triangulo : public Figura {
public:
    void Dibujar();
};


/**
 * @class Circulo
 * @brief Hereda de la clase Figura a la que implementa.
 */

class Circulo : public Figura {
public:
    void Dibujar();
};


/**
 * @class Decorador
 * @brief Hereda de la clase Figura.
 * @brief Es la clase principal utilizada para decorar.
 * @brief Es abstracta, por lo que las clases hijas la implementan.
 */

class Decorador : public Figura {
public:
    Decorador(){};
    Decorador(Figura*);
    void Dibujar() = 0;
protected:
    Figura* figure;
};


/**
 * @class DecoradorColor
 * @brief Hereda de la clase Decorador a la que implementa.
 */

class DecoradorColor : public Decorador {
public:
    DecoradorColor(Figura*);
    void Dibujar();
};


/**
 * @class DecoradorBorde
 * @brief Hereda de la clase Decorador a la que implementa.
 */

class DecoradorBorde : public Decorador {
public:
    DecoradorBorde(Figura*);
    void Dibujar();
    void DibujarBorde();
};