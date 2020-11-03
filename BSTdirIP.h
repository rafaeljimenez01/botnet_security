/*
*   BSTdirIP.h - Equipo 8
*
*   Rafael Alejandro Jimenez Lafuente   A01637850
*   Marco Alexis Lopez Cruz             A01638032
*   Oscar Miranda Escalante             A01630791
*   Eduardo Esteva Camacho              A01632202
*   02 de noviembre de 2020
*/

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
    void top5(IPBSTnode* current, int& top);
public:
    BSTdirIP();
    void insert(string IP, int keyduplicados);
    void inorder();
    void top5();
};

#endif
