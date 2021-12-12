#pragma once
#include<vector>

struct Node {
	int data;
	Node* left;
	Node* right;
	unsigned char height;
};

typedef Node* TTree;
typedef void(*FunctionType) (int& node);

void initTree(TTree& root);
void initTree(TTree& root, int elem);
void initTree(TTree& root, int elem, TTree leftTree, TTree rightTree);

void destroyTree(TTree& root);

bool isEmpty(TTree root);

int getRootData(TTree root);
void setRootData(TTree& root, int elem);

void attachLeftSon(TTree root, int elem);
void attachRightSon(TTree root, int elem);

void attachLeftSubtree(TTree root, TTree subTree);
void attachRightSubtree(TTree root, TTree subTree);

TTree getLeftSubtree(TTree root); //создает копию левого поддерева
TTree getLRightSubtree(TTree root);

void detachLeftSubtree(TTree root, TTree& leftTree);
void detachRightSubtree(TTree root, TTree& rightTree);

void copyTree(TTree root, TTree& newRoot);

void preorder(TTree root, FunctionType visit);
void inorder(TTree root, FunctionType visit);
void postorder(TTree root, FunctionType visit);
void printNode(int& elem);

TTree insert(TTree pNode, int elem);
TTree LL_rotate(TTree q);
TTree RR_rotate(TTree p);
TTree balance(TTree p);

int findSuccessor(TTree& pNode);
//std::vector<int> preorderFill(TTree root);