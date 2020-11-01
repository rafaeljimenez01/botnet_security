#ifndef BSTDIRIP_H
#define BSTDIRIP_H

#include <string>
#include <iostream>
using namespace std;

struct IPBSTnode {
    string dirIP;
    int keyDuplicados;
    IPBSTnode* left;
    IPBSTnode* right;
    IPBSTnode(string dirIP, int keyduplicados) {
        this->dirIP = dirIP;
        this->keyDuplicados = keyduplicados;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BSTdirIP {
private:
    IPBSTnode* root;
    int size;
    void inorder(IPBSTnode* current);
public:
    BSTdirIP();
    void insert(string IP, int keyduplicados);
    void inorder();
};

#endif
