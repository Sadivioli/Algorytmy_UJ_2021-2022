Autor: Maciej Macuga
Zadanie:
    Implementacja drzewa AVL.

Instrukcja uruchomienia: 
    make run

Dokumentacja:
    isEmpty() - sprawdza czy drzewo jest puste
        Operacja dominująca: root == NULL
        Złożoność czasowa: O(1)
    isFull() - sprawdzenie czy drzewo jest pełne (każdy rodzic posiada maksymalną możliwą liczbę dzieci ~ 2 lub 0);
        Operacja dominująca: root->left == NULL && root->right == NULL
        Złożoność czasowa: O(n)
    getHeight() - wysokość drzewa;
        Operacja dominująca: int leftHeight = getHeight(root->left);
        Złożoność czasowa: O(log(n))
    treeSize() - zwraca aktualny rozmiar drzewa (liczbę węzłów);
        Operacja dominująca: return treeSize(root->left) + treeSize(root->right) + 1
        Złożoność czasowa: O(n)
    parent(w) - zwraca adres rodzica węzła w;
        Operacja dominująca: root->value > value
        Złożoność czasowa: O(n)
    insert(root, element) - wstawienie elementu element do drzewa, zwraca adres roota;
        Operacja dominująca: node->value < root->value
        Złożoność czasowa: O(log(n))
    remove(root, element) - usunięcie elementu element z drzewa, zwraca adres roota;
        Operacja dominująca: value < root->value
        Złożoność czasowa: O(log(n))
    search(root, element) - sprawdzenie czy element element znajduje się w drzewie, zwraca adres roota;
        Operacja dominująca: value < root->value
        Złożoność czasowa: O(log(n))
    contains(element) - sprawdzenie czy element element znajduje się w drzewie, zwraca true/false;
        Operacja dominująca: value < root->value
        Złożoność czasowa: O(log(n))
    getMin() - zwrócenie najmniejszego elementu w drzewie, używa fukcji findMin();
        Operacja dominująca: current = current->left;
        Złożoność czasowa: O(log(n))
    getMax() - zwrócenie największego elementu w drzewie, używa fukcji findMax();
        Operacja dominująca: current = current->right;
        Złożoność czasowa: O(log(n))
    preorder(root) - wyświetlenie drzewa w kolejności preorder;
        Operacja dominująca: cout << root->value << " ";
        Złożoność czasowa: O(n)
    inorder(root) - wyświetlenie drzewa w kolejności inorder;
        Operacja dominująca: cout << root->value << " ";
        Złożoność czasowa: O(n)
    postorder(root) - wyświetlenie drzewa w kolejności postorder;
        Operacja dominująca: cout << root->value << " ";
        Złożoność czasowa: O(n)
    leaf(element) - sprawdzenie czy element element jest liściem (nie ma potomków), zwraca true/false;
        Operacja dominująca: node->left == NULL && node->right == NULL
        Złożoność czasowa: O(1)
    clone - klonowanie drzewa, zwraca adres nowego drzewa;
        Operacja dominująca:  Node* newNode = new Node(root->value);
        Złożoność czasowa: O(n)