/*
*   MYLinkedList.cpp - Equipo 8
*
*   Rafael Alejandro Jimenez Lafuente   A01637850
*   Marco Alexis Lopez Cruz             A01638032
*   Oscar Miranda Escalante             A01630791
*   Eduardo Esteva Camacho              A01632202
*   29 de noviembre de 2020
*/
#include <iostream>
#include <string>
#include "MyLinkedList.h"

using namespace std;

MyLinkedList::MyLinkedList(){
    this->head=this->tail=nullptr;
    this->size=0;
}

MyLinkedList::~MyLinkedList(){
    if(head == nullptr){
        return;
    }
    MyNodoLL* current = head;
    while(current->next != nullptr){
        MyNodoLL* next = current ->next;
        delete current;
        current = next;
    }
    head = nullptr;
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

MyNodoLL* MyLinkedList::getAt(string key){
    MyNodoLL* current=this->head;
    for(int i=0;i<this->size;i++){
        if(current->key==key){
            return current;
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
/*
    InsertFirst
    Descripcion: Inserta un valor brindado por el usuario en la 1ra posición de la lista
    Parametro de entrada: key y fecha brindada por el usuario
    Comlejidad: O(1)
*/
void MyLinkedList::insertFirst(string key,string date){
    this->head=new MyNodoLL(key,date,this->head);
    if(this->tail==nullptr){
        this->tail=this->head;
    }
    this->size++;
}
/*
    InsertFirst
    Descripcion: Inserta un valor brindado por el usuario en la 1ra posición de la lista
    Parametro de entrada: key brindada por el usuario y vector de fechas
    Comlejidad: O(1)
*/
void MyLinkedList::insertFirst(string key, vector<string> dates){
    this->head=new MyNodoLL(key, dates, this->head);
    if(this->tail==nullptr){
        this->tail=this->head;
    }
    this->size++;
}
/*
    RemoveFirst
    Descripcion: Remueve el 1er elemento de la lista
    Comlejidad: O(1)
*/
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
/*
    RemoveLast
    Descripcion: Remueve el ultimo elemento de la lista
    Comlejidad: O(n)
*/
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
