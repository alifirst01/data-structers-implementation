#ifndef HEADER.H
#define HEADER

struct node{
	node* left;
	node* right;
	int data;
};

class Trees{
	node* root;
	int hieght;

public:
	Trees();
	Trees (Trees& T);
	~Trees();
	bool isEmpty();
	bool search(int);
	Trees& operator = (Trees& T);
	bool operator == (Trees& T);
	bool insert(node*&, int);
	bool delete_node(int);
	void printAss_recurrsive(node*);
	void printDes_recurrsive(node*);
	void printAss_iterative();
	void printDes_iterative();
	void print_LevelOrder();
	void countNodesRecursive(node*, int&);
	int countNodesIterative();
	void MirrorBST(node*&, node*&);
	int findHieght(node*, int);
	node* &getRoot(){
		return root;
	}
};

struct node1{
	node1* next;
	node1* prev;
	node* var;
};

class Stack{
	node1* current;
	int size;

public:
	Stack();
	bool push(node* e);
	bool pop(node*& e);
	bool isEmpty();
	int getSize(){
		return size;
	}
	void print();
};

class queue{
	node1* front;
	node1* rear;
public:
	queue();
	bool isEmpty();
	bool push(node* e);
	bool pop(node*& e);
};

#endif