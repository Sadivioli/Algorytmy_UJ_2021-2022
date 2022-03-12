#include "poly.h"
using namespace std;


Polynomial::Polynomial(const int coeff[], const int degree[]){
    for(int i = 0; i < POLY_MAX; i++){
        poly[i] = 0;
    }
    for(int i = 0; i < POLY_MAX; i++){
        poly[i] = coeff[i];
    }
    for(int i = 0; i < POLY_MAX; i++){
        poly[i] = degree[i];
    }
}

Polynomial::~Polynomial(){
    for(int i = 0; i < POLY_MAX; i++){
        poly[i] = 0;
    }
}

void Polynomial::printPoly(){
    int size = sizeof(poly)/sizeof(poly[0]);
    for(int i = 0; i < size; i++){
        if(poly[i] != 0){
            cout << poly[i] << "x^" << poly[i+1] << " ";
        }
    }
    cout << endl;
}