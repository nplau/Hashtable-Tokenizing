#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

class Node
{
private:
    std::string word;
    int token;
    Node *p_next;
public:
    Node(std::string word, int token);
    ~Node();
    void setNext(Node *next);
    Node *getNext();
    std::string getWord();
    void setWord(std::string new_word);
    int getToken();
};

#endif