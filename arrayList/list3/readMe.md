Autor: Maciej Macuga
Zadanie:
    Wskaźnikowa implementacja listy (singly linked list)

Instrukcja uruchomienia: 
    make run

Dokumentacja:
    insert(index, element) - wstawienie elementu element na pozycję index. Zwraca ’true’ jeśli element został wstawiony pomyślnie, a ’false’ w przeciwnym przypadku
    Operacja dominująca: items[i+1] = items[i];
    Złożoność: O(n)

    remove(index) - usunięcie elementu na pozycji index. Zwraca ’true’ jeśli element został pomyślnie usunięty, a ’false’ w przeciwnym przypadku.
    Operacja dominująca: items[i-1] = items[i];
    Złożoność: O(n)

    retrieve(index) - zwraca element znaleziony na pozycji index, a -1 w przeciwnym przypadku.
    Operacja dominująca: return items[index];
    Złożoność: O(1)

    locate(element) - zwraca pozycję elementu w liście. Jeżeli element nie został znaleziony, wówczas zwracany jest indeks pozycji za ostatnim elementem w liście (END).
    Operacja dominująca: items[i] == element
    Złożoność: O(n)

    end() - zwraca indeks pozycji za ostatnim elementem w liście (END).
    Operacja dominująca: return listSize;
    Złożoność: O(1)

    first() - zwraca indeks pozycji pierwszego elementu w liście.
    Operacja dominująca: return isEmpty() ? -1 : 0;
    Złożoność: O(1)

    next(index) - zwraca pozycję elementu w liście usytuowanego za elementem na pozycji index.
    Operacja dominująca: return index++;
    Złożoność: O(1)

    prev(index) - zwraca pozycję elementu w liście usytuowanego przed elementem na pozycji index.
    Operacja dominująca: return index--;
    Złożoność: O(1)

    last() - zwraca pozycję ostatniego elementu w liście.
    Operacja dominująca: int a = listSize;
    Złożoność: O(1)

    back() - zwraca ostatni element w liście.
    Operacja dominująca: return items[--listSize];
    Złożoność: O(1)

    pushFront(element) - wstawia element na początek listy. Zwraca ’true’ w przypadku pomyślnego wstawienia elementu lub ’false’ w przeciwnym przypadku.
    Operacja dominująca: items[i+1] = items[i];
    Złożoność: O(n)

    pushBack(element) - wstawia element na końcu listy. Zwraca ’true’ w przypadku pomyślnego wstawienia elementu lub ’false’ w przeciwnym przypadku.
    Operacja dominująca: items[listSize] = element;
    Złożoność: O(1)

    popFront() – usuwa pierwszy element listy.
    Operacja dominująca: items[i-1] = items[i];
    Złożoność: O(n)

    popBack() – usuwa ostatni element listy.
    Operacja dominująca: listSize--;
    Złożoność: O(1)

    removeAllInstances() – uwsuwa wszystkie elementy listy.
    Operacja dominująca: items[i] == element;
    Złożoność: O(n^2)

    reverse() – odwracanie listy
    Operacja dominująca: temp[listSize-1-i] = items[i];
    Złożoność: O(n)

