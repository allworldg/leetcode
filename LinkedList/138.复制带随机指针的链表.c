/*
 * @lc app=leetcode.cn id=138 lang=c
 *
 * [138] 复制带随机指针的链表
 * 思路：在链表每个旧节点后复制该节点，让新旧节点互相穿插，然后让通过旧节点的random指针关系赋予新节点
 * 1、遍历链表，每个旧节点后连接一个新的复制节点，互相穿插。
 * 2、遍历链表，将每个旧节点的random指针关系复制到新节点上
 * 3、遍历链表，生成单独由新节点生成的独立链表。
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

// @lc code=end
