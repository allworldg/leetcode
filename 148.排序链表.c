/*
 * @lc app=leetcode.cn id=148 lang=c
 *
 * [148] 排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



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

// @lc code=end

