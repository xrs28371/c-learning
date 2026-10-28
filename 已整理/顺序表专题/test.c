#include"test.h"



void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;

}




//顺序表的销毁
void SLDestory(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}



void SLCheckCapacity(SL*ps)//检查空间
{
	assert(ps);
	//先判断插入数据前看空间够不够
	if (ps->capacity == ps->size)
	{
		//申请空间
		//判断capacity 是否为0
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newcapacity * 2 * sizeof(SLDataType));//申请多大的空间？ 一次增容多大呢
		if (tmp == NULL)
		{
			perror("realloc error");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newcapacity;
		//通常是成倍数增加 一般2倍 
	}
}



//尾插
void SLPushBack(SL* ps, SLDataType x)
{
	SLCheckCapacity(ps);
	ps->arr[ps->size] = x;
	++ps->size;

}




//头插
void SLPushFront(SL* ps, SLDataType x)
{
	SLCheckCapacity(ps);
	//让顺序表所有数据整体向后移动
	for (int i = ps->size;i > 0;i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	++ps->size;
}

//打印顺序表
void SLprint(SL s)
{
	for (int i = 0;i < s.size;i++)
	{
		printf("%d ", s.arr[i]);
	}
	printf("\n");
}


//尾删  size--
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size);
	//顺序表不能为空
	ps->arr[ps->size - 1] = -1;
	--ps->size;
}


//头删
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size);

	//数据整体向前挪动一位
	for (int i = 0;i < ps->size - 1;i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	--ps->size;
}