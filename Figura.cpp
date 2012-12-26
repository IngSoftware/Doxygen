#include "Figura.h"


/**
 * @fn Dibujar
 * @brief Pertenece a la clase Triangulo.
 * @brief Dibuja un triángulo.
 */

void Triangulo :: Dibujar () {
    cout << "Soy un triangulo." << endl;
};


/**
 * @fn Dibujar
 * @brief Pertenece a la clase Circulo.
 * @brief Dibuja un círculo.
 */

void Circulo :: Dibujar () {
    cout << "Soy un circulo." << endl;
};


/**
 * @fn Decorador
 * @brief Pertenece a la clase Decorador.
 * @brief Es el constructor de la clase.
 * @param fig Es un elemento de la clase Figura.
 */

Decorador :: Decorador (Figura* fig) {
    figure = fig;
};


/**
 * @fn DecoradorColor
 * @brief Pertenece a la clase DecoradorColor.
 * @brief Es el constructor de la clase.
 * @param fig Es un elemento de la clase Figura.
 */

DecoradorColor :: DecoradorColor (Figura* fig) {
    figure = fig;
};


/**
 * @fn Dibujar
 * @brief Pertenece a la clase DecoradorColor.
 * @brief Dibuja la figura que corresponda a color.
 */

void DecoradorColor :: Dibujar () {
    cout << "\033[31m";
    figure->Dibujar();
    cout << "\033[0m";
};


/**
 * @fn DecoradorBorde
 * @brief Pertenece a la clase DecoradorBorde.
 * @brief Es el constructor de la clase.
 * @param fig Es un elemento de la clase Figura.
 */

DecoradorBorde :: DecoradorBorde (Figura* fig) {
    figure = fig;
};


/**
 * @fn Dibujar
 * @brief Pertenece a la clase DecoradorBorde.
 * @brief Dibuja un un borde antes y después de la figura correspondiente.
 */

void DecoradorBorde :: Dibujar () {
    DibujarBorde();
    figure->Dibujar();
    DibujarBorde();
};

/**
 * @fn DibujarBorde
 * @brief Pertenece a la clase DecoradorBorde.
 * @brief Dibuja un borde.
 */

void DecoradorBorde :: DibujarBorde () {
    cout << "*-.-*-·-*-.-*-·-*-.-*-·-*" << endl;
};


/**
 * @fn main
 * @brief Es el menú principal del programa.
 */

int main () {
    cout << " * Figuras *" << endl;
    int op = 0;
    while ((op != 1) && (op != 2)) {
        cout << "Seleccione el tipo de figura que desea dibujar:" << endl;
        cout << "  1. Triangulo" << endl;
        cout << "  2. Circulo" << endl;
        cin >> op;
        if ((op != 1) && (op != 2))
            cout << "Opcion incorrecta, seleccione otra opcion." << endl;
    }
    Figura* fig;
    if (op == 1)
        fig = new Triangulo();
    if (op == 2)
        fig = new Circulo();
    op = 0;
    while ((op != 1) && (op != 2) && (op != 3)) {
        cout << "Seleccione el tipo de decorado que desea:" << endl;
        cout << "  1. Borde" << endl;
        cout << "  2. Color" << endl;
        cout << "  3. Borde y color" << endl;
        cin >> op;
        if ((op != 1) && (op != 2) && (op != 3))
            cout << "Opcion incorrecta, seleccione otra opcion." << endl;
    }
    if (op == 1) {
        DecoradorBorde* figborde = new DecoradorBorde(fig);
        figborde->Dibujar();
    }
    if (op == 2) {
        DecoradorColor* figcolor = new DecoradorColor(fig);
        figcolor->Dibujar();
    }
    if (op == 3) {
        DecoradorColor* figcolor = new DecoradorColor(fig);
        DecoradorBorde* figcolorborde = new DecoradorBorde(figcolor);
        figcolorborde->Dibujar();
    }
}