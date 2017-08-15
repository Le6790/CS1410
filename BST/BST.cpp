#include "BST.hpp"
#include <iostream>

void BinarySearchTree::insert(std::string value)
{
	TreeNode* newNode = new TreeNode(value);

	insert(m_root, newNode);
}

void BinarySearchTree::insert(TreeNode*& node, TreeNode* newNode)
{
	if (node == nullptr)
	{
		node = newNode;
	}
	else if (newNode->data < node->data)
	{
		insert(node->left, newNode);
	}
	else
	{
		insert(node->right, newNode);
	}
}

bool BinarySearchTree::search(std::string value)
{
	TreeNode* tree = m_root;

	while (tree)
	{
		if (tree->data == value)
		{
			return true;
		}
		else if (value < tree->data)
		{
			tree = tree->left;
		}
		else 
		{
			tree = tree->right;
		}
	}
	return false;
}

void BinarySearchTree::display()
{
	display(m_root);
}
void BinarySearchTree::display(TreeNode* node)
{
	if (node != nullptr)
	{
		display(node->left);
		std::cout << node->data << std::endl;
		display(node->right);
	}
}

void BinarySearchTree::remove(std::string value)
{

	if (m_root == NULL)
	{
		return;
	}
	remove(value, m_root);
}
void BinarySearchTree::remove(std::string value, TreeNode*& node) 
{
	if (value < node->data)
	{
		remove(value, node->left);
	
	}
	else if (value > node->data)
	{
		remove(value, node->right);
	}
	else
	{
		remove(node);
	}
}

void BinarySearchTree::remove(TreeNode*& node)
{
	if (node->left == nullptr)
	{
		TreeNode* temp = node;
		node = node->right;
		delete temp; 
	}
	else if (node->right == nullptr)
	{
		TreeNode* temp = node;
		node = node->left;
		delete temp; 
	}
	else 
	{
		insert(node->right, node->left);
		/*TreeNode* left = node -> right;
		while (left->left != nullptr)
		{
			left = left -> left;
		}
		left->left = node->left;

		TreeNode* temp = node;
		node = node->right;
		delete temp;
	*/
	}

}