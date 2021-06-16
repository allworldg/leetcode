#include <stdio.h>
#include <stdlib.h>

typedef struct MyLinkedList
{
    struct MyLinkedList *pre;
    struct MyLinkedList *next;
    int val;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList *myLinkedListCreate()
{
    MyLinkedList *node = malloc(sizeof(struct MyLinkedList));
    node->val = 0;
    node->pre = NULL;
    node->next = NULL;
    return node;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
/* 失效条件：1、index<0.2、真实头结点为null 3、位置大于链表长度 */
int myLinkedListGet(MyLinkedList *obj, int index)
{
    if (index < 0 || obj == NULL || (obj != NULL && obj->next == NULL))
    { //满足前两点失效条件
        return -1;
    }
    MyLinkedList *cur = obj->next;
    int i = 0;
    /* 判断方法一：通过当前结点是否为null进行判断，如果当前位置到达index，则返回当前结点值，如果跳出循环，说明cur已经为空，此时i未到index或者i到index，但是此结点已经是空，所以直接返回-1；*/
    while (cur != NULL)
    {
        if (i == index)
        {
            return cur->val;
        }
        ++i;
        cur = cur->next;
    }
    return -1;

    /* 方法二，通过当前位置是否达到index进行判断，在循环中如果出现空指针，说明index大于链表长度，直接返回-1，
    如果当前位置已经是index，则跳出循环，此时需要判断此时的位置是否为空 */
    /*   while(i<index){
        if(cur==NULL){
            return -1;
        }
        ++i;
        cur = cur->next;
    }
    if(cur==NULL){
        return -1;
    }
    return cur->val; */
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
    MyLinkedList *newNode = myLinkedListCreate();
    newNode->val = val;
    MyLinkedList *nextTemp = obj->next;
    obj->next = newNode;
    newNode->pre = obj;
    newNode->next = nextTemp;
    nextTemp->pre = newNode;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
    MyLinkedList *newNode = myLinkedListCreate();
    newNode->val = val;
    while (obj->next)
    {
        obj = obj->next;
    }
    obj->next = newNode;
    newNode->pre = obj;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
    if (obj == NULL)
    {
        return;
    }
    if (index <= 0)
    {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    int n = 0;
    while (n < index)
    {
        if (obj->next == NULL)
        {
            return;
        }
        n++;
        obj = obj->next;
    }

    MyLinkedList *nextTemp = obj->next;
    MyLinkedList *newNode = myLinkedListCreate();
    newNode->val = val;
    newNode->next = nextTemp;
    newNode->pre = obj;
    obj->next = newNode;
    if (nextTemp)
    {
        nextTemp->pre = newNode;
        newNode->next = nextTemp;
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
    if (obj == NULL || index < 0)
    {
        return;
    }
    int i = 0;
    while (i < index)
    {
        if (obj->next == NULL)
        {
            return; 
        }
        ++i;
        obj = obj->next;
    }
    if(obj->next){
        MyLinkedList *nextTemp = obj->next->next;
        obj->next = nextTemp;
        if(nextTemp){
            nextTemp->pre = obj;
        }
    }
}

void myLinkedListFree(MyLinkedList *obj)
{
    if (obj == NULL)
    {
        return;
    }
    MyLinkedList *cur = NULL;
    while (obj->next)
    {
        cur = obj->next;
        MyLinkedList *nextTemp = cur;
        obj->next = nextTemp;
        cur->next = NULL;
        cur->pre = NULL;
        cur->val = NULL;
        if (nextTemp)
        {
            nextTemp->pre = obj;
        }
        free(cur);
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/