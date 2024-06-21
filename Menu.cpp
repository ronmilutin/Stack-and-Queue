/* Assignment C++: 1
   Author: Ido Shwartz, ID: 318732856
   Author: Ron Milutin, ID: 316389584
*/

#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu() {} // Constructor
Menu::~Menu() {} // Destructor

void Menu::mainMenu() const {
    int choice;
    do {
        cout << "(1) Integer Stack" << endl;
        cout << "(2) Integer Queue Menu" << endl;
        cout << "(3) Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                Stack stack;
                stackMenu(stack);
                break;
            }
            case 2: {
                int queueSize;
                cout << "Enter the size of the queue: ";
                cin >> queueSize;
                MyQueue queue(queueSize);
                queueMenu(queue);
                break;
            }
            case 3:
                cout << "Goodbye!" << endl;
                exit(0);
            default:
                cout << "Invalid selection." << endl;
        }
    } while (choice != 3);
}

void Menu::stackMenu(Stack& stack) const {
    int choice;
    do {
        cout << "*** Manage your integer stack ***" << endl;
        cout << "1. Push new element" << endl;
        cout << "2. Pop element" << endl;
        cout << "3. Check if empty" << endl;
        cout << "4. Print stack elements" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter the value to push: ";
                cin >> value;
                stack.push(value);
                break;
            }
            case 2:
                stack.pop();
                break;
            case 3:
                cout << (stack.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
                break;
            case 4: {
                if (stack.isEmpty()) {
                    cout << "The stack is empty"<< endl;
                }else{
                    cout << stack << endl;
                }
                break;
            }
            case 5:
                break;
            default:
                cout << "Invalid selection." << endl;
        }
    } while (choice != 5);
}

void Menu::queueMenu(MyQueue& queue) const {
    int choice;
    do {
        cout << "*** Welcome to Queue Menu ***" << endl;
        cout << "To select an item, enter" << endl;
        cout << "1. Show Queue" << endl;
        cout << "2. Insert new element" << endl;
        cout << "3. Remove element" << endl;
        cout << "4. Check the first element" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1: { // Print queue elements


                if (queue.isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout <<queue << endl;
                }
                break;
            }
            case 2: { // add element to the queue
                int value;
                cout << "Enter the value to insert: ";
                cin >> value;
                if (queue.enQueue(value)) {
                    cout << "The new queue:" <<  endl;
                    cout <<queue << endl;
                } else {
                    cout << "Queue is full." << endl;
                }
                break;
            }
            case 3: { // remove  element from the queue
                if (queue.deQueue()) {
                    if (queue.isEmpty()){
                        cout << "Queue is empty." << endl;
                    } else{
                        cout << "The new queue:" << endl << queue <<  endl;
                    }

                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
            }
            case 4: {
                int frontValue = queue.peek();
                if (frontValue != -1) {
                    cout << frontValue << endl;
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
            }
            case 5:
                break;
            default:
                cout << "Invalid selection." << endl;
        }
    } while (choice != 5);
}