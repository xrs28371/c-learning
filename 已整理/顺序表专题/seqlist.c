#include "seqlist.h"

#include <stdint.h>
#include <stdio.h>

/* 保留原来的插入、移动、删除算法；Bcheck 负责扩容前的安全检查。 */

//初始化
void Binit(B* ps)
{
    assert(ps);
    ps->arr = NULL;
    ps->size = 0;
    ps->capacity = 0;
}

//销毁
void Bdestory(B* ps)
{
    assert(ps);
    if (ps->arr)
    {
        free(ps->arr);
    }
    ps->arr = NULL;
    ps->size = ps->capacity = 0;
}

//检查和扩容
void Bcheck(B* ps)
{
    //先判断是否为空
    assert(ps);
    assert(ps->size >= 0 && ps->size <= ps->capacity);
    assert(ps->capacity == 0 ? ps->arr == NULL : ps->arr != NULL);
    if (ps->size == ps->capacity)
    {
        //进行扩容
        //先对空间进行判断是否为0  
        // 定义一个数据去接受这个 空间
        //增容   给B增容

        /* 先检查再乘二，避免 int 溢出。 */
        if (ps->capacity > INT_MAX / 2)
        {
            fputs("顺序表容量过大，无法继续扩容。\n", stderr);
            exit(EXIT_FAILURE);
        }
        int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
        if ((size_t)newcapacity > SIZE_MAX / sizeof(Equipment))
        {
            fputs("申请内存的字节数过大。\n", stderr);
            exit(EXIT_FAILURE);
        }
        Equipment* tmp = (Equipment*)realloc(ps->arr, newcapacity * sizeof(Equipment));
        if (tmp == NULL)
        {
            perror(" realloc error");
            exit(1);
        }
        ps->arr = tmp;
        ps->capacity = newcapacity;


    }
}
//头插
void BFrontback(B* ps, Equipment x)
{
    //第一步还是检查空间
    Bcheck(ps);
    // 先让整体向后移动 我们再插入
    // for 循环
    for (int i = ps->size - 1;i >= 0;i--)
    {
        ps->arr[i + 1] = ps->arr[i];
    }
    ps->arr[0] = x;
    ps->size++;

}

//尾插
void BPushback(B* ps, Equipment x)
{
    //  第一步 检查空间 是否够
    Bcheck(ps);

    //第二步 让最后一位数字等于插入的数据 
    ps->arr[ps->size] = x;
    ps->size++;

}

//头删
void BPopFront(B* ps)
{
    assert(ps);
    assert(ps->size > 0);
    for (int i = 0;i <= ps->size - 2;i++)
    {
        ps->arr[i] = ps->arr[i + 1];

    }
    ps->size--;
}

//尾删
void BPopBack(B* ps)
{
    assert(ps);
    assert(ps->size > 0);
    ps->size--;
}


//指定位置删除
void BErase(B* ps, int x)
{
    assert(ps);
    assert(x >= 0 && x < ps->size);
    for (int i = x;i < ps->size - 1;i++)
    {
        ps->arr[i] = ps->arr[i + 1];
    }
    ps->size--;
}

//指定位置插入
void BInsert(B* ps, int x, Equipment y)
{
    assert(ps);
    assert(x >= 0 && x <= ps->size);
    Bcheck(ps);
    for (int i = ps->size;i > x;i--)
    {
        ps->arr[i] = ps->arr[i - 1];

    }
    ps->arr[x] = y;
    ps->size++;

}
