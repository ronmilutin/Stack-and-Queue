/* Assignment C++: 1
   Author: Ido Shwartz, ID: 318732856
   Author: Ron Milutin, ID: 316389584
*/

#ifndef STACK_H
#define STACK_H
#include "StackNode.h"
#include <iostream>
using namespace std;

class Stack{
private:
    StackNode* top;

public:

    Stack(); // Constructor
    ~Stack(); // Destructor

    void push(int val); // Inserts a new element at the top of the stack
    void pop(); // Removes the top element on the stack
    bool isEmpty() const; //Returns if the stack is empty or not
    int peek() const; //Returns the top element present in the stack without modifying the stack

    // Operators
    Stack operator+(const Stack& other) const; // Stack + Stack
    Stack operator+(int val) const; // Stack + int
    friend Stack operator+(int val, const Stack& S); // int + Stack
    Stack& operator+=(int val); //Stack = int + Stack
    bool operator==(const Stack& other) const; // StackA == StackB
    friend ostream& operator<<(ostream& os, const Stack& stack); // Print the Stack

};
#endif //STACK_H
