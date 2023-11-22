#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include "Node.hpp"

class Linkedlist
{
private:
    Node *head;
    Node *tail;
public:
    Linkedlist(/* args */);
    ~Linkedlist();
    void setHead(Node *head);
    Node *getHead();
    void setTail(Node *tail);
    Node *getTail();
    bool insertNode(std::string word, int token);
};


#endif