#include <iostream>
#include "Broom.h"

Broom::Broom() {
	name = "�����";
	speed = 20.0;
	cruise = 0.0;
}

double Broom::time_count(int trassa) {
	double hours = 0, track = 0, crs = cruise;
	for (int i = 0; i < 2;) {
		for (double j = 0; j < (10 * (100 - crs)) / speed ; ++j) {
			if ((static_cast<double>(trassa) - track) < speed) {
				if (static_cast<double>(trassa) < track) {
					hours += (static_cast<double>(trassa) - track) / speed;
					track += speed;
				}
				else i = 2; break;
			}
			else {
				track += speed;
				++hours;
			}
			if (track >= trassa) {
				i = 2; break;
			}
		}		
		if (i == 2) break;		
		crs += 1.0;
		trassa -= 10 * crs;
		if (trassa <= 0) break; // ���� ���������� ��������� > 100000 - ������ �� ���������� �� ������� ������ ����������, ���������� ���������. �� ������, ����������� ������ ���, ��� ����� ����� ��������, ����� ������ ��������������� � ������
	}
	return hours;
}
