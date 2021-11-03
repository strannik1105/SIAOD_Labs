#pragma once
#include <iostream>

using namespace std;

class List
{
private:
	List* next_node;
	List* prev_node;
	int value;	
	int number;
	void Change_Number();
public:
	List(int);
	List(List*, int, int);
	void Add_Node_In_End(int);
	void Add_Node_In_Start(int);
	void Add_Node_After_Node(int, int);
	List* Get_Node(int);
	int Get_Value();
};

