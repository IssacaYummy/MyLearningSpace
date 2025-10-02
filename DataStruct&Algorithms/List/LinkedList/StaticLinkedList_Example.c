/* 静态链表示例（C语言实现）
 * 包含初始化、插入、删除、打印等操作
 */
#include <stdio.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct {
    ElemType data; // 数据域
    int cur;      // 游标，指向下一个节点的下标
} Component, StaticLinkedList[MAXSIZE];

// 初始化静态链表，将所有节点串成备用链表
Status InitStaticLinkedList(StaticLinkedList space) {
    for (int i = 0; i < MAXSIZE - 1; i++) {
        space[i].cur = i + 1;
    }
    space[MAXSIZE - 1].cur = 0; // 头节点，实际链表的头
    return OK;
}

// 分配一个空闲节点，返回下标
int Malloc_SLL(StaticLinkedList space) {
    int i = space[0].cur;
    if (i) {
        space[0].cur = space[i].cur;
    }
    return i; // 返回分配到的节点下标，0表示失败
}

// 释放节点，将其归还到备用链表
void Free_SLL(StaticLinkedList space, int k) {
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

// 在第i个位置插入元素e
Status InsertStaticLinkedList(StaticLinkedList space, int i, ElemType e) {
    if (i < 1) return ERROR;
    int j = Malloc_SLL(space);
    if (j == 0) return ERROR; // 没有空闲节点
    space[j].data = e;
    int k = MAXSIZE - 1; // 头节点
    for (int l = 1; l < i; l++) {
        k = space[k].cur;
        if (k == 0) return ERROR;
    }
    space[j].cur = space[k].cur;
    space[k].cur = j;
    return OK;
}

// 删除第i个元素
Status DeleteStaticLinkedList(StaticLinkedList space, int i) {
    if (i < 1) return ERROR;
    int k = MAXSIZE - 1;
    for (int l = 1; l < i; l++) {
        k = space[k].cur;
        if (space[k].cur == 0) return ERROR;
    }
    int j = space[k].cur;
    if (j == 0) return ERROR;
    space[k].cur = space[j].cur;
    Free_SLL(space, j);
    return OK;
}

// 打印静态链表内容
void PrintStaticLinkedList(StaticLinkedList space) {
    int i = space[MAXSIZE - 1].cur;
    printf("链表内容: ");
    while (i != 0) {
        printf("%d ", space[i].data);
        i = space[i].cur;
    }
    printf("\n");
}

int main() {
    StaticLinkedList space;
    InitStaticLinkedList(space);
    printf("初始化后备用链表头: %d\n", space[0].cur);

    // 插入元素
    InsertStaticLinkedList(space, 1, 10);
    InsertStaticLinkedList(space, 2, 20);
    InsertStaticLinkedList(space, 3, 30);
    InsertStaticLinkedList(space, 2, 15); // 在第2个位置插入15
    PrintStaticLinkedList(space);

    // 删除元素
    DeleteStaticLinkedList(space, 3); // 删除第3个元素
    PrintStaticLinkedList(space);

    // 再插入
    InsertStaticLinkedList(space, 2, 99);
    PrintStaticLinkedList(space);
    return 0;
}
