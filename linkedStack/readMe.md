Autor: Maciej Macuga
Zadanie:
    Wskaźnikowa implementacja stosu.

Instrukcja uruchomienia: 
    make run

Dokumentacja:
    Stos jest implementowany za pomocą zaimplementowanej wcześniej listy wskaźnikowej.

    peek() - zwraca element na szczycie stosu.
    Operacja dominująca: return head->data;
    Złożoność: O(1)

    push(element) - wstawia element do stosu ("na górę" stosu).
    Operacja dominująca: node->next = temp;
    Złożoność: O(1)

    pop() – usuwa element na szczycie stosu.
    Operacja dominująca:  head = head->next;
    Złożoność: O(1)

    isEmpty() – sprawdza, czy stos jest pusty.
    Operacja dominująca: head == NULL
    Złożoność: O(1)

    size() – zwraca rozmiar stosu.
    Operacja dominująca: return size;
    Złożoność: O(1)

    print() – wypisuje stos na ekran.
    Operacja dominująca: cout << temp->data << " ";
    Złożoność: O(n)
    