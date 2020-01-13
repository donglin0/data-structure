#pragma once
#include<iostream>
using namespace std;
typedef int T;

template<class T>
struct LinkNode {
	T data;//数据域
	LinkNode<T>* link;//指针域
	LinkNode(LinkNode<T>* ptr = NULL) { link = ptr; }//构造函数
	LinkNode(const T& item, LinkNode<T>* ptr = NULL){data = item;link = ptr;}
};

template<class T>
class List//单链表类定义
{
public:
	List() { first = new LinkNode<T>; }//构造函数
	List(const T& x) { first = new LinkNode<T>(x); }//带参数构造函数
	List(List<T>& L);//复制构造函数
	~List() { makeEmpty(); }//析构函数
	void makeEmpty();//链表置为空表
	int length()const;//计算链表长度
	LinkNode<T>* getHead()const { return first; }//返回附加头结点地址
	LinkNode<T>* Search(T x);//搜索含数据x的元素
	LinkNode<T>* Locate(int i);//搜索第i个元素的地址
	bool getData(int i, T& x)const;//取出第i个元素的值
	void setData(int i, T& x);//用x修改第i个元素的值
	bool Insert(int i, T& x);//插入
	bool Remove(int i, T& x);//删除
	bool IsEmpty()const { return first->link == NULL ? true : false; }
	void Sort();//排序
	void inputFront(T endTag);//前插法输入
	void inputRear(T endTag);//后插法输入
	void output();//输出
	List<T>& operator=(List<T>& L);//重载函数：赋值
private:
	LinkNode<T>* first;//链表的头指针
};


template<class T>
List<T>::List(List<T>& L)
{
	T value;
	LinkNode<T>* srcptr = L.getHead;//被复制表的附加头结点地址
	LinkNode<T>* desptr = first = new LinkNode<T>;
	while (srcptr->link != NULL)//逐个结点复制
	{
		value = srcptr->link->data;
		desptr->link = new LinkNode<T>(value);
		srcptr = srcptr->link;
		desptr = desptr->link;
	}
	desptr->link = NULL;//最后一个结点
};

template<class T>
void List<T>::makeEmpty()//将链表置为空表
{
	LinkNode<T>* q;
	while (first->link != NULL)//链不为空，删除链中所有结点
	{
		q = first->link;
		first->link = q->link;//从链上摘下被删结点
		delete q;//删除（仅保存一个表头结点）
	}
};

template<class T>
int List<T>::length()const
{
	LinkNode<T>* p = first->link;int count = 0;//p检测指针，count计数
	while (p != NULL)//循环扫描寻找链尾
	{
		p = p->link;count++;
	}
	return count;
};

template<class T>
LinkNode<T>* List<T>::Search(T x)
//搜索含有x的结点，并返回该结点的地址
{
	LinkNode<T>* current = first->link;
	while (current != NULL)
	{
		if (current->data == x) break;//循链找含x结点
		else current = current->link;
	}
	return current;
};

template<class T>
LinkNode<T>* List<T>::Locate(int i)//定位函数。返回表中第i个元素的地址，i不合理则返回NULL
{
	if (i < 0) return NULL;//i不合理
	LinkNode<T>* current = first;int k = 0;
	while (current != NULL && k < i)//循链找第i个结点
	{
		current = current->link;
		k++;
	}
	return current;//返回第i个结点地址
};

template<class T>
bool List<T>::getData(int i, T& x)const//取出链表中第i个元素的值
{
	if (i <= 0) return NULL;//i值太小
	LinkNode<T>* current = Locate(i);
	if (current == NULL) return false;//i值太大
	else { x = current->data;return true; }
};

template<class T>
void List<T>::setData(int i, T& x)
{
	if (i <= 0) return;//i值太小
	LinkNode<T>* current = Locate(i);
	if (current == NULL) return;//i值太大
	else current->data = x;
};

template<class T>
bool List<T>::Insert(int i, T& x)//新元素x插入到第i个结点之后
{
	LinkNode<T>* current = Locate(i);
	if (current == NULL) return false;//插入不成功
	LinkNode<T>* newNode = new LinkNode<T>(x);
	if (newNode == NULL) { cerr << "存储分配错误！\n";exit(1); }
	newNode->link = current->link;//链接在current之后
	current->link = newNode;
	return true;
}

template<class T>
bool List<T>::Remove(int i, T& x)//链表中第i个元素删去，通过该元素返回该元素的值
{
	LinkNode<T>* current = Locate(i - 1);//删除结点必须要知道被删结点的前一结点
	if (current == NULL || current->link == NULL) return false;//删除不成功
	LinkNode<T>* del = current->link;//重新拉链，将被删结点从链中摘下
	current->link = del->link;
	x = del->data;delete del;//取出数据值
	return true;
};

template<class T>
void List<T>::output()//单链表按逻辑顺序输出到屏幕上
{
	LinkNode<T>* current = first->link;
	while (current != NULL)
	{
		cout << current->data << " ";
		current = current->link;
	}
	cout << endl;
};

template<class T>
void List<T> ::inputFront(T endTag)//前插法建立单链表，engTag是输入序列的结束标志
{
	LinkNode<T>* newNode;T val;
	makeEmpty();
	cout << "请输入要插入的元素：\n";
	cin >> val;
	while (val != endTag)
	{
		newNode = new LinkNode<T>(val);//创建新结点
		if (newNode == NULL) { cerr << "存储分配错误！\n"; exit(1); }
		newNode->link = first->link;
		first->link = newNode;//插入到表的前端
		cin >> val;
	}
};

template<class T>
void List<T>::inputRear(T endTag)
{
	LinkNode<T>* newNode,*last;T val;
	makeEmpty();
	cout << "请输入要插入的元素：\n";
	cin >> val;
	last = first;
	while (val != endTag)//last指向表尾
	{
		newNode = new LinkNode<T>(val);//创建新结点
		if (newNode == NULL) { cerr << "存储分配错误！\n"; exit(1); }
		last->link = newNode;last = newNode;//插入到表末端
		cin >> val;
	}
	last->link = NULL;//表收尾，可省略
}

template<class T>
List<T>& List<T>::operator=(List<T>& L)
//赋值操作：A=B，A是调用此操作的List对象，B是实参
{
	T value;
	LinkNode<T>* srcptr = L.getHead();//被复制表的附加头结点地址
	LinkNode<T>* desptr = first = new LinkNode<T>;
	while (srcptr->link != NULL)//逐个结点复制
	{
		value = srcptr->link->data;
		desptr->link = new LinkNode<T>(value);
		desptr = desptr->link;
		srcptr = srcptr->link;
	}
	desptr->link = NULL;
	return *this;//返回操作对象地址
};

void List<T>::Sort()//冒泡排序
{
	int len = length();
	if (len == 0) return;
	int i, j;T tem;
	LinkNode<T>* current = getHead();
	for (i = 0; i < len-1; i++)
	{
		current = getHead()->link;//每次循环都要从头检测一遍链表
		for (j = 0;j < len - 1 - i;j++)//i表示已经排序完成的元素数
		{
			if (current->data > current->link->data)
			{
				tem = current->data;
				current->data = current->link->data;
				current->link->data = tem;
			}
			current = current->link;
		}
	}
	cout << "*排序成功！*\n";
}