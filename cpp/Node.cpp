#include "../hpp/Node.hpp"

Node::Node(TDATO element) {
   setElement(element);
   setNext(NULL);

}

Node::~Node() {

}

Node* Node::getNext(void) {
   return next_;
}

void Node::setNext(Node *next) {
   next_ = next;

}

TDATO Node::getElement(void) {
   return element_;
}

void Node::setElement(TDATO element) {
   element_ = element;
}
