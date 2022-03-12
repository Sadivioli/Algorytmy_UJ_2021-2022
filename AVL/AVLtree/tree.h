#ifndef TREE_H
#define TREE_H

#include <cstdlib>
#include <stdio.h>
#include <time.h>  
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int value;
        Node* left;
        Node* right;
        Node();
        ~Node();
        Node(int value);
};

class AVLTree{
    public:
        Node * root;
        AVLTree();
        AVLTree(AVLTree && tree); //konstruktor kopiujący
        ~AVLTree();
        bool isEmpty();
        bool isFull(Node* root); //czy każdy rodzic posiada maksymaksymalną liczbę dzieci (lub 0)
        int getHeight(Node* root);
        int getBalance(Node* node);
        int treeSize(Node* root);
        Node* parent(Node* root, int value);
        Node* rightRotate(Node* node);
        Node* leftRotate(Node* node);
        Node* insert(Node* root, Node* node);
        Node* remove(Node* root, int value);
        Node* findMin(Node* root);
        Node* findMax(Node* root);
        int getMin();
        int getMax();
        Node* search(Node* root, int value);
        void preorder(Node* root);
        void inorder(Node* root);
        void postorder(Node* root);
        bool leaf(Node* node);
        bool contains(Node* root, int value);
        Node* clone(Node* root);
};

#endif