#include "stack.h"

void ArrayBasedStack::push(int value){
    stack.pushBack(value);
}
void ArrayBasedStack::pop(){
    stack.popBack();
}
int ArrayBasedStack::peek(){
    return stack.back();
}
bool ArrayBasedStack::isEmpty(){
    return stack.isEmpty();
}
bool ArrayBasedStack::isFull(){
    return stack.isFull();
}
void ArrayBasedStack::print(){
    stack.print();
}
int ArrayBasedStack::size(){
    return stack.size();
}