#include<bits/stdc++.h>
using namespace std;

class heap
{
public:
	heap(){}
	heap(const vector<int> &src)
	{
		for (int ele : src)
		{
			vec.push_back(ele);
		}
		int len = vec.size();
		for (int i = len / 2 - 1; i >= 0; i--)
		{
			adjust(vec, i, len - 1);
		}
	}
	~heap() {}
	int size() { return vec.size(); }
	void push(int value)
	{
		vec.push_back(value);
		int len = vec.size();
		for (int i = len / 2 - 1; i >= 0; i--)
		{
			adjust(vec, i, len - 1);
		}
	}
	int top()
	{
		if (!vec.empty())
			return vec[0];
		else
			cout << "empty!" << endl;
		return INT_MIN;
	}
	void pop()
	{
		if (!vec.empty())
		{
			swap(vec[0], vec[vec.size() - 1]);
			vec.pop_back();
			int len = vec.size();
			for (int i = len / 2 - 1; i >= 0; i--)
			{
				adjust(vec, i, len - 1);
			}
		}
		else
			cout << "empty!" << endl;
	}
private:
	void adjust(vector<int>& vec, int i, int last_index)
	{
		int temp = vec[i];
		int j = 2 * i + 1;
		for (; j <= last_index; j++)
		{
			if (j + 1 <= last_index && vec[j] < vec[j + 1])
			{
				j++;
			}
			if (vec[j] <= temp)
				break;
			vec[i] = vec[j];
			i = j;
			j = 2 * i;
		}
		vec[i] = temp;
	}
	vector<int> vec;
};


int main()
{	
	heap h1(vector<int>{1, 7, 5, 8});
	cout << h1.top() << endl;
	cout << h1.size() << endl;
	h1.push(88);
	cout << h1.top() << endl;
	cout << h1.size() << endl;
	h1.pop();
	cout << h1.top() << endl;
	cout << h1.size() << endl;
	h1.pop();
	cout << h1.top() << endl;
	cout << h1.size() << endl;
	h1.push(-100);
	cout << h1.top() << endl;
	cout << h1.size() << endl;
	cout << endl;

	return 0;
}