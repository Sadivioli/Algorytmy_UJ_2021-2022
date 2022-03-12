Autor: Maciej Macuga
Zadanie:
    Wskaźnikowa implementacja listy (singly linked list)

Instrukcja uruchomienia: 
    make run

Dokumentacja
    insert(index, element) - wstawienie elementu o wartości element na pozycję index w kolejności od początku listy. Zwraca ’true’ jeśli element został wstawiony pomyślnie, a ’false’ przeciwnym przypadku. 
    Operacja dominująca: curr = curr->next;
    Złożoność: O(n)
    
    remove(index) - usunięcie elementu na pozycji index w kolejności od początku listy. Zwraca ’true’ jeśli element został pomyślnie usunięty, a ’false’ w przeciwnym przypadku.
    Operacja dominująca: curr = curr->next;
    Złożoność: O(n)

    retrieve(index) - zwraca wartość elementu na pozycji index w kolejności od początku listy, a -1 w przeciwnym przypadku.
    Operacja dominująca: curr = curr->next;
    Złożoność: O(n)

    locate(element) - zwraca pozycję elementu o wartości element w liście w kolejności od początku listy. Jeżeli element o wartości element nie został znaleziony, wówczas zwracana jest liczba -1.
    Operacja dominująca: curr = curr->next;
    Złożoność: O(n)

    isEmpty() - zwraca ’true’ jeśli lista jest pusta, a ’false’ w przeciwnym przypadku.
    Operacja dominująca: head == NULL
    Złożoność: O(1)

    first() - zwraca wskaźnik do pierwszego elementu listy.
    Operacja dominująca: return *head;
    Złożoność: O(1)

    front() - zwraca wartość pierwszego elementu w liście.
    Operacja dominująca: return head->data;
    Złożoność: O(1)

    last() - zwraca wskaźnik do ostatniego elementu listy.
    Operacja dominująca: curr = curr->next;
    Złożoność: O(n)

    back() - zwraca wartość ostatniego elementu w liście.
    Operacja dominująca: curr = curr->next;
    Złożoność: O(n)

    len() - zwraca liczbę elementów w liście.
    Operacja dominująca: return size;
    Złożoność: O(1);

    push_front(element) - wstawia element o wartości element na początek listy. Zwraca ’true’ w przypadku pomyślnego wstawienia elementu lub ’false’ w przeciwnym przypadku.
    Operacja dominująca: Node *temp = head;
    Złożoność: O(1)

    push_back(element) - wstawia element o wartości element na końcu listy. Zwraca ’true’ w przypadku pomyślnego wstawienia elementu lub ’false’ w przeciwnym przypadku.
    Operacja dominująca: tail->next = node;
    Złożoność: O(1) ~ lista przechowuje informacje o ostatnim elemencie (tail)

    pop_front() – usuwa pierwszy element listy. Zwraca ’true’ jeśli element został usunięty, a ’false’ w przeciwnym przypadku.
    Operacja dominująca: head = head->next;
    Złożoność: O(1)

    pop_back() – usuwa ostatni element listy. Zwraca ’true’ jeśli element został usunięty, a ’false’ w przeciwnym przypadku.
    Operacja dominująca: curr = curr->next;
    Złożoność: O(n)

    rmDupes() - suwa wszystkie duplikaty w liście. Zakładamy że lista nie jest posortowana
    Operacja dominująca: temp->next = temp->next->next;
    Złożoność: O(n^2)

    rmVal(value) - usuwa wszystkie elementy o wartości value. Zakładamy że lista nie jest posortowana.
    Operacja dominująca: curr = curr->next;
    Złożoność: O(n^2)

    reverse() - odwracanie listy.
    Operacja dominująca: curr->next = prev;
    Złożoność: O(n)

    rmEvenIndex() - usuwanie co drugiego elementu z listy.
    Operacja dominująca: prev->next = curr->next;
    Złożoność: O(n)