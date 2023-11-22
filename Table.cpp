#include <iostream>
#include <fstream>
#include "Table.hpp"
#include "Linkedlist.hpp"
#include "Node.hpp"

Table::Table(int m)
{
    size = m;
    table = new Linkedlist*[m];
    arr = new std::string [10];

    for (int i = 0; i < m; i++){
        table[i] = new Linkedlist();
    }

    token = 0;
}

Table::~Table()
{
    for (int i = 0; i < size; i++){
        delete table[i];
    }
    delete[] table;

    delete[] arr;
}

bool Table::insert (std::string word){
    // insert word into the hash table
    // keep track of its index

    int arr_index = hash(word); // index of the word to know which part of the array to put it in
    token++;                    // token number of the word

    if (arr_index == -1){       // if the word contains special characters
        return false;
    } else {
        
        bool pass = table[arr_index]->insertNode(word, token); // insert the word into the linked list at the index of the array
        // insert the word into the array "arr"
        if (pass == true){
            if (token == size){ // if the array is full, increase its size
                increase();
            }
            arr[token] = word;
        }
    
        return pass;

    }
                                //Linkedlist *new_list = table[arr_index];
}

bool Table::read (std::fstream& fin){
    // read in a file and insert each word into the hash table
    bool added = false;
    bool pass = false;
    // tokenize the file
    // return true if at least one word was inserted
    // return false if no words were added
    std::string toRead;

    while (fin >> toRead){ // toRead contains the next word in the file

        added = insert(toRead); // insert the word into the hash table

        if (added == true){ // to ensure at least one word was added
            pass = true;
        }
    }

   return pass;
}

int Table::tokenize (std::string word){
    // tokenize the word
    // return the index of the word 

    int arr_index = hash(word); // index of the word to know which part of the array to put it in
    Node *temp;

    if (table[arr_index] != nullptr){ // if the linked list is empty
         temp = table[arr_index]->getHead(); // get the head of the linked list at the index of the array
    }
   
    while(temp != nullptr){ // while the linked list is not empty

        if (temp->getWord() == word){ // if the word is found in the linked list
            return temp->getToken(); // return the token number of the word
        }

        temp = temp->getNext(); // go to the next node in the linked list
    }

    return 0; // return 0 if the word is not found
}

std::string Table::retrieve (int t){
    // retrieve the word at token t
    std::string word;

    if (t < token){
        return word;
    } else {
        return "UNKNOWN";
    }

}

std::string Table::print (int k){
    // print the list of words at index k of the array

    std::string words;

    if (table[k]->getHead() == nullptr){
        return "chain is empty";
    } else {

        Node *temp = table[k]->getHead();
        
        while (temp != nullptr){
            
            words += temp->getWord() + " ";
            temp = temp->getNext();
        }

        return words;
    }
}

int Table::hash (std::string word){
    // hash the word
    // return the index of the word
    int ascii = 0;
    int hashed = 0;

    for (int i = 0; i < word.length(); i++){
        //adding all the ascii values of the word
        int val = int(word[i]);
        ascii += val;
        if (val < 65 || val > 122 || (val > 90 && val < 97)){  // to check for special characters
            hashed = -1;
            break;
        }
    }
    if (hashed != -1){
        hashed = ascii%size;
    }

    return hashed;
}

void Table::increase (){

    std::string *temp = new std::string[size]; 
    // copy arr into temp
    for (int i = 0; i < size; i++){
        temp[i] = arr[i];
    }

    // delete arr
    delete[] arr;

    // create a new array with size*2
    size = size*2;
    arr = new std::string[size];

    // copy temp into the new array
    for (int i = 0; i < size/2; i++){
        arr[i] = temp[i];
    }

    // delete temp
    delete[] temp;
}



