#define _USE_MATH_DEFINES
#include"Shape.h"
#include<cmath>


void Shape::shift(int m, int n, int k)
{
	switch (type)
	{
	case Type::line:
		x1 += m; y1 += n;
		x2 += m; y2 += n;
		break;
	case Type::sqr:
		x1 += m; y1 += n;
		x2 += m; y2 += n;
		x3 += m; y3 += n;
		x4 += m; y4 += n;
		break;
	case Type::cube:
		x1 += m; y1 += n; z1 += k;
		x2 += m; y2 += n; z2 += k;
		x3 += m; y3 += n; z3 += k;
		x4 += m; y4 += n; z4 += k;
		x5 += m; y5 += n; z5 += k;
		x6 += m; y6 += n; z6 += k;
		x7 += m; y7 += n; z7 += k;
		x8 += m; y8 += n; z8 += k;
		break;
	}	
}

void Shape::scaleAxis(char axis, int a)
{
	switch (type)
	{
	case Type::line:
		if (axis == 'x') {
			x1 *= a;
			x2 *= a;
		}
		else if (axis == 'y') {
			y1 *= a;
			y2 *= a;
		}
		else if (axis == 'z') {
			z1 *= a;
			z2 *= a;
		}
		break;

	case Type::sqr:
		if (axis == 'x') {
			x1 *= a;
			x2 *= a;
			x3 *= a;
			x4 *= a;
		}
		else if (axis == 'y') {
			y1 *= a;
			y2 *= a;
			y3 *= a;
			y4 *= a;
		}
		else if (axis == 'z') {
			z1 *= a;
			z2 *= a;
			z3 *= a;
			z4 *= a;
		}
		break;

	case Type::cube:
		if (axis == 'x') {
			x1 *= a;
			x2 *= a;
			x3 *= a;
			x4 *= a;
			x5 *= a;
			x6 *= a;
			x7 *= a;
			x8 *= a;
		}
		else if (axis == 'y') {
			y1 *= a;
			y2 *= a;
			y3 *= a;
			y4 *= a;
			y5 *= a;
			y6 *= a;
			y7 *= a;
			y8 *= a;
		}
		else if (axis == 'z') {
			z1 *= a;
			z2 *= a;
			z3 *= a;
			z4 *= a;
			z5 *= a;
			z6 *= a;
			z7 *= a;
			z8 *= a;
		}
		break;
	}
}

void Shape::scale(int s)
{
	switch (type)
	{
	case Type::line:
		x1 /= s; y1 /= s;
		x2 /= s; y2 /= s;
		break;
	case Type::sqr:
		x1 /= s; y1 /= s;
		x2 /= s; y2 /= s;
		x3 /= s; y3 /= s;
		x4 /= s; y4 /= s;
		break;
	case Type::cube:
		x1 /= s; y1 /= s; z1 /= s;
		x2 /= s; y2 /= s; z2 /= s;
		x3 /= s; y3 /= s; z3 /= s;
		x4 /= s; y4 /= s; z4 /= s;
		x5 /= s; y5 /= s; z5 /= s;
		x6 /= s; y6 /= s; z6 /= s;
		x7 /= s; y7 /= s; z7 /= s;
		x8 /= s; y8 /= s; z8 /= s;
		break;
	}
}


Line::Line() {
}

Line::Line(int _x1, int _y1, int _x2, int _y2) {
	x1 = _x1; y1 = _y1;
	x2 = _x2; y2 = _y2;
	type = line;

}

Square::Square(){
}

Square::Square(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4) {
	x1 = _x1; y1 = _y1;
	x2 = _x2; y2 = _y2;
	x3 = _x3; y3 = _y3;
	x4 = _x4; y4 = _y4;
	int side_a = abs(x1 - x2);
	int side_b = abs(y1 - y2);
	type = sqr;
	square = side_a * side_b;
}

Cube::Cube(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8)
{
	x1 = _x1; y1 = _y1; z1 = _z1;
	x2 = _x2; y2 = _y2; z2 = _z2;
	x3 = _x3; y3 = _y3; z3 = _z3;
	x4 = _x4; y4 = _y4; z4 = _z4;
	x5 = _x5; y5 = _y5; z5 = _z5;
	x6 = _x6; y6 = _y6; z6 = _z6;
	x7 = _x7; y7 = _y7; z7 = _z7;
	x8 = _x8; y8 = _y8; z8 = _z8;
	type = cube;

	int side_a = abs(x1 - x2);
	int side_b = abs(y1 - y2);
	int side_c = abs(z1 - z2);

	square = 6 * side_a * side_b;
	volume = side_a * side_b * side_c;
}

Circle::Circle() {
}

Circle::Circle(int _x1, int _y1, double R) {
	x1 = _x1; y1 = _y1;
	radius = R;
	type = circle;
	square = M_PI * R * R;
}

Cylinder::Cylinder(int _x1, int _y1, double R, double H)
{
	x1 = _x1; y1 = _y1;
	radius = R;
	height = H;
	type = cylinder;
	square = M_PI * R * R + 2 * R * height;
	volume = M_PI * R * R * height;
}