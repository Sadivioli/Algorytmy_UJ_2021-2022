
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "list.h"
using namespace std;

int main(){
    srand(time(NULL));
    ArrayList newList;
    for (int i = 0; i < 200; i++){
        if(i % 6 == 0){
            newList.pushBack(17);
        }else if(i % 11 == 0){
            newList.pushBack(47);
        }else{
            int x = rand() % 50;
            newList.pushBack(x);
        }
        
    }
    int toFind = rand() % 50;
    int toRemove = rand() % 200;
    int toInsert = (rand() % 500) + 100;
    int toInsertIndex = rand() % 100;
    int toGet = rand() % 200;
    cout << "Lista bez modyfikacji: "; newList.print(); cout << "Rozmiar: " << newList.size() << endl << endl;
    cout << "Index pierwszego elementu: " << newList.first() << endl; 
    cout << "Index ostatniego elementu: " << newList.last() << endl;
    cout << "Index za ostatnim elementem: " << newList.end() << endl;
    cout << "Ostatni element w liście: " << newList.back() << endl;
    cout << "Pozycja elementu znajdującego się za indexem: " << toGet << " : " << newList.next(toGet) << endl;
    cout << "Pozycja elementu znajdującego się przed indexem: " << toGet << " : " << newList.prev(toGet) << endl;
    cout << "Element na indexie: " << toGet << " Ma wartość: " << newList.retrieve(toGet) << endl;
    cout << "Czy w liscie znajduje się element o wartości: " << toFind << ": " << newList.contains(toFind) << endl;
    cout << "Index elementu (pierwsze wystąpenie): " << toFind << ": " << newList.locate(toFind) << endl;

    
    cout << "Usuwanie elementu o wartości : " << toRemove << " Wynik funkcji: " << newList.remove(toRemove) << "\nRozmiar: " << newList.size() << endl;

    cout << "Dodawanie elementu o wartości : " << toInsert << " Na pozycję: " << toInsertIndex << " Wynik funkcji: " << newList.insert(toInsertIndex, toInsert) << "\nRozmiar: " << newList.size() << endl;

    cout << "Usuwanie elementu na pozycji : " << toRemove << " Wynik funkcji: " << newList.remove(toRemove) << "\nRozmiar: " << newList.size() << endl;

    cout << "Dodawanie elementu o wartości : " << toInsert << " Na początek listy (funkcja pushFront())" << " Wynik funkcji: " << newList.pushFront(toInsert) << "\nRozmiar: " << newList.size() << endl;
    cout << "Lista: "; newList.print(); cout << "Rozmiar: " << newList.size() << endl;

    newList.popFront();
    newList.popFront();
    cout << "Lista po usunięciu pierwszego i ostatniego elementu: "; newList.print(); cout << "Rozmiar: " << newList.size() << endl;
    
    cout << "Lista bez wartości 47: "; newList.removeAllInstances(47); newList.print(); cout << "Rozmiar: " << newList.size() << endl;
    cout << "Lista odwrócona: "; newList.invert(); newList.print();
    cout << endl;
    return 0;
}

