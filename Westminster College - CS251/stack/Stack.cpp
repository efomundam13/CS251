/*
Program Name: Project 2
Programmer: Manny Fomundam
Date: 9/17/2022
Description: Main code and method to determine if parentheses are balanced
*/

#include "Stack.h"
#include <iostream>
#include <fstream>

//Returns true if the parentheses, braces and brackets are balanced, false otherwise
bool isBalanced(string file)
{
    //Creates a stack and a char
    Stack s(200);
    char x;

    //From 0 to the length of the file, increment i each time.
    for(int i = 0; i < file.length(); i++)
    {
        //Pre-Condition: If the file index has a '(' or '[' or '{'
        if (file[i] == '(' || file[i] == '[' || file[i] == '{')
        {
            //Push into the stack
            s.push(file[i]);
            continue;
        }
        //Pre-Condition: If s is empty, return true otherwise return false
        if (s.isEmpty()) {
            return false;
        }
            
        // IF the current character is not opening
        // bracket, then there must be a closing bracket. 
        // So stack can't be empty to this point.
        switch (file[i]) {
        case ')':
            x = s.top();
            //Pop out of the stack
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;
  
        case '}':
            x = s.top();
            //Pop out of the stack
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;
  
        case ']':
            x = s.top();
            //Pop out of the stack
            s.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }
    //Check if the stack is empty
    return (s.isEmpty());
}

//Main method (Driver code)
int main() 
{
    //Get file name
    cout << "Enter the file name --> ";
    string name;
    cin >> name;
    ifstream fin(name.c_str());

    //Pre-Condition: If file doesn't exist, then print "ERROR: Could not open file "
    if (!fin) {
        cerr << "ERROR: Could not open file " << name << endl;
        exit(-1);
    }

    string a;

    //Pre-Condition: While the file is being read, print fin into a
    while(!fin.eof()) {
        fin >> a;
    }

    //Call function
    bool result = isBalanced(a);

    //Pre-Condition: If the results are true it is legal, else the results are illegal
    if(result == true) {
        cout << "legal";
    }
    else {
        cout << "illegal";
    }
}