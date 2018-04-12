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
	pList top;	//�������� ��� ������ �������
public:
	List();
	List(Element);
	List(std::initializer_list<Element>);
	~List();
	bool push_front(Element);	//������ ������� � �������� �� �������
	bool push_back(Element);	//������ ������� � ���� �� �������
	bool get_top(Element&);		//����� �� ���������� �� ������ �������
	bool remove_top();			//������� ������ �������
	bool operator +=(Element);	//������ ������� � ���� �� �������
	Element& operator[](int);	//�������� ��������
	size_t size();				//���� �� ���������� � �������
	friend std::ostream& operator <<(std::ostream&, const List&);
	List(const List&);
	List& operator=(const List&);
	List(List&&);
	List& operator=(List&&);
};

