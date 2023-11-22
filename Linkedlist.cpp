#include <iostream>
#include "Linkedlist.hpp"
#include "Node.hpp"

Linkedlist::Linkedlist(/* args */)
{
    head = nullptr;
    tail = nullptr;
}

Linkedlist::~Linkedlist()
{
    Node* temp = head;
    while(temp != nullptr){
        Node *temp2 = temp->getNext();
        delete temp;
        temp = temp2;
    }

    // head = nullptr;
    // tail = nullptr;
}

void Linkedlist::setHead(Node *head){
    this->head = head;
}

Node *Linkedlist::getHead(){
    return this->head;
}

void Linkedlist::setTail(Node *tail){
    this->tail = tail;
}

Node *Linkedlist::getTail(){
    return this->tail;
}

bool Linkedlist::insertNode(std::string word, int token){
    
    bool pass = true;
    Node *temp_ptr = head;

    while (temp_ptr != nullptr){ // check if the word is already in the linked list
        if (temp_ptr->getWord() == word){
            pass = false;
            break;
        }
        temp_ptr = temp_ptr->getNext();
    }

    if (pass == true){

        Node *new_node = new Node(word, token);
        if (head == nullptr){                // if the linked list is empty
            this->head = new_node;
            this->tail = new_node;
        }
        else{                               // add the new node to the end of the linked list
            tail->setNext(new_node);
            tail = new_node;
        }
    } 

    return pass;
}