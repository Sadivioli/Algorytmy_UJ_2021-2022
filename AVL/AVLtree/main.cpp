#include "tree.h"
#include <iostream>
using namespace std;
int main(){
  int toSearch = 21;
  AVLTree newTree;
  Node *newNode = new Node();
  newNode->value = 13;
  newTree.root = newTree.insert(newTree.root, newNode);

  for (int i = 0; i < 50; i++){
    Node *newNode = new Node();
    newNode->value = rand() % 100;
    //wpisywanie losowych wartosci sprawi że część wartości (wszystkie nieunikalne, zostaną pominięte)
    newTree.root = newTree.insert(newTree.root, newNode); 
  }
  cout << endl;
      
    cout << "Drzewo w notacji Post-Order: "; newTree.postorder(newTree.root);cout << endl;
    cout << "Drzewo w notacji Post-Order: "; newTree.preorder(newTree.root);cout << endl;
    cout << "Drzewo w notacji Post-Order: "; newTree.inorder(newTree.root);cout << endl;

    cout << "Wysokość drzewa: " << newTree.getHeight(newTree.root) << endl;
    cout << "Ilość węzłów drzewa: " << newTree.treeSize(newTree.root) << endl;
    cout << "Czy drzewo jest pełne? " << newTree.isFull(newTree.root) << endl;

    cout << "Adres rodzica węzła o wartości 13: " << newTree.parent(newTree.root, 13) << endl;

    newTree.remove(newTree.root, 13);
    cout << "Z drzewa usunięto wartość 13" << endl;
    cout << "Drzewo w notacji Post-Order: "; newTree.postorder(newTree.root);cout << endl;

    cout << "Najmniejsza wartość w drzewie: " << newTree.getMin() << " Największa wartość w drzewie: " << newTree.getMax() << endl;
    cout << "Czy drzewo zawiera wartość " << toSearch << "? "<< newTree.contains(newTree.root, toSearch) << endl;
    cout << "Czy węzęł o wartości: " << toSearch << " jest liściem? "<< newTree.isEmpty() << endl;

    cout << "Adres roota oryginalnego drzewa: " << newTree.search(newTree.root, newTree.root->value) << endl;
    cout << "Adres roota sklonowanego drzewa: " << newTree.clone(newTree.root) << endl;

    
cout << endl;
    return 0;
}