#pragma once

/*
	还未完善
*/

template<class T>
class LinkList  //链表类
{
protected:
	struct Node // 节点的数据结构
	{
		T data;
		Node *next;
		Node *pre;

		Node() :next(nullptr), pre(nullptr){}  // 无参构造
		Node(T t) :data(t), next(nullptr), pre(nullptr){} // 带参数构造
	};

private:
	Node *head; // 头指针 （空节点）
	Node *tail; // 尾指针 （空节点）
	int size;
public:
	LinkList()
	{
		head = new Node;
		tail = new Node;

		size = 0;
	}
	~LinkList()
	{
		clear();
		delete head;
		delete tail;
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

template<class T>
void LinkList<T>::insertOnHead(T val)
{
	Node *newNode = new Node;
	newNode->data = val;
	newNode->pre = head;
	newNode->next = head->next;
	head->next = newNode;

	if (!size)
		tail->next = newNode; // 把尾指针指向第一个节点
	++size;
}
template<class T>
void LinkList<T>::insertOnTail(T val)
{
	Node *newNode = new Node;
	newNode->data = val;
	newNode->next = nullptr;
	newNode->pre = tail->next;
	tail->next->next = newNode;
	tail->next = newNode;
	++size;
}
template<class T>
bool LinkList<T>::insert(int i,T val)
{
	if (i <= 0|| i > size)
		return false;

	Node *newNode = new Node;
	Node *temp = head;

	if (i == size)
		tail->next = newNode; // 如果在最后插入，更新尾指针

	for (int j = 0; j <= size; ++j)
	{
		if (i != 0)
		{
			temp = temp->next;
			--i;
		}
		else
		{
			newNode->data = val;
			newNode->pre = temp;
			newNode->next = temp->next;
			temp->next = newNode;
			break;
		}
			
	}

	++size;
	return true;
	
	
}

template<class T>
bool LinkList<T>::getData(int i, T &val)
{
	if (i <= size && i > 0)
	{
		Node *temp = head;
		for (int j = 0; j < i; ++j)
		{
			temp = temp->next;
		}
		val = temp->data;
		return true;
	}
	else
	{
		return false;
	}
}
template<class T>
bool LinkList<T>::isEmpty()
{
	return size ? false : true;
}
template<class T>
void LinkList<T>::clear()
{
	Node *tempFront = head->next;  // 指向下一个待删除
	Node *tempBack = head->next;   // 指向待删除的元素
	for (int i = 0; i < size; ++i)
	{
		tempBack = tempFront;
		tempFront = tempFront->next;
		delete tempBack;
	}
	size = 0;
}
template<class T>
void LinkList<T>::printList()
{
	if (!size)
	{
		cout << "empty link" << endl;
		return;
	}

	Node * temp = head->next;
	for (int i = 0; i < size; ++i)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}


