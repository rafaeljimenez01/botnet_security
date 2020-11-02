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

int BSTdirIP::top5(IPBSTnode* current, int top){
	if(current && top < 6){
		top = this->top5(current->right, top);
		cout << top << ":  " << current->dirIP << " Duplicados: " << current->keyDuplicados << endl;
		top ++;
		top = this->top5(current->left, top);	
	}
	return top;
}

void BSTdirIP::top5(){
	cout << endl;
	top5(this->root, 1);
	cout << endl;
}