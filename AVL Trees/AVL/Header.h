#ifndef HEADER.H
#define HEADER

struct node{
	node* left;
	node* right;
	node* parent;
	int data;
	int hieght;
};

struct node1{
	node1* next;
	node1* prev;
	node* var;
};

class Trees{
	node* root;
public:
	Trees();
	bool insert(node*&, node*&, int);
	void print(node*);
	void print_LevelOrder();
	node*& getRoot(){
		return root;
	}
	~Trees();
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