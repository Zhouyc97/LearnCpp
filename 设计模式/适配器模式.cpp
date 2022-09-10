#include<iostream>
using namespace std;
/*
适配器模式将一个类的接口转换成客户希望的另外一个接口，使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。
它包括类适配器和对象适配器，本文针对的是对象适配器。
举个例子，在STL中就用到了适配器模式。
*/

//双端队列  
class Deque  
{  
public:  
    void push_back(int x) { cout<<"Deque push_back"<<endl; }  
    void push_front(int x) { cout<<"Deque push_front"<<endl; }  
    void pop_back() { cout<<"Deque pop_back"<<endl; }  
    void pop_front() { cout<<"Deque pop_front"<<endl; }  
};

//顺序容器  
class Sequence  
{  
public:  
    virtual void push(int x) = 0;  
    virtual void pop() = 0;  
}; 

//栈  
class Stack: public Sequence  
{  
public:  
    void push(int x) { deque.push_back(x); }  
    void pop() { deque.pop_back(); }  
private:  
    Deque deque; //双端队列  
};

//队列  
class Queue: public Sequence  
{  
public:  
    void push(int x) { deque.push_back(x); }  
    void pop() { deque.pop_front(); }  
private:  
    Deque deque; //双端队列  
};

int main()
{
    Sequence *s1 = new Stack();  
    Sequence *s2 = new Queue();  
    s1->push(1); s1->pop();  
    s2->push(1); s2->pop();  
    delete s1; delete s2;  
    return 0;
}