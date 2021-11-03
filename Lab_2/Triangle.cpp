#include "Triangle.h"
#include <math.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Triangle::Triangle()
{
	while (true)
	{
		cout << "Ввод координат вершин треугольника: " << endl;
		cout << "\tA: " << endl << "\t\tx: = ";
		cin >> p1.x;
		cout << "\t\ty = ";
		cin >> p1.y;
		cout << "\tB: " << endl << "\t\tx = ";
		cin >> p2.x;
		cout << "\t\ty = ";
		cin >> p2.y;
		cout << "\tC = " << endl << "\t\tx = ";
		cin >> p3.x;
		cout << "\t\ty = ";
		cin >> p3.y;
		if ((p1 == p2) || (p1 == p3) || (p2 == p3))
		{
			cout << "Точки совпадают" << endl;
		}
		else
			break;
	}
}

Triangle::Triangle(Point p1, Point p2, Point p3)
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
}

double Triangle::Perimetr()
{
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)) + sqrt(pow(p2.x - p3.x, 2) + pow(p2.y - p3.y, 2)) + sqrt(pow(p1.x - p3.x, 2) + pow(p1.y - p3.y, 2));
}

double Triangle::Square()
{
	//формула Герона
	// p = (a + b + c)/2, где a, b, c стороны
	//	S = p(p - a)(p - b)(p - c)
	return sqrt((Perimetr() / 2) * (((Perimetr() / 2) - (sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0)))) * ((Perimetr() / 2) - (sqrt(pow(p2.x - p3.x, 2.0) + pow(p2.y - p3.y, 2.0)))) * 
		((Perimetr() / 2) - (sqrt(pow(p1.x - p3.x, 2.0) + pow(p1.y - p3.y, 2.0))))));
}

bool Triangle::Is_Right_Triangle()
{
	if ((sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0)) == sqrt(pow(p2.x - p3.x, 2.0) + pow(p2.y - p3.y, 2.0)))
		&& ((sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0)) == sqrt(pow(p1.x - p3.x, 2.0) + pow(p1.y - p3.y, 2.0)))))
	{
		return true;
	}
	return false;
}

bool Triangle::Is_Isocless_Triangle()
{
	if ((sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0)) == sqrt(pow(p2.x - p3.x, 2.0) + pow(p2.y - p3.y, 2.0))) && (sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0)) != sqrt(pow(p1.x - p3.x, 2.0) + pow(p1.y - p3.y, 2.0))))
	{
		return true;
	}
	else if ((sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0)) == sqrt(pow(p1.x - p3.x, 2.0) + pow(p1.y - p3.y, 2.0))) && (sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0)) != sqrt(pow(p2.x - p3.x, 2.0) + pow(p2.y - p3.y, 2.0))))
	{
		return true;
	}
	else if ((sqrt(pow(p1.x - p3.x, 2.0) + pow(p1.y - p3.y, 2.0)) == sqrt(pow(p2.x - p3.x, 2.0) + pow(p2.y - p3.y, 2.0))) && (sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0)) != sqrt(pow(p1.x - p3.x, 2.0) + pow(p1.y - p3.y, 2.0))))
	{
		return true;
	}
	return false;
}

bool Triangle::Is_Rectangular_Triangle()
{
	if ((pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0)) + (pow(p2.x - p3.x, 2.0) + pow(p2.y - p3.y, 2.0)) == (pow(p1.x - p3.x, 2.0) + pow(p1.y - p3.y, 2.0)))
	{
		return true;
	}
	else if ((pow(p1.x - p3.x, 2.0) + pow(p1.y - p3.y, 2.0)) + (pow(p2.x - p3.x, 2.0) + pow(p2.y - p3.y, 2.0)) == (pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0)))
	{
		return true;
	}
	else if ((pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0)) + (pow(p1.x - p3.x, 2.0) + pow(p1.y - p3.y, 2.0)) == (pow(p2.x - p3.x, 2.0) + pow(p2.y - p3.y, 2.0)))
	{
		return true;
	}
	return false;
}

void Triangle::PrintInfo()
{
	cout << "Информация о треугольнике: " << endl;
	cout << "Координаты:" << endl;
	cout << "\tA("<< p1.x << "," << p1.y <<") B(" << p2.x << "," << p2.y << ") C(" << p3.x << "," << p3.y << ")" << endl;
	cout << "Периметр треугольника: " << Perimetr() << endl;
	cout << "Площадь треугольника: " << Square() << endl;
	if (Square() != 0)
	{
		if (Is_Right_Triangle())
			cout << "Вид: правильный треугольник" << endl;
		else if (Is_Isocless_Triangle())
		{
			if (Is_Rectangular_Triangle())
			{
				cout << "Вид: равнобедренный прямоугольный треугольник" << endl;
			}
			else
			{
				cout << "Вид: равнобедренный треугольник" << endl;
			}
		}
		else if (Is_Rectangular_Triangle())
		{
			cout << "Вид: прямоугольный треугольник" << endl;
		}
		else
		{
			cout << "Вид: разносторонний треугольник" << endl;
		}
	}
	else
		cout << "Вид: вырожденный треугольник" << endl;
	cout << endl;
}