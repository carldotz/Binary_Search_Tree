#ifndef _BST_H
#define _BST_H

#include <iostream>
#include "bst_node.h"

template <typename T>
class BST {

	private:
		BST_Node<T> * root;

		bool transplant(BST_Node<T> *u, BST_Node<T> *v);

		void inorder(BST_Node<T> *location, std::ostream& out) const;
		void preorder(BST_Node<T> *location, std::ostream& out) const;
		void postorder(BST_Node<T> *location, std::ostream& out) const;
		T search(BST_Node<T> *f, long key) const;

	public:
		BST() {
			root = NULL;
		}

		~BST() {
		}

		bool insert(long key, T data);
		bool remove(long key);
		T search(long key) const;
		T max() const;
		T min() const;
		void inorder(std::ostream& out) const;
		void preorder(std::ostream& out) const;
		void postorder(std::ostream& out) const;

};

template <typename T>
bool BST<T>::transplant(BST_Node<T> *u, BST_Node<T> *v) {

	return true;
}

template <typename T>
void BST<T>::inorder(BST_Node<T> *root, std::ostream& out) const {
	if(root) {
		if(root->l) {
			inorder(root->l, out);
		}
		out << (root->key) << "," << (root->data) << "\t";
		if(root->r) {
			inorder(root->r, out);
		}	
	} else {
		out << "Empty" << std::endl;
	}
}

template <typename T>
void BST<T>::preorder(BST_Node<T> *root, std::ostream& out) const {
	if(root) {
		out << (root->key) << "," << (root->data) << "\t";
		if(root->l) {
			preorder(root->l, out);
		}
		if(root->r) {
			preorder(root->r, out);
		}
	} else {
		out << "Empty" << std::endl;
	}
}

template <typename T>
void BST<T>::postorder(BST_Node<T> *root, std::ostream& out) const {
	if(root) {
		if(root->l) {
			postorder(root->l, out);
		}
		if(root->r) {
			postorder(root->r, out);
		}
		out << (root->key) << "," << (root->data) << "\t";
	} else {
		out << "Empty" << std::endl;
	}
}

template <typename T>
void BST<T>::inorder(std::ostream& out) const {
	inorder(root, out);
}

template <typename T>
void BST<T>::preorder(std::ostream& out) const {
	preorder(root, out);
}

template <typename T>
void BST<T>::postorder(std::ostream& out) const {
	postorder(root, out);
}

template <typename T>
bool BST<T>::insert(long key, T data) { 
	BST_Node<T> *p = root; 
	BST_Node<T> *c = root;
	bool left = false;
	if(root) {
		while(c != NULL) {
			p = c;
			if(c->key == key) {
				c->data = data;
				return true;
			} else if(key > c->key) { 
				c = c->r;
				left = false;
			} else if(key < c->key) {
				c = c->l;
				left = true;
			}
		}

		if(left) {
			p->l = new BST_Node<T>;
			c = p->l;
		} else {
			p->r = new BST_Node<T>;
			c = p->r;
		}

	} else {
		root = new BST_Node<T>;
		c = root;
	}
	c->p = p;
	c->data = data;
	c->key = key;
	c->r = NULL;
	c->l = NULL;

	return true;
}

template <typename T>
bool BST<T>::remove(long key) { 

	return true;
}

template <typename T>
T BST<T>::search(BST_Node<T> *f, long key) const{
	BST_Node<T> *i = f;
	if(i->key == key) 
	  return i->data;
	else if(i->r && key > i->key)
	  return search(i->r, key);
	else if(i->l && key < i->key)
	  return search(i->l, key);
	return i->data;
}

template <typename T>
T BST<T>::search(long key) const{
	return search(root, key);
}

template <typename T>
T BST<T>::max() const {
	BST_Node<T> *i = root;
	if(root) {
		while(i->r) i = i->r;
		return i->data;
	} else {
		return 0;
	}
}

template <typename T>
T BST<T>::min() const {
	BST_Node<T> *i = root;
	if(root) {
		while(i->l) i = i->l;
		return i->data;
	} else {
		return 0;
	}
}

template <typename T>
std::ostream& operator<<(std::ostream &out, const BST<T> & bst) {
	bst.inorder(out);
	return out;
}

#endif
