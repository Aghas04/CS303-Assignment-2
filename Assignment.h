#include <iostream>
template <typename Item_Type>
struct SNode {
  //data
  Item_Type data;
  SNode* next;

  SNode(const Item_Type& data_item, SNode* next_ptr = NULL) : data(data_item), next(next_ptr) {}
};