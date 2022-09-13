#include<bits/stdc++.h>
using namespace std;
struct node 
{
    int _freq;
    int _key;
	int _val;
	node(int freq, int key, int val):_freq(freq),_key(key),_val(val) { }
};

class Solution {
public:
    Solution(int k):_size(k),_min_freq(0){}

	void set(int key, int value)
	{
		if (mp.find(key) != mp.end())
		{
			mp[key]->_val = value;
			update(key);
		}
		else
		{
            //可用空间为0
			if (_size == 0)
			{
                //需要删除fre最少的key,若相同fre有多个 删除最早使用的那个
				int oldkey = freq_mp[_min_freq].back()->_key;
				freq_mp[_min_freq].pop_back();

				if (freq_mp[_min_freq].empty())
				{
					freq_mp.erase(_min_freq);
				}
				mp.erase(oldkey);
			}
			else
				_size--;
			//最小频率置为1
			_min_freq = 1;
			//在频率为1的双向链表表头插入该键
			node *temp = new node(1, key, value);
            //map和freq_mp一定要使用同一个节点
			freq_mp[1].push_front(temp);
			mp[key] = temp;
		}

	}

	int get(int key)
	{
		if (mp.find(key) == mp.end())
			return -1;
		update(key);
		return mp[key]->_val;
	}

private:
    void update(int key)
	{
		node * temp = mp[key];
		int fre = temp->_freq;

        //移除fre频率的节点
		freq_mp[fre].remove(temp);

        //移除频次fre的空链表
		if (freq_mp[fre].empty())
		{
			freq_mp.erase(fre);
			if (_min_freq == fre)
				_min_freq++;
		}

        //map和freq_mp一定要使用同一个节点
		temp->_freq++;
		freq_mp[temp->_freq].push_front(temp);
	}

	unordered_map<int, list<node*>> freq_mp;
	unordered_map<int, node*> mp;
	int _size; //可用空间
	int _min_freq;
};

int main()
{
    Solution s(3);
    s.set(1,1);
    s.set(2,2);
    s.set(3,2);
    s.set(2,4);
    s.set(3,5);
    cout<<s.get(2)<<endl;
    s.set(4,4);
    cout<<s.get(1)<<endl;
    s.get(4);
    s.get(4);
    s.get(3);
    s.set(5,5);
    cout<<s.get(2)<<endl;
    cout<<s.get(3)<<endl;
    cout<<s.get(4)<<endl;
    cout<<s.get(5)<<endl;


    return 0;
}