#include "linkedlist.hpp"
#include <iostream>

LinkedList::LinkedList():head(nullptr){
}

LinkedList::~LinkedList(){
  Node* current = head;
  while(current != nullptr){
    Node* next = current->next;
    delete current;
    current = next;
  }
}

void LinkedList::insertFirst(int value){
  Node* newNode = new Node;
  newNode->data = value;
  newNode->next = head;
  head = newNode;
}

void LinkedList::insertLast(int value){
  Node* newNode = new Node;
  newNode->data = value;
  newNode->next = nullptr;

  if(head == nullptr){
    head = newNode;
  } else {
    Node* current = head;
    while(current->next != nullptr){
      current = current->next;
    }
    current->next = newNode;
  }
}

void LinkedList::deleteByValue(int value){
  Node* current = head;
  Node* prev = nullptr;

  while(current != nullptr){
    if(current->data == value){
      if(prev == nullptr){
        head = current->next;
      } else {
        prev->next = current->next;
      }
      delete current;
      return;
    }
    prev = current;
    current = current->next;
  }
}

void LinkedList::display() const{
  Node* current = head;
  if (head == nullptr) {
    std::cout << "List is empty." << std::endl;
    return;
  }
  
  std::cout << "[";
  while(current != nullptr){
    if (current->next == nullptr){
      std::cout << current->data << "]" << std::endl;
    } else {
      std::cout << current->data << ",";
    }
    current = current->next;  
  }
  std::cout << std::endl;
}