﻿#include"List.h"
List<T> A;

void insert(List<T>& L)
{
	int i;T val;
	cout << "请输入要在第几个元素后插入及元素值：\n";
	cin >> i >> val;
	L.Insert(i, val);
	cout << "*插入元素"<<val<<"成功！*\n";
}

void remove(List<T>& L)
{
	int i;T val;
	cout << "请输入要删除第几个元素：\n";
	cin >> i;
	L.Remove(i, val);
	cout << "*删除元素"<<val<<"成功！*\n";
}

void search(List<T>& L)
{
	T val;
	LinkNode<T>* p;
	cout << "请输入要搜索的元素：\n";
	cin >> val;
	p=L.Search(val);
	cout << p->data << endl;
}


void menu()
{
	while (1)
	{
		cout << "\t\t\t\t**************带头结点的单链表***********" << endl
			<< "\t\t\t\t*\t\t1、输出\t\t\t*" << endl
			<< "\t\t\t\t*\t\t2、建立单链表（前插法）\t*" << endl
			<< "\t\t\t\t*\t\t3、建立单链表（后插法）\t*" << endl
			<< "\t\t\t\t*\t\t4、插入\t\t\t*" << endl
			<< "\t\t\t\t*\t\t5、删除\t\t\t*" << endl
			<< "\t\t\t\t*\t\t6、搜索\t\t\t*" << endl
			<< "\t\t\t\t*\t\t7、排序\t\t\t*" << endl
			<< "\t\t\t\t*\t\t0、退出\t\t\t*" << endl
			<< "\t\t\t\t*****************************************" << endl;
		char cho;
		cout << "*请输入选择：*" << endl;
		cin>>cho;
		switch (cho)
		{
		case'1':
			cout << "\t\t\t\t**************输出***************" << endl;			
			A.output();
			break;
		case'2':
			cout << "\t\t\t\t**************建立单链表（前插法）***********" << endl;
			A.inputFront(0);
			break;
		case'3':
			cout << "\t\t\t\t**************建立单链表（后插法）***********" << endl;
			A.inputRear(0);
			break;
		case'4':
			cout << "\t\t\t\t**************插入***************" << endl;
			insert(A);
			break;
		case'5':
			cout << "\t\t\t\t**************删除***************" << endl;
			remove(A);
			break;
		case'6':
			cout << "\t\t\t\t**************搜索***************" << endl;
			search(A);
			break;
		case'7':
			cout << "\t\t\t\t**************排序***************" << endl;
			A.Sort();
			break;
		case'0':
			cout << "*谢谢使用！\n*" << endl;
			exit(0);
		default:
			cout << "*这都能输错？宁可走点心吧！！*" << endl << endl;
		}
	}
}


int main()
{
	menu();
}