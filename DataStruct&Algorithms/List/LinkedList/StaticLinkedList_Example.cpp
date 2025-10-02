#include <iostream>
const int MAXSIZE = 100;

// 静态链表节点结构体
template<typename T>
struct Component {
    T data;      // 数据域
    int cur;     // 游标，指向下一个节点的下标
};

// 静态链表类
template<typename T>
class StaticLinkedList {
public:
    Component<T> space[MAXSIZE];

    StaticLinkedList() {
        for (int i = 0; i < MAXSIZE - 1; ++i)
            space[i].cur = i + 1;
        space[MAXSIZE - 1].cur = 0; // 头节点
    }

    // 分配一个空闲节点
    int mallocNode() {
        int i = space[0].cur;
        if (i) space[0].cur = space[i].cur;
        return i;
    }

    // 释放节点
    void freeNode(int k) {
        space[k].cur = space[0].cur;
        space[0].cur = k;
    }

    // 在第pos个位置插入元素e
    bool insert(int pos, T e) {
        if (pos < 1) return false;
        int j = mallocNode();
        if (j == 0) return false;
        space[j].data = e;
        int k = MAXSIZE - 1;
        for (int l = 1; l < pos; ++l) {
            k = space[k].cur;
            if (k == 0) return false;
        }
        space[j].cur = space[k].cur;
        space[k].cur = j;
        return true;
    }

    // 删除第pos个元素
    bool remove(int pos) {
        if (pos < 1) return false;
        int k = MAXSIZE - 1;
        for (int l = 1; l < pos; ++l) {
            k = space[k].cur;
            if (space[k].cur == 0) return false;
        }
        int j = space[k].cur;
        if (j == 0) return false;
        space[k].cur = space[j].cur;
        freeNode(j);
        return true;
    }

    // 打印链表内容
    void print() {
        int i = space[MAXSIZE - 1].cur;
        std::cout << "链表内容: ";
        while (i != 0) {
            std::cout << space[i].data << " ";
            i = space[i].cur;
        }
        std::cout << std::endl;
    }
};

int main() {
    StaticLinkedList<int> list;
    list.insert(1, 10);
    list.insert(2, 20);
    list.insert(3, 30);
    list.insert(2, 15);
    list.print();

    list.remove(3);
    list.print();

    list.insert(2, 99);
    list.print();
    return 0;
}