
#include <iostream>
#include <string>
#include <functional>
#include <cmath>
#include "MyHashTable.h"

using namespace std;

MyHashTable::MyHashTable(){
    this->size=0;
    this->sizeA=11;
    this->tabla=new MyLinkedList[this->sizeA];
}

/*
    Destructor
    Complejidad - caso promedio: O(n)
*/
MyHashTable::~MyHashTable(){
    for (int i = 0; i < this->sizeA; i++) {
        if (!this->tabla[i].isEmpty()) {
            MyNodoLL* current = this->tabla[i].getAt(0);
            while (current) {
                MyNodoLL* aux = current;
                current = current->next;
                delete aux;
            }
        }
    }
    delete[] this->tabla;
}

bool MyHashTable::isEmpty(){
    return this->size==0;
}

/*
    Rehashing
    Complejidad - caso promedio: O(n), peor caso: O(n^2)
*/
void MyHashTable::rehashing(){
    // incrementar tamaño
    int auxSize = this->sizeA;
    this->sizeA *= 2;
    // reasignar espacio en memoria
    MyLinkedList* auxLL = this->tabla;
    this->tabla = new MyLinkedList[this->sizeA];
    // rehashing
    for (int i = 0; i < auxSize; i++) {
        if (!auxLL[i].isEmpty()) {
            MyNodoLL* current = auxLL[i].getAt(0);
            while (current) {
                this->put(current->key, current->numAccess);
                current = current->next;
            }
        }
    }
}

int MyHashTable::getPos(string key){
    size_t hashT=hash<string>{}(key);
    int hashCode=static_cast<int>(hashT);
    return abs(hashCode)%this->sizeA;
}

/*
    put
    Complejidad - siempre O(1)
*/
void MyHashTable::put(string key,string date){
    float laodfactor = this->size / this->sizeA;
    if (laodfactor > 0.75) {
        this->rehashing();
    }
    int pos=getPos(key);
    this->tabla[pos].insertFirst(key,date);
    this->size++;
}


int MyHashTable::get(string key){
    int pos=getPos(key);
    MyLinkedList* lista=&this->tabla[pos];
    return lista->getAt(key);
}

/*
    remove
    Complejidad: siempre O(1)
*/
void MyHashTable::remove(string key){
    int pos = this->getPos(key);
    this->tabla[pos] = MyLinkedList();
}
