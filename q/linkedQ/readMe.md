Autor: Maciej Macuga
Zadanie:
    Implementacja kolejki wskaźnikowej.

Instrukcja uruchomienia: 
    make run

Dokumentacja:
    enqueue(T &value) - wstawia nowy element o wartości value na koniec kolejki.
    Operacja dominująca: temp->data = value;
    Złożoność: O(1)

    dequeue() - usuwa pierwszy element z kolejki (front).
    Operacja dominująca: front = front->next;
    Złożoność: O(1)

    print() – wypisuje kolejkę na ekran.
    Operacja dominująca: cout << temp->data << " ";
    Złożoność: O(n)
    