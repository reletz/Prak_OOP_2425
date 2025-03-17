#include "stack.hpp"
#include <iostream>

//ctor
Stack::Stack():top(-1){
}

//pop
void Stack::pop(){
  if(!isEmpty()){
    top--;
  }
}

//push
void Stack::push(int value){
  if(!isFull()){
    top++;
    data[top] = value;
  }
}

//peek
int Stack::peek() const{
  return data[top];
}

//isEmpty
bool Stack::isEmpty() const{
  return top == -1;
}

//isFull
bool Stack::isFull() const{
  return top == MAX_SIZE - 1;
}