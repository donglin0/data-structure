#pragma once
#include<iostream>
using namespace std;
typedef int T;
const int maxSize = 100;//静态链表大小

template<class T>
struct SLinkNode 
{
	T data;//结点数据
	int link;//结点指针
};

template<class T>
class StaticList
{
private:
	SLinkNode<T> elem[maxSize];
	int avil;//当前可分配空间首地址
public:
	void InitList();//初始化
	int Length();//计算静态链表长度
	int Search(T x);//查找具有给定值的结点
	int Locate(int i);//查找第i个结点
	bool Append(T x);//在表尾增加一个新结点
	bool Insert(int i, T x);//第i个结点后插入一个新结点
	bool Remove(int i);//释放第i个结点
	bool IsEmpty();//表空否
};

template<class T>
void StaticList<T>::InitList()//链表空间初始化
{
	elem[0].link = -1;avil = 1;//当前可分配空间从1开始建立带头结点的空链表
	for (int i = 1;i < maxSize - 1;i++) elem[i].link = i + 1;//构成空闲链接表
	elem[maxSize - 1].link = -1;//链表收尾
};

template<class T>
int StaticList<T> ::Length()
{
	int p = elem[0].link;int i = 0;
	while (p != -1)
	{
		p = elem[p].link;i++;
	}
	return i;
};

template<class T>
bool StaticList<T> ::IsEmpty()
{
	if (elem[0].link == -1) return true;
	else return false;
}

template<class T>
int StaticList<T> ::Search(T x)
{
	int p = elem[0].link;
	while (p != -1)
	{
		if (elem[p].data == x) break;
		else p = elem[p].link;
	}
	return p;
}

template<class T>
int StaticList<T> ::Locate(int i)//查找第i个结点位置
{
	if (i < 0) return -1;
	if (i == 0) return 0;
	int j = 1, p = elem[0].link;
	while (p != -1 && j < i) { p = elem[p].link;j++; }//循链查找第i号结点
	return p;
};

template<class T>
bool StaticList<T> ::Append(T x)//表尾追加新结点
{
	if (avil == -1) return false;
	int q = avil;
	avil = elem[avil].link;
	elem[q].data = x; elem[q].link = -1;
	int p = 0;
	while (elem[p].link != -1)  p = elem[p].link;//查找表尾
	elem[p].link = q;//追加
	return true;
};

template<class T>
bool StaticList<T> ::Insert(int i, T x)
{
	int p = Locate(i);
	if (p == -1) return false;
	int q = avil;//分配结点
	avil = elem[q].link;
	elem[q].data = x;
	elem[q].link = elem[p].link;//链入
	elem[p].link = q;
	return true;
};

template<class T>
bool StaticList<T> ::Remove(int i)
{
	int p = Locate(i - 1);//被删结点前一结点
	if (p == -1) return false;
	int q = elem[p].link;//第i号结点
	elem[p].link = elem[q].link;
	elem[q].link = avil;//释放，该结点放入空闲队列
	avil = q;
	return true;
};