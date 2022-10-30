#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "List.h"
#include <sstream>
#include <fstream>

class HashTable
{
private:
    int BUCKET;
    // ��������� ������ ����� � ���������� ����� ������
    struct diallingCodes {
    public:
        int code;
        int position;
        char city[20];
        char country[20];

        diallingCodes(){}
        diallingCodes(int code, int position, const char city[], const char country[]) {
            this->code = code;
            this->position = position;
            for (int i = 0; i < 20; i++) {
                this->city[i] = city[i];
            }
            for (int i = 0; i < 20; i++) {
                this->country[i] = country[i];
            }
        }
    };
    List<List<diallingCodes*>*>* table;
    List<diallingCodes*>* chain;
    diallingCodes* node;

public:
    HashTable(int b = 10);
    // ������� �������� � ���-�������
    void insertItem(int code, int position, const char city[], const char country[]);
    // �������� �������� ���-�������
    void deleteItem(int key);
    // ���-�������
    int HashTableFunction(int x) {
        return (x % BUCKET);
    }
    // ������� ��������� �� �������, ��������� �� �����
    diallingCodes* getItemByKey(int key);
    // ����� ���-������� � ������� � �������� ����
    void displayHashTable();
    diallingCodes* getNode() { return this->node; }
};
#endif
