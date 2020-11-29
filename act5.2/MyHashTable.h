

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
        void put(string key,string date);
        void put(string key,vector<string> dates);
        vector<string> getDates(string key);
        int getNumAccess(string key);
        void remove(string key);
        int getSize();
        MyNodoLL* operator[](string key) {
            int pos=getPos(key);
            MyLinkedList* lista = &this->tabla[pos];
            if (!lista->isEmpty()) {
                MyNodoLL* current = lista->getAt(0);
                while (current) {
                    if (current->key == key) {
                        return current;
                    }
                    current = current->next;
                }
            }
            return nullptr;
        }
};
#endif 