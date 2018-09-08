#include <iostream>
#include "Header.h"
using namespace std;

int main(){

	int size = 0, e;
	cout << "Enter Size: ";
	cin >> size;
	Max_Heap M(size);

	cout << "Enter Elements: ";
	for (int i = 0; i < size; i++){
		cin >> e;
		M.Insert(e);
	}
	cout << endl;

	cout << "After Inserting Elements\n";
	M.Print_Heap();

	M.Delete_Max();
	cout << "After Deleting Max\n";
	M.Print_Heap();

	M.Heap_Sort();
	cout << "Heap Sort\n";
	M.Print_Heap();

	M.Max_heapify();
	cout << "After Heapify\n";
	M.Print_Heap();
	return 0;
}