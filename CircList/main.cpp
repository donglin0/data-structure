#include"CircList.h"
#include"Josephus.h"

int main()
{
	cout << "循环链表！\n";
	CircList<T> clist(-3);
	int i, m, n;
	cout << "输入游戏者人数和报数间隔：";
	cin >> n >> m;
	for (i = 1;i <= n;i++)
		clist.Insert(i-1,i);//形成约瑟夫环
	Josephus(clist, n, m);//解决约瑟夫问题

}