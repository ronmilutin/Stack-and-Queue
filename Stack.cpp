/* Assignment C++: 1
   Author: Ido Shwartz, ID: 318732856
   Author: Ron Milutin, ID: 316389584
*/

#include "Stack.h"
#include <iostream>
#include <climits>

using namespace std;

// Constructor initializes top to NULL
Stack::Stack() : top(nullptr){}

// Destructor
Stack::~Stack() {
    // implement if needed
}

// Inserts a new element at the top of the stack
void Stack::push(int val) {
    StackNode* newNode = new StackNode(val);
    newNode->setNext(top);
    top = newNode;
}

// Removes the top element on the stack
void Stack::pop(){
    if (isEmpty()){
        cout<<"Stack is empty" << endl;
        return;
    }
    StackNode* temp = top;
    int poppedValue = top->getData(); // Get the value before popping
    top = top->getNext();
    cout<<"Removing "<<poppedValue<<endl;
    delete temp;
}

bool Stack::isEmpty() const {
    return (top == nullptr);
}

int Stack::peek() const {
    if (!isEmpty()){
        return top->getData();
    } else{
        return INT_MIN;
    }
}

// operators:
Stack Stack::operator+(const Stack &other) const {
    Stack result = other;

    // Use a temporary stack to store elements in reverse order
    Stack tempStack;

    // Temporary pointers to iterate over the current stack and the other stack
    StackNode* currentNode = top;

    // Copy elements from the current stack to tempStack in reverse order
    while (currentNode != nullptr) {
        tempStack.push(currentNode->getData());
        currentNode = currentNode->getNext();
    }

    // Iterate over the temporary stack and push each element to the concatenated result stack
    StackNode* pt = tempStack.top;
    while (pt != nullptr) {
        result.push(pt->getData());
        pt = pt->getNext();
    }

    // Return the concatenated stack
    return result;
}

Stack Stack::operator+(int val) const {
    Stack result;
    result.push(val); // push val to the empty result stack
    result = *this + result; // result + this stack
    return result;
}

Stack operator+(int val, const Stack& S){
    // // Push an integer to the stack
    Stack result = S;
    result.push(val);
    return result;
}

Stack& Stack::operator+=(int val){

    // Push an integer to the stack
    push(val);
    return *this;
}

bool Stack::operator==(const Stack &other) const {
    // Temporary pointers to iterate over the current stack and the other stack
    StackNode* currentNode = top;
    StackNode* otherNode = other.top;

    // Iterate over the  top of the two stack

    while ((currentNode != nullptr) && (otherNode != nullptr)){
        if (currentNode->getData() != otherNode->getData()){
            return false;
        }

        //move to the next two elements
        currentNode = currentNode->getNext();
        otherNode = otherNode->getNext();
    }

    // Check if both stacks are of the same length
    if (currentNode != nullptr || otherNode != nullptr) {
        return false; // Stacks have different lengths
    }
    return true;
}

ostream& operator<<(ostream& os, const Stack& stack) {
    StackNode* current = stack.top;
    int i=1;

    os << "Stack Elements:"<<endl;
    while (current != nullptr) {
        os << i <<". " << current->getData() << endl;
        i++;
        current = current->getNext();

    }
    os << endl;
    return os;
}
