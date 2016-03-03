#include "../hpp/Stack.hpp"

Stack::Stack(void) {
   setFirst(NULL);
}

Stack::~Stack(void) {

}

bool Stack::empty() {
   return (first_ == NULL);
}

void Stack::setFirst(Node* first) {
   first_ = first;
}


Node* Stack::getFirst(void) {
   return first_;
}

void Stack::setHead(TDATO element) {
   Node* aux = new Node(element);               //Creating Node with data
   if (empty()) {                               //If stack is empty
      setFirst(aux);                            //First node = aux
   }
   else {                                       //If stack is not empty
      aux->setNext(getFirst());                 //Set next of aux to 1st element
      setFirst(aux);                            // and change 1st element to aux
   }
}

void Stack::deleteFirst() {
   if (empty())
      std::cout << "Empty stack, nothing deleted" << std::endl;
   else {
      if (getFirst()->getNext() == NULL) {            //If only one element
         Node* aux = getFirst();                //Create aux pointer to first
         setFirst(NULL);                        //Set first = null
         delete aux;                            //Delete node
      }
      else {                                    //If more than one element
         Node* aux = getFirst();                //Create aux pointer to first
         setFirst(aux->getNext());              //Set first = 2nd element
         delete aux;                            //Delete node (old first)
      }
      std::cout << "Deleted" << std::endl;
   }
}

void Stack::printItems() {
   if (empty())
      std::cout << "The stack is empty" << std::endl;
   else {
      Node* aux = getFirst();                   //Create aux pointer to first
      do{
         std::cout << aux->getElement() << " "; //Print item of stack
         aux = aux->getNext();                  //Iterate to the next
      } while (aux != NULL);                    //While no end of stack
      std::cout << "\n";
   }
}
