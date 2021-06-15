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
struct ListNode* reverse(struct ListNode* head){
    struct ListNode* newHead = NULL;
    while(head){
        struct ListNode* nextTemp = head->next;
        head->next = newHead;
        newHead = head;
        head = nextTemp;
    }
    return newHead;
}

void reorderList(struct ListNode* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    struct ListNode* dummyNode = malloc(sizeof(struct ListNode));
    dummyNode->val = -1;
    dummyNode->next = head;
    struct ListNode * quick = dummyNode;
    struct ListNode *slow = dummyNode;
    while(quick&&quick->next){
        quick = quick->next->next;
        slow = slow->next;
    }
    struct ListNode* newNode =slow->next;
    slow->next = NULL;
    newNode = reverse(newNode);
    struct ListNode* cur1 = dummyNode->next;
    while(cur1&&newNode){
        struct ListNode* nextTemp1 = cur1->next;
        struct ListNode* nextTemp2 = newNode->next;
        newNode->next = cur1->next;
        cur1->next = newNode;
        cur1 = nextTemp1;
        newNode = nextTemp2;

        
    }
    return dummyNode->next;
}

int main()
{
    struct ListNode *node1 = createNode(1);
    struct ListNode *node2 = createNode(2);
    struct ListNode *node3 = createNode(3);
    struct ListNode *node4 = createNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    // node5->next = node6;
    reorderList(node1);
    return 0;
}
