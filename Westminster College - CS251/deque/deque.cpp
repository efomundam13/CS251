/*
Programmer: Manny Fomundam
Date: October 15, 2022
Description: Create a linked list implementation of a deque
(Main Class)
*/

#include "deque.h"

Deque::Deque() : front(nullptr), back(nullptr), size(0) {}

Deque::~Deque() {
  while (!is_empty()) {
    pop_front();
  }
}

void Deque::push_front(int x) {
  Node* new_node = new Node{x, nullptr, front};
  if (front != nullptr) {
    front->prev = new_node;
  }
  front = new_node;
  size++;
}

int Deque::pop_front() {
  if (is_empty()) {
    return -1;
  }

  int value = front->value;
  Node* old_front = front;
  front = front->next;
  if (front != nullptr) {
    front->prev = nullptr;
  }
  delete old_front;
  size--;
  return value;
}

void Deque::push_back(int x) {
  Node* new_node = new Node{x, back, nullptr};
  if (back != nullptr) {
    back->next = new_node;
  }
  back = new_node;
  size++;
}

int Deque::pop_back() {
  if (is_empty()) {
    return -1;
  }

  int value = back->value;
  Node* old_back = back;
  back = back->prev;
  if (back != nullptr) {
    back->next = nullptr;
  }
  delete old_back;
  size--;
  return value;
}

bool Deque::is_empty() {
  return size == 0;
}

int Deque::size() {
  return size;
}

int main() {
  Deque deque;
  deque.push_front(1);
  deque.push_front(2);
  deque.push_back(3);
  deque.push_back(4);
  deque.print(); // 2 1 3 4
  std::cout << deque.pop_front() << std::endl; // 2
  std::cout << deque.eject_back() << std::endl; // 4
  deque.print(); // 1 3
  std::cout << deque.size() << std::endl; // 2
  std::cout << deque.is_empty() << std::endl; // false

  return 0;
}


