#include<iostream>
using namespace std;
//�Ǵ�ͷ��㵥����ò����ɾ���㷨
struct LinkNode//��������
{
	int data;
	LinkNode* link;
};

LinkNode* first=NULL;

bool Insert(int i, int& x)
//x���뵽��i�����֮��i=0��ʾ���ڵ�1�����֮ǰ
{
	if (first == NULL || i == 0)//����ձ��ǿձ�õ�һ�����ǰ
	{
		LinkNode* newNode = new LinkNode;//
		if (newNode == NULL) { cerr << "�洢�������\n";exit(1); }
		newNode->data = x;
		newNode->link = first;first = newNode;//�½���Ϊ��һ�����
	}
	else
	{
		LinkNode* current = first;//���ָ��ӵ�һ����㿪ʼ���
		for (int k = 1;k < i;k++)//ѭ���ҵ���i�����
			if (current == NULL)break;
			else current = current->link;
		if(current == NULL)//�ǿձ�����̫��
		{
			cerr << " ��Ч�Ĳ���λ�ã�/n";return false;
		}
		else//�����������м�
		{
			LinkNode* newNode = new LinkNode;
			if (newNode == NULL) { cerr << "�洢�������\n";exit(1); }
			newNode->data = x;
			newNode->link = current->link;
			current->link = newNode;
		}
	}
	return true;//��������
}

bool Remove(int i, int& x)
{
	LinkNode* del;
	LinkNode* current;//delΪָ��ɾ����ָ�룬currentΪ���ָ�롣
	if (i == 1)//ɾ����һ�����
	{
		del = first;first = first->link;
	}
	else
	{
		current = first;
		for (int k = 1;k < i - 1;k++)//ѭ���ҵ�i-1�����
			if (current == NULL) break;
			else current = current->link;
		if (current == NULL||current->link==NULL)//�ձ������̫��
		{
			cerr << " ��Ч�Ĳ���λ�ã�/n";return false;
		}
		del = current->link;//ɾ���м��β���ʱ����
		current->link = del->link;
	}
	x = del->data;delete del;//ȡ����ɾ��������ֵ
	return true;
}