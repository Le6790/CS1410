#include <string>
class BinarySearchTree 
{
public:
	BinarySearchTree() : m_root(nullptr) 
	{}
	void insert(std::string value);
	void remove(std::string value);
	bool search(std::string value);
	void display();

private:
	class TreeNode 
	{
	public:
		TreeNode(std::string data) :
			data(data),
			left(nullptr),
			right(nullptr)
		{}
		std::string data;
		TreeNode* left;
		TreeNode* right;

	};
	TreeNode* m_root;
	void insert(TreeNode*& node, TreeNode* newNode);
	void remove(std::string value, TreeNode*& node);
	void remove(TreeNode*& node);
	void display(TreeNode* node);
};


