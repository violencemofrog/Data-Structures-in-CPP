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
		int size();
		T get(Rank);
		void put(Rank,T const&);
		Rank insert(Rank,T const&);
		int remove(Rank,Rank);
		T remove(Rank);
		Rank find(T const&,Rank,Rank);
		Rank find(T const&);
		void traverse(void (*)(T &));
		int deduplicate();

	//运算符重载
		T& operator[](Rank);
};