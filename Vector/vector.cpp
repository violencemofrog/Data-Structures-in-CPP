// vector.cpp

#include "vector.h"

//交换a，b的值
template <typename T>
static void swap(T& a,T& b) {
	T temp=a;
	a=b;
	b=temp;
}

//复制（从下标为lo的元素复制，直至下标为hi-1的元素）
template <typename T>
void Vector<T>::copyFrom(T const* Arr,Rank lo,Rank hi) {
	_size=0;
	_elem=new T[_capacity=2*(hi-lo)];
	while(lo<hi)
		_elem[_size++]=Arr[lo++];
}

//倍增式扩容
template <typename T>
void Vector<T>::expand() {
	if(_size<_capacity)
		return;
	else {
		_capacity=(DEFAULT_CAPACITY>_capacity)?DEFAULT_CAPACITY:_capacity;
		T* oldElem=_elem;//用oldElem暂指向原数组
		_elem=new T[_capacity*=2];//重新分配空间
		for(int ind=0;ind<_size;ind++)
			_elem[ind]=oldElem[ind];
		delete[] oldElem;
	}
}

//装填因子小于25%时缩容
template <typename T>
void Vector<T>::shrink() {
	if(_capacity<DEFAULT_CAPACITY*2)//不可缩容至默认容量之下
		return;
	if(_size*4>_capacity)
		return;
	else {
		T* oldElem=_elem;
		_elem=new T[_capacity/=2];//容量减半
		for(int ind=0;ind<_size;ind++)
			_elem[ind]=oldElem[ind];
		delete[] oldElem;
	}
}

//构造函数（默认）
template <typename T>
Vector<T>::Vector(int maxsize) {
	_size=0;//初始秩为0
	_elem=new T[_capacity=maxsize];
}

//构造函数（通过复制数组）
template <typename T>
Vector<T>::Vector(T const* Arr,Rank lo,Rank hi) {
	copyFrom(Arr,lo,hi);
}

//构造函数（通过向量复制）
template <typename T>
Vector<T>::Vector(Vector<T> const& Vec,Rank lo,Rank hi) {
	copyFrom(Vec._elem,lo,hi);
}

//复制函数
template <typename T>
Vector<T>::Vector(Vector<T> const& Vec) {
	copyFrom(Vec._elem,0,Vec._size);
}

//析构函数
template <typename T>
Vector<T>::~Vector() {
	if(!_elem)
		delete[] _elem;
}

//返回当前元素个数
template <typename T>
int Vector<T>::size() {
	return _size;
}

// 获取秩为r的元素的值
template <typename T>
T Vector<T>::get(Rank r) {
	return _elem[r];
}

//把秩为r的元素的值变为e
template <typename T>
void Vector<T>::put(Rank r,T const& e) {
	_elem[r]=e;
}

//在秩为r(0<=r<=VectorSize)处插入元素e（剩余元素后移）
template <typename T>
Rank Vector<T>::insert(Rank r,T const& e) {
	expand();
	for(int ind=_size;ind>r;ind--)
		_elem[ind]=_elem[ind-1];
	_elem[r]=e;
	_size+=1;
	return r;
}

//删除区间[lo,hi)间的元素，返回删除的元素数目
template <typename T>
int Vector<T>::remove(Rank lo,Rank hi) {
	if(lo==hi)
		return 0;
	else {
		while(hi<_size)
			_elem[lo++]=_elem[hi++];
		_size=lo;//注意更新VectorSize，此时lo=lo_0+hi后元素个数，即总的元素个数
		shrink();
		return hi-lo;
	}
}

//删除秩为r的元素，返回该元素的值
template <typename T>
T Vector<T>::remove(Rank r) {
	T tempElem=_elem[r];
	remove(r,r+1);
	return tempElem;
}

//区间查找，返回元素值为e的元素的秩（如过有多个匹配项，返回秩最大的那一个，找不到返回-1）
template <typename T>
Rank Vector<T>::find(T const& e,Rank lo,Rank hi) {
	int r=hi-1;
	while(r>=lo) {
		if(_elem[r]==e)
			return r;
		else
			r--;
	}
	return -1;
}

//整体查找，返回元素值为e的元素的秩（如过有多个匹配项，返回秩最大的那一个，找不到返回-1）
template <typename T>
Rank Vector<T>::find(T const& e) {
	return find(e,0,_size);
}

//二分查找（区间），返回不大于e的最大元素的秩
template <typename T>
Rank Vector<T>::binSearch(T const& e,Rank lo,Rank hi) {
	if(disordered())
		sort();
	while(lo<hi) {
		Rank mid=(lo+hi)>>1;
		if(e<_elem[mid])
			hi=mid;
		else if(e>_elem[mid])
			lo=mid+1;
		else {
			while(mid<hi&&_elem[mid]==e)//找到最后一个匹配的元素
				mid++;
			return mid-1;
		}
	}
	return lo-1;//注意，找不到也不一定返回-1
}

//二分查找（整体），返回不大于e的最大元素的秩
template <typename T>
Rank Vector<T>::binSearch(T const& e) {
	return binSearch(e,0,_size);
}

//遍历所有元素，对每个元素执行visit()对应的操作
template <typename T>
void Vector<T>::traverse(void (*visit)(T &)) {
	for(int ind=0;ind<_size;ind++)
		visit(_elem[ind]);
}

//起泡排序（从小到大排序）
template <typename T>
void Vector<T>::sort() {
	for(int i=0;i<_size-1;i++)
		for(int j=i+1;j<_size;j++)
			if(_elem[i]>_elem[j])
				swap(_elem[i],_elem[j]);
			else
				continue;
}

// 返回逆序元素对数
template <typename T>
int Vector<T>::disordered() {
	int n=0;
	for(int ind=1;ind<_size;ind++)
		n+=(_elem[ind-1]>_elem[ind]);
	return n;//有序向量返回0（即元素是从小到大排序的）
}

//无序向量元素唯一化（返回删除的元素数目）
template <typename T>
int Vector<T>::deduplicate() {
	int oldSize=_size;
	Rank ind=1;
	while(ind<_size)
		if(-1==find(_elem[ind],0,ind))
			ind++;
		else
			remove(ind);
	return oldSize-_size;
}

//有序向量元素唯一化（若没有排序，回自动调用排序函数;返回删除的元素数目）
template <typename T>
int Vector<T>::uniquify() {
	if(disordered())//先检查有序性
		sort();
	Rank slow=0,fast=0;
	while(++fast<_size)
		if(_elem[slow]!=_elem[fast]) {
			slow++;
			_elem[slow]=_elem[fast];
		}
	_size=slow+1;
	shrink();
	return fast-slow;
}

//[]重载
template <typename T>
T& Vector<T>::operator[](Rank r) {
	return _elem[r];
}