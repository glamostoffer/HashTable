#include "HashTable.h"

HashTable::HashTable(int b) {
    this->BUCKET = b;
    this->table = new List<List<diallingCodes*>*>;
    for (int i = 0; i < b; i++) {
        this->chain = new List<diallingCodes*>;
        this->table->pushBack(this->chain);
    }
}

void HashTable::insertItem(int code, int position) {
    diallingCodes* node = new diallingCodes(code, position);
    int index = HashTableFunction(node->code);
    this->table->operator[](index)->pushBack(node);
}

void HashTable::deleteItem(int key) {
    // получаем нужный ключ
    int index = HashTableFunction(key);
    // находим нужный нам список
    for (int i = 0; i < this->table->operator[](index)->getSize(); i++) {
        if (this->table->operator[](index)->operator[](i)->code == key) {
            // если найден ключ, удал€ем €чейку
            this->table->operator[](index)->deleteNextNode(i);
            break;
        }
    }
}

// отображение хеш-таблицы
void HashTable::displayHashTable() {
    for (int i = 0; i < BUCKET; i++) {
        cout << "<====== " << i << " ======>\n";
        List<diallingCodes*>* localTable = this->table->operator[](i);
        localTable->printList();
    }
}

HashTable::diallingCodes* HashTable::getItemByKey(int key) {
    // получаем нужный ключ
    int index = HashTableFunction(key);
    // находим нужный нам список
    for (int i = 0; i < this->table->operator[](index)->getSize(); i++) {
        if (this->table->operator[](index)->operator[](i)->code == key) {
            this->node = this->table->operator[](index)->operator[](i);
            return this->node;
            break;
        }
    }
}
