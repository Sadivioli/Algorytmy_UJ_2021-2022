#include "linkedlist.h"

List::List(){}
List::~List(){}

Node::Node(int data){
    this->data = data;
    this->next = NULL;
}
Node::~Node(){};
LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
    size = 0;
}
LinkedList::~LinkedList(){
    Node *next;
    while(head != NULL){
        next = head->next;
        delete (head);
        head = next;
    }
}
int LinkedList::len(){
    return size;
}
bool LinkedList::validIndex(int index){
    if (index < 0 || index >= size){
        return false;
    }
    return true;
}
bool LinkedList::isEmpty(){
    if(head == NULL){
        return true;
    }return false;
}
void LinkedList::printList(){
    Node *temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
bool LinkedList::insert(int index, int data){
    if (index > 0 && index <= size + 1){
        if (index == 0){push_front(data);}
        else if (index == size + 1){push_back(data);}
        else if (head != NULL){
            Node *node = new Node(data);
            Node *curr = head;
            Node *prev;
            for (int i = 0; i < index; i++){
                prev = curr;
                curr = curr->next;
            }
            prev->next = node;
            node->next = curr;
            size++;
        }
    }
    return true;
}

bool LinkedList::remove(int index){
    if (validIndex(index)){
        if (index == 0){pop_front();}
        else if (index == size){pop_back();}
        else if (head != NULL){
            Node *curr = head;
            Node *prev;
            for (int i = 0; i < index; i++){
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            delete (curr);
            size--;
        }   
    }
    return true;
}

int LinkedList::retrive(int index){
    if(validIndex(index)){
        Node *curr = head;
        Node *prev;
        for(int i = 0; i < index; i++){
            prev = curr;
            curr = curr->next;
        }
        return curr->data;
    }else{
        return -1;
    }
}


int LinkedList::locate(int data){
        Node *curr = head;
        Node *prev;
        for(int i = 0; i < size; i++){
            if(curr->data == data){
                return i;
            }
            prev = curr;
            curr = curr->next;
        }
        return -1;
}

bool LinkedList::push_back(int data){
    Node *node = new Node(data);
    //kiedy lista jest pusta
    if(isEmpty()){
        head = node;
        tail = node;
    }else{
        tail->next = node;
        tail = node;
    }
    size++;
    return true;
}
bool LinkedList::push_front(int data){
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
    return true;
}

bool LinkedList::pop_front(){
    if (!isEmpty()){
        Node *temp = head;
        head = head->next;
        delete (temp);
        size--;
    } 
    return true; 
}
bool LinkedList::pop_back(){
    if (!isEmpty()){
        //w liście znajduje się jeden element (head)
        if (head->next == NULL){
            pop_front();
        }else{
            Node *curr = head;
            while (curr->next->next != NULL){
                curr = curr->next;
            }
            delete (curr->next);
            curr->next = NULL;
            size--;
        }
    }
    return true;  
}


Node LinkedList::first(){
    return *head;
}
Node LinkedList::last(){
    Node *curr = head;
    Node *prev;
    for(int i = 0; i < size-1; i++){
        prev = curr;
        curr = curr->next;
    }
    return *curr;
}
int LinkedList::front(){
    return head->data;
}
int LinkedList::back(){
    Node *curr = head;
    Node *prev;
    for(int i = 0; i < size-1; i++){
        prev = curr;
        curr = curr->next;
    }
    return curr->data;
}


void LinkedList::rmDupes(){ 
    Node *curr, *temp, *dup; 
    curr = head; 

    while ((curr != NULL) && (curr->next != NULL)){ 
        temp = curr; 
  
        while (temp->next != NULL){
            if (curr->data == temp->next->data) { 
                dup = temp->next; 
                temp->next = temp->next->next; 
                delete(dup);
                size--;
            } 
            else{
                temp = temp->next; 
            }
        }
        curr = curr->next; 
    } 
} 
void LinkedList::rmVal(int val){
   Node *curr = head;
   Node *prev;
   while (curr != NULL){
       while (curr->data == val){
            Node *temp = curr;
            curr = curr->next;
            if (temp == head){
               head = curr;
            }
            if (prev){
               prev->next = curr;
            }
            delete (temp);
            size--;
        }
        prev = curr;
        curr = curr->next;
   }
}
void LinkedList::reverse(){
    Node *curr = head;
    Node *prev = NULL, *temp = NULL;
    while (curr != NULL){
        temp = curr->next;
        curr->next = prev;

        prev = curr;
        curr = temp;
    }
    head = prev;
}
void LinkedList::rmEvenIndex(){
    Node *curr = head;
    Node *prev;
    for(int i = 0; i < size; i++){
        prev = curr;
        curr = curr->next;
        if ((i%2) == 0){

            prev->next = curr->next;
            delete (curr);
            size--;
        }
        
    }
}