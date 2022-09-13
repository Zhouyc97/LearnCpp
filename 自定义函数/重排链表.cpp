#include<iostream>


struct ListNode {
int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};


using namespace std;

    //获取链表中点
    ListNode* getMid(ListNode* head)
    {
        if(head == nullptr)
            return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    //合并链表
    void merge(ListNode* l1, ListNode* l2)
    {

        while(l1 && l2)
        {
            ListNode* temp_1 = l1->next;
            ListNode* temp_2 = l2->next;

            l1->next = l2;
            l2->next = temp_1;

            l1 = temp_1;
            l2 = temp_2;
        }
    }
    //翻转链表
    ListNode* reverse(ListNode* head)
    {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur)
        {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
    //交替排列
    void reorderList(ListNode* head) {
        ListNode* mid = getMid(head);
    
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverse(l2);
        
        merge(head,l2);
    }

int  main() {
	ListNode* head = new ListNode(1);
	ListNode* node1 = new ListNode(2);
	ListNode* node2 = new ListNode(3);
	ListNode* node3 = new ListNode(4);
	ListNode* node4 = new ListNode(5);

	head->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = nullptr;

    ListNode* cur = head;
    while (cur != nullptr) {
		cout << cur->val<<" ";
		cur = cur->next;
	}
    cout<<endl;

	reorderList(head);
    cur = head;
	while (cur != nullptr) {
		cout << cur->val<<" ";
		cur = cur->next;
	}
    cout<<endl;

	return 0;
}
