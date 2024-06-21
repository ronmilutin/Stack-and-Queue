/* Assignment C++: 1
   Author: Ido Shwartz, ID: 318732856
   Author: Ron Milutin, ID: 316389584
*/

#include "StackNode.h"
//using namespace std;

// Constructor initializes data and next pointer
StackNode::StackNode(int val, StackNode* node) {
    data = val;
    next = node;
}

// Destructor
StackNode::~StackNode() {}

// Getter
int StackNode::getData() const {
    return data;
}
StackNode *StackNode::getNext() const {
    return next;
}

// Setter
void StackNode::setData(int val) {
    data = val;
}
void StackNode::setNext(StackNode *node) {
    next = node;
}
