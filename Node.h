#pragma once
#include <vector>
using namespace std;
/// <summary>
/// class "Node" of binary tree
/// </summary>
template<typename T>
class Node
{
private:
	 /// <summary>
	 /// info in node
	 /// </summary>
	 T Data;
     /// <summary>
     /// reference to left node
     /// </summary>
     Node *Left = nullptr;
	 /// <summary>
	 /// reference to right node
	 /// </summary>
	 Node *Right = nullptr;

public:
	/// <summary>
	/// empty constructor
	/// </summary>
	/// <returns></returns>
	Node()	{}

	/// <summary>
	/// getter info from node
	/// </summary>
	/// <returns>Data</returns>
	T GetData()
	{
		return Data;
	}
	/// <summary>
	/// getter reference to left node
	/// </summary>
	/// <returns>Left</returns>
	Node* GetLeft()
	{
		return Left;
	}
	/// <summary>
	/// getter reference to right node
	/// </summary>
	/// <returns>Right</returns>
	Node* GetRight()
	{
		return Right;
	}
	/// <summary>
	/// constructor with start-data node
	/// </summary>
	/// <param name="data"></param>
	/// <returns></returns>
	Node(T data)
	{
		Data = data;
	}
	/// <summary>
	/// constructor, which is initialize node with all needed info(Data, left, right) for this node(not recommended)
	/// </summary>
	/// <param name="data">info</param>
	/// <param name="left">reference to left node</param>
	/// <param name="right">reference to right node</param>
	/// <returns></returns>
	Node(int data, Node* left, Node* right)
	{
		Data = data;
		Left = left;
		Right = right;
	}

	/// <summary>
	/// setter for info node
	/// </summary>
	/// <param name="data">info</param>
	void SetData(T data)
	{
		Data = data;
	}
	/// <summary>
	/// setter for right node
	/// </summary>
	/// <param name="right"></param>
	void SetRight(Node* right)
	{
		Right = right;
	}
	/// <summary>
	/// setter for left node
	/// </summary>
	/// <param name="left"></param>
	void SetLeft(Node* left)
	{
		Left = left;
	}


public:
	//true from.CompareTo(to) from > to
	//false from.CompareTo(to) from < to
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
		throw exception("Binary Tree is in sh*t!");
	}
	/// <summary>
	/// adding reference to new node(left or right, else return)
	/// </summary>
	/// <param name="data">info</param>
	void Add(T data)
	{
		Node<T> *node = new Node<T>();
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
		else if (node->Data > Data)
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

