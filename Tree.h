#include <iostream>
#include "Node.h"
#include <vector>
#include <algorithm>
using namespace std;
template <typename T>
/// <summary>
/// class if Binary Tree
/// </summary>
/// <typeparam name="T">using data-type for tree</typeparam>
class Tree
{
private:
	/// <summary>
	/// main root of tree(start node)
	/// </summary>
	Node<T> *Root = nullptr;
	/// <summary>
	/// count of nodes
	/// </summary>
	int Count = 0;

public:
	/// <summary>
	/// getter for root-reference(NOT recommended - unsafe, you can lose all the tree)
	/// </summary>
	/// <returns>Root</returns>
	Node<T>* GetRoot()
	{
		return Root;
	}
	/// <summary>
	/// getter count of nodes
	/// </summary>
	/// <returns>Count</returns>
	int GetCount()
	{
		return Count;
	}
	/// <summary>
	/// method for add new node
	/// </summary>
	/// <param name="data">info</param>
	void Add(T data)
	{
		if (Root == nullptr)
		{
			Node<T> *node = new Node<T>();
			node->SetData(data);
			Root = node;
			Count = 1;
			return;
		}

		Root->Add(data);
		Count++;
	}

	//pryamoy (NLR)
    vector<T> Preorder()
	{
		if (Root == nullptr)
		{
			return vector<int>();
		}

		return Preorder(Root);
	}

	//obratniy (post-order) LRN
	vector<T> Postorder()
	{
		if (Root == nullptr)
		{
			return vector<T>();
		}

		return Postorder(Root);
	}

	//centrirovanniy (in-order) LNR
	vector<T> Inorder()
	{
		if (Root == nullptr)
		{
			return vector<T>();
		}

		return Inorder(Root);
	}

	/// <summary>
	/// binary search
	/// </summary>
	/// <param name="item"></param>
	/// <returns>true if found, else false</returns>
	bool BinarySearch(T item)
	{
		try
		{
			if (Root != nullptr)
			{
				if (Root->GetData() == item)
				{
					return true;
				}
				else
				{
					if (Root->GetData() < item)
					{
						if (Root->GetRight() != nullptr)
							return Search(Root->GetRight(), item);
					}
					else if (Root->GetData() > item)
					{
						if (Root->GetLeft() != nullptr)
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


	/// <summary>
	/// empty constructor
	/// </summary>
	/// <returns></returns>
	Tree() {}

private:
	/// <summary>
	/// recursive help-method for preorder
	/// </summary>
	/// <param name="node"></param>
	/// <returns></returns>
	vector<T> Preorder(Node<T>* node)
	{
		vector<T> list;
		if (node != nullptr)
		{
			list.push_back(node->GetData());

			if (node->GetLeft() != nullptr)
			{
				auto V = Preorder(node->GetLeft());
				list.insert(list.end(), V.begin(), V.end());
			}

			if (node->GetRight() != nullptr)
			{
				auto V = Preorder(node->GetRight());
				list.insert(list.end(), V.begin(), V.end());
			}
		}

		return list;
	}
	/// <summary>
	/// recursive help-method for Postorder
	/// </summary>
	/// <param name="node"></param>
	/// <returns></returns>
	vector<T> Postorder(Node<T>* node)
	{
		vector<T> list;
		if (node != nullptr)
		{
			if (node->GetLeft() != nullptr)
			{
				auto V = Postorder(node->GetLeft());
				list.insert(list.end(), V.begin(), V.end());
			}

			if (node->GetRight() != nullptr)
			{
				auto V = Postorder(node->GetRight());
				list.insert(list.end(), V.begin(), V.end());
			}

			list.push_back(node->GetData());
		}
		return list;
	}
	/// <summary>
	/// recursive help-method for Inorder
	/// </summary>
	/// <param name="node"></param>
	/// <returns></returns>
	vector<T> Inorder(Node<T>* node)
	{
		vector<T> list;
		if (node != nullptr)
		{
			if (node->GetLeft() != nullptr)
			{
				auto V = Inorder(node->GetLeft());
				list.insert(list.end(), V.begin(), V.end());
			}

			list.push_back(node->GetData());

			if (node->GetRight() != nullptr)
			{
				auto V = Inorder(node->GetRight());
				list.insert(list.end(), V.begin(), V.end());
			}
		}

		return list;
	}
	/// <summary>
	/// recursive help-method for binary search
	/// </summary>
	/// <param name="node"></param>
	/// <param name="item"></param>
	/// <returns></returns>
	bool Search(Node<T>* node, T item)
	{
		if (node->GetData() == item)
		{
			return true;
		}
		else if (node->GetData() < item)
		{
			if (node->GetRight() != nullptr)
			{
				return Search(node->GetRight(), item);
			}
		}
		else
		{
			if (node->GetLeft() != nullptr)
			{
				return Search(node->GetLeft(), item);
			}
		}
		return false;
	}
};

