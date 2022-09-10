#include<iostream>
#include<cstring>
using namespace std;


class m_string
{
public:
	friend ostream& operator<<(ostream &os, const m_string & str);
	m_string(const char * str = nullptr)
	{
		cout << "构造函数调用" << endl;
		if (str == nullptr)
		{
			m_data = new char[1];
			*m_data = '\0';
		}
		else
		{
			m_data = new char[strlen(str) + 1];
			strcpy(m_data, str);
		}
	}
	m_string(const m_string &other)
	{
		cout << "拷贝构造调用" << endl;
		m_data = new char[strlen(other.m_data) + 1];
		strcpy(m_data, other.m_data);
	}
	~m_string()
	{
		cout << "析构函数调用" << endl;
		delete[] m_data;
	}
	m_string& operator=(const m_string &other)
	{
		cout << "赋值函数调用" << endl;
		if (this != &other)
		{
			delete [] m_data;
			m_data = new char[strlen(other.m_data) + 1];
			strcpy(m_data, other.m_data);
		}
		return *this;
	}
	int size()
	{
		return strlen(m_data);
	}

private:
	char* m_data;
};
ostream & operator<<(ostream &os,const m_string & str)
{
	char *cur = str.m_data;

	while (*cur != '\0')
	{
		os << *cur;
		cur++;
	}
	return os;
}

int main()
{
	m_string str;
	cout << "str = " << str << ",str.size() = " << str.size() << endl;

	m_string str_1("hello");
	cout << "str_1 = " << str_1 << ",str_1.size() = " << str_1.size() << endl;

	m_string str_2(str_1);
	cout << "str_2 = " << str_2 << ",str_2.size() = " << str_2.size() << endl;

	m_string str_3(str);

	cout << "str_3 = " << str_3 << ",str_3.size() = " << str_3.size() << endl;

	str_3 = str_1;
	cout << "str_3 = " << str_3 << ",str_3.size() = " << str_3.size() << endl;

	return 0;
}