#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


#define OK 1
#define ERROR 0
#define OVERFLOW -1

#define ElemType string
#define MAXSIZE 100
#define Status int

typedef struct SqList
{
    ElemType* e;
    int length;
}SqList;

// 单链表节点结构定义
typedef struct ListNode 
{
    ElemType data;              // 数据域，存储节点的数据
    struct ListNode* next;      // 指针域，指向下一个节点
} ListNode, *LinkList;

// 函数声明
Status InitList(LinkList& L);           // 初始化链表
Status InsertList(LinkList& L, int pos, ElemType e);   // 按位置插入
Status DeleteList(LinkList& L, int pos);               // 按位置删除  
Status DeleteByValue(LinkList& L, ElemType e);         // 按值删除
int LocateElem(LinkList L, ElemType e);                // 查找元素位置
Status GetElem(LinkList L, int pos, ElemType& e);      // 按位置查找
void DisplayList(LinkList L);                          // 显示链表
int ListLength(LinkList L);                            // 求链表长度
void ClearList(LinkList& L);                           // 清空链表
void DestroyList(LinkList& L);                         // 销毁链表

// ======================== 单链表基本操作实现 ========================

/**
 * 初始化单链表（带头节点）
 * @param L 链表头指针的引用
 * @return OK表示成功，ERROR表示失败
 */
Status InitList(LinkList& L) 
{
    // 创建头节点
    L = new ListNode;
    if (!L) return ERROR;  // 内存分配失败
    
    L->next = NULL;        // 头节点指针域置空
    cout << "链表初始化成功！" << endl;
    return OK;
}

/**
 * 按位置插入元素
 * @param L 链表头指针的引用
 * @param pos 插入位置（从1开始）
 * @param e 要插入的元素
 * @return OK表示成功，ERROR表示失败
 */
Status InsertList(LinkList& L, int pos, ElemType e) 
{
    if (pos < 1) return ERROR;  // 位置不合法
    
    ListNode* p = L;  // p指向头节点
    int i = 0;
    
    // 寻找第pos-1个节点
    while (p && i < pos - 1) {
        p = p->next;
        i++;
    }
    
    if (!p) return ERROR;  // 位置超出范围
    
    // 创建新节点
    ListNode* newNode = new ListNode;
    if (!newNode) return ERROR;
    
    newNode->data = e;
    newNode->next = p->next;  // 新节点指向原来的下一个节点
    p->next = newNode;        // 前一个节点指向新节点
    
    cout << "在位置 " << pos << " 插入元素 \"" << e << "\" 成功！" << endl;
    return OK;
}

/**
 * 按位置删除元素
 * @param L 链表头指针的引用
 * @param pos 删除位置（从1开始）
 * @return OK表示成功，ERROR表示失败
 */
Status DeleteList(LinkList& L, int pos) 
{
    if (pos < 1) return ERROR;  // 位置不合法
    
    ListNode* p = L;  // p指向头节点
    int i = 0;
    
    // 寻找第pos-1个节点
    while (p->next && i < pos - 1) {
        p = p->next;
        i++;
    }
    
    if (!p->next) return ERROR;  // 位置超出范围或链表为空
    
    ListNode* temp = p->next;    // 要删除的节点
    p->next = temp->next;        // 修改指针连接
    
    cout << "删除位置 " << pos << " 的元素 \"" << temp->data << "\" 成功！" << endl;
    delete temp;                 // 释放内存
    return OK;
}

/**
 * 按值删除元素（删除第一个匹配的元素）
 * @param L 链表头指针的引用
 * @param e 要删除的元素值
 * @return OK表示成功，ERROR表示失败
 */
Status DeleteByValue(LinkList& L, ElemType e) 
{
    ListNode* p = L;  // p指向头节点
    
    // 寻找值为e的节点的前驱
    while (p->next && p->next->data != e) {
        p = p->next;
    }
    
    if (!p->next) {
        cout << "未找到值为 \"" << e << "\" 的元素！" << endl;
        return ERROR;  // 未找到
    }
    
    ListNode* temp = p->next;    // 要删除的节点
    p->next = temp->next;        // 修改指针连接
    
    cout << "删除值为 \"" << e << "\" 的元素成功！" << endl;
    delete temp;                 // 释放内存
    return OK;
}

/**
 * 按值查找元素位置
 * @param L 链表头指针
 * @param e 要查找的元素
 * @return 元素位置（从1开始），找不到返回0
 */
int LocateElem(LinkList L, ElemType e) 
{
    ListNode* p = L->next;  // p指向第一个数据节点
    int pos = 1;
    
    while (p) {
        if (p->data == e) {
            cout << "找到元素 \"" << e << "\" 位于位置 " << pos << endl;
            return pos;
        }
        p = p->next;
        pos++;
    }
    
    cout << "未找到元素 \"" << e << "\"" << endl;
    return 0;  // 未找到
}

/**
 * 按位置获取元素
 * @param L 链表头指针
 * @param pos 位置（从1开始）
 * @param e 用于返回元素值的引用
 * @return OK表示成功，ERROR表示失败
 */
Status GetElem(LinkList L, int pos, ElemType& e) 
{
    if (pos < 1) return ERROR;  // 位置不合法
    
    ListNode* p = L->next;  // p指向第一个数据节点
    int i = 1;
    
    while (p && i < pos) {
        p = p->next;
        i++;
    }
    
    if (!p) {
        cout << "位置 " << pos << " 超出范围！" << endl;
        return ERROR;  // 位置超出范围
    }
    
    e = p->data;
    cout << "位置 " << pos << " 的元素是 \"" << e << "\"" << endl;
    return OK;
}

/**
 * 显示链表所有元素
 * @param L 链表头指针
 */
void DisplayList(LinkList L) 
{
    ListNode* p = L->next;  // p指向第一个数据节点
    
    if (!p) {
        cout << "链表为空！" << endl;
        return;
    }
    
    cout << "链表内容: ";
    while (p) {
        cout << "\"" << p->data << "\"";
        p = p->next;
        if (p) cout << " -> ";  // 不是最后一个元素时输出箭头
    }
    cout << " -> NULL" << endl;
}

/**
 * 计算链表长度
 * @param L 链表头指针
 * @return 链表长度
 */
int ListLength(LinkList L) 
{
    ListNode* p = L->next;  // p指向第一个数据节点
    int length = 0;
    
    while (p) {
        length++;
        p = p->next;
    }
    
    cout << "链表长度: " << length << endl;
    return length;
}

/**
 * 清空链表（保留头节点）
 * @param L 链表头指针的引用
 */
void ClearList(LinkList& L) 
{
    ListNode* p = L->next;  // p指向第一个数据节点
    ListNode* temp;
    
    while (p) {
        temp = p;
        p = p->next;
        delete temp;
    }
    
    L->next = NULL;  // 头节点指针域置空
    cout << "链表已清空！" << endl;
}

/**
 * 销毁链表（包括头节点）
 * @param L 链表头指针的引用
 */
void DestroyList(LinkList& L) 
{
    ListNode* p = L;
    ListNode* temp;
    
    while (p) {
        temp = p;
        p = p->next;
        delete temp;
    }
    
    L = NULL;
    cout << "链表已销毁！" << endl;
}

int main()
{
    cout << "======================== 单链表学习演示 ========================" << endl;
    
    LinkList L;  // 定义链表头指针
    ElemType e;
    
    // 1. 初始化链表
    cout << "\n1. 初始化链表:" << endl;
    InitList(L);
    DisplayList(L);
    
    // 2. 插入元素演示
    cout << "\n2. 插入元素演示:" << endl;
    InsertList(L, 1, "Apple");      // 在第1个位置插入"Apple"
    InsertList(L, 2, "Banana");     // 在第2个位置插入"Banana"  
    InsertList(L, 3, "Cherry");     // 在第3个位置插入"Cherry"
    InsertList(L, 2, "Orange");     // 在第2个位置插入"Orange"
    DisplayList(L);
    ListLength(L);
    
    // 3. 查找演示
    cout << "\n3. 查找演示:" << endl;
    LocateElem(L, "Orange");        // 按值查找
    LocateElem(L, "Grape");         // 查找不存在的元素
    GetElem(L, 2, e);               // 按位置查找
    GetElem(L, 10, e);              // 查找超出范围的位置
    
    // 4. 删除演示
    cout << "\n4. 删除演示:" << endl;
    DeleteList(L, 2);               // 按位置删除
    DisplayList(L);
    DeleteByValue(L, "Cherry");     // 按值删除
    DisplayList(L);
    DeleteByValue(L, "Grape");      // 删除不存在的元素
    ListLength(L);
    
    // 5. 更多插入测试
    cout << "\n5. 更多插入测试:" << endl;
    InsertList(L, 1, "First");      // 头插法
    InsertList(L, ListLength(L) + 1, "Last");  // 尾插法  
    DisplayList(L);
    
    // 6. 清空链表
    cout << "\n6. 清空链表:" << endl;
    ClearList(L);
    DisplayList(L);
    ListLength(L);
    
    // 7. 重新添加一些元素
    cout << "\n7. 重新添加元素:" << endl;
    InsertList(L, 1, "Hello");
    InsertList(L, 2, "World");
    InsertList(L, 3, "C++");
    DisplayList(L);
    
    // 8. 销毁链表
    cout << "\n8. 销毁链表:" << endl;
    DestroyList(L);
    
    cout << "\n======================== 演示结束 ========================" << endl;
    
    return 0;
}