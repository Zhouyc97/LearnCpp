#include<iostream>
using namespace std;
/*
构造函数是私有的，因此无法通过构造函数实例化，
唯一的方法就是通过调用静态函数GetInstance
*/
pthread_mutex_t lock;
class single
{
public:
	static single* get_instance()
	{
		if (ptr == nullptr)
		{
			pthread_mutex_lock(&lock);
			if (ptr == nullptr)
			{
				ptr = new single();
			}
			pthread_mutex_unlock(&lock);
		}
		return ptr;
	}
private:
	single(){}
	static single* ptr;
};
single* single::ptr = nullptr;


class single_1
{
public:
	static single_1* get_instance()
	{
		return ptr;
	}

private:
	single_1() {}

	static single_1* ptr;
};
single_1* single_1::ptr = new single_1();

class single_2
{
public:
	static single_2* get_instance()
	{
		static single_2 obj;
		return &obj;
	}
private:
	single_2() = default;
};

void test()
{
    cout<<"双检查锁: "<<endl;
    pthread_mutex_init(&lock,NULL);
	cout << single::get_instance() << endl;
	cout << single::get_instance() << endl;
    pthread_mutex_destroy(&lock);

    cout<<"饿汉模式: "<<endl;
	cout << single_1::get_instance() << endl;
	cout << single_1::get_instance() << endl;

    cout<<"局部静态: "<<endl;
	cout << single_2::get_instance() << endl;
	cout << single_2::get_instance() << endl;

}
int main()
{
    test();
	return 0;
}