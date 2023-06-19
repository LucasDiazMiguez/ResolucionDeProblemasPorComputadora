#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <cstdarg>
#include <iostream>

using namespace std;

#define MAX_SIZE 10

class Polynomial
{
private:
    int degree;
    int *terms;

public:
    Polynomial(int grade, ...);
    Polynomial(int grade, int terms[]);
    Polynomial(Polynomial &p);

    ~Polynomial();
    void input();
    void display();
    Polynomial copy();
    Polynomial operator*(const Polynomial &p);
    Polynomial operator+(const Polynomial &p);
    Polynomial operator-(const Polynomial &p);
    // Polynomial operator/(Polynomial &p);
    int evaluation(int val);
};
#endif // POLYNOMIAL_H