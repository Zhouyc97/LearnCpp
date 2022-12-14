#include<iostream>
using namespace std;
void swap_1(int &x, int &y)
{
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

void swap_2(int &x, int &y)
{
    x = x + y;
    y = x - y;
    x = x - y;
}

int main()
{
    int x = 5, y = 88;
    cout<<"x = "<<x<<" "<<"y = "<<y<<endl;

    swap_1(x,y);
    cout<<"x = "<<x<<" "<<"y = "<<y<<endl;

    swap_2(x,y);
    cout<<"x = "<<x<<" "<<"y = "<<y<<endl;
    
    return 0;
}