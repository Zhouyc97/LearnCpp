#include<bits/stdc++.h>
using namespace std;

struct node
{
    int _key,_value;
    node *pre, *next;
    node(int key,int value):_key(key),_value(value),pre(nullptr),next(nullptr){}
};

class Solution
{
public:
    Solution(int capacity);
    ~Solution();
    void set(int key,int value);
    int get(int key);
    void showHead();
private:
    void moveHead(node* cur);
    void insert(int key,int value);
    void delTail();


    int _capacity;
    node* head, *tail;
    unordered_map<int,node*> mp;
};
Solution::Solution(int capacity)
{
    this->_capacity = capacity;
    head = new node(100,100);
    tail = new node(-100,-100);
    head->next = tail;
    tail->pre = head;
}
Solution::~Solution()
{
    delete head; head = nullptr;
    delete tail; tail = nullptr;
    for(auto& ele : mp)
    {
        delete ele.second;
        ele.second = nullptr;
    }
}
void Solution::set(int key,int value)
{
    if(mp.find(key) != mp.end())
    {
        mp[key]->_value = value;
        moveHead(mp[key]);
        return;
    }

    if(mp.size() == this->_capacity)
        delTail();

    insert(key,value);
}
int Solution::get(int key)
{
    if(mp.find(key) == mp.end())
        return -1;
    moveHead(mp[key]);
    return mp[key]->_value;
}
void Solution::moveHead(node* cur)
{
    if(cur->pre && cur->next)
    {
        cur->pre->next = cur->next;
        cur->next->pre = cur->pre;
    }

    cur->next = head->next;
    head->next = cur;

    cur->next->pre = cur;
    cur->pre = head;

}
void Solution::delTail()
{
    node* cur = tail->pre;
    cur->pre->next = tail;
    tail->pre = cur->pre;
    mp.erase(cur->_key);

    delete cur;
    cur = nullptr;
}

void Solution::insert(int key,int value)
{
    node* cur = new node(key,value);
    mp[key] = cur;
    moveHead(cur);
}

void Solution::showHead()
{
    if(head->next != tail)
    {
        cout<<head->next->_value<<endl;
    }
    else
        cout<<"LRU为空"<<endl;
}
int main()
{
    Solution s(2);
    s.showHead();
    s.set(1,1);
    s.set(2,2);
    cout<<s.get(1)<<endl;
    s.set(3,3);
    cout<<s.get(2)<<endl;
    s.set(4,4);
    cout<<s.get(1)<<endl;
    cout<<s.get(3)<<endl;
    cout<<s.get(4)<<endl;
    s.showHead();
    return 0;
}