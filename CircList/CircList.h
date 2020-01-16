#pragma once
#include<iostream>
using namespace std;
typedef int T;//��ģ��ʵ����

template<class T>
struct CircListNode//ѭ���������ඨ��
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
	CircList(const T& x);//���캯��
	CircList(CircList<T>& L);//���ƹ��캯��
	~CircList();//��������
	int length()const;//�����
	bool IsEmpty() { return first->link == first ? true : false; }
	CircListNode<T>* getHead()const { return first; }//���ظ���ͷ����ַ
	CircListNode<T>* getRear()const { return last; }//����βָ��
	//void setHead(CircListNode<T>* p);//���ø���ͷ����ַ
	CircListNode<T>* Search(T x);//����������x��Ԫ��
	CircListNode<T>* Locate(int i);//������i��Ԫ�صĵ�ַ
	bool getData(int i,T& x);//ȡ����i��Ԫ�ص�ֵ
	void setData(int i, T& x);//���õ�i��Ԫ�ص�ֵ
	bool Insert(int i, T& x);//�ڵ�i��Ԫ�غ����x
	bool Remove(int i, T& x);//ɾ���ڸ�Ԫ�أ���ͨ��x���ر�ɾԪ�ص�ֵ
private:
	CircListNode<T>* first, * last;//ͷָ�롢βָ��
};

template<class T>
CircList<T>::CircList(const T& x)//���캯��
{
	first = new CircListNode<T>;//firstָ�򸽼�ͷ���
	last = first;
	last->link = first;//βָ��lastָ�򸽼�ͷ���
};

template<class T>
CircList<T>::CircList(CircList<T>& L)//���ƹ��캯��
{
	T value;
	CircListNode<T>* srcptr = L.getHead;
	CircListNode<T>* desptr = first = last = new CircListNode<T>;
	while (srcptr->link != first)//�ж������������㸴��
	{
		value = srcptr->link->data;
		desptr->link = new CircListNode<T>(value);
		last = desptr->link;last->link = first;//����βָ��

		desptr = desptr->link;
		srcptr = srcptr->link;
	}
};

template<class T>
CircList<T>::~CircList()//����������������Ϊ�ձ�
{
	CircListNode<T> *q=NULL;
	while (first->link != first)//������ʱ��ɾ�����н��
	{
		if (q == NULL) break;//βָ��ָ�򸽼�ͷ���
		q = first->link;
		first->link = q->link;//����ɾժ�±�ɾ���
		delete q;
	}
	last = first;last->link = first;//����βָ��
}

template<class T>
int CircList<T>::length()const//�����ͷ���ѭ������ĳ���
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
CircListNode<T>* CircList<T> ::Search(T x)//����������x��Ԫ�أ��ɹ�ʱ���ظý��ĵ�ַ
{
	CircListNode<T>* current = first->link;//���ָ��
	while (current != first)//ѭ���Һ�x���
	{
		if (current->data == x) break;
		else current = current->link;
	}
	return current;
}

template<class T>
CircListNode<T>* CircList<T> ::Locate(int i)//���ر��е�i��Ԫ�صĵ�ַ
{
	if (i < 0) return NULL;
	CircListNode<T>* current = first->link;int k = 1;
	while (current != first && k < i)//ѭ���ҵ�i�����,ע��ѭ�������ĸı�
	{
		current = current->link;
		k++;
	}
	return current;
};
/*
template<class T>
T& CircList<T> ::getData(int i)//ȡ�������i��Ԫ�ص�ֵ
{
	int x;
	if (i < 0) return;//i̫С
	CircListNode<T>* current = Locate(i);
	if (current == NULL) return;//i̫��
	else { x = current->data; return x;}
}
*/

template<class T>
bool CircList<T> ::getData(int i,T& x)//ȡ�������i��Ԫ�ص�ֵ
{
	if (i < 0) return false;//i̫С
	CircListNode<T>* current = Locate(i);
	if (current == NULL) return true;//i̫��
	else { x = current->data; return x; }
}

template<class T>
void CircList<T> ::setData(int i, T& x)//�������е�i��Ԫ�ظ���x
{
	if (i < 0) return;//i̫С
	CircListNode<T>* current = Locate(i);
	if (current == NULL) return;//i̫��
	else current->data = x;
};

template<class T>
bool CircList<T> ::Insert(int i, T& x)//��Ԫ��x���뵽��i��Ԫ�غ�
{
	CircListNode<T>* current = Locate(i);
	if (current == NULL) return false;//���벻�ɹ�
	CircListNode<T>* newNode = new CircListNode<T>(x);
	if (newNode == NULL) { cerr << "�洢�������\n";exit(1); }

	newNode->link = current->link;//������current֮��,������ͳһ��
	current->link = newNode;

	last = Locate(length());//����βָ��
	last->link = first;
	return true;
}

template<class T>
bool CircList<T> ::Remove(int i, T& x)//�������i��Ԫ��ɾȥ����ͨ��x���ر�ɾԪ�ص�ֵ
{
	CircListNode<T>* current = Locate(i-1);//��λ��ɾԪ�ص�ǰһ���
	if (current == NULL && current->link == first) return false;
	CircListNode<T>* del = current->link;//��������������������ժ��
	current->link = del->link;
	x = del->data;delete del;//ȡֵ
	return true;
}