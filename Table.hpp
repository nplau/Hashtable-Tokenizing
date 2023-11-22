#ifndef TABLE_HPP
#define TABLE_HPP

#include <iostream>
#include "Linkedlist.hpp"
#include "Node.hpp"

class Table
{
private:
    int size;
    int hashtable;
    Linkedlist **table;
    std::string *arr;
    int token;
    
public:
    Table();       // default constructor
    Table(int m);  // constructor with parameters
    ~Table();

    bool insert (std::string word);
    bool read (std::fstream& fin);
    int tokenize (std::string word);
    std::string retrieve (int t);
    std::string print (int k);
    int hash(std::string word);
    void increase();

};

#endif