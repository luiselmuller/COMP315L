/********************************************************************************
	COMP315L - Analysis and Design of Data Structures and Algorithms Laboratory
	Circular Doubly linked List
	This class implements the circular doubly linked list using templates
	Each list has one attribute:
		-head: the node that you are step in

	Considerations:
	1. head point to null in an empty list
	2. There is not need of a tail pointer
********************************************************************************/

/******************************
  Luisel A. Muller Rodriguez
  #S01394043
******************************/

#include "intDLLNode.h"

template <class T>
class circDLList{
public:
	// Default constructor: creates an empty list
	circDLList();

	// Destructor: deallocate memory
	~circDLList();	

	// addToHead(T val): creates a new node with val as info, 
	// and this new node is the new head 
	void addToHead(T val);

	// addToTail(T val): creates a new node with val as info, 
	// and this new node is the new tail 	
	void addToTail(T val);

	// deleteFromHead: remove head from the list,
	// the new head is the previous head->next
	// if the list had only one node, head and tail point null
	void deleteFromHead();

	// deleteFromTail: remove tail from the list,
	// the new tail is the previous node to tail
	// if the list had only one node, head and tail point null
	void deleteFromTail();

	// In the list is empty, returns true
	// otherwise, returns false
	bool isEmpty();

	// printList(): prints all nodes in the list from head to tail
	void printList();

	// printList(): prints all nodes in the list from tail to head
	void printRevList();

private:
	IntDLLNode<T> *head; // A pointer to the first node
};

/****************
	Default constructor: creates an empty list
	head and tail point null
*****************/
template <class T>
circDLList<T>::circDLList()
{
	head = 0;
}
/***********************
	Destructor: deallocate memory removing each node from the list
*****************/
template <class T>
circDLList<T>::~circDLList()
{
	while(!isEmpty())	
		this->deleteFromHead();
}

/***********************
	printList(): prints all nodes in the list
*****************/
template <class T>
void circDLList<T>::printList()
{
	IntDLLNode<T>* prtNode;
	prtNode = head;
	if (prtNode != 0)
	{
		while (prtNode->getNext() != head) {
			cout << prtNode->getInfo() << " ";
			prtNode = prtNode->getNext();
		}
		cout << prtNode->getInfo() << " ";
	}
}

/***********************
	printRevList(): prints all nodes in the list from tail to head
*****************/
template <class T>
void circDLList<T>::printRevList()
{
	IntDLLNode<T>* prtNode;
	prtNode = head;
	if (prtNode != 0)
	{
		while (prtNode->getPrev() != head) {
			prtNode = prtNode->getPrev();
			cout << prtNode->getInfo() << " ";
		}
		cout << head->getInfo() << " ";
	}
}

/***********************
	If the list is empty, returns true
	otherwise, returns false
*****************/
template <class T>
bool circDLList<T>::isEmpty()
{
	bool res;
	res = false;
	if (head == 0)
	{
		res = true;
	}
	return res;
}

/***********************
	Implement other methods
***********************/

/**********************************************************
  Adds a new node to the head (first position of the list)
  @params:
		val: the value to be stored in the new node
**********************************************************/
template <class T>
void circDLList<T>::addToHead(T val)
{
	//create a new node
	IntDLLNode<T>* nhNode = new IntDLLNode<T>;
	//pointer to the last node | if head is empty the node will be a new node, 
	//if not then it will point to the last node using the heads previous
	IntDLLNode<T>* last = head == NULL ? new IntDLLNode<T> : head->getPrev();

	//sets the info of the new node
	nhNode->setInfo(val);

	//if the list is empty both head and tail point to the new node
	if (nullptr == head)		
	{
		head = last = nhNode;		//make the new node head and tail
		nhNode->setPrev(head);		//point the new nodes previous to head
		nhNode->setNext(head);		//point the new nodes next to head
	}
	else
	{
		last->setNext(nhNode);		//setting the tails next to the new node (the head)
		nhNode->setNext(head);		//setting the new nodes next to the previous head
		head->setPrev(nhNode);		//setting the previous heads previous to the new node
		nhNode->setPrev(last);		//setting the new nodes previous to the tail

		head = nhNode;				//making the new node the head of the list
	}
}

/**********************************************************
  Adds a new node to the tail (last position of the list)
  @params:
		val: the value to be stored in the new node
**********************************************************/
template <class T>
void circDLList<T>::addToTail(T val)
{
	//creating a new node to be inserted
	IntDLLNode<T>* ntNode = new IntDLLNode<T>;
	//pointer to the last node | if head is empty the node will be a new node, 
	//if not then it will point to the last node using the heads previous
	IntDLLNode<T>* last = head == NULL ? new IntDLLNode<T> : head->getPrev();

	//set the new nodes info to the val parameter
	ntNode->setInfo(val);		

	//if the list is empty
	if (nullptr == head)
	{
		head = last = ntNode;	//make the new node head and tail
		ntNode->setPrev(last);	//set the new nodes previous to the tail 
		ntNode->setNext(last);	//set the new nodes next to the tail
	}
	else
	{
		ntNode->setNext(head);	//setting the new nodes next to point to the head
		last->setNext(ntNode);	//setting the tails next to the new inserted node
		ntNode->setPrev(last);	//setting the new nodes previous to point to the previous tail
		head->setPrev(ntNode);	//setting the heads previous to point to the new node

		last = ntNode;			//making the new node the last node in the list
	}
}

/************************************
  Deletes the first node in the list
************************************/
template <class T>
void circDLList<T>::deleteFromHead()
{
	//temporary pointer to head
	IntDLLNode<T>* temp = head;	
	//pointer to the last node | if head is empty the node will be a new node, 
	//if not then it will point to the last node using the heads previous
	IntDLLNode<T>* last = head == NULL ? new IntDLLNode<T> : head->getPrev();

	//if the node is the last node in the list
	if (head->getNext() == head)
	{
		head = last = NULL;	//head and taill are set to NULL
	}
	else
	{
		head = head->getNext();	//setting head to point to the next node in the list
		head->setPrev(last);	//setting heads previous to point to the tail
		last->setNext(head);	//setting the tails next to point to the head
	}
	delete temp;	//deleting the previous head
	
}

/************************************
  Deletes the last node in the list
************************************/
template <class T>
void circDLList<T>::deleteFromTail()
{
	//pointer to the last node | if head is empty the node will be a new node, 
	//if not then it will point to the last node using the heads previous
	IntDLLNode<T>* last = head == NULL ? new IntDLLNode<T> : head->getPrev();
	//temporary pointer to head
	IntDLLNode<T>* temp = last;

	//if the node is the only one in the list
	if (head->getNext() == head)
	{
		head = last = NULL;		//both head and tail are NULL
	}
	else
	{
		last = last->getPrev();	//makes the second to last node the new tail
		head->setPrev(last);	//sets the heads next to the new tail
		last->setNext(head);	//sets the new tails next to the head
	}
	delete temp;	//deletes the previous tail
}
