#include "q.h"
using namespace std;

template<typename T>
ArrayBasedQueue<T>::ArrayBasedQueue() {
    front = rear = -1;
    size = MAX_SIZE;
    items = new T[MAX_SIZE];
}

template<typename T>
ArrayBasedQueue<T>::~ArrayBasedQueue() {
    front = rear = size = 0;
}

template<typename T>
bool ArrayBasedQueue<T>::isEmpty() {
    return (front == -1 && rear == -1);
}

template<typename T>
bool ArrayBasedQueue<T>::isFull() {
    return (rear+1) % MAX_SIZE == front ? true : false;
}
template<typename T>
int ArrayBasedQueue<T>::getSize() {
    return ((rear - front + MAX_SIZE) % MAX_SIZE) +1;
}


template<typename T>
void ArrayBasedQueue<T>::enqueue(T &value) {
    if (isFull()) {
        cout << "Kolejka jest pełna!" << endl;
        return;
    }else{
        items[rear] = value;
        rear = (rear + 1) % MAX_SIZE;
    }
    
}

template <typename T>
int ArrayBasedQueue<T>::dequeue() {
    if (isEmpty()) {
        cout << "Kolejka jest pusta!" << endl;
        return 0;
    }
    int fr = items[front];
    front = (front + 1)%MAX_SIZE;
    return fr;
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
    return items[((rear - 1 + MAX_SIZE) % MAX_SIZE)+1];
}

template<typename T>
void ArrayBasedQueue<T>::print(){
    int numItems = getSize();
    for (int i = 0; i < numItems; i++) {
        cout << items[i] << " ";
    }
    cout << endl;
}

template class ArrayBasedQueue<int>;