/**********************
	COMP 315L - Analysis and Design of Data Structures and Algorithms Laboratory
	Binary Search Tree
	This class implements the Binary Search Tree using templates
	Each list has one attribute:
		-root: a pointer to the first node in tree

	Considerations:
		1. root points to null in an empty list
******************/

/***
	Luisel A. Muller Rodriguez
	#S01394043
***/

#include "BSTNode.h"

template <class T>
class BSTree{
public:
	//Default constructor: creates an empty tree
	BSTree();

	//Destructor: deallocate memory
	~BSTree();	

	//insert(T val): creates a new node with val as info, 
	void insert(T val);
	
	//remove(T val): remove the first node with val as info, 
	//if the node is removed, returns true, otherwise returns false
	bool remove(T val);

	//search(T val): returns a pointer to node with val as info
	BSTNode<T>* search(T val);
	
	//If the tree is empty, returns true
	//otherwise, returns false
	bool isEmpty();

	//printInOrder(): InOrder Traversal
	void printInOrder();

	//printPreOrder(): PreOrder Traversal
	void printPreOrder();

	//printPostOrder(): PostOrder Traversal
	void printPostOrder();
private:
	BSTNode<T> *root; // A pointer to the first node
	void visitInOrder(BSTNode<T> *node); // Recursive support method for printInOrder
	void visitPreOrder(BSTNode<T> *node); // Recursive support method for printPreOrder
	void visitPostOrder(BSTNode<T> *node); // Recursive support method for printPostOrder
	void removePostOrder(BSTNode<T>* node); // Recursive support method for the destructor
	BSTNode<T>* recursiveSearch(BSTNode<T> *node, T val); // Recursive support method for search
	bool recursiveSearchForRemove(BSTNode<T> *node, T val); // Recursive support method for remove
	BSTNode<T>* findLowest(BSTNode<T> *node); // Extract the lowest node in a subtree rooted on node
};

/****************
	Default constructor: creates an empty Binary Search tree
*****************/
template <class T>
BSTree<T>::BSTree()
{
	root = 0;
}

/*****************
	Destructor: deallocate memory removing each node from the tree
*****************/
template <class T>
BSTree<T>::~BSTree()
{
	removePostOrder(root);
}

/*****************
	Recursive support method for the destructor
*****************/
template <class T>
void BSTree<T>::removePostOrder(BSTNode<T>* node)
{
	if (node != 0) {
		removePostOrder(node->getLeft());
		removePostOrder(node->getRight());
		delete node;
	}
}

/*****************
	search(T val): returns a pointer to node with val as info
*****************/
template <class T>
BSTNode<T>* BSTree<T>::search(T val)
{
	return recursiveSearch(root, val);
}

/*****************
	Recursive support method for search
*****************/
template <class T>
BSTNode<T> *BSTree<T>::recursiveSearch(BSTNode<T> *node, T val)
{
	BSTNode<T> *res;//function result
	res = 0; //default value
	if (node != 0)
	{
		if (val == node->getInfo()) // Node found
			res = node;
		else if(val < node->getInfo()) // Search at the left
			res = recursiveSearch(node->getLeft(), val);
		else // Search at the right
			res = recursiveSearch(node->getRight(), val);
	}
	return res;
}

/*****************
	Recursive support method for remove
*****************/
template <class T>
bool BSTree<T>::recursiveSearchForRemove(BSTNode<T> *node, T val)
{
	bool res; //function result
	res = false; //default value
	BSTNode<T> *tmp, *found;
	if ((node->getLeft() != 0) && (val < node->getInfo())){ //It could be at the left
		if (node->getLeft()->getInfo() == val)
		{//val is its left child
			found = node->getLeft();
			if (found->getRight() == 0){//No right child
				node->setLeft(found->getLeft());
			} else {//right child
				tmp = findLowest(found->getRight()); //find the lowest greater children
				node->setLeft(tmp);
			}
			res = true;
		} 
		else
			res=recursiveSearchForRemove(node->getLeft(), val); //It could be at the left
	} else if ((node->getRight() != 0) && (val > node->getInfo()))
	{ //It could be at the right
		if (node->getRight()->getInfo() == val){//val is its right child
			found = node->getRight();
			if (found->getRight() == 0)//No right child
				node->setRight(found->getLeft());
			else{
				tmp = findLowest(found->getRight()); //find the lowest greater children
				node->setRight(tmp);
			}
			res = true;
		} else
			res = recursiveSearchForRemove(node->getRight(), val); //it could be at the right
	}
	return res;
}

/*****************
	Extract the lowest node in a subtree rooted on node
*****************/
template <class T>
BSTNode<T>* BSTree<T>::findLowest(BSTNode<T> *node)
{
	BSTNode<T> *tmp;
	if (node->getLeft() == 0) { //No left child
		tmp = node;
	}else{ //find the lowest value
		while(node->getLeft()->getLeft() != 0)
			node = node->getLeft();
		tmp = node->getLeft();		
		node->setLeft(tmp->getRight());
	}
	return tmp;
}

/*****************
	printInOrder(): InOrder Traversal
*****************/
template <class T>
void BSTree<T>::printInOrder()
{
	visitInOrder(root);			
}

/*****************
	Recursive support method for printInOrder
*****************/
template <class T>
void BSTree<T>::visitInOrder(BSTNode<T>* node)
{
	if (node != 0) {
		visitInOrder(node->getLeft());
		cout << "-" << node->getInfo() << "-";
		visitInOrder(node->getRight());
	}
}

/*****************
	printPreOrder(): PreOrder Traversal
*****************/
template <class T>
void BSTree<T>::printPreOrder()
{
	visitPreOrder(root);			
}

/*****************
	Recursive support method for printPreOrder
*****************/
template <class T>
void BSTree<T>::visitPreOrder(BSTNode<T>* node)
{
	if (node != 0){
		cout << "-" << node->getInfo() << "-";
		visitPreOrder(node->getLeft());
		visitPreOrder(node->getRight());
	}
}

/*****************
	printPostOrder(): PostOrder Traversal
*****************/
template <class T>
void BSTree<T>::printPostOrder()
{
	visitPostOrder(root);
}

/*****************
	Recursive support method for printPostOrder
*****************/
template <class T>
void BSTree<T>::visitPostOrder(BSTNode<T>* node)
{
	if (node != 0){
		visitPostOrder(node->getLeft());
		visitPostOrder(node->getRight());
		cout << "-" << node->getInfo() << "-";
	}
}

/*****************
	remove(T val): remove the first node with val as info, 
	if the node is removed, returns true, otherwise returns false
*****************/
template <class T>
bool BSTree<T>::remove(T val)
{
	bool res = false;
	if (root != 0)
	{
		if (root->getInfo() == val) { //Remove root
			if ((root->getLeft() == 0) && (root->getRight() == 0)) {//Delete root without children
				delete root;
				root = 0;
			}
			else {
				BSTNode<T>* tmp;
				tmp = root;
				if (root->getLeft() == 0) //Root does not have left child
					root = root->getRight();//The new root is its right child				
				else if (root->getRight() == 0)//Root does not have right child
					root = root->getLeft();//The new root is its left child
				else {
					BSTNode<T>* lowest;
					lowest = findLowest(root->getRight()); //find the lowest greater children

					if (root->getRight() == lowest) {//The lowest is its right child
						lowest->setLeft(root->getLeft());
						root = lowest;
					}
					else {
						root = lowest;
						root->setLeft(tmp->getLeft());
						root->setRight(tmp->getRight());
					}
				}	delete tmp;
			}	res = true;
		}
		else
			res = recursiveSearchForRemove(root, val); // It is not the root
	}	return res;
}

/***********************
	Implement other methods
***********************/

template <class T>
void BSTree<T>::insert(T val)
{
	BSTNode<T>* nNode = new BSTNode<T>;		//the node to be inserted	
	BSTNode<T>* temp = root;				//a temporary node pointing to root
	BSTNode<T>* parent = new BSTNode<T>;	//a node that will point to the parent of temp

	nNode->setInfo(val);	//setting the new nodes info

	//if root is null then the new node will become root
	if (root == NULL) root = nNode;

	//while temp is not null, including to the left and right
	while (temp != NULL)
	{
		//parent gets updated to point to the parent of the current node that temp points to
		parent = temp;

		//if the value is less or equal to the value of the current node then we move left
		if (val <= temp->getInfo())
		{
			temp = temp->getLeft();
		}
		else
		{
			//else we move to the right
			temp = temp->getRight();
		}
	}
	
	//when the parent node is found, we check if the value is less/equal or greater
	if (val <= parent->getInfo())
		parent->setLeft(nNode);	//if it's less the new node is added to its left
	else
		parent->setRight(nNode);//if it's greater the new node is added to the right
}
	
