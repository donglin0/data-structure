#pragma once
#include<iostream>
using namespace std;
typedef int T;

template<class T>
struct DblNode//链表节点类定义
{
	T data;//数据域
	DblNode<T> *lLink, * rLink;//左链、右链指针
	DblNode(DblNode<T>* left = NULL, DblNode<T>* right = NULL):lLink(left), rLink(right){};//构造函数
	DblNode(T value, DblNode<T>* left = NULL, DblNode<T>* right = NULL) :data(value), lLink(left), rLink(right) {}
};

template<class T>
class DblList
{
public:
	DblList(T uniqueVal);//构造函数
	~DblList();//析构函数
	int length()const;//计算双链表长度
	bool IsEmpty() { return first->rLink == first; }//空否
	DblNode<T>* getHead()const { return first; }//取附加头结点地址
	void setHead(DblNode<T>* ptr) { first = ptr; }//设置附加头结点地址
	DblNode<T> *Search(const T& x);//沿后继方向寻找等于x的结点
	DblNode<T>* Locate(int i, int d);//定位序号为i（>=0）的结点，d=0按前驱方向，d不为0按其他方向
	bool Insert(int i, T& x, int d);//在第i个结点后插入含x的新结点，d=0按前驱方向
	bool Remove(int i, T& x, int d);//删除第i个结点，d=0按前驱方向
private:
	DblNode<T>* first;//头指针
};

template<class T>
DblList<T>::DblList(T uniqueVal)//构造函数：建立双链表的附加头结点
{
	first = new DblNode<T>(uniqueVal);
	if (first == NULL) { cerr << "存储分配错误！\n";exit(1); }
	first->rLink = first->rLink = first;
};

template<class T>
DblList<T>::~DblList()
{
	DblNode<T>* q = NULL;
	while (first->rLink != first)//链不空时，删掉所有结点
	{
		q = first->rLink;
		first->rLink = q->rLink;//从链删摘下被删结点
		delete q;
	}
	first->rLink = first->rLink = first;//设置尾指针
}

template<class T>
int DblList<T>::length()const//带头结点双链表长度
{
	DblNode<T>* current = first->rLink;int count = 0;
	while (current != first) { current = current->rLink;count++; }
	return count;
}

template<class T>
DblNode<T>* DblList<T> ::Search(const T& x)//按后继方向搜索含x的结点
{
	DblNode<T>* current = first->rLink;
	while (current != first && current->data != x) current = current->rLink;
	if (current != first) return current;//搜索成功
	else return NULL;
}

template<class T>
DblNode<T>* DblList<T> ::Locate(int i, int d)//d=0前驱方向
{
	if (first->rLink == first || i == 1) return first;
	DblNode<T>* current=first;
	if (d == 0) current = current->lLink;//搜索方向
	else current = current->rLink;
	for (int j = 1;j < i;j++)//逐个结点检测
	{
		if (current == first) break;//链太短
		if (d == 0) current = current->lLink;
		else current = current->rLink;
	}
	if (current != first) return current;//搜索成功
	else return NULL;
}

template<class T>
bool DblList<T> ::Insert(int i, T& x, int d)
{
	DblNode<T>* current = Locate(i, d);//查找第i个结点
	if (current == NULL) return false;//i不合理
	DblNode<T>* newNode = new DblNode<T>(x);
	if (newNode == NULL) { cerr << "存储分配错误！\n";exit(1); }
	if (d == 0)//前驱方向插入
	{
		newNode->lLink = current->lLink;
		current->lLink = newNode;
		newNode->lLink->rLink = newNode;
		newNode->rLink = current;
	}
	else//后继方向插入
	{
		newNode->rLink = current->rLink;
		current->rLink = newNode;
		newNode->rLink->lLink = newNode;
		newNode->lLink = current;
	}
	return true;
};

template<class T>
bool DblList<T> ::Remove(int i, T& x, int d)//带附加头结点的双链表按照d所指方向删除第i个结点
{
	DblNode<T>* current = Locate(i, d);//查找第i个结点
	if (current == NULL) return false;
	current->rLink->lLink = current->lLink;//从lLink链中摘下
	current->lLink->rLink = current->rLink;//从rLink链中摘下
	x = current->data;delete current;//删除
	return true;
};