#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    Person(int a_,int b_){
        a = a_;
        b = b_;
    }
    ~Person(){}
    
    int a;
    int b;
};

class PersonHash
{
public:
    int operator()(const Person& p) const
    {
        return hash<int>()(p.a) ^ hash<int>()(p.b);
    }
};

class PersonEqual
{
public:
    bool operator()(const Person& p1,const Person& p2) const
    {
        return (p1.a == p2.a) && (p1.b == p2.b);
    }
};

class PersonGreater
{
public:
    bool operator()(const Person& p1,const Person& p2) const
    {
        if(p1.a == p2.a)
            return p1.b < p2.b;
        else
            return p1.a < p2.a;
    }
};

int main() 
{
    
    map<Person,int,PersonGreater> mp;
    Person p1(1,1);
    Person p2(2,2);
    mp.insert({p1,5});
    mp.insert({p2,8});

    cout<<mp[p1]<<endl;
    cout<<mp[p2]<<endl;

    unordered_map<Person,int,PersonHash,PersonEqual> mp2 = {{p1,3},{p2,4}};
    cout<<mp2[p1]<<endl;
    cout<<mp2[p2]<<endl;


    return 0;
}