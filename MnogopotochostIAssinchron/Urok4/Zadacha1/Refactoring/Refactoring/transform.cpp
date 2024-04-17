#include "transform.h"

transform::transform(const Shape& sh)
{
	shape = sh;
}

Shape transform::shift(int m, int n, int k)                 
{
	switch (shape.getType())
	{
	case Type::line:
		shape.x1 += m; shape.y1 += n;
		shape.x2 += m; shape.y2 += n;
		break;
	case Type::sqr:
		shape.x1 += m; shape.y1 += n;
		shape.x2 += m; shape.y2 += n;
		shape.x3 += m; shape.y3 += n;
		shape.x4 += m; shape.y4 += n;
		break;
	case Type::cube:
		shape.x1 += m; shape.y1 += n; shape.z1 += k;
		shape.x2 += m; shape.y2 += n; shape.z2 += k;
		shape.x3 += m; shape.y3 += n; shape.z3 += k;
		shape.x4 += m; shape.y4 += n; shape.z4 += k;
		shape.x5 += m; shape.y5 += n; shape.z5 += k;
		shape.x6 += m; shape.y6 += n; shape.z6 += k;
		shape.x7 += m; shape.y7 += n; shape.z7 += k;
		shape.x8 += m; shape.y8 += n; shape.z8 += k;
		break;
	}
	return shape;
}

Shape transform::scaleAxis(char axis, int a)
{
	switch (shape.getType())
	{
	case Type::line:
		if (axis == 'x') {
			shape.x1 *= a;
			shape.x2 *= a;
		}
		else if (axis == 'y') {
			shape.y1 *= a;
			shape.y2 *= a;
		}
		else if (axis == 'z') {
			shape.z1 *= a;
			shape.z2 *= a;
		}
		break;

	case Type::sqr:
		if (axis == 'x') {
			shape.x1 *= a;
			shape.x2 *= a;
			shape.x3 *= a;
			shape.x4 *= a;			
		}
		else if (axis == 'y') {
			shape.y1 *= a;
			shape.y2 *= a;
			shape.y3 *= a;
			shape.y4 *= a;
		}
		else if (axis == 'z') {
			shape.z1 *= a;
			shape.z2 *= a;
			shape.z3 *= a;
			shape.z4 *= a;
		}
		break;

	case Type::cube:
		if (axis == 'x') {
		shape.x1 *= a;
		shape.x2 *= a;
		shape.x3 *= a;
		shape.x4 *= a;
		shape.x5 *= a;
		shape.x6 *= a;
		shape.x7 *= a;
		shape.x8 *= a;
	}
	else if (axis == 'y') {
			shape.y1 *= a;
			shape.y2 *= a;
			shape.y3 *= a;
			shape.y4 *= a;
			shape.y5 *= a;
			shape.y6 *= a;
			shape.y7 *= a;
			shape.y8 *= a;
		}
	else if (axis == 'z') {
			shape.z1 *= a;
			shape.z2 *= a;
			shape.z3 *= a;
			shape.z4 *= a;
			shape.z5 *= a;
			shape.z6 *= a;
			shape.z7 *= a;
			shape.z8 *= a;
		}
		break;
	}
	return shape;
}

Shape transform::scale(int s)
{
	switch (shape.getType())
	{
	case Type::line:
		shape.x1 /= s; shape.y1 /= s;
		shape.x2 /= s; shape.y2 /= s;
		break;
	case Type::sqr:
		shape.x1 /= s; shape.y1 /= s;
		shape.x2 /= s; shape.y2 /= s;
		shape.x3 /= s; shape.y3 /= s;
		shape.x4 /= s; shape.y4 /= s;
		break;
	case Type::cube:
		shape.x1 /= s; shape.y1 /= s; shape.z1 /= s;
		shape.x2 /= s; shape.y2 /= s; shape.z2 /= s;
		shape.x3 /= s; shape.y3 /= s; shape.z3 /= s;
		shape.x4 /= s; shape.y4 /= s; shape.z4 /= s;
		shape.x5 /= s; shape.y5 /= s; shape.z5 /= s;
		shape.x6 /= s; shape.y6 /= s; shape.z6 /= s;
		shape.x7 /= s; shape.y7 /= s; shape.z7 /= s;
		shape.x8 /= s; shape.y8 /= s; shape.z8 /= s;
		break;
	}

	return shape;
}