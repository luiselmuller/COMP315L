/**********************
	COMP315L - Analysis and Design of Data Structures and Algorithms Laboratory
	Singly linked List
	This class implements the singly linked list using templates
	Each list has two attributes:
		-head: first node in the list
		-tail: last node in the list

	Considerations:
	1. head and tail point to null in an empty list
	2. tail->next = null
******************/

#include "IntSLLNode.h"

template <class T>
class IntSLList{
	public:
		//Default constructor: creates an empty list
		IntSLList();

		//Destructor: deallocate memory
		~IntSLList();	

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

		//If the list is empty, returns true
		//otherwise, returns false
		bool isEmpty();

		//printList(): prints all nodes in the list
		void printList();
	private:
		IntSLLNode<T> *head; //A pointer to the first node
		IntSLLNode<T> *tail; //A pointer to the last node
};

/****************
	Default constructor: creates an empty list
	head and tail point null
*****************/
template <class T>
IntSLList<T>::IntSLList()
{
	tail = head = 0;
}

/***********************
	Destructor: deallocate memory removing each node from the list
*****************/
template <class T>
IntSLList<T>::~IntSLList()
{
	//Declare a pointer prtNode	
	IntSLLNode<T> *prtNode;

	//prtNode points head
	prtNode = head;
	
	//While there is a node in the list, remove it
	while(prtNode != 0)
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
	If the list is empty, returns true
	otherwise, returns false
*****************/
template <class T>
bool IntSLList<T>::isEmpty()
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

/***********************
	printList(): prints all nodes in the list
*****************/
template <class T>
void IntSLList<T>::printList()
{
	/* PLACE YOUR CODE HERE */
	IntSLLNode<T>* temp = head;	//temporary pointer to head

	while (temp != nullptr)
	{
		cout << temp->getInfo() << " ";	//prints the info in the node
		temp = temp->getNext();			//switches to the next node
	}
}
/***********************************************
Adds a new node to the head(start) of the list
@params:
	val: the value to be stored in the node
	as a parameter
***********************************************/
template <class T>
void IntSLList<T>::addToHead(T val)
{
	/* PLACE YOUR CODE HERE */
	IntSLLNode<T>* nhNode = new IntSLLNode<T>;	//creating new node

	nhNode->setInfo(val);	//setting the new nodes info
	if (head == nullptr)
	{
		//if the new node is the only node in the list then it is both head and tail
		head = nhNode;
		tail = nhNode;
	}
	else
	{
		nhNode->setNext(head);	//setting the new node to point to the previous head
		head = nhNode;			//setting head to point to the new node
	}
}

/********************************************
Adds a new node to the tail(end) of the list
@params:
	val: the value to be stored in the node
	as a parameter (val)
********************************************/
template <class T>
void IntSLList<T>::addToTail(T val)
{
	/* PLACE YOUR CODE HERE */
	//creating new node
	IntSLLNode<T>* ntNode = new IntSLLNode<T>;

	ntNode->setInfo(val);	//setting the new nodes info

	if (head == nullptr)
	{
		//if the new node is the only node in the list then it is both head and tail
		head = ntNode;
		tail = ntNode;
	}
	else
	{
		tail->setNext(ntNode);	//making the previous tail point to the new node
		tail = ntNode;			//making the new node the new tail
	}
}

/**********************************
Deletes the first item of the list
**********************************/
template <class T>
void IntSLList<T>::deleteFromHead()
{
	/* PLACE YOUR CODE HERE */
	IntSLLNode<T>* temp = head; //temporary pointer to head

	head = head->getNext();		//making head point to the next node
	delete temp;				//previous head gets deleted
}

/*********************************
Deletes the last item of the list
*********************************/
template <class T>
void IntSLList<T>::deleteFromTail()
{
	/* PLACE YOUR CODE HERE */
	IntSLLNode<T>* endNode = head;	//becomes the last node when found  
	IntSLLNode<T>* temp = head;		//new tail node (second to last node)

	//iterating through the list to find the last node
	while (endNode->getNext() != NULL)
	{ 
		temp = endNode;					//second to last node
		endNode = endNode->getNext();	//last node
	}

	//if the last node is the head node it is set to null
	if (endNode == head)
	{
		head = NULL;
	}
	
	temp->setNext(endNode->getNext());	//temp is set to null since it is the new tail
	tail = temp;						//the second to last node becomes the new tail

	delete endNode;	//deleting the last node
}

