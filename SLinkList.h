#ifndef __SLINKLIST_H__ 
#define __SLINKLIST_H__

#include<stdio.h>
#include<stdlib.h>

namespace SLinkList{


typedef struct SNode
{
    int data;
    struct SNode * next;
}SNode;

void InitList(SNode * head)
{
    head->data = 0;
    head->next = NULL;
}

void ClearList(SNode * head)
{
    if(head->next == NULL) return;
    SNode * p = head;
    head = head->next;
    while (head->next != NULL)
    {
        head = head->next;
        free(p);
        p = head;
    }
    free(head);
}

int ListLength(SNode * head)
{
    int i = 0;
    while(head->next != NULL)
    {
        i++;
        head = head->next;
    }
    return i;
}

int GetElem(SNode *head, int i, int &e)
{
    if (head == NULL || i < 1) return 0;
    SNode *p = head->next; 
    int k = 1;
    while (p != NULL && k < i)
    {
        p = p->next;
        k++;
    }

    if (p == NULL)
        return 0;

    e = p->data;
    return 1;
}

int ListEmpty(SNode * head)
{
    if(head->next==NULL) return 1;
    else return 0;
}

int AddTail(SNode * head, int e)
{
    SNode * p = (SNode*)malloc(sizeof(SNode));
    if(p==NULL) return 0;
    while(head->next!=NULL)
    {
        head = head->next;
    }
    p->next = NULL;
    p->data = e;
    head->next = p;
    return 1;
}

int AddHead(SNode * head, int e)
{
    SNode * p = (SNode*)malloc(sizeof(SNode));
    if(p==NULL) return 0;
    if(head->next==NULL)
    {
        head->next = p;
        p->data = e;
        p->next = NULL;
        return 1;
    }
    p->next = head->next;
    p->data = e;
    head->next = p;
    return 1;
}

int Insert(SNode * head, int i, int e)
{   
    SNode * p = (SNode*)malloc(sizeof(SNode));
    if(p==NULL || i<1) return 0;
    int k = 1;
    while (head->next!=NULL && k<i)
    {
        k++;
        head = head->next;
    }
    p->next = head->next;
    p->data = e;
    head->next = p;
    return 1;
}



}

#endif