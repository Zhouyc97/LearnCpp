#include<iostream>
#include<cstring>
using namespace std;
class A
{
public:
	A()
	{
		_ptr = new int(10);
		cout << "构造函数,_ptr = " << _ptr << endl;
	}
	~A()
	{
		delete _ptr;
		cout << "析构函数" << endl;
	}
	A(const A& a)
	{
		_ptr = new int;
		memcpy(_ptr, a._ptr, sizeof(int));
		cout << "拷贝构造,_ptr = " <<_ptr<< endl;
	}
	//右值引用
	A(A &&a)
	{
		_ptr = a._ptr;
		a._ptr = nullptr;
		cout << "移动构造,_ptr = " << _ptr << endl;
	}
	A& operator=(const A& a)
	{
		if (this == &a)
			return *this;

		cout<<"释放内存,_ptr = " << _ptr << endl;
		delete _ptr;

		_ptr = new int;
		memcpy(_ptr, a._ptr, sizeof(int));
		cout << "赋值运算符,_ptr = " << _ptr << endl;
	}


	int *_ptr;
};
void func(int &n)
{
	cout << "leftValue = " << n << endl;
}
void func(int &&n)
{
	cout << "rightValue = " << n << endl;
}
template<class T>
void revoke(T &&t)
{
	//T &&为万能引用,可以传入左值、左值引用、右值、右值引用
	//但是t无论是哪种引用,t都是左值,因此 func(t)都去调用第一个左值函数
	//funt(t);

	// 左右值引用都是左值，forward将引用去掉 保证获得左值 或者右值再去调用相应的函数
	func(forward<T>(t));
}

void test()
{
	A a;
	//右值引用主要用于移动语义 和 完美转发
	//移动语义,直接将资源移动到另外一个对象，避免资源重新分配
	//通过触发移动构造
	A b(move(a));
	cout << "a._ptr = " << a._ptr << endl;
	cout << "b._ptr = " << b._ptr << endl;

	//完美转发主要用于函数模板,将自己参数完美地转发给内部调用的其他函数
	//完美转发需要转发参数的值 还有参数的左右值属性
	int num = 10;
	int &m = num;
	int &&n = 151;
	revoke(num);
	revoke(15);
	revoke(m);
	//不强转 n也是左值
	revoke((int &&)n);
}
int main()
{
	test();

	return 0;
}