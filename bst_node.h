#ifndef _BST_NODE_H
#define _BST_NODE_H


template <typename T>
struct BST_Node {
	long key;
	BST_Node<T> *l;
	BST_Node<T> *r;
	BST_Node<T> *p;
	T data;
	bool valid;
};

#endif
