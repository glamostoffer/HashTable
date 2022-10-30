#pragma once
#include "HashTable.h"
#include "List.h"
#include "Codes.h"

HashTable hashTable(5);

struct diallingCodes {
    int code;
    char city[20];
    char country[20];
};

void setArray(char* arr, const char word[]) {
    for (int i = 0; i < sizeof(word); i++) {
        arr[i] = word[i];
    }
}

void setStruct(diallingCodes& obj, int code, const char city[], const char country[]) {
    obj.code = code;
    setArray(obj.city, city);
    setArray(obj.country, country);
}

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
    diallingCodes obj;
    int code, size = 0;
    char word1[20], word2[20];
    int choise;
    choise = hashTestMenu();
    while (choise != 0) {
        switch (choise) {
        case(1): {
            cout << "Please enter the name of the city: ";
            cin >> word1;
            cout << "Please enter the name of the country: ";
            cin >> word2;
            cout << "Please enter the dialling code: ";
            cin >> code;
            setStruct(obj, code, word1, word2);
            hashTable.insertItem(obj.code, size, obj.city, obj.country);
            size++;
            break;
        }
        case(2): {
            cout << "Please enter the dialling code: ";
            cin >> code;
            hashTable.deleteItem(code);
            size--;
            break;
        }
        case(3): {
            cout << "Please enter the dialling code: ";
            cin >> code;
            hashTable.getItemByKey(code);
            cout << "\n" << hashTable.getNode()->code <<
                " " << hashTable.getNode()->city <<
                " " << hashTable.getNode()->country;
            break;
        }
        case(4): {
            hashTable.displayHashTable();
            break;
        }
        }
        choise = hashTestMenu();
    }
}