#ifndef MY_LINKEDLIST_H
#define MY_LINKEDLIST_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct MyNodoLL{
    string key; //IP
    int numAccess; //Times the IP tried to access the system.
    vector<string> dates; //Vector with every date
    MyNodoLL* next; //Pointer to next

    MyNodoLL(string key, string date, MyNodoLL* next){
        this->key = key; //IP
        this->dates.push_back(date); //Dates
        this->numAccess = this->dates.size(); //Number of access
        this->next=next;
    }

    MyNodoLL(string key, string date) : MyNodoLL(key, date, nullptr){}

    MyNodoLL(string key, vector<string> dates, MyNodoLL* next = nullptr) {
        this->key = key;
        this->dates = dates;
        this->numAccess = this->dates.size();
        this->next = next;
    }
};

class MyLinkedList{
    private:
        MyNodoLL* head;
        MyNodoLL* tail;
        int size;
    public:
        //Class
        MyLinkedList();
        ~MyLinkedList();
        //Linked List 
        int length();
        bool isEmpty();
        //Nodes
        MyNodoLL* getAt(int pos);
        MyNodoLL* getAt(string key);
        int getNumAccess(string key);
        int getDates(string key);
        //Linked list manipulation
        void insertFirst(string key, string date);
        void insertFirst(string key, vector<string> dates);
        void removeFirst();
        void removeLast();
        //Linked list printer
        friend ostream& operator<<(ostream& os,const MyLinkedList& ll){
            MyNodoLL* current=ll.head;
            for(int i=0;i<ll.size;i++){
                os<<"["<<current->key<<",";
                os << current->numAccess << ",";
                for (int i = 0; i < current->dates.size(); i++) {
                    os << " " << current->dates[i];
                }
                os << endl;
                current=current->next;
            }
            return os;
        }
};
#endif 
