#include "Header.h"
#include <iostream>
using namespace std;
int main(){
	Trees T;
	node* ptr = NULL;

	T.insert(T.getRoot(), ptr, 5);
	T.insert(T.getRoot(), ptr, 3);
	T.insert(T.getRoot(), ptr, 12);
	T.insert(T.getRoot(), ptr, 15);
	T.insert(T.getRoot(), ptr, 19);
	T.insert(T.getRoot(), ptr, 7);
	T.insert(T.getRoot(), ptr, 8);
	T.insert(T.getRoot(), ptr, 9);
	T.insert(T.getRoot(), ptr, 0);
	T.insert(T.getRoot(), ptr, 13);
	T.insert(T.getRoot(), ptr, 26);
	T.insert(T.getRoot(), ptr, 21);
	T.insert(T.getRoot(), ptr, 32);
	T.insert(T.getRoot(), ptr, 54);
	T.insert(T.getRoot(), ptr, 45);
	T.insert(T.getRoot(), ptr, 6);
	T.insert(T.getRoot(), ptr, 2);
	T.insert(T.getRoot(), ptr, 79);
	T.insert(T.getRoot(), ptr, 48);

	T.print_LevelOrder();
	return 0;
}