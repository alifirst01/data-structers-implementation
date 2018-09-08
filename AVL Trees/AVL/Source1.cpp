#include "Header.h"
#include <iostream>
using namespace std;

void updateHieght(node* current){

	int check = 0;
	node* temp = current;
	current = current->parent;
	while (current != NULL){
		if (current->left == NULL || current->right == NULL || check == 1){
			if (current->hieght == temp->hieght)
				++current->hieght;
			else
				break;
			temp = current;
			current = current->parent;
			check = 1;
		}
		else
			break;
	}
	return;
}

void NodeDestructor(node* &ptr){
	if (ptr != NULL){
		NodeDestructor(ptr->left);
		NodeDestructor(ptr->right);
		delete ptr;
		ptr = NULL;
	}
}

node* updateTreeHieght(node* root){
	Trees* T = new Trees;
	queue Q;
	node* current = root;
	node* ptr = NULL;
	Q.push(current);
	while (!Q.isEmpty()){

		Q.pop(current);
		T->insert(T->getRoot(), ptr, current->data);
		if (current->left != NULL)
			Q.push(current->left);
		if (current->right != NULL)
			Q.push(current->right);
		ptr = NULL;
	}
	NodeDestructor(root);
	return T->getRoot();
}

bool checkDifference(node* current){

	if (current->left != NULL || current->right != NULL){
		if (current->left == NULL){
			if (abs(-1 - current->right->hieght) > 1)
				return false;
		}
		else if (current->right == NULL){
			if (abs(current->left->hieght - (-1)) > 1)
				return false;
		}
		else{
			if (abs(current->left->hieght - current->right->hieght) > 1)
				return false;
		}
	}
	return true;
}

int findCase(node* current){

	int ans;
	if (current->right == NULL){
		if (current->left->right == NULL)
			ans = 1;
		else if (current->left->left == NULL)
			ans = 3;
		else{
			if (current->left->left->hieght > current->left->right->hieght)
				ans = 1;
			else
				ans = 3;
		}
	}
	else if (current->left == NULL){

		if (current->right->left == NULL)
			ans = 2;
		else if (current->right->right == NULL)
			ans = 4;
		else{
			if (current->right->right->hieght > current->right->left->hieght)
				ans = 2;
			else
				ans = 4;
		}
	}
	else{
		if (current->left->hieght > current->right->hieght){
			if (current->left->right == NULL)
				ans = 1;
			else if (current->left->left == NULL)
				ans = 3;
			else{
				if (current->left->left->hieght > current->left->right->hieght)
					ans = 1;
				else
					ans = 3;
			}
		}
		else{
			if (current->right->left == NULL)
				ans = 2;
			else if (current->right->right == NULL)
				ans = 4;
			else{
				if (current->right->right->hieght > current->right->left->hieght)
					ans = 2;
				else
					ans = 4;
			}
		}
	}
	return ans;
}

void performLeftRotation(node* X, node* Y, int num){

	X->right = NULL;
	Y->parent = NULL;
	X->right = Y->left;
	Y->left = X;

	Y->parent = X->parent;
	if (num == 1)
		X->parent->left = Y;
	else if (num == 2)
		X->parent->right = Y;
	X->parent = Y;
}

void performRightRotation(node* X, node* Y, int num){

	X->left = NULL;
	Y->parent = NULL;
	X->left = Y->right;
	Y->right = X;

	Y->parent = X->parent;
	if (num == 1)
		X->parent->left = Y;
	else if (num == 2)
		X->parent->right = Y;
	X->parent = Y;
}

void BalanceTree(node* current, node*& root){

	int Case = 0, num = 0;
	bool ans = false;
	while (current != NULL){
		if (!checkDifference(current)){
			ans = true;
			break;
		}
		current = current->parent;
	}

	if (ans == true){
		if (current->parent != NULL){
			if (current->parent->left == NULL)
				num = 1;
			else if (current->parent->right == NULL)
				num = 2;
			else if (current->parent->left->hieght >= current->parent->right->hieght)
				num = 1;
			else
				num = 2;
		}
		Case = findCase(current);

		if (Case == 1)
			performRightRotation(current, current->left, num);

		else if (Case == 2)
			performLeftRotation(current, current->right, num);

		else if (Case == 3){
			performLeftRotation(current->left, current->left->right, 1);
			performRightRotation(current, current->left, num);
		}
		else if (Case == 4){
			performRightRotation(current->right, current->right->left, 2);
			performLeftRotation(current, current->right, num);
		}
		while (current->parent != NULL)
			current = current->parent;
		root = current;
		root = updateTreeHieght(root);
	}
}

Trees::Trees(){
	root = NULL;
}

bool Trees::insert(node*& current, node*& previous, int e){

	if (current != NULL){
		if (e == current->data)
			return false;
		previous = current;
		if (e > current->data)
			return(insert(current->right, previous, e));
		else if (e < current->data)
			return(insert(current->left, previous, e));
	}

	current = new node;
	current->left = NULL;
	current->right = NULL;
	current->data = e;
	current->parent = previous;
	current->hieght = 0;

	updateHieght(current);
	BalanceTree(current, root);

	return true;
}

void Trees::print(node* current){

	if (current != NULL){
		print(current->left);
		cout << "D:" << current->data << "  H:" << current->hieght << " , ";
		print(current->right);
	}
	return;
}

void Trees::print_LevelOrder(){
	queue que;
	node* current = root;
	que.push(current);

	while (!que.isEmpty()){
		que.pop(current);
		cout << current->data << " ";
		if (current->left != NULL)
			que.push(current->left);
		if (current->right != NULL)
			que.push(current->right);
	}
}

Trees::~Trees(){
	NodeDestructor(root);
	root = NULL;
}

queue::queue(){
	front = NULL;
	rear = NULL;
}

bool queue::isEmpty(){
	return((front == NULL && rear == NULL));
}

bool queue::push(node* e){

	if (isEmpty()){
		rear = new node1;
		rear->next = NULL;
		rear->prev = NULL;
		rear->var = e;
		front = rear;
	}
	else{
		node1* temp = new node1;
		temp->var = e;
		rear->next = temp;
		temp->prev = rear;
		temp->next = NULL;
		rear = temp;
	}
	return true;
}

bool queue::pop(node*& e){
	if (!isEmpty()){
		if (rear == front){
			e = front->var;
			delete front;
			front = NULL;
			rear = NULL;
		}
		else{
			node1* temp = front;
			e = front->var;
			front = front->next;
			front->prev = NULL;
			delete temp;
		}
		return true;
	}
	return false;
}