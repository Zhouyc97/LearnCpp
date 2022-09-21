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

//迭代法
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

//递归法
Node* reverseRecur(Node* head)
{
    if(head == nullptr || head->next == nullptr)
        return head;
    Node* temp = reverseRecur(head->next);
    head->next->next = head;
    head->next = nullptr;
    return temp;
}

//翻转[head,tail]间链表
pair<Node*,Node*> reverse(Node* head,Node* tail)
{
    Node* pre = nullptr;
    Node* cur = head;
    Node* end = tail->next;
    while(cur != end)
    {
        Node* p = cur->next;
        cur->next = pre;
        pre = cur;
        cur = p;
    }
    return {pre,head};
}

//k个一组翻转链表
Node* swapPairs(Node* head,int k) 
{

    Node* dummy = new Node(0,head);
    Node* pre = dummy;

    while(head)
    {
        Node* tail = pre;
        //剩余长度是否大于等于k
        for(int i = 0; i < k; i++)
        {
            tail = tail->next;
            if(tail == nullptr)
                return dummy->next;
        }

        Node* temp = tail->next;
        pair<Node*,Node*> ret = reverse(head,tail);

        pre->next = ret.first;
        ret.second->next = temp;
        pre = ret.second;
        head = temp;
    }
    Node* res = dummy->next;
    delete dummy;
    return res;
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

    cout<<"2个一组翻转链表：";
    head = swapPairs(head,2);
    print(head);

    return 0;
}