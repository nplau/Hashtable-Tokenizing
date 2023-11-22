#include <iostream>
#include <fstream>
#include "Table.hpp"
#include "Linkedlist.hpp"
#include "Node.hpp"

int main()
{
    std::string input;
    std::string filename;
    Table *hash;

    int m;
    std::string word;
    int t;
    std::string words;
    int tokens;
    int k;

    while (std::cin >> input){

        if (input == "M"){
            
            std::cin >> m;

            if (m > 0){ 
                hash = new Table(m);
                std::cout << "success" << std::endl;
            } 

        } else if (input == "INSERT"){
            std::cin >> word;
            if (hash->insert(word)){
                std::cout << "success" << std::endl;
            } else {
                std::cout << "failure" << std::endl;
            }

        } else if (input == "READ"){
            std::cin >> filename;
            std::fstream fin(filename.c_str());
            if (hash->read(fin)){
                std::cout << "success" << std::endl;
            } else {
                std::cout << "failure" << std::endl;
            }

        } else if (input == "TOKENIZE"){
            std::cin >> word;
            std::cout << hash->tokenize(word) << std::endl;

        } else if (input == "RETRIEVE"){
            std::cin >> t;
            std::cout << hash->retrieve(t) << std::endl;
            

        } else if (input == "STOK"){

            while (std::cin >> words){
                if (words == "_DONE_"){
                    break;
                } else {
                    std::cout << hash->tokenize(words) << " ";
                }
            }
            std::cout << std::endl;

        } else if (input == "TOKS"){
            
            while (std::cin >> tokens){
                if (tokens == -1){
                    break;
                } else {
                    std::cout << hash->print(tokens) << " ";
                }
            }

            std::cout << std::endl;

        } else if (input == "PRINT"){
           
            std::cin >> k;
            std::cout << hash->print(k) << std::endl;

        } else if (input == "EXIT"){
            return 0;
        } 
    }
}
