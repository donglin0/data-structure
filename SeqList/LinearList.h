#pragma once
template <class T>
class LinearList {
public:
	LinearList(); //构造函数
	～LinearList(); //析构函数
	virtual int Size() const = 0; //求表最大体积
	virtual int Length() const = 0; //求表长度
	virtual int Search(T& x) const = 0; //搜索
	virtual int Locate(int i) const = 0; //定位
	virtual bool getData(int i, T& x) const = 0; //取值
	virtual void setData(int i, T& x) = 0; //赋值
	virtual bool Insert(int i, T& x) = 0; //插入
	virtual bool Remove(int i, T& x) = 0; //删除
	virtual bool IsEmpty() const = 0; //判表空
	virtual bool IsFull() const = 0; //判表满
	virtual void Sort() = 0； //排序
	virtual void input() = 0； //输入
	virtual void output() = 0； //输出
	virtual LinearList<T>operator=(LinearList<T> & L) = 0; //复制
};