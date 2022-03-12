#include "q.h"
using namespace std;

template <typename T>
PointerBasedQueue<T>::PointerBasedQueue() {
    header = new Node;
    header->next = NULL;
    front = header;
    rear = header;
    size = 0;
}
template <typename T>
PointerBasedQueue<T>::~PointerBasedQueue() {
    Node *temp;
    while (front != NULL) {
        temp = front;
        front = front->next;
        delete temp;
    }
}
template <typename T>
bool PointerBasedQueue<T>::isEmpty() const {
    return front == rear;
}
template <typename T>
int PointerBasedQueue<T>::getSize() const {
    return size;
}
template <typename T>
void PointerBasedQueue<T>::enqueue(T &value) {
    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;
    rear->next = temp;
    rear = temp;
    size++;
}
template <typename T>
void PointerBasedQueue<T>::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    Node *temp = front;
    front = front->next;
    delete temp;
    header = front;
    size--;
}
template <typename T>
T PointerBasedQueue<T>::getFront() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return front->data;
}
template <typename T>
T PointerBasedQueue<T>::getRear() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return rear->data;
}
template <typename T>
void PointerBasedQueue<T>::print() {
    Node *temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

template class PointerBasedQueue<int>;