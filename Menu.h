/* Assignment C++: 1
   Author: Ido Shwartz, ID: 318732856
   Author: Ron Milutin, ID: 316389584
*/

#ifndef MENU_H
#define MENU_H

#include "Stack.h"
#include "MyQueue.h"

class Menu{
public:
    Menu(); // Constructor
    ~Menu(); // Destructor

    void mainMenu() const;
    void stackMenu(Stack& stack) const;
    void queueMenu(MyQueue& queue) const;
};

#endif //MENU_H