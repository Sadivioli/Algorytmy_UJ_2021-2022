#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next; //mogą być prywatne ale trzeba użyć get i st
        //konstruktor i destruktor 
        Node(int data);
        ~Node();
};

Node::Node(int data){
    this->data = data;
    next = NULL;
}

Node::~Node(){};

class LinkedList{
    private:
        Node *head;
        Node *tail;
        int size; //ile jest node w liście
    public:
        LinkedList();
        ~LinkedList();
        int getSize();
        bool isEmpty();
        bool validIndex(int index);
        void append(int data); //dodawanie nowego elementu do listy
        void prepend(int data);//dodawanie elementu na początek listy (new head)
        void printList(); //wypisanie listy
        void rmFisrt(); //usun pierwszy element listy
        void rmLast(); //usun ostatni element listy
        void rmAt(int index); //usun element listy na danym "indeksie"
        void appendAt(int index, int data); //usun element listy na danym "indeksie"
};

LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
    size = 0;
}
LinkedList::~LinkedList(){
    Node *next;
    while (head != NULL){
        next = head->next;
        delete head;
        head = next;
    }
    
}
int LinkedList::getSize(){
    return size;
}
bool LinkedList::validIndex(int index){
    if (index < 1 || index >= size){
        return false;
    }
    return true;
}
bool LinkedList::isEmpty(){
    if(head == NULL){
        return true;
    }return false;
}
void LinkedList::append(int data){
    Node *node = new Node(data);
    //kiedy lista jest pusta
    if(isEmpty()){
        head = node;
        tail = node;
    }else{//kiedy coś już się w nej znajduje
        tail->next = node;
        tail = node;
    }
    size++;
}
void LinkedList::prepend(int data){
    Node *node = new Node(data);
    //kiedy lista jest pusta
    if (isEmpty()){
       head = node;
       tail = node;
    }else{
        Node *temp = head;
        head = node;
        node->next = temp;
    }
    size++;
}
void LinkedList::printList(){
    //tworzymy tymczasowy pointer, wskazującu na head
    Node *temp = head;

    //wypisujemy dane wzkazywane przez ten pointer, aż zacznie wskazywać na null
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void LinkedList::rmFisrt(){
    if (!isEmpty()){
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }  
}
void LinkedList::rmLast(){
    if (!isEmpty()){
        //w liście znajduje się jeden element (head)
        if (head->next == NULL){
            rmFisrt();
        }else{
            Node *curr = head;
            Node *prev;
            while (curr->next != NULL){
                prev = curr;
                curr = curr->next;
            }
            tail = prev;
            prev->next = head;
            delete curr;
            size--;
        }
        
        
    }  
}
void LinkedList::rmAt(int index){
    if (validIndex(index)){
        if (index == 1){rmFisrt();}
        else if (index == size){rmLast();}
        else if (head != NULL){
            Node *curr = head;
            Node *prev;
            for (int i = 1; i < index; i++){
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr;
            delete curr;
            size--;
        }
        
    }
    
}
void LinkedList::appendAt(int index, int data){
    if (index > 0 && index <= size + 1){
        if (index == 1){prepend(data);}
        else if (index == size + 1){append(data);}
        else if (head != NULL){
            Node *node = new Node(data);
            Node *curr = head;
            Node *prev;
            for (int i = 1; i < index; i++){
                prev = curr;
                curr = curr->next;
            }
            prev->next = node;
            node->next = curr;
            size++;
        }
        
    }
}

int main(){
    LinkedList newList;
    
    for (int i = 0; i < 30; i++){
        int x = rand() % 100; 
        if ((i % 6) == 0){
           newList.prepend(x);
        }else{
            newList.append(x);
        }
        
    }
    newList.appendAt(15, 2137);
    newList.printList();
}