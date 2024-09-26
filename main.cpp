#include <iostream>
#include <vector>
#include "Linked_list.h"

using namespace std;
/*
//template initalizer
template <typename Item_Type>
class Linked_List {
protected: //class variables : headPtr is the top item and tailPtr is the bottem item
  SNode<Item_Type>* headPtr;
  SNode<Item_Type>* tailPtr;
  int num_items = 0;//the amount on items in the list
public:
  Linked_List() : headPtr(nullptr) {}//the cosntructior
  //the function to add items to the front
  void push_front(const Item_Type& item) {
    //creates a new item and sets assigns the new data
    SNode<Item_Type>* new_node = new SNode<Item_Type>(item);
    new_node->next = headPtr;//points the new data to what was the top item
    headPtr = new_node;//sets the new data as the top item
    if (num_items == 0) {//if the list is empty set both tail and head ptr the same
      tailPtr = headPtr;
    }
    num_items++;//add a item to the list
  }
//the function adds a item to the back
  void push_back(const Item_Type& item) {
  SNode<Item_Type>* new_node = new SNode<Item_Type>(item);//creates a new node with the given data
  
  
  if (empty()) {//checks if list is empty and if so then sets the new data as the top and bottem
    headPtr = tailPtr = new_node;
  } else {//if not empty, points the tail ptr to the new node and sets the new node as the tailPtr
    tailPtr->next = new_node;
    tailPtr = new_node;
  }
  num_items++;//add a item to the item count
}
//the function removes the front item
  void pop_front() {
    if (!empty()) {//checking if the list is empty
      SNode<Item_Type>* old_head = headPtr;//sets the head
      headPtr = headPtr->next;//set the next node as the head
      delete old_head;//delete the old head
      num_items--;//remove one node from the count
      if (empty()) {//if the list is empty set tailPtr as null
        tailPtr = nullptr;
      }
    }
  }
//the function remvoes the back item
  void pop_back() {
    if (empty()) {//check if the list is empty if so return
      return;
    }
    if (headPtr == tailPtr) {//check if there is one item in the list, if so then headptr and tailptr would be the same
      delete headPtr;//delete the item
      headPtr = tailPtr = nullptr;//set both to null
    } else {
      SNode<Item_Type>* current = headPtr;//create the headptr
      while (current->next != tailPtr) {
        current = current->next;//iterate to the last node that is not the tailPtr
      }
      delete tailPtr;//delete the tail Ptr
      tailPtr = current;//set the tailptr to the sencond to ast node
      tailPtr->next = nullptr;//set the tail pointers next to null
    }
    num_items--;//reduce the size by one
  }
//the fucntion returns the top item
  Item_Type front() {
    if (empty()) {//check if the list is empty
      throw runtime_error("the list is empty");
    }
    else {
      return headPtr->data;//return the headPtrs data
    }
  }
//the function returns the back item
  Item_Type back() {
    if (empty()) {//check if the list is empty
      throw runtime_error("the list is empty");
    }
    else {
      return tailPtr->data;//return the tailPtr data
    }
  }
//the function returns a bool if there is items in the list
  bool empty() {
    return num_items == 0;//return the bool if there is 0 items in the list
  }
//the function inserts a node at a specified index
  void insert(size_t index, const SNode<Item_Type>& item) {
    if (index == 0) {//check if the index is 0 therefore use push_front
      push_front(item.data);
      return;
    }
    if (index == num_items) {
      push_back(item.data);//check if they want to add to the back then use push_back
      return;
    }
    if (index > num_items) {//check if the index is out of range
      throw runtime_error("the index is out of range");
      return;
    }
    SNode<Item_Type>* current = headPtr;//set the current as HeadPtr
    int cur_index = 0; //the current index
    while (current != nullptr) {//while the current node is not null
      if (cur_index == index - 1) {//stops at the index before the set index
        SNode<Item_Type>* new_node = new SNode<Item_Type>(item);
        new_node->next = current->next;//sets the next node to the currents next
        current->next = new_node;//sets the current to point at the new
      }
      current= current->next;
      cur_index++;
    }
  }
//the function prints the list
  void printList() {
    SNode<Item_Type>* current = headPtr;//sets inital
    while (current != nullptr) {//goes untill the end
      cout << current->data << " -> ";
      current = current->next;
    }
    cout << "nullptr" << endl;
  }
//the fucntion removes a node at a specified index
  bool remove(size_t index) {
    if (index > num_items || empty()) {//return if the index is out of range or the list is empty
      return false;
    }
    if (index == 0 ) {
      pop_front();//if they want to remove the first index then pop_front
      return true;
    }
    SNode<Item_Type>* current = headPtr;
    int cur_index = 0;
    
    while (current != nullptr) {
      if (cur_index == index - 1) {//iterate thrugh the list and stop at the index-1
        SNode<Item_Type>* remove_node = current->next;
        current->next = remove_node->next;

        if (remove_node == tailPtr) {
          tailPtr = current;
        }
        delete remove_node;
        num_items--;

      }
      current= current->next;
      cur_index++;
    }
    return true;
  }
//the function returns the index of the first apperance of the given item
  size_t find(const Item_Type& item) {
    SNode<Item_Type>* current = headPtr;
    int cur_index = 0;
    while (current != nullptr) {//iterate thrugh the list
      if (current->data == item) {
       return cur_index;//return if item is found
      }
      cur_index++;
      current = current->next;
    }
    return cur_index;//return the size if not found
  }
};
*/
int main() {
  Linked_List<int> list;
  list.push_front(13);
  list.push_front(12);
  list.push_back(15);
  list.push_back(7);
  list.pop_front();
  list.pop_back();
  
  cout << list.front() << endl;
  cout << list.back() <<endl;
  list.insert(2, 19);
  list.printList();
  list.remove(1);
  list.printList();
  cout << list.find(13) << endl;
  //Create a stack object.
  vector<int> stack;
  //2) Check the stack is empty or not.
  if (stack.size() == 0) {
    cout << "Stack is empty" << endl;
  } else {
    cout << "stack is not empty" << endl;
  }
  //3) Insert some integer values onto the stack.
  stack.push_back(2);
  stack.push_back(3);
  stack.push_back(4);
  stack.push_back(5);

  //4) Remove an element from the stack.
  stack.pop_back();
  //5) Find the Top of the stack.
  cout << stack[stack.size() - 1] << endl; 
  //6) Find average value of the stack elements
  int total_val = 0;
  float avrage;
  for (int i = 0; i < stack.size(); i++) {
    total_val += stack[i];
  }
  avrage = total_val/stack.size();
  cout << avrage << endl;
}