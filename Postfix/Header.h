#ifndef HEADER_H
#define HEADER_H
using namespace std;

template <class T>              //Template Struct Node
struct node{
	node<T>* next;
	node<T>* prev;
	T var;
};

template <class T>              //Template Class Stack
class Stack{
	node<T>* current;
	int size;

public:
	Stack();                    //Stack Functions
	bool push(T e);
	bool pop(T& e);
	bool isEmpty();
	int getSize(){
		return size;
	}
	void print();
};

template <class T>
Stack<T>::Stack(){
	current = NULL;
	size = 0;
}

template <class T>
bool Stack<T>::push(T e){
	if (size == 0){
		current = new node<T>;
		current->next = NULL;
		current->prev = NULL;
		current->var = e;
	}
	else{
		node<T>* temp = new node<T>;
		temp->var = e;
		temp->next = NULL;
		current->next = temp;
		temp->prev = current;
		current = temp;
	}
	size++;
	return true;
}

template <class T>
bool Stack<T>::pop(T& e){
	if (!isEmpty()){
		if (size == 1){
			e = current->var;
			delete[] current;
			current = NULL;
		}
		else{
			node<T>* temp = current;
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

template <class T>
bool Stack<T>::isEmpty(){
	if (size == 0)
		return true;
	else
		return false;
}

template <class T>
void Stack<T>::print(){

	for (int i = 0; i < size; i++)
	{
		cout << current->var << " ";
		current = current->prev;
	}
}

#endif