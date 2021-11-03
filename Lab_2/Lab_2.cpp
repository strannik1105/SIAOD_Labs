#include "Triangle.h"
#include <iostream>
#include <Windows.h>


int main()
{
	system("chcp 1251");
	while (true)
	{
		Triangle* triangle = new Triangle();
		triangle->PrintInfo();
		system("pause");
	}
	system("pause");
}