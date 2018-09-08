#include "Header.h"
#include <iostream>
using namespace std;

int main(){

	Array<int> arr;                        //Declaration and Setting Dimensions

	arr.setFullArray();                      //Input All array Elements

	cout << "Element: " << arr.getElement() << endl;          //Getting an array element. Dimension are input in function

	arr.setElement(arr.getElement() + arr.getElement());      //Setting an array element. Dimension are input in function

	arr.print();                             //Printing all array elements

	return 0;
}