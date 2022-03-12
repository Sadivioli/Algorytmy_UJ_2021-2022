#include "hash.h"
using namespace std;

int main(){
    const string fruits[]={"orange", "apple", "plum", "tangerine", "pear", "banana", "grape", "peach", "cherry", "mango", "blueberry", "gooseberry", "raspberry", "strawberry", "pinapple", "orange"};

    HashTable<int> intBasedHash(SIZE);
    HashTable<string> stringBasedHash(SIZE);

    for(int i = 0; i < SIZE; i++){
        //intBasedHash.insert(i);
        stringBasedHash.insert(fruits[i]);
    }
    stringBasedHash.printHashTable();
}