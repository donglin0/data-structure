#pragma once
#include<iostream>
using namespace std;
typedef int T;
const int maxSize = 100;//��̬�����С

template<class T>
struct SLinkNode 
{
	T data;//�������
	int link;//���ָ��
};

template<class T>
class StaticList
{
private:
	SLinkNode<T> elem[maxSize];
	int avil;//��ǰ�ɷ���ռ��׵�ַ
public:
	void InitList();//��ʼ��
	int Length();//���㾲̬������
	int Search(T x);//���Ҿ��и���ֵ�Ľ��
	int Locate(int i);//���ҵ�i�����
	bool Append(T x);//�ڱ�β����һ���½��
	bool Insert(int i, T x);//��i���������һ���½��
	bool Remove(int i);//�ͷŵ�i�����
	bool IsEmpty();//��շ�
};

template<class T>
void StaticList<T>::InitList()//����ռ��ʼ��
{
	elem[0].link = -1;avil = 1;//��ǰ�ɷ���ռ��1��ʼ������ͷ���Ŀ�����
	for (int i = 1;i < maxSize - 1;i++) elem[i].link = i + 1;//���ɿ������ӱ�
	elem[maxSize - 1].link = -1;//������β
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
int StaticList<T> ::Locate(int i)//���ҵ�i�����λ��
{
	if (i < 0) return -1;
	if (i == 0) return 0;
	int j = 1, p = elem[0].link;
	while (p != -1 && j < i) { p = elem[p].link;j++; }//ѭ�����ҵ�i�Ž��
	return p;
};

template<class T>
bool StaticList<T> ::Append(T x)//��β׷���½��
{
	if (avil == -1) return false;
	int q = avil;
	avil = elem[avil].link;
	elem[q].data = x; elem[q].link = -1;
	int p = 0;
	while (elem[p].link != -1)  p = elem[p].link;//���ұ�β
	elem[p].link = q;//׷��
	return true;
};

template<class T>
bool StaticList<T> ::Insert(int i, T x)
{
	int p = Locate(i);
	if (p == -1) return false;
	int q = avil;//������
	avil = elem[q].link;
	elem[q].data = x;
	elem[q].link = elem[p].link;//����
	elem[p].link = q;
	return true;
};

template<class T>
bool StaticList<T> ::Remove(int i)
{
	int p = Locate(i - 1);//��ɾ���ǰһ���
	if (p == -1) return false;
	int q = elem[p].link;//��i�Ž��
	elem[p].link = elem[q].link;
	elem[q].link = avil;//�ͷţ��ý�������ж���
	avil = q;
	return true;
};