
#include <iostream>
#include <string>
#include <functional>
#include <cmath>
#include "MyHashTable.h"

using namespace std;

MyHashTable::MyHashTable(){
    this->size = 0;
    this->sizeA = 1009;
    this->tabla = new MyLinkedList[this->sizeA];
}

/*
    Destructor
    Complejidad - caso promedio: O(n)
*/
MyHashTable::~MyHashTable(){
    for(int i=0; i < this->sizeA; i++){
        tabla[i].~MyLinkedList();
    }
    delete[] tabla;
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
    this->sizeA = sizeA * 2 + 1;
    // reasignar espacio en memoria
    MyLinkedList* auxLL = this->tabla;
    this->tabla = new MyLinkedList[this->sizeA];
    // rehashing
    for (int i = 0; i < auxSize; i++) {
        if (!auxLL[i].isEmpty()) {
            MyNodoLL* current = auxLL[i].getAt(0);
            while (current) {
                this->put(current->key, current->dates);
                current = current->next;
            } 
            //auxLL[i].~MyLinkedList();
        }
    }
    //delete[] auxLL;
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
void MyHashTable::put(string key, string date){
    // test for rehashing
    float laodfactor = this->size / this->sizeA;
    if (laodfactor > 0.75) {
        this->rehashing();
    }
    // insertion
    int pos=getPos(key);
    if (this->tabla[pos].isEmpty()) {
        this->tabla[pos].insertFirst(key,date);
    } else {
        MyNodoLL* current = this->tabla[pos].getAt(0);
        bool found = false;
        while (current) {
            if (current->key == key) {
                found = true;
                current->dates.push_back(date);
                current->numAccess++;
            }
            current = current->next;
        }
        if (!found) {
            this->tabla[pos].insertFirst(key,date);
        }
    }
    this->size++;
}

void MyHashTable::put(string key, vector<string> dates){
    int pos=getPos(key);
    this->tabla[pos].insertFirst(key,dates);
    this->size++;
}


/*
    vector <string> getDates(string key): devuelve un vector de fechas correspondientes a la IP "key"
*/
vector<string> MyHashTable::getDates(string key){
    int pos=getPos(key);
    MyLinkedList* lista = &this->tabla[pos];
    return lista->getAt(key)->dates;
}

/*
    int getNumAccess(string key): devuelve el número de accesos correspondientes a la IP "key"
*/
int MyHashTable::getNumAccess(string key){
    int pos=getPos(key);
    MyLinkedList* lista = &this->tabla[pos];
    return lista->getAt(key)->numAccess;
}

/*
    remove
    Complejidad: siempre O(1)
*/
void MyHashTable::remove(string key){
    int pos = this->getPos(key);
    this->tabla[pos] = MyLinkedList();
}

int MyHashTable::getSize() {
    return this->size;
}
