#include <iostream>
#include <string>
#include "MyLinkedList.h"

using namespace std;

MyLinkedList::MyLinkedList(){
    this->head=this->tail=nullptr;
    this->size=0;
}

MyLinkedList::~MyLinkedList(){
    MyNodoLL* current = this->head;
    while (current) {
        MyNodoLL* aux = current;
        current = current->next;
        delete aux;
    }
}

int MyLinkedList::length(){
    return this->size;
}

bool MyLinkedList::isEmpty(){
    return this->size==0;
}

int MyLinkedList::getNumAccess(string key){
    MyNodoLL* current=this->head;
    for(int i=0;i<this->size;i++){
        if(current->key==key){
            return current->numAccess;
        }
        current=current->next;
    }
    throw invalid_argument("No se encontró "+key+" en la lista");
}

MyNodoLL* MyLinkedList::getAt(int pos){
    if(pos>=0 && pos<this->size){
        MyNodoLL* current=this->head;
        for(int i=0;i<pos;i++){
            current=current->next;
        }
        return current;
    }else{
        throw invalid_argument("No se puede insertar en la posición "+to_string(pos)+" en una lista de tamaño "+to_string(this->size));
    }
}

void MyLinkedList::insertFirst(string key,string date){
    this->head=new MyNodoLL(key,date,this->head);
    if(this->tail==nullptr){
        this->tail=this->head;
    }
    this->size++;
}

void MyLinkedList::removeFirst(){
    if(this->size>0){
        MyNodoLL* tmp=this->head;
        this->head=this->head->next;
        this->size--;
        if(this->size==0){
            this->tail=nullptr;
        }
        delete tmp;
    }else{
        throw invalid_argument("No se puede borrar el inicio de una lista vacía");
    }
}

void MyLinkedList::removeLast(){
    if(this->size<=1){
        removeFirst();
    }else{
        MyNodoLL* current=this->head;
        for(int i=0;i<this->size-2;i++){
            current=current->next;
        }
        this->tail=current;
        delete current->next;
        this->tail->next=nullptr;
        this->size--;
    }
}

void MyLinkedList::removeAt(int pos){
}