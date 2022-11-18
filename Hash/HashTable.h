#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "List.h"
#include <sstream>
#include <fstream>

class HashTable
{
public: 
    // Структура записи таблицы содержит в себе ключ (код города) и позицию в файле
    struct diallingCodes {
    public:
        int code;
        int position;

        diallingCodes() {}
        diallingCodes(int code, int position) {
            this->code = code;
            this->position = position;
        }
    };
private:
    int BUCKET;
    List<List<diallingCodes*>*>* table;
    List<diallingCodes*>* chain;
    diallingCodes* node;

public:
    HashTable(int b = 10);
    // Вставка элемента в хэш-таблицу
    void insertItem(int code, int position);
    // Удаление элемента хэш-таблицы
    void deleteItem(int key);
    // Хэш-функция
    int HashTableFunction(int x) {
        return (x % BUCKET);
    }
    // Возврат указателя на элемент, найденный по ключу
    diallingCodes* getItemByKey(int key);
    // Вывод хэш-таблицы в консоль в читаемом виде
    void displayHashTable();
    diallingCodes* getNode() { return this->node; }
};
#endif
