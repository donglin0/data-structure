#pragma once
#include<iostream>
using namespace std;
typedef int T;

template<class T>
struct LinkNode {
	T data;//������
	LinkNode<T>* link;//ָ����
	LinkNode(LinkNode<T>* ptr = NULL) { link = ptr; }//���캯��
	LinkNode(const T& item, LinkNode<T>* ptr = NULL){data = item;link = ptr;}
};

template<class T>
class List//�������ඨ��
{
public:
	List() { first = new LinkNode<T>; }//���캯��
	List(const T& x) { first = new LinkNode<T>(x); }//���������캯��
	List(List<T>& L);//���ƹ��캯��
	~List() { makeEmpty(); }//��������
	void makeEmpty();//������Ϊ�ձ�
	int length()const;//����������
	LinkNode<T>* getHead()const { return first; }//���ظ���ͷ����ַ
	LinkNode<T>* Search(T x);//����������x��Ԫ��
	LinkNode<T>* Locate(int i);//������i��Ԫ�صĵ�ַ
	bool getData(int i, T& x)const;//ȡ����i��Ԫ�ص�ֵ
	void setData(int i, T& x);//��x�޸ĵ�i��Ԫ�ص�ֵ
	bool Insert(int i, T& x);//����
	bool Remove(int i, T& x);//ɾ��
	bool IsEmpty()const { return first->link == NULL ? true : false; }
	void Sort();//����
	void inputFront(T endTag);//ǰ�巨����
	void inputRear(T endTag);//��巨����
	void output();//���
	List<T>& operator=(List<T>& L);//���غ�������ֵ
private:
	LinkNode<T>* first;//�����ͷָ��
};


template<class T>
List<T>::List(List<T>& L)
{
	T value;
	LinkNode<T>* srcptr = L.getHead;//�����Ʊ�ĸ���ͷ����ַ
	LinkNode<T>* desptr = first = new LinkNode<T>;
	while (srcptr->link != NULL)//�����㸴��
	{
		value = srcptr->link->data;
		desptr->link = new LinkNode<T>(value);
		srcptr = srcptr->link;
		desptr = desptr->link;
	}
	desptr->link = NULL;//���һ�����
};

template<class T>
void List<T>::makeEmpty()//��������Ϊ�ձ�
{
	LinkNode<T>* q;
	while (first->link != NULL)//����Ϊ�գ�ɾ���������н��
	{
		q = first->link;
		first->link = q->link;//������ժ�±�ɾ���
		delete q;//ɾ����������һ����ͷ��㣩
	}
};

template<class T>
int List<T>::length()const
{
	LinkNode<T>* p = first->link;int count = 0;//p���ָ�룬count����
	while (p != NULL)//ѭ��ɨ��Ѱ����β
	{
		p = p->link;count++;
	}
	return count;
};

template<class T>
LinkNode<T>* List<T>::Search(T x)
//��������x�Ľ�㣬�����ظý��ĵ�ַ
{
	LinkNode<T>* current = first->link;
	while (current != NULL)
	{
		if (current->data == x) break;//ѭ���Һ�x���
		else current = current->link;
	}
	return current;
};

template<class T>
LinkNode<T>* List<T>::Locate(int i)//��λ���������ر��е�i��Ԫ�صĵ�ַ��i�������򷵻�NULL
{
	if (i < 0) return NULL;//i������
	LinkNode<T>* current = first;int k = 0;
	while (current != NULL && k < i)//ѭ���ҵ�i�����
	{
		current = current->link;
		k++;
	}
	return current;//���ص�i������ַ
};

template<class T>
bool List<T>::getData(int i, T& x)const//ȡ�������е�i��Ԫ�ص�ֵ
{
	if (i <= 0) return NULL;//iֵ̫С
	LinkNode<T>* current = Locate(i);
	if (current == NULL) return false;//iֵ̫��
	else { x = current->data;return true; }
};

template<class T>
void List<T>::setData(int i, T& x)
{
	if (i <= 0) return;//iֵ̫С
	LinkNode<T>* current = Locate(i);
	if (current == NULL) return;//iֵ̫��
	else current->data = x;
};

template<class T>
bool List<T>::Insert(int i, T& x)//��Ԫ��x���뵽��i�����֮��
{
	LinkNode<T>* current = Locate(i);
	if (current == NULL) return false;//���벻�ɹ�
	LinkNode<T>* newNode = new LinkNode<T>(x);
	if (newNode == NULL) { cerr << "�洢�������\n";exit(1); }
	newNode->link = current->link;//������current֮��
	current->link = newNode;
	return true;
}

template<class T>
bool List<T>::Remove(int i, T& x)//�����е�i��Ԫ��ɾȥ��ͨ����Ԫ�ط��ظ�Ԫ�ص�ֵ
{
	LinkNode<T>* current = Locate(i - 1);//ɾ��������Ҫ֪����ɾ����ǰһ���
	if (current == NULL || current->link == NULL) return false;//ɾ�����ɹ�
	LinkNode<T>* del = current->link;//��������������ɾ��������ժ��
	current->link = del->link;
	x = del->data;delete del;//ȡ������ֵ
	return true;
};

template<class T>
void List<T>::output()//�������߼�˳���������Ļ��
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
void List<T> ::inputFront(T endTag)//ǰ�巨����������engTag���������еĽ�����־
{
	LinkNode<T>* newNode;T val;
	makeEmpty();
	cout << "������Ҫ�����Ԫ�أ�\n";
	cin >> val;
	while (val != endTag)
	{
		newNode = new LinkNode<T>(val);//�����½��
		if (newNode == NULL) { cerr << "�洢�������\n"; exit(1); }
		newNode->link = first->link;
		first->link = newNode;//���뵽���ǰ��
		cin >> val;
	}
};

template<class T>
void List<T>::inputRear(T endTag)
{
	LinkNode<T>* newNode,*last;T val;
	makeEmpty();
	cout << "������Ҫ�����Ԫ�أ�\n";
	cin >> val;
	last = first;
	while (val != endTag)//lastָ���β
	{
		newNode = new LinkNode<T>(val);//�����½��
		if (newNode == NULL) { cerr << "�洢�������\n"; exit(1); }
		last->link = newNode;last = newNode;//���뵽��ĩ��
		cin >> val;
	}
	last->link = NULL;//����β����ʡ��
}

template<class T>
List<T>& List<T>::operator=(List<T>& L)
//��ֵ������A=B��A�ǵ��ô˲�����List����B��ʵ��
{
	T value;
	LinkNode<T>* srcptr = L.getHead();//�����Ʊ�ĸ���ͷ����ַ
	LinkNode<T>* desptr = first = new LinkNode<T>;
	while (srcptr->link != NULL)//�����㸴��
	{
		value = srcptr->link->data;
		desptr->link = new LinkNode<T>(value);
		desptr = desptr->link;
		srcptr = srcptr->link;
	}
	desptr->link = NULL;
	return *this;//���ز��������ַ
};

void List<T>::Sort()//ð������
{
	int len = length();
	if (len == 0) return;
	int i, j;T tem;
	LinkNode<T>* current = getHead();
	for (i = 0; i < len-1; i++)
	{
		current = getHead()->link;//ÿ��ѭ����Ҫ��ͷ���һ������
		for (j = 0;j < len - 1 - i;j++)//i��ʾ�Ѿ�������ɵ�Ԫ����
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
	cout << "*����ɹ���*\n";
}