#include "stack.h"

using namespace std;

void ArrayBasedStack::push(int value){
    stack.push_front(value);
}
void ArrayBasedStack::pop(){
    stack.pop_front();
}
int ArrayBasedStack::peek(){
    return stack.front();
}
bool ArrayBasedStack::isEmpty(){
    return stack.isEmpty();
}
bool ArrayBasedStack::isFull(){
    return false;
}
int ArrayBasedStack::size(){
    return stack.len();
}
void ArrayBasedStack::print(){
    stack.printList();
}