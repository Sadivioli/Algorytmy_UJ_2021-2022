#include "linkedlist.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class ArrayBasedStack {
    private:
        LinkedList stack;
    public:
        void push(int value);
        void pop();
        int peek();
        bool isEmpty();
        bool isFull();
        int size();
        void print();
};