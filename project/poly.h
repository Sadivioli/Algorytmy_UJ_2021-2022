#ifndef POLY_H
#define POLY_H
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
using namespace std;

/*! \struct Node 
    \brief Obiekt reprezentujący jednomian wielomianu w postaci: współczynnik * x^stopień
    *
*/
typedef struct Node {
    int coeff; //współczynnik, liczba przy x
    int degree; //stopień, potęga x
} Node;

/*! \class Polynomial
    \brief Klasa reprezentująca wielomian w postaci listy jednomianów
*/
class Polynomial{
    private: 
        /*! \brief
         * Lista jednomianów
        */
        list<Node> poly;
    public:
        /*! \brief
         * konstruktor bezargumentowy - tworzy pusty wielomian */
        Polynomial(); 
        /*! \brief
         * konstruktor z argumentami - tworzy wielomian z podanymi współczynnikami i stopniami */
        Polynomial(const vector<int>& coeff, const vector<int>& degree); 
        ~Polynomial();
        
        /*! \brief
         * wyliczanie wartości wielomianu w punkcie x, używając algorytmu Hornera
        */
        double hornerEval(int); 

        /*! \brief
         * wypisuje wielomian na ekran */
        void printPoly();

        /*! \brief 
         * sprowadzenie wielomianu do postaci uporządkowanej - funkcja pomocncza dla operatora mnożenia 
        */
        void polySiplify(); 

        //przeładowanie operatorów

        /*! \brief Dodawanie wielomianów*/
        Polynomial operator+(const Polynomial&) const;
        /*! \brief Odejmowanie wielomianów*/
        Polynomial operator-(const Polynomial&) const;
        /*! \brief Mnożenie wielomianów*/
        Polynomial operator*(const Polynomial&) const; 


};
#endif