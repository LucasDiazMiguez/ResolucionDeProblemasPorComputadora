#include "Polynomial.h"

int main()
{
    int degree1, degree2;
    cout << "Ingrese el grado del polinomio 1 = "; 
    cin >> degree1;
    cout << "Ingrese el grado del polinomio 2 = ";
    cin >> degree2;

    Polynomial p1(degree1);
    p1.input();
    Polynomial p2(degree2);
    p2.input();
    cout << "Polynomial mul";

    cout<<"\n";

    p1.display();
    p2.display();
    
    Polynomial p3 = p1 * p2;
    p3.display();
    cout << "Polynomial sum";
    cout<<"\n";
    Polynomial p4 = p1 + p2;
    p4.display();
    return 0;
}