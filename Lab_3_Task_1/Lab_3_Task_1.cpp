#include "List.h"
#include <iostream>

using namespace std;

int main()
{
	List* list = new List(0);
	list->Add_Node_In_End(-3);
	cout << endl;
	list->Add_Node_In_End(5);
	cout << endl;
	list->Add_Node_In_End(6);
	cout << endl;
	//list->Get_Node(0);
	//cout << list->Get_Node(2)->Get_Value() << endl;
	//cout << list->Get_Node(1)->Get_Value() << endl;
	//cout << list->Get_Node(3)->Get_Value() << endl;
	//cout << list->Get_Node(3)->Get_Value() << endl;
	return 0;
}