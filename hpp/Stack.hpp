#include "Node.hpp"

class Stack {
private:
   Node* first_;                    //Pointer to the first element
public:
   Stack(void);                     //Constructor
   ~Stack(void);                    //Destructor
   bool empty(void);                //Check if empty stack
   void setFirst(Node* first);      //Set pointer to the first node
   Node* getFirst(void);            //Get pointer to the first element
   void setHead(TDATO element);     //Set element from head
   void deleteFirst(void);          //Delete node from head
   void printItems(void);           //Print the stack of elements
};
