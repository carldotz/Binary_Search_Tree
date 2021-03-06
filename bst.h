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
		BST_Node<T>& search(BST_Node<T> *f, long key) const;
		void free(BST_Node<T> *root);
		BST_Node<T>& max(BST_Node<T> *root) const; 
		BST_Node<T>& min(BST_Node<T> *root) const; 

	public:
		BST() {
			root = NULL;
		}

		~BST() {
			free(root);
		}

		bool insert(long key, T data);
		bool remove(long key);
		BST_Node<T>& search(long key) const;
		BST_Node<T>&  max() const;
		BST_Node<T>&  min() const;
		void inorder(std::ostream& out) const;
		void preorder(std::ostream& out) const;
		void postorder(std::ostream& out) const;

};

template <typename T>
bool BST<T>::transplant(BST_Node<T> *u, BST_Node<T> *v) {
	if(!u->p) {
		root = v;
	} else if(u == u->p->l) {
		u->p->l = v;
	} else if(u == u->p->r) {
		u->p->r = v;
	}
	if(v) {
		v->p = u->p;
	}

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
void BST<T>::free(BST_Node<T> *root) {
	if(root) {
		if(root->l) {
			free(root->l);
		}
		if(root->r) {
			free(root->r);
		}	
		delete root;
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
	c->valid = true;

	return true;
}

template <typename T>
bool BST<T>::remove(long key) { 
	BST_Node<T> *z = &(search(key));
	BST_Node<T> *y = NULL;
	if(!z->valid) return false;
	if(!z->l) {
		transplant(z,z->r);
	} else if(!z->r) {
		transplant(z,z->l);
	} else {
		y = &min(z->r);
		if(y->p != z) {
			transplant(y, y->r);
			y->r = z->r;
			y->r->p = y;
		}
		transplant(z, y);
		y->l = z->l;
		y->l->p = y;
	}
	delete z;
	return true;
}

template <typename T>
BST_Node<T>& BST<T>::search(BST_Node<T> *f, long key) const{
	BST_Node<T> *i = f;
	if(i->key == key) 
	  return *i;
	else if(i->r && key > i->key)
	  return search(i->r, key);
	else if(i->l && key < i->key)
	  return search(i->l, key);
	return *(new BST_Node<T>);
}

template <typename T>
BST_Node<T>& BST<T>::search(long key) const{
	return search(root, key);
}

template <typename T>
BST_Node<T>& BST<T>::max(BST_Node<T> *root) const {
	BST_Node<T> *i = root;
	if(root) {
		while(i->r) i = i->r;
		return *i;
	} else {
		return *(new BST_Node<T>);
	}
}

template <typename T>
BST_Node<T>& BST<T>::min(BST_Node<T> *root) const {
	BST_Node<T> *i = root;
	if(root) {
		while(i->l) i = i->l;
		return *i;
	} else {
		return *(new BST_Node<T>);
	}
}

template <typename T>
BST_Node<T>& BST<T>::max() const {
	return max(root);
}

template <typename T>
BST_Node<T>& BST<T>::min() const {
	return min(root);
}

template <typename T>
std::ostream& operator<<(std::ostream &out, const BST<T> & bst) {
	bst.inorder(out);
	return out;
} 

#endif
