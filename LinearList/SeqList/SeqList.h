#pragma once

/*
#define maxSize 100
typedef struct {//顺序表的静态存储表示
	T data[maxSize];
	int n;
}SeqList;


typedef struct {//顺序表的动态存储表示
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
	T* data;//存放数组
	int maxSize;//最大可容纳表项的项数
	int last;//当前表项的最后位置（从0开始）
	void reSize(int newSize);//改变data数组空间大小
public:
	SeqList(int sz = defaultSize);
	SeqList(SeqList<T>& L);//复制构造函数
	~SeqList() { delete[] data; }//析构函数
	int Size()const { return maxSize; };//最大可容纳表项
	int Length()const { return last + 1; };//表长度 
	int Search(T& x)const;//搜索x在表中位置，返回表项序号
	int Locate(int i)const;//定位第i个表项，返回表项序号
	bool getData(int i, T& x)const//取第i个表项的值
	{
		if (i > 0 && i <= last + 1) { x = data[i - 1];return true; }
		else return false;
	}
	void setData(int i, T& x)//修改第i个表项的值
	{
		if (i > 0 && i <= last + 1) data[i - 1] = x;
	}
	bool Insert(int i, T& x);//插入在第i个表项之后
	bool Remove(int i, T& x);//删除第i个表项，通过x返回表项的值
	bool IsEmpty() { return (last == maxSize - 1) ? true : false; }//判断表空
	bool IsFull() { return (last == -1) ? true : false; }//判断表满
	void input();//输入 
	void output();//输出
	//SeqList<T> operater = (SeqList<T> & L);//表整体赋值
};

template<class T>
SeqList<T>::SeqList(int sz)//通过参数sz定义数组长度
{
	if (sz > 0) {
		maxSize = sz;
		last = -1;//置表的实际长度为空
		data = new T[maxSize];//创建顺序表存储数组
		if (data == NULL)
		{
			cout << "存储分配错误！" << endl;exit(1);
		}
	}
}

template<class T>
SeqList<T>::SeqList(SeqList<T>& L)//复制构造函数
{
	maxSize = L.maxSize;
	last = L.Length() - 1;
	T value;
	data = new T[maxSize];
	if (data == NULL)
	{
		cout << "存储分配错误！" << endl;exit(1);
	}
	for (int i = 0;i < last + 1;i++)
	{
		L.getData(i, value);//取第i个表项的值
		data[i - 1] = value;
	}
}

template<class T>
void SeqList<T>::reSize(int newSize)//扩充顺序表的数组空间大小，新数组元素个数为maxsize
{
	if (newSize < 0)
	{
		cout << "无效的数组大小" << endl;return;
	}
	if (newSize != maxSize)//修改
	{
		T* newarry = new T[newSize];//建立新数组
		if (newarry == NULL)
		{
			cout << "存储分配错误！" << endl;exit(1);
		}
		int n = last + 1;
		T* srcptr = data;//源数组首地址
		T* desptr = newarry;//目的数组首地址
		while (n--)//复制
		{
			*desptr++ = *srcptr++;//对应元素复制
		}
		delete[] data;//删除旧数组
		data = newarry;maxSize = newSize;//复制新数组
	}
}

template<class T>
int SeqList<T>::Search(T& x)const//搜索与定制x匹配的表项，若找到这返回该表项是第几个元素
{
	for (int i = 0;i <= last;i++)
	{
		if (data[i] == x)return i + 1;//顺序搜索
	}
	return 0;
}

template<class T>
int SeqList<T>::Locate(int i)const//定位函数，返回第i个表项的位置
{
	if (i > 0 && i <= last + 1) return i;
	else return 0;
}

template<class T>
bool SeqList<T>::Insert(int i, T& x)
//新元素x插入到第i（0<=i<=last+1）个表项之后。i=0是指插在第一元素位置
{
	if (last == maxSize - 1) return false;//full
	if (i<0 || i>last + 1) return false;//参数i不合理
	for (int j = last;j >= i;j--) data[j + 1] = data[j];//依次后移，空出第i号位置
	data[i] = x;//插入到第i+1位置，号和位置
	last++;//最后位置加1
	return true;
}

template<class T>
bool SeqList<T>::Remove(int i, T& x)
//从表中删除第i（1<=i<=last+1）各表项，并通过参数x返回被删除元素值
{
	if (last == maxSize - 1) return false;//full
	if (i<0 || i>last + 1) return false;//参数i不合理
	x = data[i - 1];//村被删元素值
	for (int j = i;j <= last + 1;j++)
		data[j - 1] = data[j];//依次前移填补
	last--;//最后位置减一
	return true;
}

template<class T>
void SeqList<T>::input()//从键盘这个输入数据建立顺序表
{
	cout << "请输入元素个数：" << endl;
	while (1) {
		cin >> last;//输入元素最后位置
		last = last - 1;
		if (last <= maxSize - 1) break;
		cout << "元素个数输入有误，范围不超过" << maxSize - 1 << "!\n";
	}
	for (int i = 0;i <= last;i++)//逐个输入元素值
	{
		cin >> data[i];
	}
}

template<class T>
void SeqList<T>::output()
{
	cout << "共有元素：" <<last+1<< endl;
	for (int i = 0;i <= last;i++)//逐个输出
		cout << "*" << i + 1 << ":" << data[i] << endl;
}