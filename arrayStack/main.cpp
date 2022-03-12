#include "stack.h"

using namespace std;

int main(){
    ArrayBasedStack newStack;
    srand(time(NULL));
    for (int i = 0; i < 30; i++){
        int x = rand() % 50;
        newStack.push(x);
    }
    cout << "Stan początkowy stosu: "; newStack.print();
    cout << "Rozmiar stosu: " << newStack.size() << endl;
    cout << "Wartość elementu na szczycie stosu: " << newStack.peek() << endl;
    newStack.pop(); //usuwanie elementu na szczycie stosu
    newStack.pop(); 

    cout << endl;
    cout << "Stan po usunięciu elementu na szczycie stosu: "; newStack.print();
    cout << "Rozmiar stosu: " << newStack.size() << endl;
    cout << "Wartość elementu na szczycie stosu: " << newStack.peek() << endl;
    return 0;
}