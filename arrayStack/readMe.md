Autor: Maciej Macuga
Zadanie:
    Tablicowa implementacja stosu.

Instrukcja uruchomienia: 
    make run

Dokumentacja:
    Stos jest implementowany za pomocą zaimplementowanej wcześniej listy na bazie tablicy.

    peek() - zwraca element na szczycie stosu.
    Operacja dominująca: return items[lastIndex];
    Złożoność: O(1)

    push(element) - wstawia element do stosu ("na górę" stosu).
    Operacja dominująca: items[listSize] = element;
    Złożoność: O(1)

    pop() – usuwa element na szczycie stosu.
    Operacja dominująca: listSize--;
    Złożoność: O(1)

    isEmpty() – sprawdza, czy stos jest pusty.
    Operacja dominująca: return listSize == 0;
    Złożoność: O(1)

    isFull() – sprawdza, czy stos jest pełny.
    Operacja dominująca: return arrayLength == listSize;
    Złożoność: O(1)

    size() – zwraca rozmiar stosu.
    Operacja dominująca: return listSize;
    Złożoność: O(1)

    print() – wypisuje stos na ekran.
    Operacja dominująca: cout << items[i] << " ";
    Złożoność: O(n)
    