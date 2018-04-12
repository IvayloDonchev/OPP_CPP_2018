#pragma once
#include <iostream>
#include <initializer_list>
typedef int Element;

class List
{
private:
	class Node
	{
	public:
		Element key;
		Node *next;
		Node() : key(), next(nullptr) {}
		Node(Element x) : key(x), next(nullptr) {}
		friend std::ostream& operator <<(std::ostream&, const List&);
	};
	typedef Node* pList;
private:
	pList top;	//указател към първия елемент
public:
	List();
	List(Element);
	List(std::initializer_list<Element>);
	~List();
	bool push_front(Element);	//добавя елемент в началото на списъка
	bool push_back(Element);	//добавя елемент в края на списъка
	bool get_top(Element&);		//копие на стойността на първия елемент
	bool remove_top();			//изтрива първия елемент
	bool operator +=(Element);	//добавя елемент в края на списъка
	Element& operator[](int);	//индексна операция
	size_t size();				//брой на елементите в списъка
	friend std::ostream& operator <<(std::ostream&, const List&);
	List(const List&);
	List& operator=(const List&);
	List(List&&);
	List& operator=(List&&);
};

