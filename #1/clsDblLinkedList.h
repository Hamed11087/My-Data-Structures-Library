#pragma once
#include<iostream>
#include <string>
using namespace std;


template<class T>
class clsDblLinkedList
{
private:
	int _Size = 0;

public:


	class Node
	{
	public:
		Node* Next;
		Node* Prev;
		T value;


	};
	Node* head = NULL;


	void InsertAtBeginning(T value)
	{
		Node* newNode = new Node();
		newNode->value = value;
		newNode->Next = head;
		newNode->Prev = NULL;
		if (head != NULL)
		{
			head->Prev = newNode;
		}
		head = newNode;
		_Size++;
	}

	void PrintList()
	{
		Node* temp = head;

		while (temp != NULL)
		{
			cout << temp->value << " ";
			temp = temp->Next;
		}
		cout << endl;
	}

	Node* Find(T value)
	{
		Node* temp = head;

		while (temp != NULL)
		{
			if (temp->value == value)
			{
				return temp;
			}

			temp = temp->Next;
		}

		return NULL;
	}

	void InsertAfter(Node* Current, T value)
	{
		Node* newNode = new Node();
		newNode->value = value;
		newNode->Next = Current->Next;
		newNode->Prev = Current;

		if (Current->Next != NULL)
		{
			Current->Next->Prev = newNode;
		}
		Current->Next = newNode;
		_Size++;
	}

	void InsertAtEnd(T value)
	{
		Node* newNode = new Node();
		newNode->value = value;
		newNode->Next = NULL;
		if (head == NULL)
		{
			newNode->Prev = NULL;
			head = newNode;
		}
		else
		{
			Node* current = head;
			while (current->Next != NULL)
			{
				current = current->Next;
			}

			current->Next = newNode;
			newNode->Prev = current;
		}
		_Size++;
	}

	void DeleteNode(Node* NodeTobeDelete)
	{

		if (head == NULL || NodeTobeDelete == NULL)
		{
			return;
		}

		if (head == NodeTobeDelete)
		{
			head = head->Next;
		}
		if (NodeTobeDelete->Next != NULL)
		{
			NodeTobeDelete->Next->Prev = NodeTobeDelete->Prev;
		}
		if (NodeTobeDelete->Prev != NULL)
		{
			NodeTobeDelete->Prev->Next = NodeTobeDelete->Next;
		}

		delete NodeTobeDelete;
		_Size--;

	}

	void DeleteFirstNode()
	{

		if (head == NULL)
		{
			return;
		}
		Node* temp = head;
		head = head->Next;
		if (head != NULL)
		{
			head->Prev = NULL;
		}

		delete temp;
		_Size--;
	}

	void DeleteLastNode()
	{
		if (head == NULL)
			return;

		if (head->Next == NULL)
		{
			delete head;
			head = NULL;
			return;
		}

		Node* Current = head;
		while (Current->Next->Next != NULL)
		{
			Current = Current->Next;
		}

		Node* temp = Current->Next;
		Current->Next = NULL;
		delete temp;
		_Size--;
	}

	int Size()
	{
		return _Size;
	}

	bool isEmpty()
	{
		return (_Size == 0 ? true : false);
	}

	void Clear()
	{
		while (_Size > 0)
		{
			DeleteFirstNode();
		}

	}


	void Reverse()
	{
		//To swap the prev with next we need third node to save it and then we can change it so this is what we did here 
		Node* Current = head;
		Node* temp = nullptr;
		
		while (Current != NULL)
		{
			temp = Current->Prev;
			Current->Prev = Current->Next;		
			Current->Next = temp; 
			Current = Current->Prev; 
			
		}

		if (temp != nullptr)
			head = temp->Prev;
	}

	Node* GetNode(int Index)
	{
		
		if (Index > _Size - 1 || Index < 0)
			return NULL;
		

			Node* temp = head; 
			int count = 0; 
			while (temp != NULL)
			{


				if (count == Index)
				{
					break; 
				}
				count++;
				temp = temp->Next;

			}

		return temp; 
	}

	T GetItem(int Index)
	{
		Node* N = GetNode(Index); 

		return (N==NULL) ? NULL :  N->value; 
	}

	bool UpdateItem(int Index, T value)
	{
		Node* ItemNode = GetNode(Index); 

		if (ItemNode != NULL)
		{
			ItemNode->value = value;
			ItemNode->value = value;
			return true; 
		}
		else
			return false; 

	}

	bool InsertAfter(int Indext, T value)
	{
	
		Node* ItemNode = GetNode(Indext); 
		if (ItemNode != NULL)
		{
			InsertAfter(ItemNode, value);
			return true;
		}
		else
			return false;
	}

};

