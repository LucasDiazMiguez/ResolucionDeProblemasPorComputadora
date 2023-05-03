
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <cstdarg>
#include <iostream>

#define MAX_SIZE 10
using namespace std;

struct Term
{
    float coef;
    int expo;
};


class Polynomial
{
private:
    int degree;
    Term *terms;

public:
    Polynomial(int degree);
    ~Polynomial();
    void input();
    void display();
    Polynomial operator*(Polynomial &p);
    Polynomial operator+(Polynomial &p);
};
#endif // POLYNOMIAL_H