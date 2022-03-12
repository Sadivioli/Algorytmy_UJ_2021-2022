#ifndef POLY_H
#define POLY_H
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

static const int POLY_MAX = 100;

typedef struct Node {
    int coeff; //współczynnik, liczba przy x
    int degree; //stopień, potęga x
} Node;

class Polynomial{
    private: 
        int poly[POLY_MAX];
    public:
        Polynomial(const int coeff[], const int degree[]);
        ~Polynomial();
        
        Polynomial hornerEval(const Polynomial&);
        void printPoly();
        //przeładowanie operatorów
        Polynomial operator+(const Polynomial&);
        Polynomial operator-(const Polynomial&);
        Polynomial operator*(const Polynomial&);
};
#endif