

#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H
#include <string>
#include "MyLinkedList.h"

class MyHashTable{
    private:
        int size;//El número de elementos que tiene almacenado
        int sizeA; //El tamaño del arreglo
        MyLinkedList* tabla;
        void rehashing();
        int getPos(string key);
    public:
        MyHashTable();
        ~MyHashTable();
        bool isEmpty();
        void put(string key,int value);
        int get(string key);
        void remove(string key);
};
#endif 