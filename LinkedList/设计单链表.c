#include <stdio.h>
#include <stdlib.h>

typedef struct MyLinkedList
{
    int val;
    struct MyLinkedList *next;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList *myLinkedListCreate()
{
    MyLinkedList *linkList = malloc(sizeof(MyLinkedList));
    linkList->next = NULL;
    linkList->val = -1;
    return linkList;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList *obj, int index)
{
    if (index < 0||obj->next ==NULL)
    {
        return -1;
    }
    int n = 0;
    MyLinkedList *cur = obj;
    while(n<index){
        if(cur->next==NULL){
            return -1;
        }
        n++;
        cur = cur->next;
    }
    if(cur->next == NULL){
        return -1;
    }
    return cur->next->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
    MyLinkedList *newNode = myLinkedListCreate();
    newNode->val = val;
    newNode->next = obj->next;
    obj->next = newNode;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
    MyLinkedList *newNode = myLinkedListCreate();
    newNode->val = val;
    MyLinkedList *cur = obj;
    while (cur->next)
    {
        cur = cur->next;
    }
    cur->next = newNode;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
    if (index <= 0)
    {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    int n = 0;
    MyLinkedList *cur = obj;
    while (cur->next)
    {
        if (n == index)
        {
            MyLinkedList *newNode = myLinkedListCreate();
            newNode->val = val;
            newNode->next = cur->next;
            cur->next = newNode;
            return;
        }
        ++n;
        cur = cur->next;
    }
    if (n == index)
    {
        MyLinkedList *newNode = myLinkedListCreate();
        newNode->val = val;
        cur->next = newNode;
    }
    return;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
    if (index < 0)
    {
        return;
    }
    MyLinkedList *cur = obj;
    int n = 0;
    while (cur->next)
    {
        if (n == index)
        {
            MyLinkedList *next = cur->next;
            cur->next = next->next;
            next->next = NULL;
            free(next);
            return;
        }
        n++;
        cur = cur->next;
    }
}

void myLinkedListFree(MyLinkedList *obj)
{
    if (obj == NULL)
    {
        return;
    }
    MyLinkedList *cur;
    while (obj->next)
    {
        cur = obj->next;
        obj->next = cur->next;
        cur->next = NULL;
        free(cur);
    }
    free(obj);
}

int main()
{
    MyLinkedList *obj = myLinkedListCreate();
    myLinkedListAddAtHead(obj, 7);
    myLinkedListAddAtHead(obj, 2);
    myLinkedListAddAtHead(obj, 1);
    myLinkedListAddAtIndex(obj, 3, 0);
    myLinkedListDeleteAtIndex(obj, 2);
    myLinkedListAddAtHead(obj, 4);
    myLinkedListAddAtTail(obj, 4);
    myLinkedListGet(obj, 4);
    return 0;
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