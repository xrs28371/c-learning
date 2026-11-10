
#define EQUIPMENT_SEQLIST_H
#define NAME_MAX 39
#define CATEGRORY 19

#include <stdlib.h>
#include <assert.h>
#include <limits.h>

/* TODO：自己定义器材结构体与动态顺序表结构体。 */
/* TODO：自行声明初始化、销毁、检查扩容、指定位置插入与删除接口。 */
/* 先写清每个参数、返回值及调用前提，再实现。 */


typedef struct a
{
    int id;
    char name[NAME_MAX];
    char category[CATEGRORY];
    int total;
    int borrowed;


}Equipment;// 这里是静态顺序表 存放每个器材 的结构体

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

