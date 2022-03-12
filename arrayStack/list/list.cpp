
#include <iostream>
#include "list.h"
using namespace std;

List::List() {}
List::~List() {}
ArrayList::ArrayList(){
    //inicjalizujemy parametry
    arrayLength = MAX_SIZE;
    listSize = 0;
    items = new int[MAX_SIZE];
};
//deconstrucor
ArrayList::~ArrayList(){
    delete []items;
};

void ArrayList::resize(){
    //zwiększamy rozmiar tablicy x2 za każdym razem kiedy braknie miejsca na nowe elementy
    int *temp = new int[arrayLength*2];
    for (int i = 0; i < arrayLength; i++){
        temp[i] = items[i];
    }
    items = temp;
    arrayLength *= 2;
}


bool ArrayList::isFull(){
    return arrayLength == listSize;
}

bool ArrayList::isEmpty(){
    return listSize == 0;
}

bool ArrayList::validIndex(int index){
    return (index >= 0 && index < arrayLength);
}

bool ArrayList::contains(int element){
    for(int i = 0; i < listSize; i++){
        if(items[i] == element){ return true; }
    } return false;
}
//wstawienie elementu element na pozycję index

bool ArrayList::insert(int index, int element){
    if (isFull()){
        resize();
    }
    if (!(index >= 0 && index <= arrayLength))
        return false;
    if (index == arrayLength){
        pushBack(element);
    }
    
    //trzeba zrobić miejsce na element gdzieś w środku listy, przesuwamy wszystkie elementy od indexu do końca tablicy, o 1 "w prawo"
    for (int i = listSize - 1; i >= index; i--){
        items[i+1] = items[i];
    }
    items[index] = element;
    listSize++;
    return true;
}


bool ArrayList::remove(int index){
    if (!validIndex(index))
        return false;
    //przesuwamy wszystkie elementy od indexu do końca tablicy, o 1 "w lewo"
    for (int i = index+1; i < listSize; i++){
        items[i-1] = items[i];
    }
    //items[listSize-1] = NULL;
    listSize--;
    return true;
}
//wstawianie elementu na koniec listy
bool ArrayList::pushBack(int element){
    //sprawdzamy czy jest miejsce na kolejny element
    if (isFull()){
        resize();
    }
    items[listSize] = element;
    listSize++;
    return items[listSize] == element;
};
bool ArrayList::pushFront(int element){
   return insert(0,element);
}
void ArrayList::popFront(){ remove(0);}
void ArrayList::popBack(){ remove(listSize);}

int ArrayList::retrieve(int index){ 
    return items[index];
}
int ArrayList::back(){ 
    int lastIndex = listSize - 1;
    return items[lastIndex];
}
int ArrayList::locate(int element){ 
    for (int i = 0; i < listSize; i++){
        if (items[i] == element){
            return i;
        }
    }
    return -1;
}
int ArrayList::end(){ return listSize; }
int ArrayList::first(){ return isEmpty() ? -1 : 0; }
int ArrayList::last(){ 
    int a = listSize;
    a -= 1;
    return a; 
}
int ArrayList::size(){ return listSize; }

int ArrayList::next(int index){ return ++index; }
int ArrayList::prev(int index){ return --index; }


void ArrayList::removeAllInstances(int element){
    for (int i = 0; i < listSize; i++){
        if (items[i] == element){
            remove(i);
        }
    }
}
void ArrayList::invert(){
    int temp[listSize];
    for (int i = 0; i < listSize; i++){
        temp[listSize-1-i] = items[i];
    }
    for (int i = 0; i < listSize; i++){
        items[i] = temp[i];
    }
}
void ArrayList::print(){
    for (int i = 0; i < listSize; i++){
        cout << items[i] << " ";
    }
    cout << endl;
}