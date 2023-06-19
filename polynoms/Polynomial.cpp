#include "Polynomial.h"
#include <cmath>

Polynomial::Polynomial(int degreeValue, ...) {
    this->degree = degreeValue;
    terms = new int[MAX_SIZE];
    va_list list;

    va_start(list,degreeValue);

    for (int i = 0; i < degreeValue + 1; i++)
        terms[i] = va_arg(list, int);

    for (int i = degreeValue + 1; i < MAX_SIZE; i++)
        terms[i] = 0;

    va_end(list);
}


Polynomial::Polynomial(Polynomial &p) {
    
    degree = p.degree;

    for (size_t i = 0; i < degree + 1; i++)
        terms[i] = p.terms[i];

    for (size_t i = degree + 1; i < MAX_SIZE; i++)
        terms[i] = 0;
}

Polynomial::~Polynomial()
{
    delete[] terms;
}

Polynomial::Polynomial(int grade, int coef[]) {

    this->degree = grade;
    terms = new int[MAX_SIZE];

    for (size_t i = 0; i < grade+1; i++)
        this->terms[i] = coef[i];

    for (size_t i = grade + 1; i < MAX_SIZE; i++)
        this->terms[i] = 0;
}

void Polynomial::display()
{
    cout << "Polynomial: ";
    for (int i = 0; i <= degree; i++)
    {
        cout << terms[i]<< "x^" << i;
        if (i < degree)
            cout << " + ";
    }
    cout << endl;
}

Polynomial Polynomial::operator+(const  Polynomial  &p)
{
    int newDegree = max(degree,p.degree);
    int newTerms[newDegree] = {0};

    for (size_t i = 0; i <= newDegree; i++)
        newTerms[i] = terms[i] + p.terms[i];
    
    Polynomial res(newDegree, newTerms);
    return res;
}

Polynomial Polynomial::operator-(const  Polynomial  &p)
{
    int newDegree = max(degree,p.degree);
    int newTerms[newDegree] = {0};

    for (size_t i = 0; i <= newDegree; i++)
        newTerms[i] = terms[i] - p.terms[i];
    
    Polynomial res(newDegree, newTerms);
    return res;
}

Polynomial Polynomial::operator*(const Polynomial  &p)
{

    int newDegree = degree + p.degree;
    int newTerms[newDegree+1] = {0}; //! porque anda esto?  

    for (int i = 0; i <= degree; i++)
    {
        for (int j = 0; j <= p.degree; j++)
        {
            if (!(terms[i] == 0 || p.terms[j] == 0))
            {
                cout<<"multiplicacion = "<<terms[i] * p.terms[j]<<"  i ="<<i<<" j= "<<j<<"\n";
                newTerms[i + j] += terms[i] * p.terms[j];
            }
        }
    }
    Polynomial res(newDegree, newTerms);
    return res;
}

int Polynomial::evaluation(int val)
{

    int result = terms[0];

    for (int i = 1; i <= degree; i++)
        result = result +  terms[i] * pow(val,i);
  return result;
}
Polynomial Polynomial::copy()
{
    int newTerms[degree] = {0};

    for (int i = 0; i <=degree; i++)
        newTerms[i] = terms[i];

    Polynomial NewPol(degree,newTerms);
    return NewPol;
}
// Polynomial Polynomial::operator/(Polynomial  &Divisor){
      
//     Polynomial Quotient;
//     Polynomial Mul;
//     Polynomial Rest = this->copy();
//     cout<<"Divisor\n";
//     Divisor.display();
//     cout<<"\n Rest \n";
//     Rest.display();
//     cout<<"\n Dividiend \n";
//     this->display();
//     for (int i = 0; i < 1; i++)//Dividiend.degree
//     {
//         Mul.degree = Rest.degree-1;
//         cout<<Mul.degree<<" Mul.degree \n";
//         cout<<Rest.terms[Rest.degree]<<" Rest.terms[Rest.degree] \n";
//         cout<<terms[1]<<" terms[1]"<<"\n";
        
//         Mul.terms[Rest.degree-1] = Rest.terms[Rest.degree]/terms[1];

//         cout<<"\n Mul \n";
//         Mul.display();

//         // Quotient = Rest * Mul;
//         // cout<<"\n Quotient \n";
//         // Quotient.display();
//     }
    

//     return Quotient;

    
// } 

// // // ponerle nulll por defecto al constructor de polinmoios,

// //