#include <iostream>
#include <string>

#define OK 1
#define ERROR 0
#define MAXSIZE 1000

typedef int ElemType;
typedef int Status;


typedef struct 
{
    ElemType data;  //数据
    int cur;        //游标 cursor
}Component, StaticLinkedList[MAXSIZE];

//Function Declaration 
Status InitStaticLinkedList(StaticLinkedList space);
int ListLength(StaticLinkedList L);
int Malloc_SLL(StaticLinkedList space);
void Free_SLL(StaticLinkedList L, int i);
Status ListInsert(StaticLinkedList L, int i, ElemType e);
Status ListDelete(StaticLinkedList L, int i);

int main()
{

}


Status InitStaticLinkedList(StaticLinkedList space)
{
    int i ;
    for ( i = 0; i < MAXSIZE - 1; i++)
    {
        space[i].cur = i + 1;
    }

    space[MAXSIZE-1].cur = 0;

    return OK;
    
}


int ListLength(StaticLinkedList L)
{
    int length = 0;
    int i = L[MAXSIZE - 1].cur; // 从表头开始
    while (i != 0)
    {
        length++;
        i = L[i].cur; // 移动到下一个节点
    }
    return length;
}


int Malloc_SLL(StaticLinkedList space)
{
    int i = space[0].cur;   //取出空闲结点的下标

    if(space[0].cur)
    {
        space[0].cur = space[i].cur;    //将链表头指向下一个空闲结点
    }

    return i;
}

void Free_SLL(StaticLinkedList L, int i)
{
    L[i].cur = L[0].cur; // 释放节点指向当前空闲链表头
    L[0].cur = i;        // 空闲链表头指向被释放节点
}


Status ListInsert(StaticLinkedList L, int i, ElemType e)
{
    int j, k, l;
    k = MAXSIZE - 1;
    if ( i < 1 || i > ListLength(L) + 1)
    {
        return ERROR;
    } //判断k的值是否合法

    j = Malloc_SLL(L); //取出空闲列表的第一个的下标

    if(j)   
    {
        L[j].data = e;
        for( l = 1; l <= i - 1; l ++)   //找到第i个元素之前的下标
        {
            k = L[k].cur;
        }

        L[j].cur = L[k].cur;    //把第i个元素之前的cur赋值给新元素的cur
        L[k].cur = j;           //把新元素的下标赋值给第i个元素之前的元素的cur
        return OK;
    }

    return ERROR;
}


Status ListDelete(StaticLinkedList L, int i)
{
    int j, k;
    if(i < 1 || i > ListLength(L))
    {
        ERROR;
    }

    k = MAXSIZE - 1;

    for ( j = 0; j <= i - 1; j++)
    {
        k = L[k].cur;
    }

    j = L[k].cur;
    L[k].cur = L[j].cur;

    Free_SLL(L, j);

    return OK;
    
}