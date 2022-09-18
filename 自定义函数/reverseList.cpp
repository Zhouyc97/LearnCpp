#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node(){};
    Node(int _val):val(_val),next(nullptr) {}
    Node(int _val,Node* _next):val(_val),next(_next) {}
    int val;
    Node* next;
};

void print(Node* head)
{
    while(head)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* reverseIter(Node* head)
{
    Node* pre = nullptr;
    Node* cur = head;
    while(cur)
    {
        Node* temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}

Node* reverseRecur(Node* head)
{
    if(head == nullptr || head->next == nullptr)
        return head;
    Node* temp = reverseRecur(head->next);
    head->next->next = head;
    head->next = nullptr;
    return temp;
}

int main()
{
    Node* n5 = new Node(5);
    Node* n4 = new Node(4,n5);
    Node* n3 = new Node(3,n4);
    Node* n2 = new Node(2,n3);
    Node* head = new Node(1,n2);

    cout<<"初始化：";
    print(head);

    cout<<"迭代法：";
    head = reverseIter(head);
    print(head);

    cout<<"递归法：";
    head = reverseRecur(head);
    print(head);

    return 0;
}