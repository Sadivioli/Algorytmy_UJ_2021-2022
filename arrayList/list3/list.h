#ifndef LIST_H
#define LIST_H
#pragma once

const int MAX_SIZE = 10;

class List{
    public:
        void resize(); //funkcja zmieniająca rozmiar tablicy
        bool isFull(); //funkcja mówiąca czy tablica jest pełna, tj. czy trzeba ją zwiększyć
        bool isEmpty(); 
        bool validIndex(int); //funkcja sprawdza czy index mieści sie w zakresie
        bool contains(int); //funkcja sprawdza czy element istnieje
        
    
        List();
        virtual ~List();
        virtual bool insert(int, int){return false;}; //wstawienie elementu element na pozycję index
        virtual bool remove(int){return false;}; //usunięcie elementu na pozycji index
        virtual bool pushFront(int){return false;}; //wstawienie elementu na początek listy
        virtual bool pushBack(int){return false;}; //wstawianie elementu na koniec listy

        virtual void popFront(){}; //usuwa pierwszy element listy
        virtual void popBack(){}; //usuwa ostatni element listy
        virtual void removeAllInstances(int items[]){}; //usuwa wszystkie wystąpienia elementu w liście
        virtual void invert(){}; //odwraca listę

        virtual int retrieve(int){return 0;}; //zwraca element znaleziony na pozycji index
        virtual int back(){return 0;}; //zwraca ostatni element w liście.

        virtual int locate(int){return 0;}; //zwraca pozycję elementu w liście
        virtual int end(){return 0;}; //zwraca indeks pozycji za ostatnim elementem w liście
        virtual int first(){return 0;}; //zwraca indeks pozycji pierwszego elementu w liście
        virtual int next(int){return 0;}; // zwraca pozycję elementu w liście usytuowanego za danym indexem
        virtual int prev(int){return 0;}; //zwraca pozycję elementu w liście usytuowanego przed elementem na pozycji index.
        virtual int last(){return 0;}; //zwraca pozycję ostatniego elementu w liście.
        virtual int size(){return 0;}; //funkcja obliczajaca ilość elementów w liście
        virtual void print(){}; 
};

class ArrayList : public List{
        
    protected:
        //int *items;
        //int items;
        int arrayLength; //długość całej tablicy na której będziemy budować listę
        int listSize; //faktyczna ilość elementów w liście
        void resize(); //funkcja zmieniająca rozmiar tablicy
        bool isFull(); //funkcja mówiąca czy tablica jest pełna, tj. czy trzeba ją zwiększyć
        bool isEmpty(); 
        bool validIndex(int); //funkcja sprawdza czy index mieści sie w zakresie
        
    public:
        int *items;
       //constructor
        ArrayList();
        //deconstrucor
        ~ArrayList();
        bool contains(int); //funkcja sprawdza czy element istnieje
         bool insert(int, int); //wstawienie elementu element na pozycję index
         bool remove(int); //usunięcie elementu na pozycji index
         bool pushFront(int); //wstawienie elementu na początek listy
         bool pushBack(int); //wstawianie elementu na koniec listy

         void popFront(); //usuwa pierwszy element listy
         void popBack(); //usuwa ostatni element listy
         void removeAllInstances(int); //usuwa wszystkie wystąpienia elementu w liście
         void invert(); //odwraca listę

         int retrieve(int); //zwraca element znaleziony na pozycji index (get(int index))
         int back(); //zwraca ostatni element w liście.

         int locate(int); //zwraca pozycję elementu w liście
         int end(); //zwraca indeks pozycji za ostatnim elementem w liście
         int first(); //zwraca indeks pozycji pierwszego elementu w liście
         int next(int); // zwraca pozycję elementu w liście usytuowanego za danym indexem
         int prev(int); //zwraca pozycję elementu w liście usytuowanego przed elementem na pozycji index.
         int last(); //zwraca pozycję ostatniego elementu w liście.
         int size(); //funkcja obliczajaca ilość elementów w liście
         void print(); 
};

#endif