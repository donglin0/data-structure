#pragma once
#include"CircList.h"

template<class T>
void Josephus(CircList<T>& Js, int n, int m)
{
	CircListNode<T>* p = Js.Locate(1), * pre = NULL;
	int i, j;
	for (i = 0;i < n - 1;i++)//ִ��n-1��
	{
		for (j = 1;j < m;j++)//��m-1����,j��1��ʼ
		{	
			if (p == Js.getHead()) { pre = p;p = p->link; }
			pre = p;
			p = p->link;
			if (p == Js.getHead()) { pre = p;p = p->link; }
		}
		cout << "���е����ǣ�" << p->data << endl;//���
		pre->link = p->link;delete p;//ɾ��������Ľ��
		p = pre->link;
	}
};
