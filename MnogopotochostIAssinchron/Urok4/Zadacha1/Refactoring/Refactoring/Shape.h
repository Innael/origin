#pragma once
#include<string>

enum Type {
	  line = 0,
      sqr = 1,
      cube = 2,
      circle = 3,
      cylinder = 4
};

class Shape
{
public:		
	Shape() = default;					
	int getType() { return type; }
	void shift(int m, int n, int k);
	void scaleAxis(char axis, int a);
	void scale(int s);

	int type = 0;
	int x1 = 0, y1 = 0, z1 = 0,
		x2 = 0, y2 = 0, z2 = 0,
		x3 = 0, y3 = 0, z3 = 0,
		x4 = 0, y4 = 0, z4 = 0,
		x5 = 0, y5 = 0, z5 = 0,
		x6 = 0, y6 = 0, z6 = 0,
		x7 = 0, y7 = 0, z7 = 0,
		x8 = 0, y8 = 0, z8 = 0;	
	double volume = 0;
	double square = 0;
	double height = 0;
	double radius = 0;
};

class Line : public Shape {
public:
	Line();
	Line(int _x1, int _y1, int _x2, int _y2);
};

class Square : public Line {
public:
	Square();
	Square(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4);
};

class Cube : public Square {
public:
	Cube(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8);
};

class Circle : public Shape {
public:
	Circle();
	Circle(int _x1, int _y1, double R);
};

class Cylinder : public Circle {
public:
	Cylinder(int _x1, int _y1, double R, double H);
};
