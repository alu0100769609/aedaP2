#include <iostream>

template <class TDATO>
class Node {
private:
   TDATO element_;                     //Item
   Node* next_;                        //Pointer

public:
   Node(TDATO element) {               //Constructor with element
      setElement(element);
      setNext(NULL);
}
   ~Node(){}                           //Destructor
   void setNext(Node* next) { next_= next; }           //Set pointer to the next
   Node* getNext(void) { return next_; }                //Get pointer of the next
   void setElement(TDATO element) { element_ = element; }     //Set node item
   TDATO getElement(void) { return element_;}             //Get node item
};
