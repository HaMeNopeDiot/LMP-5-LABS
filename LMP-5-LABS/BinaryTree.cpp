#include "BinaryTree.h"
#include <iostream>
#include <vector>
//#include "Queue.h"
//#include "Stack.h"


void initTree(TTree& root)
{
	root = nullptr;
}

void initTree(TTree& root, int elem)
{
	root = new Node;
	root->data = elem;
	root->left = nullptr;
	root->right = nullptr;
}

void initTree(TTree& root, int elem, TTree leftTree, TTree rightTree)
{
	initTree(root, elem);
	attachLeftSubtree(root, leftTree);
	attachRightSubtree(root, rightTree);
}

void destroyTree(TTree& root) // удаление дерева
{
	if (root != nullptr) {
		destroyTree(root->left);
		destroyTree(root->right);
		delete root;
		root = nullptr;
	}
}

bool isEmpty(TTree root)
{
	return root == nullptr;
}

int getRootData(TTree root) //получить значение корневого узла
{
	if (!isEmpty(root))
		return root->data;
	else
		std::cout << "The tree is empty" << std::endl;
}

void setRootData(TTree& root, int elem) //установить значение корневого узла
{
	if (!isEmpty(root))
		root->data = elem;
	else
		initTree(root, elem);
}

void attachLeftSon(TTree root, int elem) //присоединить левого сына
{
	if (isEmpty(root))
		std::cout << "The tree is empty" << std::endl;
	else
		if (root->left != nullptr)
			std::cout << "Left subtree is not empty" << std::endl;
		else {
			TTree p = new Node;
			p->data = elem;
			p->left = nullptr;
			p->right = nullptr;
			root->left = p;
		}
}

void attachRightSon(TTree root, int elem)
{
	if (isEmpty(root))
		std::cout << "The tree is empty" << std::endl;
	else
		if (root->right != nullptr)
			std::cout << "Left subtree is not empty" << std::endl;
		else {
			TTree p = new Node;
			p->data = elem;
			p->left = nullptr;
			p->right = nullptr;
			root->right = p;
		}
}

void attachLeftSubtree(TTree root, TTree subTree) //присоединить левое поддерево
{
	if (isEmpty(root))
		std::cout << "The tree is empty" << std::endl;
	else
		if (root->left != nullptr)
			std::cout << "Left subtree is not empty" << std::endl;
		else
			root->left = subTree;
}

void attachRightSubtree(TTree root, TTree subTree)
{
	if (isEmpty(root))
		std::cout << "The tree is empty" << std::endl;
	else
		if (root->right != nullptr)
			std::cout << "Left subtree is not empty" << std::endl;
		else
			root->right = subTree;
}

TTree getLeftSubtree(TTree root) //создает копию левого поддерева
{
	TTree subTree;
	if (isEmpty(root))
		subTree = nullptr;
	else
		copyTree(root->left, subTree);
	return subTree;
}

TTree getLRightSubtree(TTree root)
{
	TTree subTree;
	if (isEmpty(root))
		subTree = nullptr;
	else
		copyTree(root->right, subTree);
	return subTree;
}

void detachLeftSubtree(TTree root, TTree& leftTree)//отсоединяет левое поддерево
{
	if (isEmpty(root))
		std::cout << "The tree is empty" << std::endl;
	else {
		leftTree = root->left;
		root->left = nullptr;
	}
}

void detachRightSubtree(TTree root, TTree& rightTree)
{
	if (isEmpty(root))
		std::cout << "The tree is empty" << std::endl;
	else {
		rightTree = root->right;
		root->right = nullptr;
	}
}

void copyTree(TTree root, TTree& newRoot) // копирует дерево
{
	if (root != nullptr) {
		newRoot = new Node;
		newRoot->data = root->data;
		newRoot->left = nullptr;
		newRoot->right = nullptr;

		copyTree(root->left, newRoot->left);
		copyTree(root->right, newRoot->right);
	}
	else
		newRoot = nullptr;
}

void preorder(TTree root, FunctionType visit)
{
	if (root != nullptr) {
		//std::cout << root->data << std::endl;
		visit(root->data);
		preorder(root->left, visit);
		preorder(root->right, visit);
	}
}

void inorder(TTree root, FunctionType visit)
{
	if (root != nullptr) {
		inorder(root->left, visit);
		visit(root->data);
		inorder(root->right, visit);
	}
}

void postorder(TTree root, FunctionType visit)
{
	if (root != nullptr) {
		postorder(root->left, visit);
		postorder(root->right, visit);
		visit(root->data);
	}
}

void printNode(int& elem)
{
	std::cout << elem << " ";
}




unsigned char height(TTree pNode)
{
	return pNode ? pNode->height : 0;
}
int balanceFactor(TTree pNode)
{
	return height(pNode->right) - height(pNode->left);
}
void fixHeight(TTree pNode)
{
	unsigned char hLeft = height(pNode->left);
	unsigned char hRight = height(pNode->right);
	pNode->height = (hLeft > hRight ? hLeft : hRight) + 1;
}

TTree insert(TTree pNode, int elem)
{
	if (pNode == 0)
	{
		pNode = new Node;
		pNode->data = elem;
		pNode->left = nullptr;
		pNode->right = nullptr;
		return balance(pNode);
	}
	if (elem < pNode->data)
		pNode->left = insert(pNode->left, elem);
	else
		pNode->right = insert(pNode->right, elem);
	return balance(pNode);
}

TTree RR_rotate(TTree p)
{
	TTree q = p->left;
	p->left = q->right;
	q->right = p;
	fixHeight(p);
	fixHeight(q);
	return q;
}
TTree LL_rotate(TTree q)
{
	TTree p = q->right;
	q->right = p->left;
	p->left = q;
	fixHeight(q);
	fixHeight(p);
	return p;
}

TTree balance(TTree p)
{
	fixHeight(p);
	if (balanceFactor(p) == 2)
	{
		if(balanceFactor(p->right) < 0)
			p->right=RR_rotate(p->right);
		return LL_rotate(p);
	}
	if (balanceFactor(p) == -2)
	{
		if (balanceFactor(p->left) > 0)
			p->left = LL_rotate(p->left);
		return RR_rotate(p);
	}
	return p;
}

int findSuccessor(TTree& pNode)
{
	if (pNode->left == 0)
	{
		int elem = pNode->data;
		TTree delNode = pNode;
		pNode = pNode->right;
		delete delNode;
		return elem;
	}
	return findSuccessor(pNode->left);
}