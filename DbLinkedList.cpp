#include "DbLinkedList.h"
#include <iostream>
#include <limits>
using namespace std;

DbLinkedList::DbLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

DbLinkedList::~DbLinkedList() {
    while (!this->isEmpty()) {
        this->removeFirst();
    }
}

/*
    first()
    Devuelve el primer elemento de la lista
    Complejidad: O(1)
*/

Falla DbLinkedList::first() {
    if (this->size > 0) {
        return this->head->falla;
    }
    else {
        throw invalid_argument("No existe el elemento.");
    }
}

/*
    last()
    Devuelve el ˙ltimo elemento de la lista
    Complejidad: O(1)
*/
Falla DbLinkedList::last() {
    if (this->size > 0) {
        return this->tail->falla;
    }
    else {
        throw invalid_argument("No existe el elemento.");
    }
}

DbLinkedListNode* DbLinkedList::firstNode() {
    return this->head;
}

/*
    length()
    Devuelve el n˙mero de nodos que la lista contiene
    Complejidad: O(1)
*/
int DbLinkedList::length() {
    return this->size;
}

/*
    getAt(int pos)
    Par·metro: n˙mero entero que indica posiciÛn de la cual se desea obtener el elemento
    Salida: n˙mero entero en pos (si existe esa posiciÛn)
    Complejidad: O(n)
*/
Falla DbLinkedList::getAt(int pos) {
    if (pos < 0) {
        throw invalid_argument("PosiciÛn no puede ser menor a 0.");
    }
    if (pos >= this->size) {
        throw invalid_argument("No se puede acceder al elemento.");
    }
    DbLinkedListNode* current = this->head;
    for (int i = 0; i < pos; i++) {
        current = current->next;
    }
    return current->falla;
}

/*
    isEmpty()
    Salida: valor booleano que indica si la lista est· vacÌa
    Complejidad: O(1)
*/
bool DbLinkedList::isEmpty() {
    return this->head == nullptr;
}

/*
    insertFirst(Falla data)
    Entrada: n˙mero entero que se desea insertar al inicio
    Complejidad: O(1)
*/
void DbLinkedList::insertFirst(Falla data) {
    this->head = new DbLinkedListNode(data, nullptr, this->head);
    if (this->size == 0) {
        this->tail = this->head;
    }
    else if (this->size > 0) {
        this->head->next->prev = head;
    }
    this->size++;
}

/*
    insertLast(Falla data)
    Entrada: n˙mero entero que se desea insertar al final
    Complejidad: O(1)
*/
void DbLinkedList::insertLast(Falla data) {
    if (this->size == 0) {
        this->insertFirst(data);
    }
    else {
        DbLinkedListNode* newNode = new DbLinkedListNode(data, this->tail, nullptr);
        this->tail->next = newNode;
        this->tail = newNode;
        this->size++;
    }

}

/*
    insertAt(Falla data, int pos)
    Inserta el valor data en la posiciÛn pos
    Entrada: n˙mero entero data y n˙mero entero pos
    Complejidad: O(n)
*/
void DbLinkedList::insertAt(Falla data, int pos) {
    DbLinkedListNode* newNode = new DbLinkedListNode(data);
    if (pos >= 0 && pos < this->size)
    {
        DbLinkedListNode* current = this->head;
        for (int i = 0; i < pos - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        newNode->next->prev = newNode;
        newNode->prev = current;
        this->size++;
    }
    else
    {
        throw invalid_argument("PosiciÛn inv·lida.");
    }
}

/*
    setAt(Falla data, int pos)
    Cambia el valor en la posiciÛn pos por el valor data
    Entrada: n˙mero entero data y n˙mero entero pos
    Complejidad: O(n)
*/
void DbLinkedList::setAt(Falla falla, int pos) {
    if (pos >= 0 && pos < this->size) {
        DbLinkedListNode* current = this->head;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
        current->falla = falla;
    }
    else {
        throw invalid_argument("PosiciÛn inv·lida.");
    }
}

/*
    removeFirst()
    Elimina el primer nodo de la lista
    Complejidad: O(1)
*/
void DbLinkedList::removeFirst() {
    if (this->size > 0) {
        DbLinkedListNode* headTemp = this->head;
        this->head = this->head->next;
        this->size--;
        if (this->size == 0) {
            this->tail = nullptr;
        }
        else if (this->size > 0) {
            this->head->prev = nullptr;
        }
        delete headTemp;
    }
    else {
        throw invalid_argument("No existe el elemento.");
    }
}

/*
    removeLast()
    Elimina el ˙ltimo nodo de la lista
    Complejidad: O(n)
*/
void DbLinkedList::removeLast() {
    if (this->size > 0) {
        DbLinkedListNode* tempTail = this->tail;
        this->tail = this->tail->prev;
        this->size--;
        if (this->size == 0) {
            this->head = nullptr;
        }
        delete tempTail;
    }
    else {
        throw invalid_argument("No existe el elemento.");
    }
}

/*
    removeAt(int pos)
    Elimina el nodo en pos
    Entrada: n˙mero entero que indica la posiciÛn
    Complejidad: O(n)
*/
void DbLinkedList::removeAt(int pos) {
    if (pos >= 0 && pos < this->size) {
        if (pos == 0) {
            this->removeFirst();
        }
        else {
            DbLinkedListNode* current = this->head;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }
            DbLinkedListNode* canceled = current->next;
            current->next = canceled->next;
            current->next->prev = current;
            delete canceled;
            if (pos == this->size - 1) {
                this->tail = current;
            }
            this->size--;
        }
    }
    else {
        throw invalid_argument("PosiciÛn inv·lida.");
    }
}

DbLinkedListNode* DbLinkedList::split() {
    DbLinkedListNode* fast = head;
    DbLinkedListNode* slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    DbLinkedListNode* centro = slow->next;   // cuidado por quÈ next? 1 2 3 4 
    return centro;
}

void DbLinkedList::mezcla(DbLinkedListNode* inicio, DbLinkedListNode* centro, DbLinkedListNode* final) {
    DbLinkedList tempDBLL;
    DbLinkedListNode* i = inicio;
    DbLinkedListNode* j = centro;
    while (i != centro && j->next != final->next) {
        if (j->falla.getDireccionIP().isAfter(i->falla.getDireccionIP())) {
            tempDBLL.insertLast(i->falla);
            i = i->next;
        }
        else {
            tempDBLL.insertLast(j->falla);
            j = j->next;
        }
    }
    while (i != centro) {
        tempDBLL.insertLast(i->falla);
        i = i->next;
    }
    while (j != final->next) {
        tempDBLL.insertLast(j->falla);
        j = j->next;
    }

    DbLinkedListNode* k = inicio;
    DbLinkedListNode* nodoOrdenado = tempDBLL.firstNode();
    while (k != final->next && nodoOrdenado->next != nullptr) {
        k->falla = nodoOrdenado->falla;
        nodoOrdenado = nodoOrdenado->next;
        k = k->next;
    }
}

void DbLinkedList::mergeSort(DbLinkedListNode* inicio, DbLinkedListNode* final) {
    if (inicio->next != final) {
        DbLinkedListNode* centro = this->split();
        mergeSort(inicio, centro->prev);
        mergeSort(centro, final);
        mezcla(inicio, centro, final);
    }
}

void DbLinkedList::mergeSort() {
    this->mergeSort(this->head, this->tail);
}


int main() {
    DbLinkedList dbll;
    Falla f1("Aug 27 10:32:24 123.2.230.77:6166 Failed password for illegal user guest");
    Falla f2("Aug 29 23:07:49 789.53.984.6:6710 Failed password for root");
    Falla f3("Aug 28 23:07:49 456.53.984.6:6710 Failed password for root");
    Falla f4("Aug 30 23:07:49 1.53.984.6:6710 Failed password for root");
    dbll.insertLast(f1);
    dbll.insertLast(f2);
    dbll.insertLast(f3);
    dbll.insertLast(f4);
    dbll.mergeSort();
    cout << dbll;
    return 0;
}

