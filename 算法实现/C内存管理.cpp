#include<iostream>
#include<cassert>
#include<cstdio>
#include<cstring>
#include<climits>
using namespace std;

int my_atoi(const char* str) {
	//空指针
	assert(str);
	int flag = 1;//表示是正数
	//空字符串
	if (*str == '\0') {
		//发现这样返回无论怎样都不合适，所以我们设置一个变量
		//判断当前返回值是否有效，合法还是非法
		//使用枚举
		return 0;
	}
	//处理空白字符
	while (isspace(*str)) {
		//如果是空白字符，就跳过去了
		str++;
	}
	//正负号
	if (*str == '-') {
		flag = -flag;//有一个'-'变一次号
		str++;
	}
	//遍历串
	long long n = 0;
	while (*str) {
		if (isdigit(*str)) {
			n = n * 10 + (flag) * (*str - '0');
			if (n<INT_MIN || n>INT_MAX) {//说明越界了
				//但是，如果存到n里面去，是肯定不会越界的，因为会发生截断
				//所以，设置成long long是最好的
				n = 0;
				break;
			}
		}
		else {
			n = 0;
			break;
		}
		str++;
	}
	return (int)n;
}
size_t my_strlen(const char* str)
{
	int count = 0;
	while (*str++ != '\0')
	{
		count++;
	}
	return count;
}

void* my_memcpy(void* dest, const void* src, size_t num)
{
	void* ret = dest;

	assert(dest && src);
	for (int i = 0; i < num; i++)
	{
		*((char*)dest) = *((char*)src);

		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;//返回拷贝完的地址
}

void my_strcpy(char* dest, char* src)
//dest代表拷贝的目的地，src代表拷贝的来源
{
	while (*src != '\0')//同样的，循环走起来
	{
		*dest++ = *src++;//把来源拷贝到目的地去
	}
	*dest = *src;
}
void get_next(char* next , const char* s)
{
	next[0] = 0;
	int len = my_strlen(s);
	for (int i = 1, j = 0; i < len; i++)
	{
		while (j > 0 && s[i] != s[j])
		{
			j = next[j - 1];
		}
		if (s[i] == s[j]) j++;
		next[i] = j;
	}
}

int my_strstr(const char* str1, const char* str2)
{
	int len = my_strlen(str2);
	char* next = new char[len];
	memset(next, 0, len);
	cout << strlen(next) << endl;
	get_next(next, str2);
	cout << strlen(next) << endl;
	int size = strlen(str1);
	for (int i = 0, j = 0; i < size; i++)
	{
		while (j > 0 && str1[i] != str2[j])
		{
			j = next[j - 1];
		}

		if (str1[i] == str2[j]) j++;

		if (j == len)
		{
			return i - j + 1;
		}
	}
	return -1;
	delete[] next;
}
int main()
{
	char str[20] = "abadad";
	cout << my_atoi(str) << endl;
	cout << my_strlen(str) << endl;

	char dest_1[20];
	my_strcpy(dest_1, str);
	printf("%s\n", dest_1);
	cout << my_strlen(dest_1) << endl;

	char dest_2[20];
	my_memcpy(dest_2, str, sizeof(str));
	printf("%s\n", dest_2);
	cout << my_strlen(dest_2) << endl;

	const char* str_1 = "hello";
	const char* str_2 = "ll";
	cout << my_strstr(str_1, str_2) << endl;

	return 0;
}