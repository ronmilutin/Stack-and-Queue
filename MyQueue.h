/* Assignment C++: 1
   Author: Ido Shwartz, ID: 318732856
   Author: Ron Milutin, ID: 316389584
*/

#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <vector>
#include <iostream>
using namespace std;

class MyQueue{
private:
    vector<int> elements;
    int maxQ;

public:
    MyQueue(int maxQ); // Constructor
    ~MyQueue(); // Destructor

    bool enQueue(int val); // insert a new element at the end of the queue. Return if succeed
    bool deQueue(); // remove the next element in the queue. Return if succeed
    bool isEmpty() const; // return if the queue is empty
    int peek() const; // returns the value of the first element in the queue


    const vector<int>& getElements() const; // Getter for the queue
    friend ostream& operator<<(ostream& os, const MyQueue& queue); // print the queue

};
#endif //MYQUEUE_H



