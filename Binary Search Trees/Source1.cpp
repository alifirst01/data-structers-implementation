#include "Header.h"
#include <iostream>
using namespace std;
bool ans;
node* makeCopy(node* current){
	if (current != NULL){
		node* temp = new node;
		temp->data = current->data;
		temp->left = makeCopy(current->left);
		temp->right = makeCopy(current->right);
		return temp;
	}
	return NULL;
}

bool compareNode(node* n1, node* n2){
	if (n1 == NULL && n2 == NULL)
		return true;
	if (n1 == NULL || n2 == NULL)
		return false;
	if (n1->data == n2->data){
		ans = compareNode(n1->left, n2->left);
		if (ans == false)
			return false;
		ans = compareNode(n1->right, n2->right);
		if (ans == false)
			return false;
	}
	else
		return false;
	return true;
}

void NodeDestructor(node* &ptr){
	if (ptr != NULL){
		NodeDestructor(ptr->left);
		NodeDestructor(ptr->right);
		delete ptr;
		ptr = NULL;
	}
}

void find_case(node* &current, node* &previous, int e){

	if (current->left == NULL && current->right == NULL){
		delete current;
		if (e < previous->data)
			previous->left = NULL;
		else
			previous->right = NULL;
	}
	else if (current->right == NULL){
		if (e > previous->data)
			previous->right = current->left;
		else
			previous->left = current->left;
		delete current;
	}
	else if (current->left == NULL){
		if (e > previous->data)
			previous->right = current->right;
		else
			previous->left = current->right;
		delete current;
	}
	else{

		node* temp = current;
		previous = current;
		current = current->left;
		while (current->right != NULL){
			previous = current;
			current = current->right;
		}
		swap(current->data, temp->data);
		find_case(current, previous, current->data);
	}
}

Trees::Trees(){
	root = NULL;
	hieght = 0;
}

Trees::Trees(Trees& T){
	root = makeCopy(T.getRoot());
}

bool Trees::isEmpty(){
	return ((root == NULL) ? true : false);
}

bool Trees::search(int e){

	node* current = root;
	while (current != NULL){
		if (e == current->data)
			return true;
		else if (e > current->data)
			current = current->right;
		else if (e < current->data)
			current = current->left;
	}
	return false;
}

bool Trees::insert(node*& current, int e){

	if (current != NULL){
		if (e == current->data)
			return false;
		else if (e > current->data){
			return(insert(current->right, e));
		}
		else if (e < current->data)
			return(insert(current->left, e));
	}

	current = new node;
	current->left = NULL;
	current->right = NULL;
	current->data = e;
	return true;
}

Trees& Trees::operator = (Trees& T){
	if (T.getRoot() != NULL){
		this->~Trees();
		root = makeCopy(T.getRoot());
	}
	else
		root = NULL;
	return *this;
}

bool Trees::operator == (Trees& T){
	return(compareNode(root, T.getRoot()));
}

bool Trees::delete_node(int e){
	node* current = root;
	node* previous;

	if (!isEmpty()){
		while (e != current->data && current != NULL){
			previous = current;
			if (e > current->data)
				current = current->right;
			else if (e < current->data)
				current = current->left;
		}
	}
	if (current == NULL)
		return false;
	find_case(current, previous, e);
	return true;
}

void Trees::printAss_recurrsive(node* current){

	if (current->left == NULL)
		cout << current->data << " ";
	else{
		printAss_recurrsive(current->left);
		cout << current->data << " ";
	}
	if (current->right == NULL)
		return;
	printAss_recurrsive(current->right);
	return;
}

void Trees::printDes_recurrsive(node* current){
	if (current->right == NULL)
		cout << current->data << " ";
	else{
		printDes_recurrsive(current->right);
		cout << current->data << " ";
	}
	if (current->left == NULL)
		return;
	printDes_recurrsive(current->left);
	return;
}

void Trees::printAss_iterative(){
	Stack stk;
	node* current = root;

	stk.push(current);
	current = current->left;

	while (!(stk.isEmpty() && current == NULL)){
		if (current != NULL){
			stk.push(current);
			current = current->left;
		}
		else{
			stk.pop(current);
			cout << current->data << " ";
			current = current->right;
		}
	}
}

void Trees::printDes_iterative(){

	Stack stk;
	node* current = root;

	stk.push(current);
	current = current->right;

	while (!(stk.isEmpty() && current == NULL)){
		if (current != NULL){
			stk.push(current);
			current = current->right;
		}
		else{
			stk.pop(current);
			cout << current->data << " ";
			current = current->left;
		}
	}
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

void Trees::countNodesRecursive(node* current, int& count){
	if (current != NULL){
		countNodesRecursive(current->left, ++count);
		countNodesRecursive(current->right, count);
	}
}

int Trees::countNodesIterative(){

	int count = 0;
	queue que;
	if (root == NULL)
		return 0;

	node* current = root;
	que.push(current);

	while (!que.isEmpty()){
		que.pop(current);
		count++;
		if (current->left != NULL)
			que.push(current->left);
		if (current->right != NULL)
			que.push(current->right);
	}
	return count;
}

int Trees::findHieght(node* current, int temp){

	if (current != NULL){
		findHieght(current->left, ++temp);
		--temp;
		findHieght(current->right, temp);
	}
	else{
		if (hieght < temp)
			hieght = temp;
	}
	return hieght;
}

void Trees::MirrorBST(node*& left, node*& right){
	if (left != NULL && right != NULL){
		swap(left, right);
		MirrorBST(left->left, left->right);
		MirrorBST(right->left, right->right);
	}
}

Trees::~Trees(){
	NodeDestructor(root);
	root = NULL;
}

Stack::Stack(){
	current = NULL;
	size = 0;
}

bool Stack::push(node* ptr){
	if (size == 0){
		current = new node1;
		current->next = NULL;
		current->prev = NULL;
		current->var = ptr;
	}
	else{
		node1* temp = new node1;
		temp->var = ptr;
		temp->next = NULL;
		current->next = temp;
		temp->prev = current;
		current = temp;
	}
	size++;
	return true;
}

bool Stack::pop(node*& e){
	if (!isEmpty()){
		if (size == 1){
			e = current->var;
			delete[] current;
			current = NULL;
		}
		else{
			node1* temp = current;
			e = current->var;
			current = current->prev;
			current->next = NULL;
			delete temp;
		}
		size--;
		return true;
	}
	return false;
}

bool Stack::isEmpty(){
	if (size == 0)
		return true;
	else
		return false;
}

void Stack::print(){

	for (int i = 0; i < size; i++)
	{
		cout << current->var << " ";
		current = current->prev;
	}
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
