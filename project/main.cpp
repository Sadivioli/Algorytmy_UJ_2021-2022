#include "poly.h"
using namespace std;

int main(){
    int p1 = -1, p2 = 0, p3 = 1, numOfTermP = 9, numOfTermQ = 4;

    //wielomiany są reprezenotwane za pomocą dwóch tablic: współczynników i ich stopni
    vector<int> coeffP;
    vector<int> degreeP;

    srand(time(NULL));
    for (int i = 0; i < numOfTermP; i++){
        int x = rand() % 20;
        int toPush = x - 10;
        coeffP.push_back(toPush);
    }
    for (int i = coeffP.size()-1; i >= 0 ; i--){
        degreeP.push_back(i);
    }

    Polynomial polyP(coeffP, degreeP);
    cout << "Wielomian P(x): "; polyP.printPoly();
    
    //oblicznie wartości wielomianu dla wybranych wartości
    cout << "Wartość wielomianu P(x) dla x = " << p1 << ": " << polyP.hornerEval(p1) << endl;
    cout << "Wartość wielomianu P(x) dla x = " << p2 << ": " << polyP.hornerEval(p2) << endl;
    cout << "Wartość wielomianu P(x) dla x = " << p3 << ": " << polyP.hornerEval(p3) << endl;

    vector<int> coeffQ;
    vector<int> degreeQ;

    srand(time(NULL));
    for (int i = 0; i < numOfTermQ; i++){
        int x = rand() % 19;
        int toPush = x - 9;
        coeffQ.push_back(toPush);
    }
    for (int i = coeffQ.size()-1; i >= 0 ; i--){
        degreeQ.push_back(i);
    }

    Polynomial polyQ(coeffQ, degreeQ);
    cout << endl;
    cout << "Wielomian Q(x): "; polyQ.printPoly();
    cout << "Wartość wielomianu Q(x) dla x = " << p1 << ": " << polyQ.hornerEval(p1) << endl;
    cout << "Wartość wielomianu Q(x) dla x = " << p2 << ": " << polyQ.hornerEval(p2) << endl;
    cout << "Wartość wielomianu Q(x) dla x = " << p3 << ": " << polyQ.hornerEval(p3) << endl;

    /*------------------------------------------------------*/
    //Działania na wielomianach
    cout << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "Działania na wielomianach P(x) i Q(x)" << endl;

    //dodawanie wielomianów
    Polynomial sum = polyP + polyQ;
    cout << "Suma wielomianów P(x) i Q(x): "; sum.printPoly();

    cout << endl;

    //odejmowanie wielomianów
    Polynomial diff = polyP - polyQ;
    cout << "Różnica wielomianów P(x) i Q(x): "; diff.printPoly();

    cout << endl;

    //mnożenie wielomianów
    Polynomial prod = polyP * polyQ;
    prod.polySiplify();
    cout << "Iloczyn wielomianów P(x) i Q(x): "; prod.printPoly();
    cout << endl;

    //cout << poly1.hornerEval(1) << endl;
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