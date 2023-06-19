// El trabajo del lunes es la implementación de polinomios de coeficientes con operaciones de suma, resta, multiplicación y división, evaluación, búsqueda de raíces en un entorno por el método de bisección módulo un cierto error relativo y factorización usando división. La idea es implementar toda la clase, constructores, destructores, asignación, operadores, input y output, todo lo necesario para usar estos objetos debidamente.
// Algunos punteros de interés:
// Error relativo (https://en.wikipedia.org/wiki/Approximation_error), 
// Teorema de Bolzano (https://en.wikipedia.org/wiki/Intermediate_value_theorem),
//  Método de bisección (https://en.wikipedia.org/wiki/Bisection_method), 
// División (https://en.wikipedia.org/wiki/Polynomial_long_division)

// g++ hello.cpp
#include "Polynomial.h"
#include <cstdarg>


int main()
{

    int degree1, degree2;
    int result;

    Polynomial p1(3, 1, 1, 1,2);
    p1.display();
    Polynomial p2(1, 1, 1);
    p2.display();
    result = p1.evaluation(2);
    cout<< "\n \n resultado es:"<<result<<"\n \n";
    Polynomial x = p1 + p2 ; 
    Polynomial y = p1 - p2 ; 
    cout<<"soy p1 \n";
    p1.display();
    cout<<"soy p2 \n";
    p2.display();

    Polynomial z = p1*p2;
    x.display();
    y.display();
    z.display();
    return 0;
}