#include <iostream>
#include "Node.h"
#include <vector>
#include <algorithm>
using namespace std;
class Tree
{
private:
	Node *Root;
	int Count;

public:
	Node* GetRoot()
	{
		return Root;
	}

	int GetCount()
	{
		return Count;
	}

	void Add(int data)
	{
		if (Root == NULL)
		{
			Node *node = new Node();
			node->SetData(data);
			Root = node;
			Count = 1;
			return;
		}

		Root->Add(data);
		Count++;
	}

	//Прямой обход (NLR)
    vector<int> Preorder()
	{
		if (Root == NULL)
		{
			return vector<int>();
		}

		return Preorder(Root);
	}

	//обратный (post-order) LRN
	vector<int> Postorder()
	{
		if (Root == NULL)
		{
			return vector<int>();
		}

		return Postorder(Root);
	}

	//центрированный (in-order) LNR
	vector<int> Inorder()
	{
		if (Root == NULL)
		{
			return vector<int>();
		}

		return Inorder(Root);
	}

	bool BinarySearch(int item)
	{
		try
		{
			if (Root != NULL)
			{
				if (Root->GetData() == item)
				{
					return true;
				}
				else
				{
					if (Root->GetData() < item)
					{
						if (Root->GetRight() != NULL)
							return Search(Root->GetRight(), item);
					}
					else if (Root->GetData() > item)
					{
						if (Root->GetLeft() != NULL)
							return Search(Root->GetLeft(), item);
					}
					return false;
				}
			}
			else
			{
				throw exception();
			}
		}
		catch (exception)
		{
			cout << "Tree is empty";
		}
	}



	Tree() {}

private:
	vector<int> Preorder(Node* node)
	{
		vector<int> list;
		if (node != NULL)
		{
			list.push_back(node->GetData());

			if (node->GetLeft() != NULL)
			{
				auto V = Preorder(node->GetLeft());
				list.insert(list.end(), V.begin(), V.end());
			}

			if (node->GetRight() != NULL)
			{
				auto V = Preorder(node->GetRight());
				list.insert(list.end(), V.begin(), V.end());
			}
		}

		return list;
	}

	vector<int> Postorder(Node* node)
	{
		vector<int> list;
		if (node != NULL)
		{
			if (node->GetLeft() != NULL)
			{
				auto V = Postorder(node->GetLeft());
				list.insert(list.end(), V.begin(), V.end());
			}

			if (node->GetRight() != NULL)
			{
				auto V = Postorder(node->GetRight());
				list.insert(list.end(), V.begin(), V.end());
			}

			list.push_back(node->GetData());
		}
		return list;
	}

	vector<int> Inorder(Node* node)
	{
		vector<int> list;
		if (node != NULL)
		{
			if (node->GetLeft() != NULL)
			{
				auto V = Inorder(node->GetLeft());
				list.insert(list.end(), V.begin(), V.end());
			}

			list.push_back(node->GetData());

			if (node->GetRight() != NULL)
			{
				auto V = Inorder(node->GetRight());
				list.insert(list.end(), V.begin(), V.end());
			}
		}

		return list;
	}

	bool Search(Node* node, int item)
	{
		if (node->GetData() == item)
		{
			return true;
		}
		else if (node->GetData() < item)
		{
			if (node->GetRight() != NULL)
			{
				return Search(node->GetRight(), item);
			}
		}
		else
		{
			if (node->GetLeft() != NULL)
			{
				return Search(node->GetLeft(), item);
			}
		}
		return false;
	}

	void SetCount(int count)
	{
		Count = count;
	}

	void SetRoot(Node* root)
	{
		Root = root;
	}
};

