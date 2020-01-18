#pragma once

/*
#define maxSize 100
typedef struct {//˳���ľ�̬�洢��ʾ
	T data[maxSize];
	int n;
}SeqList;


typedef struct {//˳���Ķ�̬�洢��ʾ
	T* data;
	int maxSize, n;
}SeqList;

*/
typedef int T;
#include<iostream>
#include<stdlib.h>
using namespace std;
const int defaultSize = 100;
template<class T>
class SeqList {
protected:
	T* data;//�������
	int maxSize;//�������ɱ��������
	int last;//��ǰ��������λ�ã���0��ʼ��
	void reSize(int newSize);//�ı�data����ռ��С
public:
	SeqList(int sz = defaultSize);
	SeqList(SeqList<T>& L);//���ƹ��캯��
	~SeqList() { delete[] data; }//��������
	int Size()const { return maxSize; };//�������ɱ���
	int Length()const { return last + 1; };//���� 
	int Search(T& x)const;//����x�ڱ���λ�ã����ر������
	int Locate(int i)const;//��λ��i��������ر������
	bool getData(int i, T& x)const//ȡ��i�������ֵ
	{
		if (i > 0 && i <= last + 1) { x = data[i - 1];return true; }
		else return false;
	}
	void setData(int i, T& x)//�޸ĵ�i�������ֵ
	{
		if (i > 0 && i <= last + 1) data[i - 1] = x;
	}
	bool Insert(int i, T& x);//�����ڵ�i������֮��
	bool Remove(int i, T& x);//ɾ����i�����ͨ��x���ر����ֵ
	bool IsEmpty() { return (last == maxSize - 1) ? true : false; }//�жϱ��
	bool IsFull() { return (last == -1) ? true : false; }//�жϱ���
	void input();//���� 
	void output();//���
	//SeqList<T> operater = (SeqList<T> & L);//�����帳ֵ
};

template<class T>
SeqList<T>::SeqList(int sz)//ͨ������sz�������鳤��
{
	if (sz > 0) {
		maxSize = sz;
		last = -1;//�ñ��ʵ�ʳ���Ϊ��
		data = new T[maxSize];//����˳���洢����
		if (data == NULL)
		{
			cout << "�洢�������" << endl;exit(1);
		}
	}
}

template<class T>
SeqList<T>::SeqList(SeqList<T>& L)//���ƹ��캯��
{
	maxSize = L.maxSize;
	last = L.Length() - 1;
	T value;
	data = new T[maxSize];
	if (data == NULL)
	{
		cout << "�洢�������" << endl;exit(1);
	}
	for (int i = 0;i < last + 1;i++)
	{
		L.getData(i, value);//ȡ��i�������ֵ
		data[i - 1] = value;
	}
}

template<class T>
void SeqList<T>::reSize(int newSize)//����˳��������ռ��С��������Ԫ�ظ���Ϊmaxsize
{
	if (newSize < 0)
	{
		cout << "��Ч�������С" << endl;return;
	}
	if (newSize != maxSize)//�޸�
	{
		T* newarry = new T[newSize];//����������
		if (newarry == NULL)
		{
			cout << "�洢�������" << endl;exit(1);
		}
		int n = last + 1;
		T* srcptr = data;//Դ�����׵�ַ
		T* desptr = newarry;//Ŀ�������׵�ַ
		while (n--)//����
		{
			*desptr++ = *srcptr++;//��ӦԪ�ظ���
		}
		delete[] data;//ɾ��������
		data = newarry;maxSize = newSize;//����������
	}
}

template<class T>
int SeqList<T>::Search(T& x)const//�����붨��xƥ��ı�����ҵ��ⷵ�ظñ����ǵڼ���Ԫ��
{
	for (int i = 0;i <= last;i++)
	{
		if (data[i] == x)return i + 1;//˳������
	}
	return 0;
}

template<class T>
int SeqList<T>::Locate(int i)const//��λ���������ص�i�������λ��
{
	if (i > 0 && i <= last + 1) return i;
	else return 0;
}

template<class T>
bool SeqList<T>::Insert(int i, T& x)
//��Ԫ��x���뵽��i��0<=i<=last+1��������֮��i=0��ָ���ڵ�һԪ��λ��
{
	if (last == maxSize - 1) return false;//full
	if (i<0 || i>last + 1) return false;//����i������
	for (int j = last;j >= i;j--) data[j + 1] = data[j];//���κ��ƣ��ճ���i��λ��
	data[i] = x;//���뵽��i+1λ�ã��ź�λ��
	last++;//���λ�ü�1
	return true;
}

template<class T>
bool SeqList<T>::Remove(int i, T& x)
//�ӱ���ɾ����i��1<=i<=last+1���������ͨ������x���ر�ɾ��Ԫ��ֵ
{
	if (last == maxSize - 1) return false;//full
	if (i<0 || i>last + 1) return false;//����i������
	x = data[i - 1];//�屻ɾԪ��ֵ
	for (int j = i;j <= last + 1;j++)
		data[j - 1] = data[j];//����ǰ���
	last--;//���λ�ü�һ
	return true;
}

template<class T>
void SeqList<T>::input()//�Ӽ�������������ݽ���˳���
{
	cout << "������Ԫ�ظ�����" << endl;
	while (1) {
		cin >> last;//����Ԫ�����λ��
		last = last - 1;
		if (last <= maxSize - 1) break;
		cout << "Ԫ�ظ����������󣬷�Χ������" << maxSize - 1 << "!\n";
	}
	for (int i = 0;i <= last;i++)//�������Ԫ��ֵ
	{
		cin >> data[i];
	}
}

template<class T>
void SeqList<T>::output()
{
	cout << "����Ԫ�أ�" <<last+1<< endl;
	for (int i = 0;i <= last;i++)//������
		cout << "*" << i + 1 << ":" << data[i] << endl;
}