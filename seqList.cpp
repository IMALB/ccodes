/*
* 内 容：静态顺序表 动态线性表
* 最后修改日期：2020.7.02
*/
#include <iostream>
using namespace std;
/*
// 静态顺序表
#define MaxSize 50    //顺序表最大长度
struct SqList {
    int data[MaxSize];//顺序表元素
    int length;       //顺序表现在的长度
};
// 静态顺序表初始化
void InitList(SqList &L) {
    L.length = 0;
    // 全部赋值为0可以省略
    for (int i = 0; i < MaxSize; i++)
        L.data[i] = 0; 
}
*/
// 动态顺序表 
#define InitSize 5
struct SqList {
    int *data;     //指向动态数组的头部
    int MaxSize;   //记录动态数组的最大长度
    int length;    //现有长度
};
// 动态数组的初始化
void InitList(SqList &L) {
    //data指向的是一片空间
    //大小为InitSize个int
    L.data = new int[InitSize];
    L.MaxSize = 5;
    L.length = 0;
}
// 增加动态数组的长度,O(n)
void IncrSize(SqList L, int len) {
    int *p = L.data;
    L.data = new int[len + L.MaxSize];
    L.MaxSize = len + L.MaxSize;
    // 把原来空间的数据移到新的空间
    for (int i = 0; i < L.length; i++)
        L.data[i] = p[i];
    // 一定要释放原来的空间
    delete[] p;
}
// 在顺序表第i个位置插入e
bool ListInset(SqList &L, int i, int e) {
    if (i < 1||i > L.length + 1||L.length == L.MaxSize)
        return false;
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    return true;
}
// 删除第i个元素用引用变量e返回
bool ListDelete(SqList &L, int i, int &e) {
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i - 1; j < L.length-1; j++)
        L.data[j] = L.data[j + 1];
    L.length--;
    return true;
}
// 按位查找，用引用变量e接收数值
bool GetElem(SqList L, int i, int &e) {
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    return true;
}
// 按值查找，返回位序
int LocateElem(SqList L, int e) {
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i+1;
    return 0;  // 表示查找失败
}
// 打印顺序表
void PrintList(SqList L) {
    for (int i = 0; i< L.length; i++)
        cout << L.data[i] << " ";
    cout << endl;
}
// 打印地址
void PrintIndex(SqList L) {
    for (int i = 0; i < 5; i++)
        cout << &L.data[i] << " ";
}
int main()
{
    SqList L;     //声名一个线性表
    InitList(L);
    L.data[0] = 0, L.data[1] = 1, L.data[2] = 2;
    L.length = 3;
    int e = 0;
    PrintList(L);
    return 0;
}