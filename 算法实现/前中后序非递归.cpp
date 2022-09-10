#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct Treenode
{
	Treenode(int value) :val(value), left(nullptr), right(nullptr) {}
	int val;
	Treenode* left;
	Treenode* right;
};
void pre_recursion(Treenode* root)
{
	if (root == nullptr)
		return;
	cout << root->val << " ";
	pre_recursion(root->left);
	pre_recursion(root->right);
}
void pre_iteration(Treenode* root)
{
	stack<Treenode*> sta;
	Treenode* cur = root;
	while (cur || !sta.empty())
	{
		//当前节点存在
		if (cur)
		{
			sta.push(cur);
			cout << cur->val << " ";
			cur = cur->left;
		}
		//当前节点为空但是栈不为空
		else
		{
			Treenode* temp = sta.top();
			sta.pop();
			cur = temp->right;
		}
	}
}
void in_recursion(Treenode* root)
{
	if (root == nullptr)
		return;
	in_recursion(root->left);
	cout << root->val << " ";
	in_recursion(root->right);
}
void in_iteration(Treenode* root)
{
	stack<Treenode*> sta;
	Treenode* cur = root;
	while (cur || !sta.empty())
	{
		//当前节点存在
		if (cur)
		{
			sta.push(cur);
			cur = cur->left;
		}
		//当前节点为空但是栈不为空
		else
		{
			Treenode* temp = sta.top();
			cout << temp->val << " ";
			sta.pop();
			cur = temp->right;
		}
	}
}
void back_recursion(Treenode* root)
{
	if (root == nullptr)
		return;
	back_recursion(root->left);
	back_recursion(root->right);
	cout << root->val << " ";
}
void back_iteration(Treenode* root)
{
	stack<Treenode*> sta;
	Treenode* flag = nullptr;
	Treenode* cur = root;
	while (cur || !sta.empty())
	{
		//当前节点存在
		if (cur)
		{
			sta.push(cur);
			cur = cur->left;
		}
		//当前节点为空但是栈不为空
		else
		{
			Treenode* temp = sta.top();
			//右子树存在且没有访问过
			if (temp->right && temp->right != flag)
			{
				cur = temp->right;
			}
			else
			{
				sta.pop();
				flag = temp;
				cout << temp->val << " ";
				cur = nullptr;
			}
		}
	}
}
int main()
{
	Treenode* root = new Treenode(1);
	Treenode* node_2 = new Treenode(2);
	Treenode* node_3 = new Treenode(3);
	Treenode* node_4 = new Treenode(4);
	Treenode* node_5 = new Treenode(5);
	root->left = node_2;
	root->right = node_3;
	node_2->left = node_4;
	node_2->right = node_5;
	pre_recursion(root);
	pre_iteration(root);
	cout << endl;
	in_recursion(root);
	in_iteration(root);
	cout << endl;
	back_recursion(root);
	back_iteration(root);
	cout << endl;

	return 0;
}