#pragma once
#ifndef LIST_H
#define LIST_H
#include <iostream>

using namespace std;

template<typename T>
class List {//�����, ����������� ������
public:
    List();//�����������
    ~List();//����������
    void pushBack(T data);//����� ���������� �������� � ����� ������; � �������� ��������� 
                             //�������� �������������� ����� ������������ ����
    int getSize() { return size; };//����� ��� ��������� ������� ������
    T& operator[](int position);//���������� ��������� [] ��� �������� ������ �� ������� ����
    void printList();
    void deleteNextNode(int pos);
private:
    template<typename T>
    class Node {//�����, ����������� ���� ������
    public:
        Node<T>* p_next;//��������� �� ��������� ����(pointer next)
        T data;//��������(�������������� �����) ���� ������
        Node(T data = T(), Node* p_next = nullptr)//�����������, ������������� �������� ��������
        {                                      //���������� ����� �������� ������� ����� ������;
            this->data = data;                 //����� ���������� ��������� �� ��������� ��� ��������,
                                               //����� �����-�� ������� �� ��� ������� � �������� ���������.
            this->p_next = p_next;
        }
    };
    Node<T>* root;//��������� �� �������� �������
    int size;//���������� ��������� ������
};

template<typename T>
List<T>::List()//����������� �������� ��������� �������� ���������� ������
{
    size = 0;
    root = nullptr;
}

template<typename T>
List<T>::~List()
{
}

template<typename T>
void List<T>::pushBack(T data)//����� ���������� �������� � ����� ������;
                              //��������: �������������� ����� ������������ ����
{
    if (root == nullptr) {//���������, ���������� �� ������ �������
                           //���� ������� �������� ������ ���, �� �� ������ ���
        root = new Node<T>(data);
    }
    else {             //���� ������ ������� ����, �� ��������� � ������ �������
        Node<T>* current = this->root;
        while (current->p_next != nullptr) {
            current = current->p_next;
        }
        current->p_next = new Node<T>(data);
    }
    size++;
}

template<typename T>
T& List<T>::operator[](int position)//���������� ��������� ��� ��������� ������ �� ���� �� ��� �������;
                                    //� �������� ��������� ������� ������� �������� ��������
{
    Node<T>* current = this->root;
    for (int i = 0; i < size; i++) {
        if (position == i) return current->data;//��� ���������� �������� � �������� ������� ���������� ������
        else current = current->p_next;//��� ������������ ������������ �� ������ ������
    }
}

template<typename T>
void List<T>::printList()//����� ��� ������ ������ �� �����
{
    Node<T>* current = this->root;
    for (int i = 0; i < size; i++) {
        cout << current->data->code << " " << current->data->position << endl;
        current = current->p_next;
    }
}
template<typename T>
void List<T>::deleteNextNode(int pos)
{
    if (pos == 0) {
        Node<T>* current = this->root;
        Node<T>* local = current->p_next;
        if (local == nullptr) {
            delete current;
        }
        else {
            this->root = local;
            delete current;
        }
        size--;
        return;
    }
    else if (pos + 1 != size) {
        Node<T>* current = this->root;
        for (int i = 0; i < size; i++) {
            if (pos == i) break;
            else current = current->p_next;//��� ������������ ������������ �� ������ ������
        }
        Node<T>* local = current->p_next;
        if (current->p_next->p_next != nullptr) current->p_next = current->p_next->p_next;
        else current->p_next = nullptr;
        delete local;
        size--;
        return;
    }
    else {
        Node<T>* current = this->root;
        for (int i = 0; i < size; i++) {
            if (pos == i) break;
            else current = current->p_next;//��� ������������ ������������ �� ������ ������
        }
        delete current->p_next;
        current->p_next = nullptr;
        size--;
    }
}
#endif