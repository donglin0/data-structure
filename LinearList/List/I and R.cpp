#include<iostream>
using namespace std;
//非带头结点单链表得插入和删除算法
struct LinkNode//链表结点类
{
	int data;
	LinkNode* link;
};

LinkNode* first=NULL;

bool Insert(int i, int& x)
//x插入到第i个结点之后，i=0表示插在第1个结点之前
{
	if (first == NULL || i == 0)//插入空表或非空表得第一个结点前
	{
		LinkNode* newNode = new LinkNode;//
		if (newNode == NULL) { cerr << "存储分配错误！\n";exit(1); }
		newNode->data = x;
		newNode->link = first;first = newNode;//新结点成为第一个结点
	}
	else
	{
		LinkNode* current = first;//检测指针从第一个结点开始检测
		for (int k = 1;k < i;k++)//循环找到第i个结点
			if (current == NULL)break;
			else current = current->link;
		if(current == NULL)//非空表但链表太短
		{
			cerr << " 无效的插入位置！/n";return false;
		}
		else//插入在链表中间
		{
			LinkNode* newNode = new LinkNode;
			if (newNode == NULL) { cerr << "存储分配错误！\n";exit(1); }
			newNode->data = x;
			newNode->link = current->link;
			current->link = newNode;
		}
	}
	return true;//正常插入
}

bool Remove(int i, int& x)
{
	LinkNode* del;
	LinkNode* current;//del为指向被删结点的指针，current为检测指针。
	if (i == 1)//删除第一个结点
	{
		del = first;first = first->link;
	}
	else
	{
		current = first;
		for (int k = 1;k < i - 1;k++)//循链找第i-1个结点
			if (current == NULL) break;
			else current = current->link;
		if (current == NULL||current->link==NULL)//空表或链表太短
		{
			cerr << " 无效的插入位置！/n";return false;
		}
		del = current->link;//删除中间或尾结点时拉链
		current->link = del->link;
	}
	x = del->data;delete del;//取出被删结点的数据值
	return true;
}