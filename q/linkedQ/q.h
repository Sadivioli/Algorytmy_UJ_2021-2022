#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<bits/stdc++.h>
using namespace std;

template <typename T>

class PointerBasedQueue {
    private:
        struct Node {
            T data;
            Node *next;
        };
        Node *header, *front, *rear;
        int size;
    public:
        PointerBasedQueue();
        ~PointerBasedQueue();
        bool isEmpty() const;
        int getSize() const;
        void enqueue(T &value);
        void dequeue();
        T getFront();
        T getRear();
        void print();
};