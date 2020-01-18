#include"SeqList.h"

void Union(SeqList<T>& LA, SeqList<T>& LB)//合并顺序表LA和LB，保存于LA中，去除重复元素 
{
    int n = LA.Length(), m = LB.Length(), i, k, x;
    for (i = 1;i <= m;i++)//i从1开始
    {
        LB.getData(i, x);//在LB中取一元素
        k = LA.Search(x);//在LA中搜索该元素
        if(k==0)//若不存在LA中这插入
        {
            LA.Insert(n, x);
            n++;//插入第n个表项之后
        }
    }
}

void Intersection(SeqList<T>& LA, SeqList<T>& LB)//求两顺序表得共有元素，并存于LA中
{
    int n = LA.Length(), m = LB.Length(), i = 1, k, x;
    while (i<=n)
    {
        LA.getData(i, x);//在LA中取一数据
        k = LB.Search(x);//在LB中搜索
        if (k == 0)//若不在LB中则删除
        {
            LA.Remove(i, x);
        }
        else
            i++;//存在，则继续检验下一元素
    }
}





int main()
{
    SeqList<T> A(20);
    SeqList<T> B(20);
    A.input();
    B.input();
    Union(A, B);
    A.output();
}
