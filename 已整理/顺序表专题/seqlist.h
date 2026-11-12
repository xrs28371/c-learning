#ifndef EQUIPMENT_SEQLIST_H
#define EQUIPMENT_SEQLIST_H
#define NAME_MAX 40
#define CATEGRORY 20

#include <stdlib.h>
#include <assert.h>
#include <limits.h>

/* NAME_MAX 和 CATEGRORY 是数组容量，已经包含字符串结束符的位置。 */
/* 底层函数接收已经初始化的 B，插入范围 0..size，删除范围 0..size-1。 */


typedef struct a
{
    int id;
    char name[NAME_MAX];
    char category[CATEGRORY];
    int total;
    int borrowed;


}Equipment;// 一条完整的器材记录，arr[i] 就是这样的一个对象

typedef struct b {
    Equipment* arr;
    int size;
    int capacity;
}B;//  这里是动态顺序表  


void Binit(B* ps);
void Bdestory(B* ps);
void Bcheck(B* ps);
void BFrontback(B* ps, Equipment x);
void BPushback(B* ps, Equipment x);
void BPopFront(B* ps);
void BPopBack(B* ps);
void BErase(B* ps, int x);
void BInsert(B* ps, int x, Equipment y);


#endif
