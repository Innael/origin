#pragma once
#include"Shape.h"
class transform              // избыточный класс, с неуместной близостью, и завистливыми функциями
{
public:
	transform(const Shape& sh);
	Shape shift(int m, int n, int k);
	Shape scaleAxis(char axis, int a);	
	Shape scale(int s);

private:
	Shape shape;
};