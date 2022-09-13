#include<bits/stdc++.h>
#include<arpa/inet.h>
using namespace std;

int func(int num)
{
    char *p = (char *)&num;
    int num1 = 0x000000ff & num;
    int num2 = *p;
    if(num1 == num2)
    {
        cout<<"小端"<<endl;
        num1 = (0xff000000 & num) >> 24;
        num2 = (0x00ff0000 & num) >> 16;
        int num3 = (0x0000ff00 & num) >> 8;
        int num4 = (0x000000ff & num) >> 0;

        num = (num4 << 24) | (num3 << 16) | (num2 << 8) | num1;
        return num;
    }
    else
    {
        cout<<"大端"<<endl;
        return num;
    }
    
}

int main()
{
    cout<<"自定义实现:"<<endl;
    int num1 = 0x12345678;
    int num2 = func(num1);
    printf("%x\n%x\n",num1,num2);

    cout<<"调用库函数实现:"<<endl;
    int num3 = 0x12345678;
    int num4 = htonl(num3);
    printf("%x\n%x\n",num3,num4);
    return 0;
}
