#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{
	vector<int> vec{ 0,2,2,3,4,5,6};
	map<int, int> map{ {0,0},{1,1},{2,2},{3,3},{4,4} };
	//vector用迭代器删除
	for (auto it = vec.begin(); it != vec.end();)
	{
		if ((*it) % 2 == 0)
			it = vec.erase(it);
		else
			it++;
	}


	//map用迭代器删除
	for (auto iter = map.begin(); iter != map.end();)
	{
		if ((*iter).first % 2 == 0)
			map.erase(iter++);
		else
			iter++;
	}
	for (auto a : map)
		cout << a.first << " " << a.second << " ";
	cout << endl;

	return 0;
}