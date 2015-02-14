#include <iostream>
#include <cmath>
#include "bst.h"
#include "bst_node.h"

using std::cout;
using std::endl;

int main() {
	BST<int> bst;
	cout << "**********0********" << endl;
	cout << bst << endl;
	cout << "**********1********" << endl;
	bst.insert(90,300);
	cout << bst << endl;
	cout << "**********2********" << endl;
	for(int i=0;i<100;++i) 
		bst.insert(random()%100, random()%100);
	cout << bst << endl;
	cout << "********search*****" << endl;
	cout << bst.search(90) << endl;
	cout << "********max********" << endl;
	cout << bst.max() << endl;
	cout << "********min********" << endl;
	cout << bst.min() << endl;
	return 0;
}
