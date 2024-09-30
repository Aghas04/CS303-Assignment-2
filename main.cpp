#include <iostream>
#include <vector>
#include "Linked_list.h"

using namespace std;

int main() {
    int operation = 0;
    
    while (!(operation == -1)) {
        operation = menu();
        if (operation == 1) {
            cout << "create the Linked list object" << endl;
            Linked_List<int> list;
            cout << "check if list is empty" << endl;
            if (list.empty()) {
                cout << "List is  empty" << endl;
            }
            else {
                cout << "list is not empty" << endl;
            }
            cout << "added some values to the front(13,12,18)" << endl;
            list.push_front(13);
            list.push_front(12);
            list.push_front(18);
            list.printList();
            cout << "added some values to the back(15,7,4)" << endl;
            list.push_back(15);
            list.push_back(7);
            list.push_back(4);
            list.printList();
            cout << "display the front and back item\nFront: " << list.front() << endl << "Back: " << list.back() << endl;
            cout << endl << "List" << endl;
            list.printList();
            cout << endl;
            cout << "remove the front item" << endl;
            list.pop_front();
            list.printList();
            cout << "remove the back item" << endl;
            list.pop_back();
            list.printList();

            cout << "insert item 19 at index 2" << endl;
            list.insert(2, 19);
            list.printList();
            cout << "remove the item at index 1" << endl;
            list.remove(1);
            list.printList();
            cout << "location of 15: Index " << list.find(15) << endl;
        }
        else if (operation == 2) {
            //Create a stack object.
            vector<int> stack;
            cout << "stack vector created" << endl;
            //2) Check the stack is empty or not.
            cout << "checking if the vector is empty" << endl;
            if (stack.size() == 0) {
                cout << "Stack is empty" << endl;
            }
            else {
                cout << "stack is not empty" << endl;
            }
            //3) Insert some integer values onto the stack.
            cout << "added some values to the stack(2,3,4,5) being that five is the last  it is on the top" << endl;
            stack.push_back(2);
            stack.push_back(3);
            stack.push_back(4);
            stack.push_back(5);

            //4) Remove an element from the stack.
            cout << "removed the top(back) item from the stack" << endl;
            stack.pop_back();
            //5) Find the Top of the stack.
            cout << "find the item at the top of stack" << endl;
            cout << stack[stack.size() - 1] << endl;
            //6) Find average value of the stack elements
            cout << "find the avrage of the values in the stack" << endl;
            int total_val = 0;
            float avrage;
            for (int i = 0; i < stack.size(); i++) {
                total_val += stack[i];
            }
            avrage = total_val / stack.size();
            cout << avrage << endl;
        }
        
    }
        
}
