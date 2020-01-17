#pragma once
#include"CircList.h"

template<class T>
void Josephus(CircList<T>& Js, int n, int m)
{
	CircListNode<T>* p = Js.Locate(1), * pre = Js.getHead();//初始时pre指向附加头结点
	int i, j;

	for (i = 0;i < n - 1;i++)//执行n-1次
	{
		for (j = 1;j < m;j++)//数m-1个数,j从1开始
		{	
			if (p == Js.getHead()) { pre = p;p = p->link; }
			pre = p;
			p = p->link;
			if (p == Js.getHead()) { pre = p;p = p->link; }
		}
		cout << "出列的人是：" << p->data << endl;//输出
		pre->link = p->link;delete p;//删除已输出的结点
		p = pre->link;
	}
};
