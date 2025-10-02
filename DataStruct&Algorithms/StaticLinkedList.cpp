#include <iostream>
#include <string>

#define OK 1
#define ERROR 0
#define MAXSIZE 1000

typedef int ElemType;
typedef int Status;


typedef struct 
{
    ElemType deta;  //数据
    int cur;        //游标 cursor
}Component, StaticLinkedList[MAXSIZE];

//Function Declaration 
Status InitStaticLinkedList(StaticLinkedList space);



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