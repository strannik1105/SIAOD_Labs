#pragma once
typedef struct Point
{
	double x;
	double y;
	bool operator==(Point& other)
	{
		if ((x == other.x) && (y == other.y))
			return true;
		return false;
	}
};



class Triangle
{
private:
	Point p1;
	Point p2;
	Point p3;
	bool Is_Right_Triangle();
	bool Is_Isocless_Triangle();
	bool Is_Rectangular_Triangle();
public:
	Triangle();
	Triangle(Point, Point, Point);
	double Perimetr();
	double Square();
	void PrintInfo();
};

