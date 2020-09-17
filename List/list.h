// list.h

#include "listnode.h"

template <typename T>
class List {
	public:
		typedef ListNode<T>* ListNodePtr;

	private:
		int _size;
		ListNodePtr header,trailer;

	protected:

	public:
		int size()cosnt {return _size;}//返回元素个数
		ListNodePtr first()const {return header->}

};
