#ifndef EQUIPMENT_LIBRARY_H
#define EQUIPMENT_LIBRARY_H

#include "seqlist.h"

/* 整行读取整数：1 成功，0 输入无效，-1 输入结束或读取失败。 */
int EquipmentReadInt(const char* prompt, int* value);

/* 沿用已有函数名和参数；交互函数会通过键盘读取编号、数量。 */
void EquipmentAdd(B* ps);
void EquipmentDelete(B* ps, int x);
void EqiupmentRevise(B* ps, int x);
int EquipmentFind(B* ps, int id);
void EquipmentSearch(B* ps);
void EqiupmentShow(B* ps);
void EqiupmentBorrowed(B* ps, int id, int x);
void EquipmentReturn(B* ps, int id, int x);
void EquipmentStatistics(B* ps);
void EquipmentExit(B* ps, int x);

#endif
