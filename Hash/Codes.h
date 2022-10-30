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
        struct diallingCodes { //��������� ������ ����� � ���������� ����� ������
            int code;
            char city[20];
            char country[20];
        };
    public:
        void printFile(string filename); //����� � ������� ����������� ���������� �����
        void printBin(string filename); //����� � ������� ����������� ��������� �����
        bool doesExist(string name); 
        void fromTextToBinary(string fileText, string fileBin); //�������������� �������� ������ �� ���������� ����� � �������� ����
        void fromBinToText(string fileText, string fileBin); //�������������� ������ �� ��������� ����� � ���������
        diallingCodes getCurrentCode(string filename, int position); //������ � ������ �� �� ����������� ������ � �����
        void remove(string filename, int key); //�������� ������ � �������� ��������� �����
        void filterCodesByCountry(string filename, string country); //������������ � ��������� ����� ������� ����� ��������� ������
        void uploadCityCode(string filename, string city, string newCode); //���������� ���� ������ �� �������� ������
        void add(string filename, int code, const char city[], const char country[]); //������ ������ �������� � ����
};
#endif