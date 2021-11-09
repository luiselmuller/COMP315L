/***************************************************************************
Luisel A. Muller Rodriguez
#S01394043
===========================================================================
COMP315L - Analysis and Design of Data Structures and Algorithms Laboratory
Double linked List
This class implements the double linked list using templates
Each list has two attributes:
	-head: first node in the list
	-tail: last node in the list

Considerations:
1. head and tail point to null in an empty list
2. tail->next = null
**************************************************************************/

#include "IntDLLNode.h"

template <class T>
class IntDLList{
public:
	//Default constructor: creates an empty list
	IntDLList();

	//Destructor: deallocate memory
	~IntDLList();	

	//addToHead(T val): creates a new node with val as info, 
	//and this new node is the new head 
	void addToHead(T val);

	//addToTail(T val): creates a new node with val as info, 
	//and this new node is the new tail 	
	void addToTail(T val);

	//deleteFromHead: remove head from the list,
	//the new head is the previous head->next
	//if the list had only one node, head and tail point null
	void deleteFromHead();

	//deleteFromTail: remove tail from the list,
	//the new tail is the previous node to tail
	//if the list had only one node, head and tail point null
	void deleteFromTail();

	//In the list is empty, returns true
	//otherwise, returns false
	bool isEmpty();

	//printList(): prints all nodes in the list from head to tail
	void printList();

	//printRevList(): prints all nodes in the list from tail to head
	void printRevList();

private:
	IntDLLNode<T> *head; //A pointer to the first node
	IntDLLNode<T> *tail; //A pointer to the last node
};

/****************
	Default constructor: creates an empty list
	head and tail point null
*****************/
template <class T>
IntDLList<T>::IntDLList()
{
	tail = head = 0;
}

/***********************
	Destructor: deallocate memory removing each node from the list
*****************/
template <class T>
IntDLList<T>::~IntDLList()
{
	//Declare a pointer prtNode	
	IntDLLNode<T> *prtNode;
	//prtNode points head
	prtNode = head;
	
	//While there is a node in the list, remove it
	while (prtNode != 0)
	{
		//prtNode points head->next
		prtNode = head->getNext();

		//delete head
		delete head;
	
		//the new head is prtNode
		head = prtNode;
	}
}

/***********************
	printList(): prints all nodes in the list
*****************/
template <class T>
void IntDLList<T>::printList()
{
	IntDLLNode<T>* prtNode;
	prtNode = head;
	while (prtNode != 0)
	{
		cout << prtNode->getInfo() << " ";
		prtNode = prtNode->getNext();
	}
}

/***********************
	//printRevList(): prints all nodes in the list from tail to head
*****************/
template <class T>
void IntDLList<T>::printRevList()
{
	IntDLLNode<T>* prtNode;
	prtNode = tail;
	while (prtNode != 0)
	{
		cout << prtNode->getInfo() << " ";
		prtNode = prtNode->getPrev();
	}
}

/***********************
	If the list is empty, returns true
	otherwise, returns false
*****************/
template <class T>
bool IntDLList<T>::isEmpty()
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
  Adds a new node to the head (first position in the list)
  @params:
		val: the value to be stored in the new node
**********************************************************/
template <class T>
void IntDLList<T>::addToHead(T val)
{
	/* PLACE YOUR CODE HERE */

	//creating the new node to be inserted
	IntDLLNode<T>* nhNode = new IntDLLNode<T>;
	
	nhNode->setInfo(val);	//setting the new nodes info to the val parameter
	if (nullptr == head)
	{
		//if the list is empty make the new node both head and tail
		head = nhNode;
		tail = nhNode;
	}
	else
	{
		head->setPrev(nhNode);	//sets the current heads previous to point to the new node
		nhNode->setNext(head);	//sets the new nodes next to point to the previous head
		head = nhNode;			//makes head point to the new node, making the new node the head
	}
}

/**********************************************************
  Adds a new node to the tail (last position in the list)
  @params:
		val: the value to be stored in the new node
**********************************************************/
template <class T>
void IntDLList<T>::addToTail(T val)
{
	/* PLACE YOUR CODE HERE */

	//creating the new node to be inserted
	IntDLLNode<T>* ntNode = new IntDLLNode<T>;

	ntNode->setInfo(val);	//setting the new nodes info to the val parameter
	if (nullptr == head)
	{
		//if the list is empty the new node will be both tail and head
		head = ntNode;
		tail = ntNode;
	}
	else 
	{
		ntNode->setNext(tail->getNext());	//setting the new nodes next to null
		tail->setNext(ntNode);				//making the previous tail point to the new node
		ntNode->setPrev(tail);				//making the new nodes previous point to the previous tail
		tail = ntNode;						//making the new node the tail
	}
}

/*************************************************************************
  Deletes the node that head is pointing to (the first node of the list)
*************************************************************************/
template <class T>
void IntDLList<T>::deleteFromHead()
{
	/* PLACE YOUR CODE HERE */
	IntDLLNode<T>* temp = head; //temporary node pointing to head

	//if the list is not empty
	if (nullptr != head->getNext())
	{
		head = head->getNext();			 //make the head point to the next node in the list
		head->setPrev(temp->getPrev());  //make the heads previous point to null
	}
	else
	{
		head = tail = NULL;				//if the list is empty then we set both tail and head to point to NULL
	}
	delete temp;	//delete previous head
}

/*******************************************************************
  Deletes the node that tail points to (the last node of the list)
*******************************************************************/
template <class T>
void IntDLList<T>::deleteFromTail()
{
	/* PLACE YOUR CODE HERE */
	IntDLLNode<T>* temp = tail;	//temporary node pointing to tail

	//if the list is not empty
	if (nullptr != head->getNext())
	{
		tail = tail->getPrev();			//make tail point to the previous node
		tail->setNext(temp->getNext()); //set the next of the new tail to NULL
	}
	else
	{
		head = tail = NULL;				//if the list is empty we set both tail and head to NULL
	}
	delete temp;	//delete the previous tail
}