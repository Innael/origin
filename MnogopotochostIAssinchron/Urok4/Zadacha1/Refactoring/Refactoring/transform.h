#pragma once
#include"Shape.h"
class transform              // ���������� �����, � ���������� ���������, � ������������ ���������
{
public:
	transform(const Shape& sh);
	Shape shift(int m, int n, int k);
	Shape scaleAxis(char axis, int a);	
	Shape scale(int s);

private:
	Shape shape;
};