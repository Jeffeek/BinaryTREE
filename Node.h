#pragma once
#include <vector>
using namespace std;
class Node
{
private:
	 int Data;
     Node *Left;
	 Node *Right;

public:

	Node()	{}

	int GetData()
	{
		return Data;
	}
	Node* GetLeft()
	{
		return Left;
	}
	Node* GetRight()
	{
		return Right;
	}


	Node(int data)
	{
		Data = data;
	}

	Node(int data, Node* left, Node* right)
	{
		Data = data;
		Left = left;
		Right = right;
	}

	void SetData(int data)
	{
		Data = data;
	}
private:

	void SetRight(Node* right)
	{
		Right = right;
	}

	void SetLeft(Node* left)
	{
		Left = left;
	}

public:
	//true откуда.CompareTo(куда) откуда > куда
	//false откуда.CompareTo(куда) откуда < куда
	bool CompareTo(Node item)
	{
		if (Data > item.Data)
		{
			return true;
		}
		if (Data < item.Data)
		{
			return false;
		}
	}

	void Add(int data)
	{
		Node *node = new Node();
		node->Data = data;

		if (node->Data < Data)
		{
			if (Left == nullptr)
			{
				Left = node;
			}
			else
			{
				Left->Add(data);
			}
		}
		else if (node->Data > data)
		{
			if (Right == nullptr)
			{
				Right = node;
			}
			else
			{
				Right->Add(data);
			}
		}
	}
};

