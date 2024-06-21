/* Assignment C++: 1
   Author: Ido Shwartz, ID: 318732856
   Author: Ron Milutin, ID: 316389584
*/

#ifndef STACKNODE_H
#define STACKNODE_H

class StackNode{
private:
    int data;
    StackNode* next;
public:
    StackNode(int val = 0, StackNode* nextP = nullptr);
    ~StackNode();

    int getData() const;
    void setData(int val);
    StackNode* getNext() const;
    void setNext(StackNode* node);

};

#endif //STACKNODE_H

