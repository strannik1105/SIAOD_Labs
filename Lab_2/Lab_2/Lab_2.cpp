#include "Triangle.h"
#include <iostream>
#include <Windows.h>

//using namespace std;

int main()
{
	system("chcp 1251");
	while (true)
	{
		system("clear");
		Triangle* triangle = new Triangle();
		triangle->PrintInfo();
	}
	system("pause");
}