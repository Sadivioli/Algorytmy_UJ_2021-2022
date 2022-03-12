#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 20;

template <typename T>

class ArrayBasedQueue {
    private:
        T *items;
        int front, rear, size;
    public:
        ArrayBasedQueue();
        ~ArrayBasedQueue();
        bool isEmpty();
        bool isFull();
        int getSize();
        void enqueue(T &value);
        int dequeue();
        T getFront();
        T getRear();
        void print();
};