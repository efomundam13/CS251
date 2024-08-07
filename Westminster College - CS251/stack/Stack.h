/*
Program Name: Project 2
Programmer: Manny Fomundam
Date: 9/22/2022
Description: Interface and implementation of methods.
*/

#ifndef STACK_H
#define STACK_H

int const MAX = 50;

#include<iostream>
using namespace std;

class Stack
{
    private: 
    int size;
    int top_;
    char* stack;
       
    public:
        /*
        Default construtor with no argument
        */
        Stack();

        /*
        Default construtor with one parameter
        */
        Stack(int capacity);

        /*
        Inserts the element to the top of the stack
        */
        void push(char val);

        /*
        Removes an item from the top of the stack
        */
        void pop();

        /*
        Returns true if stack is empty, false otherwise
        */
        bool isEmpty();

        /*
        Default construtor with no argument
        */
        void makeEmpty();
        

        /*
        Accessor - retruns a refernece to the top item (const)
        */
        char top() const;
};

// Constructor with no parameter
Stack::Stack(){
    //Set size and top_ equal to 0
    size = 0;
    top_ = 0;
}

// Constructor with one parameter
Stack::Stack(int capacity) {
    //Set size to the capacity, top_ to 0 and, make a new stack.
    size = capacity;
	top_ = 0;
	stack = new char[size];
}

//Inserts the element to the top of the stack
void Stack::push(char val) {
    //If Stack is greater than the set max, print stack is full and end program
    if(size > MAX) {
        cout << "Stack is full!";
        exit(-1);
    }
    //Set the location in teh stack equal to the new value
    stack[top_] = val;
    //Increment top after its been added
    ++top_;
}

// Removes and returns the top element of this stack
void Stack::pop() {
    //If Stack is empty, print stack is empty and end program
    if(size < 1) {
        cout << "Stack is empty!";
        exit(-1);
    }
    //Decrement top after its been removed
    --top_;
}

//Returns true if the stack is empty
//False otherwise
bool Stack::isEmpty() {
    //If Stack is empty, return true, else return false
   if(top_ < 1) {
    return true;
   }
   return false;
}

//Makes the list empty and sets top to 0
void Stack::makeEmpty() {
   top_ = 0;
}

//Returns a refernece to the top item (const)
char Stack::top() const {
    //If top is less than 1, then say stack is empty and end program
    if(top_ < 1) {
        cout << "Stack is empty!";
        exit(-1);
    }
    //Else print the top element and return it
    cout << "The top element is " << stack[top_ -1] << endl;
    return stack[top_ - 1];
};
#endif