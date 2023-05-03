#include "Polynomial.h"

Polynomial::Polynomial(int degree)
{
    this->degree = degree;
    terms = new Term[degree + 1];
}
Polynomial::~Polynomial()
{
    delete[] terms;
}
void Polynomial::input()
{
    for (int i = 0; i <= degree; i++)
    {
        cout << "Ingrese el coeficiente del exponente " << i << ": ";
        cin >> terms[i].coef;
        terms[i].expo = i;
    }
}
void Polynomial::display()
{
    cout << "Polynomial: ";
    for (int i = 0; i <= degree; i++)
    {
        cout << terms[i].coef << "x^" << terms[i].expo;
        if (i < degree)
            cout << " + ";
    }
    cout << endl;
}

Polynomial Polynomial::operator+(Polynomial &p)
{
    Polynomial result(max(degree, p.degree));
    int degreeResult = max(degree, p.degree);
    for (size_t i = 0; i < degreeResult + 1; i++)
    {
        result.terms[i].coef = p.terms[i].coef + terms[i].coef;
        result.terms[i].expo = i;
    }
    return result;
}

Polynomial Polynomial::operator*(Polynomial &p)
{
    Polynomial result(degree + p.degree);

    // inicializo en 0 los primeros coefs

    for (int i = 0; i <= degree; i++)
    {
        for (int j = 0; j <= p.degree; j++)
        {
            if (!(terms[i].coef == 0 || p.terms[j].coef == 0))
            {
                result.terms[i + j].coef += terms[i].coef * p.terms[j].coef;
                result.terms[i + j].expo = i + j;
            }
        }
    }
  
    return result;
}
