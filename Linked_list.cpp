
#include "Linked_list.h"


template <typename Item_Type>
Linked_List<Item_Type>::Linked_List() : headPtr(nullptr) {}

template<typename Item_Type>
void Linked_List<Item_Type>::push_front(const Item_Type &item) {
  //creates a new item and sets assigns the new data
  SNode<Item_Type>* new_node = new SNode<Item_Type>(item);
  new_node->next = headPtr;//points the new data to what was the top item
  headPtr = new_node;//sets the new data as the top item
  if (num_items == 0) {//if the list is empty set both tail and head ptr the same
    tailPtr = headPtr;
  }
  num_items++;//add a item to the list
}

template<typename Item_Type>
void Linked_List<Item_Type>::push_back(const Item_Type &item) {
  SNode<Item_Type>* new_node = new SNode<Item_Type>(item);//creates a new node with the given data


  if (empty()) {//checks if list is empty and if so then sets the new data as the top and bottem
    headPtr = tailPtr = new_node;
  } else {//if not empty, points the tail ptr to the new node and sets the new node as the tailPtr
    tailPtr->next = new_node;
    tailPtr = new_node;
  }
  num_items++;//add a item to the item count
}

template<typename Item_Type>
void Linked_List<Item_Type>::pop_front() {
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

template<typename Item_Type>
void Linked_List<Item_Type>::pop_back() {
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

template<typename Item_Type>
Item_Type Linked_List<Item_Type>::front() {
  if (empty()) {//check if the list is empty
    throw runtime_error("the list is empty");
  }
  else {
    return headPtr->data;//return the headPtrs data
  }
}


template<typename Item_Type>
Item_Type Linked_List<Item_Type>::back() {
  if (empty()) {//check if the list is empty
    throw runtime_error("the list is empty");
  }
  else {
    return tailPtr->data;//return the tailPtr data
  }
}


template<typename Item_Type>
bool Linked_List<Item_Type>::empty() {
  return num_items == 0;//return the bool if there is 0 items in the list
}

template<typename Item_Type>
void Linked_List<Item_Type>::insert(size_t index, const SNode<Item_Type> &item) {
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

template<typename Item_Type>
void Linked_List<Item_Type>::printList() {
  SNode<Item_Type>* current = headPtr;//sets inital
  while (current != nullptr) {//goes untill the end
    cout << current->data << " -> ";
    current = current->next;
  }
  cout << "nullptr" << endl;
}

template<typename Item_Type>
bool Linked_List<Item_Type>::remove(size_t index) {
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

template<typename Item_Type>
size_t Linked_List<Item_Type>::find(const Item_Type &item) {
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