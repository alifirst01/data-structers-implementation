#ifndef HEADER.H
#define HEADER

class Max_Heap{
	int* array;
	int length;
	int size;

public:
	Max_Heap(int);
	bool Insert(int);
	bool Delete_Max();
	void Print_Heap();
	void Max_heapify();
	void Heap_Sort();
	~Max_Heap();
};

#endif