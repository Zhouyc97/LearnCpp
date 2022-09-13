#include<iostream>
#include<memory>
using  namespace std;

struct Node
{
	int _data;
	//弱引用解决智能指针循环引用的问题
	//shared_ptr<Node> _next;
	//shared_ptr<Node> _prev;
	weak_ptr<Node> _next;
	weak_ptr<Node> _prev;
	Node(int val):_data(val) {}
	~Node()
	{
		cout << "析构调用" << endl;
	}
};
void test()
{
	shared_ptr<Node> sp1(new Node(10));
	shared_ptr<Node> sp2(new Node(20));
	sp1->_next = sp2;
	sp2->_prev = sp1;
}
int main()
{
	test();

	return 0;
}