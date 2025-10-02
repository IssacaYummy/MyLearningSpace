#include <iostream>
#include <string>
#include <ctime>

#define MAXSIZE 100

#define OK 1
#define ERROR 0

typedef int Status;
typedef std::string ElemTpye;

typedef struct Node
{
    ElemTpye data;
    Node* Next;
}Node;

typedef Node* LinkList;

/* Function Declaration */
Status GetElem(LinkList L, int pos, ElemTpye &e);
Status InsertElem(LinkList L, int pos, ElemTpye e);
Status DeleteElem(LinkList L, int pos, ElemTpye &e);
void CreateListHead(LinkList &L, int n);
void CreateListTail(LinkList &L, int n);
Status DeleteList(LinkList &L);


int main()
{

}


/**
 * @brief Get one sepecific Element
 */
Status GetElem(LinkList L, int pos, ElemTpye &e)
{   
    if( pos < 1)
    {
        std::cout << "输入的值不合法" << std::endl;
        return ERROR;
    }

    int i = 1;
    LinkList p = L->Next;

    while(p && i < pos)
    {
        p = p->Next;
        ++i;
    }

    if(!p || i > pos)
    {
        return ERROR;
    }

    e = p->data;

    std::cout << "GetSuccessfully" << "\n";
    std::cout << "第" << pos << "个值为" << e << std::endl;

    return OK;
}


Status InsertElem(LinkList L, int pos, ElemTpye e)
{
    if(pos < 1) return ERROR;

    int i = 1;
    LinkList p = L->Next;

    while(p && i < pos-1)
    {
        p = p->Next;
        i++;
    }

    if(!p)
    {
        std::cout << "插入位数超过链表最大数值" << std::endl;
        return ERROR;
    }

    LinkList s = (LinkList)new(Node);
    s->Next = p->Next;
    p->Next = s;
    s->data = e;

    std::cout << "in pos" << pos << "insert \"" << e <<"\" successful" << std::endl;

    return OK;
}



Status DeleteElem(LinkList L, int pos, ElemTpye &e)
{
    if(pos < 1) return ERROR;

    int i = 1;
    LinkList p = L->Next;

    while(p && i < pos-1)
    {
        p = p->Next;
        i++;
    }

    if(!p || !(p->Next))
    {
        std::cout << "pos超过链表长度或要删除的结点不存在" << std::endl;
        return ERROR;
    }

    LinkList q = p->Next;    
    p->Next = q->Next;
    e = p->data;

    delete q;
    
    return OK;
}


void CreateListHead(LinkList &L, int n)
{
    LinkList p;
    int i;

    srand(time(0));

    L = (LinkList)new(Node);
    L->Next = NULL;

    for(i = 0; i < n; i++)
    {
        p = (LinkList)new(Node);
        p->data = rand()%100+1;
        p->Next = L->Next;
        L->Next = p;
    }
}


/**
 * @brief Create a linked list with tail-insert method
 */
void CreateListTail(LinkList &L, int n)
{
    LinkList p;
    int i;

    srand(time(0));

    L = (LinkList)new(Node);
    LinkList q = L;

    for(i = 0; i < n; i++)
    {
        p = (LinkList)new(Node);
        p->data = rand()%100+1;
        q->Next = p;
        q = p;
    }
    q->Next = NULL;
}

/**
 * @brief Delete the hole List
 */
Status DeleteList(LinkList &L)
{
    LinkList p,q;

    p = L->Next;

    while(p)
    {
        q = p->Next;
        free(p);
        p = q;
    }

    L->Next = NULL;

    return OK;
}