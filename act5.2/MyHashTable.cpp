
#include <iostream>
#include <string>
#include <functional>
#include <cmath>
#include "MyHashTable.h"

using namespace std;
/* Class constructor.
*  Entry value: None. Output: None
*  Complexity: O(n).
*  Space Complexity: O(1).
*/
MyHashTable::MyHashTable(){
    this->size = 0;
    this->sizeA = 1009;
    this->tabla = new MyLinkedList[this->sizeA];
}

/* Class destructor. Frees the memory after utilizing the hashtable.
*  Entry value: None. Output: None
*  Complexity: O(n).
*  Space Complexity: O(1).
*/
MyHashTable::~MyHashTable(){
    for(int i=0; i < this->sizeA; i++){
        tabla[i].~MyLinkedList();
    }
    delete[] tabla;
}

/* Function isEmpty, checks if the hashtable is empty
*  Entry value: None. Output: Bool indicating if the table is empty
*  Complexity: O(1) always.
*  Space Complexity: O(1).
*/
bool MyHashTable::isEmpty(){
    return this->size==0;
}

/* Function rehashing, migrates the current array of linked lists to a new array two times bigger +1
*  the objective of the migration is to reduce the loading factor (<0.75).
*  Entry value: None. Output: None
*  Complexity: Worst Case: O(n) linear since it needs to iterative through the hole array of linked
*  lists, the case where it needs to go through any linked list is very unusual so it can be 
*  amortized.
*  Space Complexity: O(n) 
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
            auxLL[i].~MyLinkedList();
        }
    }
    delete[] auxLL;
}

/* Function getPos, hash the key string and gives us the index table where the key should be inserted.
*  Entry value: The string to be hashed.
*  Complexity: O(1) always.
*  Space Complexity: O(1).
*/

int MyHashTable::getPos(string key){
    size_t hashT=hash<string>{}(key);
    int hashCode=static_cast<int>(hashT);
    return abs(hashCode)%this->sizeA;
}

/* Function put, inserts a new pair into the hashing table 
*  Entry value: The key to be inserted with its pair. Output: None
*  Complexity: Worst Case: O(n) linear when rehashing is needed (loadFactor > 0.75). Since we almost never have collitions
*  utilizing prime numbers and its duplicates.
*  Best Case: O(1) when no rehashing is needed. Space Complexity: O(1).
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

/* Function put, inserts a new pair into the hashing table 
*  Entry value: The key to be inserted with the vector of all the dates from the IP. Output: None
*  Complexity: Worst Case: O(n) linear when rehashing is needed (loadFactor > 0.75). Since we almost never have collitions
*  utilizing prime numbers and its duplicates.
*  Best Case: O(1) when no rehashing is needed. Space Complexity: O(1).
*/

void MyHashTable::put(string key, vector<string> dates){
    float laodfactor = this->size / this->sizeA;
    if (laodfactor > 0.75) {
        this->rehashing();
    }
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
