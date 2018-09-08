#include "Header.h"
#include <iostream>
using namespace std;

int main(){
	Trees BT1;
	int count = 0;

	BT1.insert(BT1.getRoot(), 10);              //Inserting Tree Elements
	BT1.insert(BT1.getRoot(), 2);
	BT1.insert(BT1.getRoot(), 0);
	BT1.insert(BT1.getRoot(), 3);
	BT1.insert(BT1.getRoot(), 13);
	BT1.insert(BT1.getRoot(), 14);
	BT1.insert(BT1.getRoot(), 11);
	BT1.insert(BT1.getRoot(), 5);
	BT1.insert(BT1.getRoot(), 1);
	BT1.insert(BT1.getRoot(), 4);
	BT1.insert(BT1.getRoot(), 12);
	
	if (BT1.search(12))                         //Searching Element
		cout << "Element Found\n";
	else
		cout << "Element not found\n";

	Trees BT2 = BT1;                            //Copy Constructor Calling

	cout << "Recursive Solution (Asscending): ";
	BT2.printAss_recurrsive(BT2.getRoot());         //Printing Asscending Order (Recursive Sol)
	cout << endl;
	cout << "Recursive Solution (Descending): ";    //Printing Descending Order (Recursive Sol)
	BT2.printDes_recurrsive(BT2.getRoot());
	cout << endl;
	cout << "Level Order Traversal: ";              //Level Order Traversal (Iterative)
	BT2.print_LevelOrder();
	cout << endl;

	count = BT2.countNodesIterative();             //Finding Number of Nodes
	cout << "Number of Nodes (Iterative): " << count << endl;

	BT2.delete_node(10);                           //Deleting node of tree

	Trees BT3;
	BT3 = BT2;                                     //Overloaded Assignment Operator
	
	cout << "\nAfter Deleting 10\n\n";
	cout << "Iterative Solution (Asscending): ";    //Printing Asscending Order (Iterative Sol)
	BT3.printAss_iterative();
	cout << endl;
	cout << "Iterative Solution (Descending): ";    //Printing Descending Order (Iterative Sol)
	BT3.printDes_iterative();
	cout << endl;
	cout << "Level Order Traversal: ";              //Level Order Traversal (Iterative)
	BT3.print_LevelOrder();
	cout << endl;
	count = 0;
	BT3.countNodesRecursive(BT3.getRoot(), count);

	BT3.insert(BT3.getRoot(), 10);

	cout << "Number of Nodes (Recurrsive): " << count << endl;
	cout << "Hieght: " << BT3.findHieght(BT3.getRoot(), 1) << endl;     //Finding Hieght of tree

	if (BT3 == BT2)                                //Overloaded == operator
		cout << "Equal\n";
	else
		cout << "Not Equal\n";

	cout << "\nLevel Order: ";
	BT3.print_LevelOrder();
	BT3.MirrorBST(BT3.getRoot()->left, BT3.getRoot()->right);        //Mirror BST Function
	cout << "\nAfter Mirror Image\nLevel Order: ";
	BT3.print_LevelOrder();
	cout << endl;

	return 0;                         //Destructors Calling
}