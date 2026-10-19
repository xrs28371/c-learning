/*
class 类名
public
<公有数据和函数>
protected
<保护数据和函数>
private
<私有数据和函数>
*/
//定义点
#include<iostream>
using namespace std;
class Point
	//class 意思是告诉编译器 我要设计一个新的类型
	//Point  是这个新类型的名字
{
private:
	int x, y;
public:
	void set1(int a, int b)
	{
		x = a;
		y = b;
	}
	void show()//这是在类里面声明
	{
		//cout 是标准输出对象  可以将内容输出到控制台
		//<<是输出运算符  将右边的内容送进左边的输出流
		cout << "x=" << x << ",y=" << y << endl;
		//endl 的作用
		//换行
		//刷新输出缓冲区
		//如果将这个分开去写
		//cout<<"x=";
		//cout<<x;
		//cout<<",y=";
		//cout<<y;
		//cout<<endl;
		//之所以能连起来是因为cout能够将之前的操作返回 来让下一个<<使用

	}
};
//inline void Point::show()  这样去写是在类外面声明
//{
//        cout << "x=" << x << ",y=" << y << endl;
//}
int main()
{
	Point p1;
	p1 .set1(1, 1);//是pulic的方法
	//表达的效果如下
	//p1.x=1;
	//p1.y=1;
	p1.show();
}