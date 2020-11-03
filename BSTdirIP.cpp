/*
*   BSTdirIP.cpp - Equipo 8
*
*   Rafael Alejandro Jimenez Lafuente   A01637850
*   Marco Alexis Lopez Cruz             A01638032
*   Oscar Miranda Escalante             A01630791
*   Eduardo Esteva Camacho              A01632202
*   02 de noviembre de 2020
*/

#include "BSTdirIP.h"

BSTdirIP::BSTdirIP()
{
	this->size = 0;
	this->root = nullptr;
}
void BSTdirIP::inorder() {
	this->inorder(this->root);
}


void BSTdirIP::inorder(IPBSTnode* current) {
	if (current) {
		this->inorder(current->left);
		cout << current->dirIP << " Duplicados: " << current->keyDuplicados << endl;
		this->inorder(current->right);
	}
}

void BSTdirIP::insert(string IP, int duplicates) {
	IPBSTnode* current = this->root;
	IPBSTnode* parent = nullptr;
	IPBSTnode* newNode = new IPBSTnode(IP, duplicates);
	if (current == nullptr) {
		this->root = newNode; //The tree was empty
		this->size++;
	}
	else {
		while (current != nullptr) {
			parent = current;
			if (duplicates < current->keyDuplicados) {
				current = current->left;
			}
			else if (duplicates > current->keyDuplicados) {
				current = current->right;
			}
			else {
				current = current->right;
			}
		}//Current está en null y parent está en el nodo que será el parent
		//del nuevo nodo
		if (duplicates > parent->keyDuplicados || duplicates == parent->keyDuplicados) {
			parent->right = newNode;
			this->size++;
		}
		else if (duplicates < parent->keyDuplicados) {
			parent->left = newNode;
			this->size++;
		}
	}
}

void BSTdirIP::top5(IPBSTnode* current, int& top){
	if (current && top < 5) {
		this->top5(current->right, top);
		if (top < 5) {
			cout << top+1 << ":  " << current->dirIP << " Duplicados: " << current->keyDuplicados << endl;
			top++;
		}
		this->top5(current->left, top);
	}
}

void BSTdirIP::top5(){
	cout << endl;
	int count = 0;
	top5(this->root, count);
	cout << endl;
}