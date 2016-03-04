#include "Node.hpp"

template <class TDATO>
class Stack {
private:
   Node<TDATO>* first_;                    //Pointer to the first element
public:
   Stack(void) { setFirst(NULL); }                     //Constructor
   ~Stack(void) {}                    //Destructor
   bool empty(void) { return (first_ == NULL); }                //Check if empty stack
   void setFirst(Node<TDATO>* first) { first_ = first; }      //Set pointer to the first node
   Node<TDATO>* getFirst(void) { return first_; }            //Get pointer to the first element
   void setHead(TDATO element) {     //Set element from head
      Node<TDATO>* aux = new Node<TDATO>(element);               //Creating Node with data
      if (empty()) {                               //If stack is empty
         setFirst(aux);                            //First node = aux
      }
      else {                                       //If stack is not empty
         aux->setNext(getFirst());                 //Set next of aux to 1st element
         setFirst(aux);                            // and change 1st element to aux
      }
   }
   void deleteHead(void) {           //Delete node from head
      if (empty())
         std::cout << "Empty stack, nothing deleted" << std::endl;
      else {
         if (getFirst()->getNext() == NULL) {            //If only one element
            Node<TDATO>* aux = getFirst();                //Create aux pointer to first
            setFirst(NULL);                        //Set first = null
            delete aux;                            //Delete node
         }
         else {                                    //If more than one element
            Node<TDATO>* aux = getFirst();                //Create aux pointer to first
            setFirst(aux->getNext());              //Set first = 2nd element
            delete aux;                            //Delete node (old first)
         }
      }
   }
   void printItems(void) {           //Print the stack of elements
      if (empty())
         std::cout << "The stack is empty" << std::endl;
      else {
         Node<TDATO>* aux = getFirst();                   //Create aux pointer to first
         do{
            std::cout << aux->getElement() << " "; //Print item of stack
            aux = aux->getNext();                  //Iterate to the next
         } while (aux != NULL);                    //While no end of stack
         std::cout << "\n";
      }
   }
};
