#include "hash.h"
using namespace std;

template<class T>
HashTable<T>::HashTable(int SIZE){
    this->size = SIZE;
    for(int i = 0; i < SIZE; i++){
        array[i] = new Node;
        array[i]->key = 0;
        array[i]->next = NULL;
    }
}

template<class T>
HashTable<T>::~HashTable(){
    for(int i = 0; i < SIZE; i++){
        Node * temp = array[i];
        while(temp != NULL){
            Node * temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
    }
}

template<class T>
int HashTable<T>::hash(T x){
    if constexpr(is_arithmetic<T>::value){
        return x % SIZE;
    }
    else if constexpr(is_same<T, string>::value){
        int sum = 0;
        for(int i = 0; i < x.length(); i++){
            sum += x[i];
        }
        return sum % SIZE;
    }
    return -1;
}

template<class T>
bool HashTable<T>::insert(const T & x){
    int key = hash(x);
    if (array[key]->key == 0){
        array[key]->key = key;
        array[key]->value = x;
        return true;
    }
    else{
        Node * temp = array[key];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new Node;
        temp->next->key = key;
        temp->next->value = x;
        temp->next->next = NULL;
        return true;
    }
    return false;
}

template<class T>
void HashTable<T>::empty(){
    for(int i = 0; i < SIZE; i++){
        array[i]->key = 0;
        array[i]->next = NULL;
    }
}


template<class T>
void HashTable<T>::printHashTable(){
    for(int i = 0; i < SIZE; i++){
        Node * temp = array[i];
        cout << endl;
        while(temp != NULL){
            cout << "[" << temp->key << "," << temp->value << "] --> ";
            temp = temp->next;
        }
        cout << endl;
    }
}
template<class T>
bool HashTable<T>::remove(const T & x){
    int key = hash(x);
    if (array[key]->key == 0){
        return false;
    }
    else{
        Node * temp = array[key];
        Node * temp2 = temp;
        while(temp->next != NULL){
            if(temp->next->value == x){
                temp2->next = temp->next->next;
                delete temp->next;
                return true;
            }
            temp2 = temp;
            temp = temp->next;
        }
        return false;
    }
}

template <typename T>
bool HashTable<T>::contains(const T & x){
    int key = hash(x);
    if (array[key]->key == 0){
        return false;
    }
    else{
        Node * temp = array[key];
        while(temp != NULL){
            if(temp->value == x){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
}

template class HashTable<int>;
template class HashTable<string>;