#ifndef HEADER_H
#define HEADER_H
#include <iostream>
using namespace std;

template<class T>
class Array{
	T* array;
	int length;
	int* dimensions;
	int no_of_dim;

public:
	Array();
	void setDimensions();
	T getElement();
	void setElement (T e);
	void setFullArray();
	void print();
};

int getNum(char e){

	if (e == '1')
		return 1;
	else if (e == '2')
		return 2;
	else if (e == '3')
		return 3;
	else if (e == '4')
		return 4;
	else if (e == '5')
		return 5;
	else if (e == '6')
	    return 6;
	else if (e == '7')
		return 7;
	else if (e == '8')
		return 8;
	else if (e == '9')
		return 9;
}
bool ans;

template<typename T>
int findOffset(T* array, int* dimensions, int num){

	int* co_ordinates = new int[num];
	int offset = 0, i = 0, sum;
	char ch = 'i';

	cout << "Enter Co-ordinates for element to ";
	if (ans == true)
		cout << "set\n";
	else
		cout << "get\n";

	for (int m = 0; m < num; m++){
		cout << ch << " = ";
		cin >> co_ordinates[m];
		while (co_ordinates[m] >= dimensions[m]){
			cout << "Wrong Co-Ordinates ... Enter Again\n";
			cout << ch << " = ";
			cin >> co_ordinates[m];
		}
		ch++;
	}
	while (i < num){
		sum = 1;
		for (int j = i + 1; j < num; j++)
			sum = sum * dimensions[j];
		offset = offset + co_ordinates[i] * sum;
		i++;
	}
	return offset;
}

template<class T>
Array<T>::Array(){
	array = NULL;
	dimensions = NULL;
	length = 1;
	no_of_dim = 0;

	setDimensions();              //Setting Dimensions
}

template<class T>
void Array<T>::setDimensions(){   //Function to Input Dimensions of array
	
	char* dim = new char[100];
	cout << "Enter Dimensions: ";
	cin >> dim;

	dimensions = new int[strlen(dim)];

	for (int i = 0; i < strlen(dim); i++){
		if (dim[i] >= '0' && dim[i] <= '9'){
			dimensions[no_of_dim] = getNum(dim[i]);
			no_of_dim++;
		}
	}
	for (int i = 0; i < no_of_dim; i++)
		length = length * dimensions[i];

	array = new T[length];
	delete[] dim;
}        

template<class T>
void Array<T>::setFullArray(){        //Functions to Input all Elements of Array
	cout << "Enter Elements\n";
	for (int i = 0; i < length; i++)
		cin >> array[i];
}

template<class T>                     //Function to get array element
T Array<T>::getElement(){
	int i;
	ans = false;
	i = findOffset(array, dimensions, no_of_dim);
	return array[i];
}

template<class T>
void Array<T>::setElement(T e){       //Function to set an array element
	ans = true;
	int i;
	i = findOffset(array, dimensions, no_of_dim);
	array[i] = e;
}

template<class T>
void Array<T>::print(){               //Function to print complete array

	cout << "\nArray Elements\n";
	for (int i = 0; i < length; i++){
		cout << array[i] << " ";
		if (i % (dimensions[no_of_dim - 1]) == (dimensions[no_of_dim - 1] - 1))
			cout << endl;
	} 
}

#endif