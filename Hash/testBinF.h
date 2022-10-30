#pragma once
#include "Codes.h"
#include "Codes.cpp"

Codes worker;

void testingBin() { 
    string fileName, secondName;
    char city[20], country[20];
    int choise, key;
    cout << "-===========================-";
    cout << "\nEnter 1 if you want to print your txt file;";
    cout << "\nEnter 2 if you want to print your binary file;";
    cout << "\nEnter 3 if you want to make new txt file from binary file;";
    cout << "\nEnter 4 if you want to make new binary file from txt file;";
    cout << "\nEnter 5 if you want to add new line to the file;";
    cout << "\nEnter 6 if you want to remove chosen record";
    cout << "\nEnter 7 if you want to filter codes by country;";
    cout << "\nEnter 8 if you want to upload a city code;";
    cout << "\nEnter 0 if you want to return to the main menu.\n";
    cout << "-===========================-\n";
    cin >> choise;
    while (choise != 0) {
        switch (choise) {
        case(1):
            cout << "Please enter the file name: ";
            cin >> fileName;
            worker.printFile(fileName);
            break;
        case(2):
            cout << "Please enter the file name: ";
            cin >> fileName;
            worker.printBin(fileName);
            break;
        case(3):
            cout << "Please enter the txt file name: ";
            cin >> fileName;
            cout << "Please enter the bin file name: ";
            cin >> secondName;
            worker.fromBinToText(fileName, secondName);
            break;
        case(4):
            cout << "Please enter the txt file name: ";
            cin >> fileName;
            cout << "Please enter the bin file name: ";
            cin >> secondName;
            worker.fromTextToBinary(fileName, secondName);
            break;
        case(5):
            cout << "Please enter the name of the file: ";
            cin >> fileName;
            cout << "Please enter the name of the city: ";
            cin >> city;
            cout << "Please enter the code: ";
            cin >> key;
            cout << "Please enter the name of the country: ";
            cin >> country;
            worker.add(fileName, key, city, country);
            break;
        case(6):
            cout << "Please enter the name of the file: ";
            cin >> fileName;
            cout << "Please enter the key: ";
            cin >> key;
            worker.remove(fileName, key);
            break;
        case(7):
            cout << "Please enter the name of the file: ";
            cin >> fileName;
            cout << "Please enter the name of the country: ";
            cin >> secondName;
            worker.filterCodesByCountry(fileName, secondName);
            cout << "The updated table with the codes of the cities of a certain country:\n";
            worker.printFile("selected_country_codes.txt"); //демонстрация результата
            break;
        case(8):
            cout << "Please enter the name of the file: ";
            cin >> fileName;
            cout << "Please enter the name of the city: ";
            cin >> secondName;
            cout << "Please enter the new code: ";
            string code;
            cin >> code;
            worker.uploadCityCode(fileName, secondName, code);
            cout << "The updated table with the new code of " << secondName << ":\n";
            worker.printBin(fileName); //демонстрация результата
            break;
        }
        cout << "-===========================-";
        cout << "\nEnter 1 if you want to print your txt file;";
        cout << "\nEnter 2 if you want to print your binary file;";
        cout << "\nEnter 3 if you want to make new txt file from binary file;";
        cout << "\nEnter 4 if you want to make new binary file from txt file;";
        cout << "\nEnter 5 if you want to add new line to the file;";
        cout << "\nEnter 6 if you want to remove chosen record";
        cout << "\nEnter 7 if you want to filter codes by country;";
        cout << "\nEnter 8 if you want to upload a city code;";
        cout << "\nEnter 0 if you want to return to the main menu.\n";
        cout << "-===========================-\n";
        cin >> choise;
    }

}