#include <iostream>
#include "BST.hpp"
int main() 
{


	BinarySearchTree myTree;
	myTree.insert("Austin");
	myTree.insert("5");
	myTree.insert("8");
	myTree.insert("3");
	myTree.insert("1");
	myTree.insert("2");
	myTree.insert("9");
	myTree.insert("Bob");
	myTree.insert("Davis");
	myTree.display();
	

	if (myTree.search("3"))
	{
		std::cout << "3 is in the tree" << std::endl;
	}
	else
	{
		std::cout << "3 is not in the tree" << std::endl;
	}
	if (myTree.search("10"))
	{
		std::cout << "10 is in the tree" << std::endl;
	}
	else
	{
		std::cout << "10 is not in the tree" << std::endl;
	}

	std::cout << "---------------------" << std::endl;

	std::cout << "removing 9" << std::endl;
	myTree.remove("9");
	std::cout << "removing 3" << std::endl;
	myTree.remove("3");
	myTree.remove("Bob");
	myTree.display();
}