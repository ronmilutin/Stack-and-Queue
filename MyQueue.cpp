/* Assignment C++: 1
   Author: Ido Shwartz, ID: 318732856
   Author: Ron Milutin, ID: 316389584
*/

#include "MyQueue.h"
#include <iostream>

using namespace std;

// Constructor
MyQueue::MyQueue(int maxQ) {}

// Destructor
MyQueue::~MyQueue() {}

bool MyQueue::enQueue(int val) {
    if (elements.size()<maxQ){
        elements.push_back(val); // enter val to the end of the queue
        return true;
    } else {
        return false;
    }
}

bool MyQueue::deQueue() {
    if (!isEmpty()){
        elements.erase(elements.begin()); // delete the first element in the queue
        return true;
    } else {
        return false;
    }
}

bool MyQueue::isEmpty() const {
    return elements.empty();
}

int MyQueue::peek() const {
    if (!isEmpty()) {
        return elements.front();
    } else {
        return -1;
    }
}

// Getter for the queue
const vector<int>& MyQueue::getElements() const {
    return elements;
}

ostream& operator<<(ostream& os, const MyQueue& queue) {
    const vector<int>& elements = queue.getElements();

    // Check if the vector is not empty
    if (!elements.empty()) {
        // Print the first element without " <- "
        os << elements[0];

        // Print the rest of the elements with " <- "
        for (int i = 1; i < elements.size(); ++i) {
            os << " <- " << elements[i];
        }
    }

    return os;
}

