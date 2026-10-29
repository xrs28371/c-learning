#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
日期：2026-10-28
主题：顺序表独立编写练习（两题，无实现答案）
依据：今天的 test.h、test.c 和“顺序表专题.c”。

怎么练：
  1. 在 VS 中新建一个独立的空 C 项目，只添加本文件。
     本文件自带 main 和顺序表类型，不要与原项目的 main、test.c 一起编译。
  2. 用 5 分钟口述 arr、size、capacity 的含义，再关闭原源码。    arr 代表了动态顺序表的数组  size 代表了有效的数据   capacity代表了空间大小
  3. 第一题约 35~45 分钟，第二题约 25~35 分钟，可以分两次完成。
  4. 每个 TODO 先写两句自己的思路，再开始写 C 代码。
  5. 卡住 10 分钟再看原源码；看完关掉，重新独立写，不照着逐行抄。
  6. 一题完成并自行运行检查后，再写下一题。

特别说明：
  下面的 (void)参数名 只是避免空函数的“未使用参数”警告，写实现时可删除。
  目前函数都是空壳；直接运行只会显示说明，并不代表完成了题目。
  题目中的预期结果是你完成后的核对依据，没有提供实现或隐藏答案。
*/

typedef int SLDataType;

typedef struct Seqlist
{
    SLDataType* arr;
    int size;
    int capacity;
} SL;

void SLInit(SL* ps);
void SLCheckCapacity(SL* ps);
void SLPushBack(SL* ps, SLDataType x);
void SLDestroy(SL* ps);
void SLPrint(SL s);
void SLPushFront(SL* ps, SLDataType x);
void SLPopBack(SL* ps);
void SLPopFront(SL* ps);

/* ==================== 第一题 ====================
题目：不看原源码，独立写出一个可以扩容的动态顺序表。

需要完成：
  SLInit、SLCheckCapacity、SLPushBack、SLPrint、SLDestroy。
  然后在 main 中自己写出调用代码。

要求：
  1. 初始化为空表：arr 为 NULL，size 和 capacity 都是 0。
  2. 尾插前检查空间：第一次需要空间时容量为 4，以后满了就扩大为原来的 2 倍。
  3. realloc 使用临时指针，失败时按你学过的方式报错并终止。
  4. 实际申请的空间与 capacity 记录的元素容量一致。
     注意：容量是“几个元素”，不是“几个字节”。
  5. 插入后 size 正确更新；打印只能读取有效元素。
  6. 销毁时释放申请的内存，再把三个成员恢复为空表状态。
  7. 对需要结构体指针的函数，检查指针有效。
     指针非空、arr 非空、capacity 大于 0 是三个不同的条件。

自己写调用并检查：
  A. 初始化：size=0，capacity=0，arr=NULL。
  B. 连续尾插 1、2、3、4：输出 1 2 3 4；size=4，capacity=4。
  C. 再尾插 5：输出 1 2 3 4 5；size=5，capacity=8。
  D. 继续尾插到 9：输出 1 2 3 4 5 6 7 8 9；size=9，capacity=16。
  E. 销毁：arr=NULL，size=0，capacity=0。

做完用自己的话解释：
  - SLInit 为什么接收 SL*，调用时为什么传 &s？
  - SLPrint 的 SL s 是几个参数？为什么它可以不接收结构体指针？
  - SLCheckCapacity 检查空间，与真正申请空间分别发生在哪一步？
*/

//1. 初始化为空表：arr 为 NULL，size 和 capacity 都是 0。
void SLInit(SL* ps)
{
    ps->arr = NULL;
    ps->size = ps->capacity = 0;
   
}
//是否为空 不为空怎么办
void SLCheckCapacity(SL* ps)
{
    assert(ps); //是否为空
    if (ps->size == ps->capacity)//数据大小和空间相等这时候就要去申请空间
    {
        //realloc 申请空间
        int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
        //三目操作符  两个选一个 如果capacity为0 就扩容到4 如果不为0就将capacity放大到两倍
        SLDataType* tmp = realloc(ps->arr, newcapacity * sizeof(SLDataType));
        // 创立一个临时指针去接收这个扩容 去扩容这个数组 扩容的大小为为两倍 但是要注意是扩容是根据字节来扩容的 这里是int类型 所以还要*int的大小

        //扩容也可能失败 
        if (tmp == NULL)
        {
            perror("realloc error");
            exit(1);//以1的退出码退出程序 正常是0 所以这里用非0
        }

        //扩容成功了呢
        ps->arr = tmp; //就将原来的数组扩容到两倍了
        ps->capacity = newcapacity;//同时将空间扩容到了两倍了
    }
}

//尾插
void SLPushBack(SL* ps, SLDataType x)
{
    //既然插入就要看是否需要扩容 上面可以直接拿过来
    SLCheckCapacity(ps);
    //插入数据为 x  size最后肯定要++  插入数据放在最后 
    ps->arr[ps->size] = x;//理解为将x这个数据放在了arr下标为size的地方 因为原来数组就放到size-1的地方 
    ps->size++;//后置++ 先使用了这个size进行尾插 用完再自增的 
}
//打印这个动态顺序表
void SLPrint(SL s)
{
    //循环去打印这个数组
    //是否需要判断为空？？
    for (int i = 0;i<s.size;i++)
    {
        printf("%d ", s.arr[i]);
    }
    printf("\n");//可有可无
   
}

//销毁顺序表
void SLDestroy(SL* ps)
{
    if (ps->arr)
    {
        free(ps->arr);
    }
    ps->arr = NULL;
    ps->size = ps->capacity = 0;

}

/* ==================== 第二题 ====================
题目：复用第一题的顺序表，独立实现头插、尾删和头删。

需要完成：SLPushFront、SLPopBack、SLPopFront。

要求：
  1. 头插允许空表，也必须考虑空间满了的情况。
  2. 挪动数据之前，自己在纸上画出原下标和目标下标，再决定循环方向。
  3. 每次插入、删除后，size 必须反映真实的有效元素个数。
  4. 删除不能操作空表。按你已学过的方式，用断言表达非空表前提。
  5. 删除不要求缩小 capacity，也不要求把无效位置写成 -1。
     0、-1 都可以是合法数据，空不空应根据有效元素个数判断。

在 main 中另建一个空表，自己写调用：
  A. 尾插 10、20、30      -> 10 20 30；size=3，capacity=4。
  B. 头插 -1             -> -1 10 20 30；size=4，capacity=4。
  C. 再头插 0            -> 0 -1 10 20 30；size=5，capacity=8。
  D. 尾删一次            -> 0 -1 10 20；size=4，capacity=8。
  E. 头删一次            -> -1 10 20；size=3，capacity=8。
  F. 再头删一次          -> 10 20；size=2，capacity=8。
  G. 连续尾删两次        -> 空表；size=0，capacity=8。
  H. 最后销毁            -> arr=NULL，size=0，capacity=0。

边界检查：
  - 空表头插一个数后，再头删，应回到空表。
  - 只有一个数时，头删或尾删，都应正确回到空表。
  - 如果要检查空表删除的断言，请在 VS 的 Debug 配置下单独运行这一情况；
    断言终止属于这个前提检查的预期结果，不要放在正常流程中反复触发。

完成后先给我看第一题，我会先指出最需要改的一两处，不直接给整份答案。
*/

//头插
void SLPushFront(SL* ps, SLDataType x)
{
    SLCheckCapacity(ps);
    for(int i=ps->size;i>0;i--)
    {
        ps->arr[i] = ps->arr[i - 1];
    }
    ps->arr[0] = x;
    ps->size++;
}


//尾删
void SLPopBack(SL* ps)
{
    assert(ps);
    assert(ps->size);
    ps->arr[ps->size - 1] = -1;
    ps->size--;
    
}


//头删
void SLPopFront(SL* ps)
{
    assert(ps);
    assert(ps->size);
    for (int i = 0; i < ps->size-1;i++)
    {
        ps->arr[i] = ps->arr[i + 1];
    }
    ps->size--;
}
    
    

int main()
{
    SL s1;
    SLInit(&s1);
    SLPushBack(&s1, 10);
    SLPushBack(&s1, 20);
    SLPushBack(&s1, 30);
    SLPushFront(&s1, -1);
    SLPushFront(&s1, 0);
    SLPrint(s1);
   
    SLPopBack(&s1);
    SLPrint(s1);
    
    SLPopFront(&s1);
    SLPrint(s1);
   
    SLPopBack(&s1);
    SLPopBack(&s1);
    SLPrint(s1);

    SLDestroy(&s1);






    return 0;
}
