// list.h

#pragma once

template <typename T>
struct ListNode {
	typedef ListNode<T>* ListNodePtr;
	//members
	ListNodePtr pred;
	T data;
	ListNodePtr succ;

	//functions
	ListNode(T d=0,ListNodePtr p=NULL,ListNodePtr s=NULL):data(d),pred(p),succ(s) {}
	ListNodePtr insertAsPred(T const& e);
	ListNodePtr insertAsSucc(T const& e);
};