#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "List.h"
#include <sstream>
#include <fstream>

class HashTable
{
public: 
    // ��������� ������ ������� �������� � ���� ���� (��� ������) � ������� � �����
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
    // ������� �������� � ���-�������
    void insertItem(int code, int position);
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
