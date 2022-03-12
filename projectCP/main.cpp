#include "poly.h"
using namespace std;

int main(){
    //Wielomiany są wprowadzane w postaci dwóch wektorów:
    int coeff[] = {1, 2, -3, 4, -5};
    int degree[] = {0, 1, 2, 3, 4};

    Polynomial poly1(coeff, degree);
    poly1.printPoly();
    // Polynomial p2(coeff, degree);
    // p2.printPoly();
    // Polynomial p3 = p1 + p2;
    // p3.printPoly();
    // Polynomial p4 = p1 - p2;
    // p4.printPoly();
    // Polynomial p5 = p1 * p2;
    // p5.printPoly();
    return 0;
}