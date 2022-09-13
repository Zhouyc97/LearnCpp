#include<iostream>

using namespace std;
//node内部默认是m个字节对齐 ,若指定#pragma pack(n) 则结构体按照min(m,n)对齐。n一般是1、2、4、8等。最后sizeof大小一定是每个成员大小的整数倍
//#pragma pack()取消对齐方式
#pragma pack(2) 
struct node
{
	int c;
	char b;
};

#pragma pack() 
struct node1
{
	int c;
	char b;
	int a;
};


int main()
{
	cout << sizeof(node) << endl;
	cout << sizeof(node1) << endl;
	return 0;
}