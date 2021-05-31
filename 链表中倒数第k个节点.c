#include <stdio.h>
#include <stdlib.h>
/* 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。

*/

/* 方法1：
   1. 遍历一次获得总长度 
   2. 遍历第二次找到位置返回
   （新增一个头结点，避免考虑找的点是否是头结点）链表常规操作*/

struct ListNode
{
    int val;
    struct ListNode *next;
    /* data */
};

struct ListNode *getKthFromEnd(struct ListNode *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    int length = 0;
    struct ListNode *dummyNode = malloc(sizeof(struct ListNode));
    dummyNode->next = head;
    dummyNode->val = -1;
    struct ListNode *cur = dummyNode;
    while(cur->next){
        length++;
        cur = cur->next;
    }
    int n = length - k + 1;//找到目标位置
    cur = dummyNode;
    for (int i = 0; i < n;i++){
        cur = cur->next;
    }
    return cur;
}