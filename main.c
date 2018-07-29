//
//  main.c
//  Demo
//
//  Created by 周冠华 on 2018/7/29.
//  Copyright © 2018年 周冠华. All rights reserved.
//

#include <stdio.h>
#include <sys/malloc.h>

typedef struct node
{
    int data;
    struct node *next;
}node,*pnode;

pnode createlist()
{
    pnode phead = (pnode)malloc(sizeof(node));
    pnode ptail = phead;
    ptail->next = NULL;
    return phead;
}

void display(pnode phead)
{
    pnode p = phead->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

void insert(pnode phead,int place,int val)
{
    int i=0;
    pnode _node = phead;
    pnode pswap;
    while(i<place-1)
    {
        _node = _node->next;
        i++;
    }
    pnode pnew = (pnode)malloc(sizeof(node));
    pnew->data = val;
    pswap = _node->next;
    _node->next = pnew;
    pnew->next = pswap;
}

int main()
{
    pnode phead = NULL;
    phead = createlist();
    int i;
    for(i=1;i<5;i++)
    {
        insert(phead,i,i*i);
    }
    display(phead);
}
