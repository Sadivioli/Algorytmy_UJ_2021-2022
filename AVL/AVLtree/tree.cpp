#include "tree.h"
#include <iostream>
using namespace std;

Node::Node(){
  value = 0;
  left = NULL;
  right = NULL;
}
Node::Node(int value){
  value = value;
  left = NULL;
  right = NULL;
}
Node::~Node(){
  delete left;
  delete right;
}

AVLTree::AVLTree(){
  root = NULL;
}
AVLTree::AVLTree(AVLTree && tree){
  root = tree.root;
  tree.root = NULL;
}
AVLTree::~AVLTree(){
  delete root;
}
bool AVLTree::isEmpty(){
    if (root == NULL) {
      return true;
    }else {
      return false;
    }
}

bool AVLTree::isFull(Node* root){
  if (root == NULL) {
    return true;
  }
  if (root->left == NULL && root->right == NULL) {
    return true;
  }
  if((root->left) && (root->right)){
    return (isFull(root->left) && isFull(root->right));
  }
  return false;
}

int AVLTree::getHeight(Node* root){
    if (root == NULL){
      return -1;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    if (leftHeight > rightHeight){
      return leftHeight + 1;
    }else{
      return rightHeight + 1;
    }
}

int AVLTree::treeSize(Node* root){
  if (root == NULL){
    return 0;
  }
  return treeSize(root->left) + treeSize(root->right) + 1;
}

Node* AVLTree::parent(Node* root, int value){
  if (root == NULL || root->value == value || (root->left == NULL && root->right == NULL)){
    return NULL;
  }
  if((root->left != NULL && root->left->value == value) ||
   (root->right != NULL && root->right->value == value)){
    return root;
  }
  if (root->value > value){
    return parent(root->left, value);
  }else{
    return parent(root->right, value);
  }
}

Node* AVLTree::clone(Node* root){
  if (root == NULL){
    return NULL;
  }
  Node* newNode = new Node(root->value);
  newNode->left = clone(root->left);
  newNode->right = clone(root->right);
  return newNode;
}
int AVLTree::getBalance(Node* node) {
  if (node == NULL){
    return -1;
  }
  return getHeight(node->left) - getHeight(node->right);
}

Node* AVLTree::rightRotate(Node * b) {
  Node* a = b->left;
  Node* temp = a->right;
  a->right = b;
  b->left = temp;
  return a;
}

Node* AVLTree::leftRotate(Node * a) {
  Node* b = a->right;
  Node* temp = b->left;
  b->left = a;
  a->right = temp;
  return b;
}

Node* AVLTree::insert(Node* root, Node * node) {
    if (root == NULL) {
      root = node;
      return root;
    }

    if (node->value < root->value) {
      root->left = insert(root->left, node);
    } else if (node->value > root->value) {
      root->right = insert(root->right, node);
    }
     else {
      cout << "Wsytąpiło powtórzenie" << endl;
      return root;
    }

    //Sekcja obrotów
    int balance = getBalance(root);

    //Obrót lewo-lewo
    if (balance > 1 && node->value < root->left->value)
      return rightRotate(root);

    //Obrót prawo-prawo
    if (balance < -1 && node->value > root->right->value)
      return leftRotate(root);

    //Obrót prawo-lewo
    if (balance > 1 && node->value > root->left->value) {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }

    //Obrót lewo-prawo
    if (balance < -1 && node->value < root->right->value) {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
    return root;

  }

Node* AVLTree::search(Node * root, int value) {
  if (root == NULL || root->value == value){
    return root;
  }else if (value < root->value){
    return search(root->left, value);
  }else{
    return search(root->right, value);
  }
}

bool AVLTree::contains(Node * root, int value) {
  if (root == NULL){
    return false;
  }else if (root->value == value){
    return true;
  }else if (value < root->value){
    return contains(root->left, value);
  }else{
    return contains(root->right, value);
  }
}
Node* AVLTree::findMin(Node * node) {
  Node* current = node;
  while (current->left != NULL) {
    current = current->left;
  }
  return current;
}
Node* AVLTree::findMax(Node * node) {
  Node* current = node;
  while (current->right != NULL) {
    current = current->right;
  }
  return current;
}

int AVLTree::getMin() {
  Node* min = findMin(root);
  return min->value;
}
int AVLTree::getMax() {
  Node* max = findMax(root);
  return max->value;
}
Node* AVLTree::remove(Node * root, int value) {
  // base case 
  if (root == NULL) {
    return NULL;
  }
  //szukamy w którym poddrzewie znajuje się liść o wartości value 
  else if (value < root->value){
    root->left = remove(root->left, value);
  }
  else if (value > root->value){
    root->right = remove(root->right, value);
  }

  else{
    //jeśli ma jedno lub nie ma nie ma dzieci
    if(root->left == NULL){
      Node* temp = root->right;
      delete root;
      return temp;
    }else if(root->right == NULL){
      Node* temp = root->left;
      delete root;
      return temp;
    }else{
      //dla liścia z dwoma dziećmi
      //będzie on "zamieniony" z najmniejszym z prawego poddrzewa
      Node* temp = findMin(root->right);
      root->value = temp->value;
      root->right = remove(root->right, temp->value);
    }
  }

  //Sprawdzamy czy drzewo jest zbalansowane

  int balance = getBalance(root);

  //Imbalans lewo-lewo ~ wykonamy obrót w prawo
  if (balance == 2 && getBalance(root->left) >= 0){
    return rightRotate(root);
  }
  //Imbalans lewo-prawo ~ wykonamy obrót lewo-prawo
  else if (balance == 2 && getBalance(root->left) == -1){
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  //Imbalans prawo-prawo ~ wykonamy obrót w lewo
  else if (balance == -2 && getBalance(root->right) <= 0){
    return leftRotate(root);
  }
  //Imbalans prawo-lewo ~ wykonamy obrót prawo-lewo
  else if (balance == -2 && getBalance(root->right) == 1) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

    return root;
}

void AVLTree::preorder(Node * root){//(current, lewo, prawo)
    if (root == NULL){return;}
    cout << root->value << " ";

    preorder(root->left);
    preorder(root->right);
  }

void AVLTree::inorder(Node * root){//(lewo, current, prawo)
    if (root == NULL){return;}
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
  }
void AVLTree::postorder(Node * root){//(lewo, prawo, root)
    if (root == NULL){return;}
    postorder(root->left);
    postorder(root->right);
    cout << root->value << " ";
  }

bool AVLTree::leaf(Node* node){
  if(node->left == NULL && node->right == NULL){
    return true;
  }
  return false;
}
