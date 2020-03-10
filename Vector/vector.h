// vector.h

#pragma once

#define DEFAULT_CAPACITY 10//默认初始容量
typedef int Rank;//向量的秩

template <typename T>
class Vector {
	private:
	//属性
		int _size;//元素个数（最后一个元素的秩加1）
		int _capacity;//容量（最多容纳元素数目）
		T* _elem;//数据域指针

	protected:
	//内部函数
		void copyFrom(T const*,Rank,Rank);
		void expand();
		void shrink();

	public:
	//构造和析构
		Vector(int maxsize=DEFAULT_CAPACITY);
		Vector(T const*,Rank,Rank);
		Vector(Vector<T> const&,Rank,Rank);
		Vector(Vector<T> const&);
		~Vector();
	
	//接口函数
		int size();//返回元素数目
		T get(Rank);//获取指定秩的元素值
		void put(Rank,T const&);//替换指定秩的元素值
		Rank insert(Rank,T const&);//插入
		int remove(Rank,Rank);//区间删除
		T remove(Rank);//单一元素删除
		Rank find(T const&,Rank lo,Rank hi);//区间查找
		Rank find(T const&);//整体查找
		Rank binSearch(T const&,Rank lo,Rank hi);//二分查找（区间）
		Rank binSearch(T const&);//二分查找（整体）
		void traverse(void (*)(T &));//遍历
		void sort();//起泡排序
		int disordered();//查询无序度
		int deduplicate();//无序向量唯一化
		int uniquify();//有序向量唯一化

	//运算符重载
		T& operator[](Rank);
};