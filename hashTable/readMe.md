Autor: Maciej Macuga
Zadanie:
    Implementacja tablicy haszującej.

Instrukcja uruchomienia: 
    make run

Dokumentacja:
    insert(value) - dodaje wartość do tablicy haszującej. Zwrawca true jeśli wartość została dodana, false jeśli operacja zakończyła się niepowodzeniem.
    Operacja dominująca: temp = temp->next;
    Złożoność: O(n) (najgorszy przypadek, wiele elementów na tym samym kluczu, najczęściej O(1))

    remove(value) - usunięcie elementu o wartości value. Zwraca ’true’ jeśli element został pomyślnie usunięty, a ’false’ w przeciwnym przypadku.
    Operacja dominująca: temp->next != NULL
    Złożoność: O(n) (taki sam przypadek jak w insert)

    hash(value) - hashowanie wartości. Zwraca wyliczony klucz dla podanej wartości.
    Operacja dominująca: sum += x[i];
    Złożoność: O(n) (n jest długością stringa. dla wartości int hashowanie ma złożoność O(1))

    contains(value) - sprawdza czy element o podanej wartości znajduje się w liście
    Operacja dominująca: temp->value == x
    Złożoność: O(n)

    empty() - tworzy pustą tablicę.
    Operacja dominująca:  array[i]->key = 0;
    Złożoność: O(n)

    printHashTable() - wypisuje zawartość tablicy haszującej.
    Operacja dominująca: temp = temp->next;
    Złożoność: O(n)

    
