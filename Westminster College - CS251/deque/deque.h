/*
Programmer: Manny Fomundam
Date: October 15, 2022
Description: Create a linked list implementation of a deque
(Interface and Implementation)
*/

#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>

class Deque {
public:
  Deque();
  ~Deque();

  void push_front(int x);
  int pop_front();
  void push_back(int x);
  int pop_back();

  bool is_empty();
  int size();

private:
  struct Node {
    int value;
    Node* next;
    Node* prev;
  };

  Node* front;
  Node* back;
  int size;
};

#endif