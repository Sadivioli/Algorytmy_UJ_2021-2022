
#include "linkedlist.h"


int main(){

    LinkedList newList;
    
    for (int i = 0; i < 100; i++){
        int x = rand() % 50; 
        if ((i%3) == 0){
           newList.insert(i,13);
        }else{
            newList.push_back(x);
        }
        
    }
    cout << endl;

    cout << "Wartość elementu na indexie 3: " << newList.retrive(3) << endl;
    cout << "Indeks elementu o wartości 34: " << newList.locate(34) << endl;
    cout << "\n";

    cout << "Pierwszy element: " << newList.front() << endl;
    cout << "Ostatni element: " << newList.back() << endl;
    cout << "\n";

    
    cout << "Lista: "; newList.printList();
    cout << "Rozmiar: " << newList.len();
    cout << "\n";

    newList.pop_back();
    newList.pop_front();
    cout << "\nLista po usunięciu pierwszego i ostatniego elementu: "; newList.printList();
    cout << "Rozmiar: " << newList.len();
    cout << "\n";


    newList.remove(7);
    cout << "\nLista po usunięciu elementu o indexie 7: "; newList.printList();
    cout << "Rozmiar: " << newList.len();
    cout << "\n";

    newList.rmDupes();
    cout << "\nLista bez duplikatów: "; newList.printList();
    cout << "Rozmiar: " << newList.len();
    cout << "\n";

    newList.rmVal(3);
    cout << "\nLista po usunięciu elementów o wartości 3: "; newList.printList();
    cout << "Rozmiar: " << newList.len();
    cout << "\n";

    newList.reverse();
    cout << "\nLista odwrócona: "; newList.printList();
    cout << "Rozmiar: " << newList.len();
    cout << "\n";

    newList.rmEvenIndex();
    cout << "\nLista: "; newList.printList();
    cout << "Rozmiar: " << newList.len(); 
    cout << "\n";
}