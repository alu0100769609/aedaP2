#include <iostream>

typedef int TDATO;

class Node {
private:
   TDATO element_;                     //Item
   Node* next_;                        //Pointer

public:
   Node(TDATO element);               //Constructor with element
   ~Node();                            //Destructor
   void setNext(Node* next);           //Set pointer to the next
   Node* getNext(void);                //Get pointer of the next
   void setElement(TDATO element);     //Set node item
   TDATO getElement(void);             //Get node item
};
