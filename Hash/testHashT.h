#pragma once
#include "HashTable.h"
#include "List.h"
#include "Codes.h"
#include "testBinF.h"

HashTable hashTable(5);

int hashTestMenu() {
    int choise;
    
    cout << "+===========================+\n"
        << "If you want to insert an item into hash table enter 1;\n"
        << "If you want to delete an item from hash table enter 2;\n"
        << "If you want to find a node in hash table enter 3;\n"
        << "If you want to diplay the hash table enter 4;\n"
        << "If you want to go back to main menu enter 0;\n"
        << "+===========================+\n";
    
    cin >> choise;
    return choise;
}

void testingHash() {
    Codes::diallingCodes node;
    int code;
    char word1[20], word2[20];
    int choise;
    choise = hashTestMenu();
    while (choise != 0) {
        switch (choise) {
        case(1): 
            cout << "Please enter the name of the file with records: ";
            cin >> word1;
            cout << "Please enter the index of record to write into hash table: ";
            cin >> code;
            node = worker.getCurrentCode(word1, code);
            hashTable.insertItem(node.code, code);
            break;
        case(2): 
            cout << "Please enter the key of the item (the dialling code): ";
            cin >> code;
            hashTable.deleteItem(code);
            break;
        case(3): 
            cout << "Please enter the name of the file with records: ";
            cin >> word1;
            cout << "Please enter the key of the item (the dialling code): ";
            cin >> code;
            hashTable.getItemByKey(code);
            node = worker.getCurrentCode(word1, hashTable.getNode()->position);
            cout << node.code <<
                " " << node.city <<
                " " << node.country << endl;
            break;
        case(4): 
            hashTable.displayHashTable();
            break;
        }
        choise = hashTestMenu();
    }
}