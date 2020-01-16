#pragma once
#include<iostream>
using namespace std;
typedef int T;//类模板实例化

template<class T>
struct CircListNode//循环链表结点类定义
{
	T data;
	CircListNode<T>* link;
	CircListNode(CircListNode<T>* next=NULL):link(next){}
	CircListNode(T d, CircListNode<T>* next = NULL):data(d),link(next){}
};

template<class T>
class CircList
{
public:
	CircList(const T& x);//构造函数
	CircList(CircList<T>& L);//复制构造函数
	~CircList();//析构函数
	int length()const;//计算表长
	bool IsEmpty() { return first->link == first ? true : false; }
	CircListNode<T>* getHead()const { return first; }//返回附加头结点地址
	CircListNode<T>* getRear()const { return last; }//返回尾指针
	//void setHead(CircListNode<T>* p);//设置附加头结点地址
	CircListNode<T>* Search(T x);//搜索含数据x的元素
	CircListNode<T>* Locate(int i);//搜索第i个元素的地址
	bool getData(int i,T& x);//取出第i个元素的值
	void setData(int i, T& x);//设置第i个元素的值
	bool Insert(int i, T& x);//在第i个元素后插入x
	bool Remove(int i, T& x);//删除第个元素，并通过x返回被删元素的值
private:
	CircListNode<T>* first, * last;//头指针、尾指针
};

template<class T>
CircList<T>::CircList(const T& x)//构造函数
{
	first = new CircListNode<T>;//first指向附加头结点
	last = first;
	last->link = first;//尾指针last指向附加头结点
};

template<class T>
CircList<T>::CircList(CircList<T>& L)//复制构造函数
{
	T value;
	CircListNode<T>* srcptr = L.getHead;
	CircListNode<T>* desptr = first = last = new CircListNode<T>;
	while (srcptr->link != first)//判断条件，逐个结点复制
	{
		value = srcptr->link->data;
		desptr->link = new CircListNode<T>(value);
		last = desptr->link;last->link = first;//设置尾指针

		desptr = desptr->link;
		srcptr = srcptr->link;
	}
};

template<class T>
CircList<T>::~CircList()//析构函数，置链表为空表
{
	CircListNode<T> *q=NULL;
	while (first->link != first)//链不空时，删掉所有结点
	{
		if (q == NULL) break;//尾指针指向附加头结点
		q = first->link;
		first->link = q->link;//从链删摘下被删结点
		delete q;
	}
	last = first;last->link = first;//设置尾指针
}

template<class T>
int CircList<T>::length()const//计算带头结点循环链表的长度
{
	CircListNode<T>* p = first->link;int count = 0;
	while (p != first)
	{		
		p = p->link;
		count++;
	}
	return count;
}

template<class T>
CircListNode<T>* CircList<T> ::Search(T x)//搜索含数据x的元素，成功时返回该结点的地址
{
	CircListNode<T>* current = first->link;//检测指针
	while (current != first)//循链找含x结点
	{
		if (current->data == x) break;
		else current = current->link;
	}
	return current;
}

template<class T>
CircListNode<T>* CircList<T> ::Locate(int i)//返回表中第i个元素的地址
{
	if (i < 0) return NULL;
	CircListNode<T>* current = first->link;int k = 1;
	while (current != first && k < i)//循链找第i个结点,注意循环条件的改变
	{
		current = current->link;
		k++;
	}
	return current;
};
/*
template<class T>
T& CircList<T> ::getData(int i)//取出链表第i个元素的值
{
	int x;
	if (i < 0) return;//i太小
	CircListNode<T>* current = Locate(i);
	if (current == NULL) return;//i太大
	else { x = current->data; return x;}
}
*/

template<class T>
bool CircList<T> ::getData(int i,T& x)//取出链表第i个元素的值
{
	if (i < 0) return false;//i太小
	CircListNode<T>* current = Locate(i);
	if (current == NULL) return true;//i太大
	else { x = current->data; return x; }
}

template<class T>
void CircList<T> ::setData(int i, T& x)//给链表中第i个元素复制x
{
	if (i < 0) return;//i太小
	CircListNode<T>* current = Locate(i);
	if (current == NULL) return;//i太大
	else current->data = x;
};

template<class T>
bool CircList<T> ::Insert(int i, T& x)//新元素x插入到第i个元素后
{
	CircListNode<T>* current = Locate(i);
	if (current == NULL) return false;//插入不成功
	CircListNode<T>* newNode = new CircListNode<T>(x);
	if (newNode == NULL) { cerr << "存储分配错误！\n";exit(1); }

	newNode->link = current->link;//链接在current之后,操作是统一的
	current->link = newNode;

	last = Locate(length());//调整尾指针
	last->link = first;
	return true;
}

template<class T>
bool CircList<T> ::Remove(int i, T& x)//将链表第i个元素删去，并通过x返回被删元素的值
{
	CircListNode<T>* current = Locate(i-1);//定位被删元素的前一结点
	if (current == NULL && current->link == first) return false;
	CircListNode<T>* del = current->link;//重新拉链，将结点从链上摘下
	current->link = del->link;
	x = del->data;delete del;//取值
	return true;
}