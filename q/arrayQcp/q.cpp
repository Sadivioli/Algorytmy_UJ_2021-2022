#include "q.h"
using namespace std;

template<typename T>
ArrayBasedQueue<T>::ArrayBasedQueue() {
    front = rear = size = 0;
    items = new T[MAX_SIZE];
}

template<typename T>
ArrayBasedQueue<T>::~ArrayBasedQueue() {
    front = rear = size = 0;
}

template<typename T>
bool ArrayBasedQueue<T>::isEmpty() {
    return size == 0;
}

template<typename T>
bool ArrayBasedQueue<T>::isFull() {
    return size == MAX_SIZE;
}
template<typename T>
int ArrayBasedQueue<T>::getSize() {
    return size;
}

template<typename T>
T ArrayBasedQueue<T>::getFront() {
    if (isEmpty()) {
        return 0;
    }
    return items[front];
}

template<typename T>
T ArrayBasedQueue<T>::getRear() {
    if (isEmpty()) {
        return 0;
    }
    return items[size-1];
}

template<typename T>
void ArrayBasedQueue<T>::print(){
    int numItems = getSize();
    for (int i = 0; i < numItems; i++) {
        cout << items[i] << " ";
    }
    cout << endl;
}

template<typename T>
void ArrayBasedQueue<T>::enqueue(T &value) {
    if (isFull()) {
        cout << "Kolejka jest pełna!" << endl;
        return;
    }else{
        //int numItems = sizeof(items)/sizeof(items[0]);
        items[rear] = value;
        rear = (rear + 1) % MAX_SIZE;
    }
    size++;
}


template<typename T>
void ArrayBasedQueue<T>::dequeue() {
    if (isEmpty()) {
        cout << "Kolejka jest pusta!" << endl;
        return;
    }
    //delete items[front];
    front = (front + 1) % MAX_SIZE;
    size--;
}


template class ArrayBasedQueue<int>;