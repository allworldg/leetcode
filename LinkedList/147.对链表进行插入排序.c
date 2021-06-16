/*
 * @lc app=leetcode.cn id=147 lang=c
 *
 * [147] 对链表进行插入排序
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 思路：插排原则：要插入的节点之前的节点肯定是已经排序好的部分，所以待插入节点只需要在排序好的部分进行比较，符合条件就插入 */
/* 方法：1、判断异常条件：如果head为空或者只有一个元素，则直接返回
         2、创建哑结点方便进行插入操作，同时设置第一个有效节点属于已经排序的部分，cur指向第二个节点，然后将第一个节点与之后链表断开，防止最后死循环。
         3、遍历cur，设置pre->next在已经排序的部分进行遍历，将每个已排序的节点和cur比较，如果找到位置则跳出循环，准备插入，不符合则继续往后寻找
         4、在上一个循环中，无论是break还是pre走完，此位置肯定就是待插入的位置，所以进行插入操作，继续遍历
         5、遍历结束，返回链表*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *insertionSortList(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct ListNode *dummyNode = malloc(sizeof(struct ListNode));
    dummyNode->val = -1;
    dummyNode->next = head;
    struct ListNode *pre = dummyNode;
    struct ListNode *cur = head->next; //从第二个元素开始插排
    pre->next->next = NULL;            //将第一个节点看做已经排序的部分，并且与之后断开。
    while (cur)
    {
        while (pre->next)
        {
            if (cur->val >= pre->next->val)
            {
                pre = pre->next;
            }
            else
            {
                break;
            }
        }
        struct ListNode *nextTemp = cur->next;
        cur->next = pre->next;
        pre->next = cur;
        pre = dummyNode;
        cur = nextTemp;
    }
    return dummyNode->next;
}
// @lc code=end
