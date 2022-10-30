#pragma once
#ifndef CODES_H
#define CODES_H
#include <iostream>
#include <string>
#include <random>
#include <sstream>
#include <fstream>

using namespace std;

class Codes{
    private:
        struct diallingCodes { //структура записи файла с телефонным кодом города
            int code;
            char city[20];
            char country[20];
        };
    public:
        void printFile(string filename); //вывод в консоль содержимого текстового файла
        void printBin(string filename); //вывод в консоль содержимого бинарного файла
        bool doesExist(string name); 
        void fromTextToBinary(string fileText, string fileBin); //преобразование тестовых данных из текстового файла в двоичный файл
        void fromBinToText(string fileText, string fileBin); //преобразование данных из двоичного файла в текстовый
        diallingCodes getCurrentCode(string filename, int position); //доступ к записи по ее порядковому номеру в файле
        void remove(string filename, int key); //удаление записи с заданным значением ключа
        void filterCodesByCountry(string filename, string country); //формирование в текстовом файле таблицы кодов указанной страны
        void uploadCityCode(string filename, string city, string newCode); //обновление кода города по названию города
        void add(string filename, int code, const char city[], const char country[]); //запись нового элемента в файл
};
#endif