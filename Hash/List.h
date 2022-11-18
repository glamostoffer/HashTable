#pragma once
#ifndef LIST_H
#define LIST_H
#include <iostream>

using namespace std;

template<typename T>
class List {//класс, реализующий список
public:
    List();//конструктор
    ~List();//деструктор
    void pushBack(T data);//метод добавления элемента в конец списка; в качестве параметра 
                             //получает информационную часть добавляемого узла
    int getSize() { return size; };//метод для получения размера списка
    T& operator[](int position);//перегрузка оператора [] для возврата ссылки на искомый узел
    void printList();
    void deleteNextNode(int pos);
private:
    template<typename T>
    class Node {//класс, реализующий узел списка
    public:
        Node<T>* p_next;//указатель на следующий узел(pointer next)
        T data;//значение(информационная часть) узла списка
        Node(T data = T(), Node* p_next = nullptr)//конструктор, присваивающий значение входящих
        {                                      //параметров полям текущего объекта этого класса;
            this->data = data;                 //также используем параметры по умолчанию для ситуаций,
                                               //когда какой-то элемент не был передан в качестве параметра.
            this->p_next = p_next;
        }
    };
    Node<T>* root;//указатель на корневой элемент
    int size;//количество элементов списка
};

template<typename T>
List<T>::List()//конструктор задающий начальные значения созданного списка
{
    size = 0;
    root = nullptr;
}

template<typename T>
List<T>::~List()
{
}

template<typename T>
void List<T>::pushBack(T data)//метод добавления элемента в конец списка;
                              //параметр: информационная часть добавляемого узла
{
    if (root == nullptr) {//проверяем, существует ли первый элемент
                           //если первого элемента списка нет, то мы создаём его
        root = new Node<T>(data);
    }
    else {             //если первый элемент есть, то добавляем в список элемент
        Node<T>* current = this->root;
        while (current->p_next != nullptr) {
            current = current->p_next;
        }
        current->p_next = new Node<T>(data);
    }
    size++;
}

template<typename T>
T& List<T>::operator[](int position)//перегрузка оператора для получения ссылки на узел по его позиции;
                                    //в качестве параметра передаём позицию искомого элемента
{
    Node<T>* current = this->root;
    for (int i = 0; i < size; i++) {
        if (position == i) return current->data;//при совпадении счётчика и значения позиции возвращаем данные
        else current = current->p_next;//при несовпадении продвигаемся по списку дальше
    }
}

template<typename T>
void List<T>::printList()//метод для вывода списка на экран
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
            else current = current->p_next;//при несовпадении продвигаемся по списку дальше
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
            else current = current->p_next;//при несовпадении продвигаемся по списку дальше
        }
        delete current->p_next;
        current->p_next = nullptr;
        size--;
    }
}
#endif