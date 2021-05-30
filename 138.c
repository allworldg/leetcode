/*
 * @lc app=leetcode.cn id=138 lang=c
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
    struct Node *random;
};

struct Node *create(int val)
{
    struct Node *node = malloc(sizeof(struct Node));
    node->next = NULL;
    node->random = NULL;
    node->val = val;
    return node;
}

struct Node *copyRandomList(struct Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    struct Node *cur = head;
    while (cur) //第一轮遍历，在每个旧的节点后面生成新复制节点
    {
        struct Node *new = malloc(sizeof(struct Node));
        new->val = cur->val;
        new->next = cur->next;
        new->random = NULL;
        struct Node *next = cur->next;//记录下一个节点，准备开始移动
        cur->next = new;
        cur = new->next; //跳到下一个旧节点
    }
    cur = head;

    while (cur)
    {
        cur->next->random = cur->random!= NULL ? cur->random->next : NULL;
        cur = cur->next->next;
    }

    cur = head->next;
    while (cur)
    {
        cur->next = cur->next != NULL ? cur->next->next : NULL;
        cur = cur->next;
    }
    return head->next;
}

int main()
{
    struct Node *node1 = create(7);
    struct Node *node2 = create(13);
    struct Node *node3 = create(11);
    struct Node *node4 = create(10);
    struct Node *node5 = create(1);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    node1->random = NULL;
    node2->random = node1;
    node3->random = node5;
    node4->random = node3;
    node5->random = node1;

    copyRandomList(node1);
}
// @lc code=end
