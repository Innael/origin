#include <iostream>
#include "creation_exeption.h"

const char* creation_exceptions::what() const { return "Ошибка создания фигуры\n\n"; };

const char* summa_ugl_tr_er::what() const { return "Ошибка создания фигуры. Причина: сумма углов, не равна 180\n\n"; };

const char* ugl_pr_tr_not90_er::what() const { return "Ошибка создания фигуры. Причина: угол С не равен 90\n\n"; };

const char* tr_neravenstvo_storon_er::what() const { return "Ошибка создания фигуры. Причина: сторона а, не равна стороне с \n\n"; };

const char* tr_neravenstvo_uglov_er::what() const { return "Ошибка создания фигуры. Причина: угол А, не равен углу С \n\n"; };

const char* rvnst_tr_neravenstvo_storon_er::what() const { return "Ошибка создания фигуры. Причина: стороны не равны \n\n"; };

const char* rvnst_tr_neravenstvo_uglov_er::what() const { return "Ошибка создания фигуры. Причина: углы не равны \n\n"; };

const char* summa_ugl_chtr_er::what() const { return "Ошибка создания фигуры. Причина: сумма углов, не равна 360\n\n"; };

const char* chtr_neravenstvo_storon_er::what() const { return "Ошибка создания фигуры. Причина: сторона b, не равна стороне d \n\n"; };

const char* ugl_prmg_not90_er::what() const { return "Ошибка создания фигуры. Причина: один из углов, не равен 90\n\n"; };

const char* quadr_neravenstvo_storon_er::what() const { return "Ошибка создания фигуры. Причина: стороны не равны \n\n"; };

const char* prlgrm_neravenstvo_uglov_er::what() const { return "Ошибка создания фигуры. Причина: угол B, не равен углу D \n\n"; };