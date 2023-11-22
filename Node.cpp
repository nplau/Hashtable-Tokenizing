#include <iostream>
#include "Node.hpp"

Node::Node(std::string word, int token)
{
    this->word = word;
    this->token = token;
    p_next = nullptr;
}

Node::~Node()
{
}

void Node::setNext(Node *next){
    this->p_next = next;
}

Node *Node::getNext(){
    return this->p_next;
}

std::string Node::getWord(){
   return this->word;
}

void Node::setWord(std::string new_word){
    this->word = new_word;
}

int Node::getToken(){
    return this->token;
}


