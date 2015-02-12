CC=g++

CXXFLAGS= -g
LDFLAGS= -g

BST:bst.h main.cc bst_node.h
	$(CC) $(CXXFLAGS) -o BST main.cc

.PHONY:clean

clean:
	@rm -f .o
	@rm -f BST
