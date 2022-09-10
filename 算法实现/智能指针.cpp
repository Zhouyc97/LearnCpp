#include<iostream>
#include<vector>
#include<cassert>
#include<string>
using namespace std;

template<class T>
class smartPointer
{
public:
	smartPointer();
	smartPointer(T* src_ptr);
	smartPointer(const smartPointer<T> &src);
	smartPointer<T>& operator=(const smartPointer<T> &src);
	T& operator*();
	T* operator->();
	~smartPointer();
	int use_count();
private:
	T* _ptr;
	int* count;
};
template<class T>
smartPointer<T>::smartPointer() :_ptr(nullptr)
{
	count = new int(0);
}
template<class T>
smartPointer<T>::smartPointer(T* src_ptr):_ptr(src_ptr)
{
	count = new int(1);
}
template<class T>
smartPointer<T>::smartPointer(const smartPointer<T> &src)
{
	_ptr = src._ptr;
	count = src.count;
	(*count)++;
	cout << "拷贝构造" << endl;
}
template<class T>
smartPointer<T>& smartPointer<T>::operator=(const smartPointer<T> &src)
{
	if (_ptr == src._ptr)
		return *this;
	(*count)--;
	if ((*count) <= 0)
	{
		delete _ptr;
		delete count;
		cout << "=销毁对象" << endl;
	}
	_ptr = src._ptr;
	count = src.count;
	(*count)++;
	return *this;
}
template<class T>
T& smartPointer<T>::operator*()
{
	assert(_ptr != nullptr);
	return *_ptr;
}
template<class T>
T* smartPointer<T>::operator->()
{
	assert(_ptr != nullptr);
	return _ptr;
}
template<class T>
int smartPointer<T>::use_count()
{
	return *count;
}
template<class T>
smartPointer<T>::~smartPointer()
{
	cout << "count = " << *count << endl;
	(*count)--;
	if (*count <= 0)
	{
		delete _ptr;
		delete count;
		cout << "析构函数调用" << endl;
	}
}
class student
{
public:
	student(int id, string name) :_id(id), _name(name) {}
	int _id;
	string _name;
};
void test2()
{
	smartPointer<student> obj1(new student(1, "你好1"));
	smartPointer<student> obj2(new student(2, "你好2"));
	smartPointer<student> obj3(obj1);
	smartPointer<student> obj4(new student(4, "你好4"));
	obj3 = obj4;
	cout << obj1.use_count() << endl;
	cout << obj2.use_count() << endl;
	cout << obj3.use_count() << endl;
	cout << obj4.use_count() << endl;
}

template<class T>
class un_ptr
{
public:
	un_ptr() :_ptr(nullptr) {}
	un_ptr(T* src_ptr) :_ptr(src_ptr) {}
	//禁止拷贝构造
	un_ptr(const un_ptr<T> & p) = delete;
	//禁止=
	un_ptr& operator=(const un_ptr<T> & p) = delete;
	//移动构造
	un_ptr(un_ptr<T>&& p)
	{
		_ptr = p._ptr;
		p._ptr = nullptr;
	}
	//移动=重载
	un_ptr& operator=(un_ptr<T> && p)
	{
		_ptr = p._ptr;
		p._ptr = nullptr;
		return *this;
	}
	void show()
	{
		if (_ptr)
		{
			cout << "_ptr = " << _ptr << endl;
			cout << "value = " << *_ptr << endl;
		}
		else
			cout << "_ptr = nullptr" << endl;
	}
	~un_ptr()
	{
		delete _ptr;
	}

private:
	T * _ptr;
};
void test1()
{
	un_ptr<int> obj1(new int(1));
	un_ptr<int> obj2(new int(2));
	obj1.show();
	obj2.show();
	un_ptr<int> obj3;
	un_ptr<int> obj4(move(obj2));
	obj3 = move(obj1);
	obj1.show();
	obj2.show();
	obj3.show();
	obj4.show();
}
int main()
{
	test1();

	return 0;
}