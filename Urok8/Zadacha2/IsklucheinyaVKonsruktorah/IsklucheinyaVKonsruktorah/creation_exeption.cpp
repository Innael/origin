#include <iostream>
#include "creation_exeption.h"

const char* creation_exceptions::what() const { return "������ �������� ������\n\n"; };

const char* summa_ugl_tr_er::what() const { return "������ �������� ������. �������: ����� �����, �� ����� 180\n\n"; };

const char* ugl_pr_tr_not90_er::what() const { return "������ �������� ������. �������: ���� � �� ����� 90\n\n"; };

const char* tr_neravenstvo_storon_er::what() const { return "������ �������� ������. �������: ������� �, �� ����� ������� � \n\n"; };

const char* tr_neravenstvo_uglov_er::what() const { return "������ �������� ������. �������: ���� �, �� ����� ���� � \n\n"; };

const char* rvnst_tr_neravenstvo_storon_er::what() const { return "������ �������� ������. �������: ������� �� ����� \n\n"; };

const char* rvnst_tr_neravenstvo_uglov_er::what() const { return "������ �������� ������. �������: ���� �� ����� \n\n"; };

const char* summa_ugl_chtr_er::what() const { return "������ �������� ������. �������: ����� �����, �� ����� 360\n\n"; };

const char* chtr_neravenstvo_storon_er::what() const { return "������ �������� ������. �������: ������� b, �� ����� ������� d \n\n"; };

const char* ugl_prmg_not90_er::what() const { return "������ �������� ������. �������: ���� �� �����, �� ����� 90\n\n"; };

const char* quadr_neravenstvo_storon_er::what() const { return "������ �������� ������. �������: ������� �� ����� \n\n"; };

const char* prlgrm_neravenstvo_uglov_er::what() const { return "������ �������� ������. �������: ���� B, �� ����� ���� D \n\n"; };