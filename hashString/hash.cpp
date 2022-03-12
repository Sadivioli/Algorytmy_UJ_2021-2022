#include "hash.h"

template<class T>
HashTable<T>::HashTable(int SIZE){
    this->size = SIZE;
    //this->count = 0;
    for(int i = 0; i < SIZE; i++){
        array[i] = new Node;
        array[i]->key = 0;
        //array[i]->value = NULL;
        array[i]->next = NULL;
    }
}

template<class T>
HashTable<T>::~HashTable(){
    for(int i = 0; i < SIZE; i++){
        Node * tmp = array[i];
        while(tmp != NULL){
            Node * tmp2 = tmp;
            tmp = tmp->next;
            delete tmp2;
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
        for(int i = 0; i < x.size(); i++){
            sum *= x[i];
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
        Node * tmp = array[key];
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = new Node;
        tmp->next->key = key;
        tmp->next->value = x;
        tmp->next->next = NULL;
        return true;
    }
    return false;
}

template<class T>
void HashTable<T>::empty(){
    for(int i = 0; i < SIZE; i++){
        array[i]->key = 0;
        //array[i]->value = NULL;
        array[i]->next = NULL;
    }
}


template<class T>
void HashTable<T>::printHashTable(){
    for(int i = 0; i < SIZE; i++){
        Node * tmp = array[i];
        while(tmp != NULL){
            cout << "Klucz: " << tmp->key << "wartość:  " << tmp->value << ";";
            tmp = tmp->next;
        }
    }
}

template class HashTable<int>;
template class HashTable<string>;