#include "List.h"

void List::Change_Number()
{
	this->number++;
	if (this->next_node != nullptr)
		this->next_node->Change_Number();
}

List::List(int value)
{
	this->next_node = nullptr;
	this->value = value;
	this->number = 0;
}

List::List(List* node, int value, int count)
{
	this->next_node = node;
	this->value = value;
}

void List::Add_Node_In_End(int value)
{
	if (this->next_node == nullptr)
	{
		this->next_node = new List(value);
		next_node->number = this->number + 1;
		next_node->prev_node = this;
	}
	else
	{
		this->next_node->Add_Node_In_End(value);
	}
}

void List::Add_Node_In_Start(int value)
{
	this->prev_node = new List(value);
	//this = this->prev_node;
}

void List::Add_Node_After_Node(int value, int number)
{
	List* node = Get_Node(number);
	if (node->next_node == nullptr)
		node->Add_Node_In_End(value);
	else
	{
		List* next_node = node->next_node;
		node->next_node = new List(value);
		node->next_node->number = next_node->number;
	}
}

List* List::Get_Node(int number)
{
	if (this->number == number)
		return this;
	else if (this->next_node != nullptr)
		return this->next_node->Get_Node(number);
	else
		return nullptr;
}

int List::Get_Value()
{
	return (this != nullptr) ? this->value: 0;
}