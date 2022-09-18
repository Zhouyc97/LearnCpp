#include<bits/stdc++.h>
using namespace std;

int gcd(int x,int y)
{
    int z = x % y;
    while(z)
    {
        x = y;
        y = z;
        z = x % y;
    }
    return y;
}
int main()
{
    cout<<gcd(36,27)<<endl;
    cout<<gcd(36,18)<<endl;
    cout<<gcd(36,15)<<endl;
    cout<<gcd(36,6)<<endl;
    return 0;
}