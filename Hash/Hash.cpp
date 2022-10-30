#include "testHashT.h"
#include "testBinF.h"
#include <iostream>

using namespace std;

void readAllFromFileAddToHash(string fileName, Codes bin, HashTable table) {
    ifstream binary(fileName, ios::binary | ios::in);
    diallingCodes diallingCode;
    int i = 1;

    while (binary.read((char*)&diallingCode, sizeof(diallingCodes))) {
        table.insertItem(bin.getCurrentCode(fileName, i).code, i,
            bin.getCurrentCode(fileName, i).city, bin.getCurrentCode(fileName, i).country);
        i++;
    }
}

void readFromFilenAddToHash(string fileName, int index, Codes bin, HashTable table) {
    table.insertItem(bin.getCurrentCode(fileName, index).code, index,
        bin.getCurrentCode(fileName, index).city, bin.getCurrentCode(fileName, index).country);
}

void deleteBoth(string fileName, int key, Codes bin, HashTable table) {
    table.deleteItem(key);
    bin.remove(fileName, key);
}

void getCurrentNode(string fileName, int key, Codes bin, HashTable table) {
    table.getItemByKey(key);
    cout << table.getNode()->code <<
        " " << table.getNode()->city <<
        " " << table.getNode()->country << endl;
}

int main()
{
    string fileName;
    int key;

    int choise;
    while (1) {
        cout << "-+===========================+-\n";
        cout << "If you want to test a hash table enter 1;\n"
            << "If you want to test a binary file worker enter 2;\n"
            << "If you want read struct from file and add it to the hash table enter 3;\n"
            << "If you want to delete item from the hash table and from the file enter 4;\n" 
            << "If you want to get current node from the file enter 5;\n"
            << "If you want to exit enter 0.\n"
            << "-+===========================+-\n";
        cin >> choise;
        switch (choise) {
        case(1): 
            testingHash();
            break;        
        case(2): 
            testingBin();
            break;
        case(3):
            cout << "Please enter the name of the file: ";
            cin >> fileName;
            cout << "Please enter the node index: ";
            cin >> key;
            readFromFilenAddToHash(fileName, key, worker, hashTable);
            break;
        case(4):
            cout << "Please enter the name of the file: ";
            cin >> fileName;
            cout << "Please enter the key: ";
            cin >> key;
            deleteBoth(fileName, key, worker, hashTable);
            break;
        case(5):
            cout << "Please enter the name of the file: ";
            cin >> fileName;
            cout << "Please enter the key: ";
            cin >> key;
            getCurrentNode(fileName, key, worker, hashTable);
            break;
        case(6):
            cout << "Please enter the name of the file: ";
            cin >> fileName;
            readAllFromFileAddToHash(fileName, worker, hashTable);
            break;
        case(0): 
            exit(0);
        }
    }
}
