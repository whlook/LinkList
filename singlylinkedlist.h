#pragma once

#include <iostream>
using namespace std;


template<class T>
struct Node // 节点的数据结构
{
	T data;
	Node *next;

	Node() :next(nullptr){}  // 无参构造
	Node(T t) :data(t), next(nullptr){} // 带参数构造
};

template<class T>
class LinkList  //链表类
{
private:
	Node<T> *head; // 头指针 （空节点）
	Node<T> *tail; // 尾指针 （空节点）
	int size;
public:
	LinkList()
	{
		head = new Node<T>;
		tail = new Node<T>;

		size = 0;
	}
	~LinkList()
	{

	}
public:
   /**
    *	在链表的头部插入新节点
    *		@param val：赋给新节点的值
	*/
	void insertOnHead(T val);

   /**
	*	在链表的尾部插入新节点
	*		@param val：赋给新节点的值
	*/
	void insertOnTail(T val); 

   /**
	*	在链表的某一位置插入新节点，插入成功返回true，否则返回false
	*		@param i：指定的位置
	*		@param val：赋给新节点的值
	*/
	bool insert(int i,T val); 

   /**
	*	获取某节点的值，获取成功返回true，否则返回false
	*		@param i：指定的位置
	*		@param val：赋给新节点的值	
	*/
	bool getData(int i,T &val); 

   /**
	*	判断空，空的话返回true，否则返回false
	*/
	bool isEmpty(); 

   /**
	*	清空链表
	*/
	void clear(); 

   /**
	*	打印链表
	*/
	void printList();
};
