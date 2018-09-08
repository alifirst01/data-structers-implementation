#include <iostream>
#include "Header.h"
using namespace std;

int* doubleLength(int** array, int size, int& length){
	
	length = length * 2;
	int* temp = new int[length];
	for (int i = 1; i < size; i++)
		temp[i] = (*array)[i];
	delete[](*array);
	*array = NULL;
	return temp;

}

void BubbleUp(int* array, int size){

	while (size > 1){
		if (array[size / 2] < array[size])
			swap(array[size / 2], array[size]);
		else
			break;
		size = size / 2;
	}
	return;
}

void BubbleDown(int* array, int i, int size){

	while (i <= size / 2){
		if (i * 2 + 1 <= size){
			if (array[i * 2] >= array[i * 2 + 1]){
				if (array[i] < array[i * 2])
					swap(array[i], array[i * 2]);
				else
					break;
				i = i * 2;
			}
			else{
				if (array[i] < array[i * 2 + 1])
					swap(array[i], array[i * 2 + 1]);
				else
					break;
				i = i * 2 + 1;
			}
		}
		else if (i * 2 <= size){
			if (array[i] < array[i * 2])
				swap(array[i], array[i * 2]);
			else
				break;
			i = i * 2;
		}
	}
	return;
}

Max_Heap::Max_Heap(int s){

	cout << "Constructor";
	size = 0;
	length = s;
	array = new int[length];
	cout << endl;
}

bool Max_Heap::Insert(int e){

	size++;
	if (size == length)
		array = doubleLength(&array, size, length);

	array[size] = e;
	BubbleUp(array, size);
	return true;
}

bool Max_Heap::Delete_Max(){

	swap(array[1], array[size]);
	size--;
	BubbleDown(array, 1, size);
	return true;
}

void Max_Heap::Print_Heap(){
	cout << "Max Heap: ";
	for (int i = 1; i <= size; i++)
		cout << array[i] << " ";
	cout << endl << endl;
	return;
}

//Heap Sort is creating a sorting array out of a Max heap or a Min heap which is previously created by Heapify algorithm from an unsorted array. Complexity of heap sort is O(nlogn) because you run O(logn) bubble down for n nodes.
void Max_Heap::Heap_Sort(){
	int i = size;
	while (i > 1){
		swap(array[1], array[i]);
		i--;
		BubbleDown(array, 1, i);
	}
	return;
}

//Max Heapify actually make an unsorted array into a Max Heap by starting at a node with a condition that its children are Max Heap. Thats why it starts at n/2 because the condition is satisfied here and its children (leaf nodes) are Max Heap.
//Start with node n/2 and apply bubble down and then move to n/2 - 1 and apply bubble down and so on.... As you move up, number of nodes decrease but ammount of work increase as you have to bubble down more deep. So one term decreases and other increases and that makes complexity O(n).

void Max_Heap::Max_heapify(){                            
															
	int i = size/2, check = 0;
	while (i > 1){
		if (array[i / 2] < array[i]){
			swap(array[i / 2], array[i]);
			BubbleDown(array, i, size);
		}
		i--;
	}
	return;
}
//Max Heapify can also be used for a single node if condition that both its children are max heaps is satisfied

Max_Heap::~Max_Heap(){
	cout << "Destructor";
	delete[]array;
	cout << endl;
}
