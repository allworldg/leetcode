#include <stdio.h>
#include <stdlib.h>
/* 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 
。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 思路：head遍历，找到第left-1个节点，将其保存，然后从第left结点开始普通转置， */

struct ListNode
{
    struct ListNode *next;
    int val;
};
struct ListNode *createNode(int val)
{
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->next = NULL;
    node->val = val;
    return node;
}
struct ListNode* mergeList(struct ListNode* l,struct ListNode* r){
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->next = -1;
    newNode->next = NULL;
    struct ListNode* cur = newNode;
    while(l&&r){
        if(l->val<r->val){
            cur->next = l;
            l = l->next;
        }else{
            cur->next = r;
            r = r->next;
        }
        cur = cur->next;
    }
    cur->next = l==NULL?r:l;
    return newNode->next;
}

struct ListNode* mergeSort(struct ListNode* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    struct ListNode *slow,*quick,*l,*r;
    slow = head;
    quick = head->next->next;
    while(quick&&quick->next){
        quick = quick->next->next;
        slow = slow->next;
    }
    r = mergeSort(slow->next);
    slow->next= NULL;
    l = mergeSort(head);
    return mergeList(l,r);
}


struct ListNode* sortList(struct ListNode* head){
     return mergeSort(head);
}


int main()
{
    struct ListNode *node1 = createNode(4);
    struct ListNode *node2 = createNode(2);
    struct ListNode *node3 = createNode(1);
    struct ListNode *node4 = createNode(3);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    struct ListNode *head = sortList(node1);
    return 0;
}
