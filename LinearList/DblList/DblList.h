#pragma once
#include<iostream>
using namespace std;
typedef int T;

template<class T>
struct DblNode//����ڵ��ඨ��
{
	T data;//������
	DblNode<T> *lLink, * rLink;//����������ָ��
	DblNode(DblNode<T>* left = NULL, DblNode<T>* right = NULL):lLink(left), rLink(right){};//���캯��
	DblNode(T value, DblNode<T>* left = NULL, DblNode<T>* right = NULL) :data(value), lLink(left), rLink(right) {}
};

template<class T>
class DblList
{
public:
	DblList(T uniqueVal);//���캯��
	~DblList();//��������
	int length()const;//����˫������
	bool IsEmpty() { return first->rLink == first; }//�շ�
	DblNode<T>* getHead()const { return first; }//ȡ����ͷ����ַ
	void setHead(DblNode<T>* ptr) { first = ptr; }//���ø���ͷ����ַ
	DblNode<T> *Search(const T& x);//�غ�̷���Ѱ�ҵ���x�Ľ��
	DblNode<T>* Locate(int i, int d);//��λ���Ϊi��>=0���Ľ�㣬d=0��ǰ������d��Ϊ0����������
	bool Insert(int i, T& x, int d);//�ڵ�i��������뺬x���½�㣬d=0��ǰ������
	bool Remove(int i, T& x, int d);//ɾ����i����㣬d=0��ǰ������
private:
	DblNode<T>* first;//ͷָ��
};

template<class T>
DblList<T>::DblList(T uniqueVal)//���캯��������˫����ĸ���ͷ���
{
	first = new DblNode<T>(uniqueVal);
	if (first == NULL) { cerr << "�洢�������\n";exit(1); }
	first->rLink = first->rLink = first;
};

template<class T>
DblList<T>::~DblList()
{
	DblNode<T>* q = NULL;
	while (first->rLink != first)//������ʱ��ɾ�����н��
	{
		q = first->rLink;
		first->rLink = q->rLink;//����ɾժ�±�ɾ���
		delete q;
	}
	first->rLink = first->rLink = first;//����βָ��
}

template<class T>
int DblList<T>::length()const//��ͷ���˫������
{
	DblNode<T>* current = first->rLink;int count = 0;
	while (current != first) { current = current->rLink;count++; }
	return count;
}

template<class T>
DblNode<T>* DblList<T> ::Search(const T& x)//����̷���������x�Ľ��
{
	DblNode<T>* current = first->rLink;
	while (current != first && current->data != x) current = current->rLink;
	if (current != first) return current;//�����ɹ�
	else return NULL;
}

template<class T>
DblNode<T>* DblList<T> ::Locate(int i, int d)//d=0ǰ������
{
	if (first->rLink == first || i == 1) return first;
	DblNode<T>* current=first;
	if (d == 0) current = current->lLink;//��������
	else current = current->rLink;
	for (int j = 1;j < i;j++)//��������
	{
		if (current == first) break;//��̫��
		if (d == 0) current = current->lLink;
		else current = current->rLink;
	}
	if (current != first) return current;//�����ɹ�
	else return NULL;
}

template<class T>
bool DblList<T> ::Insert(int i, T& x, int d)
{
	DblNode<T>* current = Locate(i, d);//���ҵ�i�����
	if (current == NULL) return false;//i������
	DblNode<T>* newNode = new DblNode<T>(x);
	if (newNode == NULL) { cerr << "�洢�������\n";exit(1); }
	if (d == 0)//ǰ���������
	{
		newNode->lLink = current->lLink;
		current->lLink = newNode;
		newNode->lLink->rLink = newNode;
		newNode->rLink = current;
	}
	else//��̷������
	{
		newNode->rLink = current->rLink;
		current->rLink = newNode;
		newNode->rLink->lLink = newNode;
		newNode->lLink = current;
	}
	return true;
};

template<class T>
bool DblList<T> ::Remove(int i, T& x, int d)//������ͷ����˫������d��ָ����ɾ����i�����
{
	DblNode<T>* current = Locate(i, d);//���ҵ�i�����
	if (current == NULL) return false;
	current->rLink->lLink = current->lLink;//��lLink����ժ��
	current->lLink->rLink = current->rLink;//��rLink����ժ��
	x = current->data;delete current;//ɾ��
	return true;
};