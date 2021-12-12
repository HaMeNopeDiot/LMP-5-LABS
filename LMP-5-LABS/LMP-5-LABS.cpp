#include <iostream>
#include <Windows.h>
#include "BinaryTree.h"

int main()
{
    SetConsoleOutputCP(1251);
    TTree rootPos, rootMin, root;
    initTree(rootPos);
    initTree(rootMin);
    initTree(root);
    std::cout << "Сколько элементов в вашем дереве?" << std::endl;
    int n; std::cin >> n;
    std::cout << "Введите элементы дерева" << std::endl;
    int elem;
    for (int i = 0; i < n; i++)
    {
        std::cin >> elem;
        root = insert(root, elem);
    }
    for (int i = 0; i < n; i++)
    {
        elem=findSuccessor(root);
        if (elem < 0)
        {
            rootMin = insert(rootMin, elem);
        }
        else
        {
            rootPos = insert(rootPos, elem);
        }
    }
    std::cout << "Pos:";
    preorder(rootPos, printNode);
    std::cout << std::endl;
    std::cout << "Min:";
    preorder(rootMin, printNode);
    std::cout << std::endl;

}
//6
//4 3 2 5 6 7


// 7
//-5 -3 -2 -6 -1 -8 -9

//15
//4 3 2 5 6 7 -5 0 -2 -6 -1 -8 -9 -3 1