#ifndef HASH_H
#define HASH_H
const int SIZE = 10;
#include <cstdlib>
#include <stdio.h>
#include <time.h>  
#include <bits/stdc++.h>
#include <typeinfo>
#include <type_traits>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
template <class T>

class HashTable{
    public:
        HashTable(int SIZE);
        ~HashTable();
        bool insert(const T & x);
        int hash(T x);
        bool remove(const T & x);
        bool contains(const T & x);
        void empty();
        void printHashTable();
    
    private:
        struct Node{
            int key;
            T value;
            Node * next;
        };
        Node* array[SIZE];
        int size;
        //int count;
        //Node** head; //tablica wskaźników na listy
};

#endif