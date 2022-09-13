#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
typedef void(*Fun_ptr)(vector<int>&);
//打印排序结果
void print(Fun_ptr fun,vector<int> vec)
{
	//cout << "排序前：";
	//for (int ele : vec)
	//{
	//	cout << ele << " ";
	//}
	//cout << endl;
	fun(vec);
	for (int ele : vec)
	{
		cout << ele << " ";
	}
	cout << endl;
}

//冒泡排序
void BubbleSort(vector<int>& vec)
{
	cout << "冒泡排：";
	bool flag = true;
	for (int i = 0; i < vec.size() && flag; i++)
	{
		flag = false;
		for (int j = vec.size()-2; j >= i ; j--)
		{
			if (vec[j] > vec[j+1])
			{
				swap(vec[j+1], vec[j]);
				flag = true;
			}
		}
	}
}

//选择排序
void Selection_sort(vector<int>& vec)
{
	cout << "选择排：";
	for (int i = 0; i < vec.size(); i++)
	{
		int min = i;
		for (int j = i + 1; j < vec.size(); j++)
		{
			if (vec[j] < vec[min])
				min = j;
		}
		swap(vec[min], vec[i]);
	}
}

//插入排序
void Insertion_sort(vector<int>& vec)
{
	cout << "插入排：";
	for (int i = 1; i < vec.size(); i++)
	{
		for (int j = i; j >= 1; j--)
		{
			if (vec[j - 1] > vec[j])
				swap(vec[j - 1], vec[j]);
		}
	}
}

//归并排序
void merge(vector<int>& vec, int front, int mid, int end)
{
	//合并vec[front,mid], vec[mid+1,end]二个有序序列
	int len = end - front + 1;
	vector<int> temp(len, 0);
	int left = front, right = mid + 1;
	int k = 0;
	while (left <= mid && right <= end)
	{
		if (vec[left] < vec[right])
			temp[k++] = vec[left++];
		else
			temp[k++] = vec[right++];
	}
	while(left <= mid)
		temp[k++] = vec[left++];
	while(right <= end)
		temp[k++] = vec[right++];
	k = 0;
	for (int i = front; i <= end; i++)
	{
		vec[i] = temp[k++];
	}
}
void merge_sort(vector<int>& vec,int front,int end)
{
	if (front >= end)
		return;
	int mid = front + (end - front) / 2;
	merge_sort(vec, front, mid);
	merge_sort(vec, mid + 1, end);
	merge(vec, front, mid, end);
}
void Merge_sort(vector<int>& vec)
{
	cout << "归并排：";
	int front = 0, end = vec.size() - 1;
	merge_sort(vec, front, end);
}

//堆排序
void heap_adjust(vector<int>& vec, int start, int end)
{
	// 以start当做根节点，调整其和其子树为最大堆,数组最后下标为end
	int parent = start;
	int child = 2 * parent + 1;
	while (child <= end)
	{
		if (child + 1 <= end && vec[child] < vec[child + 1])
			child++;
		if (vec[parent] >= vec[child])
			return;
		swap(vec[parent], vec[child]);
		parent = child;
		child = 2 * parent + 1;
	}
}
void Heap_sort(vector<int>& vec)
{
	cout << "堆排序：";
	//建堆
	int len = vec.size();
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		heap_adjust(vec, i, len - 1);
	}
	//排序最大的放后面
	for (int i = len - 1; i >= 1; i--)
	{
		swap(vec[0], vec[i]);
		heap_adjust(vec, 0, i - 1);
	}
}

//快排
int get_piovt(vector<int>& vec, int left, int right)
{
	int index = rand() % (right - left + 1) + left;

	swap(vec[index], vec[right]);
	int pviot = vec[right];
	int i = left, j = left;
	while (j <= right - 1)
	{
		if (vec[j] < pviot)
		{
			swap(vec[j], vec[i]);
			i++;
		}
		j++;
	}
	swap(vec[i], vec[right]);
	return i;
}
void quick_sort(vector<int>& vec, int left, int right)
{
	if (left >= right)
		return;
	int piovt = get_piovt(vec, left, right);
	quick_sort(vec, left, piovt - 1);
	quick_sort(vec, piovt + 1, right);
}
void Quick_sort(vector<int>& vec)
{
	cout << "快速排：";
	srand(unsigned(time(NULL)));
	int front = 0, end = vec.size() - 1;
	quick_sort(vec, front, end);
}
int main()
{
	vector<int> res{ 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
	//print(BubbleSort, res);
	//print(Selection_sort, res);
	//print(Insertion_sort, res);
	//print(Merge_sort, res);
	//print(Heap_sort, res);
	print(Quick_sort, res);

	return 0;
}