#pragma once
#include<iostream>
using namespace std; 


template<class T> 
class clsDynamicArray
{
protected:
	int _Size = 0;
	T* _TempArray;

public:
	T* OriginalArray;

	clsDynamicArray(int Size = 0)
	{
		if (Size < 0)
			Size = 0;

		_Size = Size;

		OriginalArray = new T[_Size];
	}

	~clsDynamicArray()
	{
		delete[] OriginalArray;
	}


	bool SetItem(int index, T value)
	{
		if (index >= _Size || index < 0)
		{
			return false;
		}

		OriginalArray[index] = value;
		return true;


	}

	bool IsEmpty()
	{
		return _Size == 0;
	}

	int Size()
	{
		return _Size;
	}

	void Resize(int NewSize)
	{

		if (NewSize < 0)
		{
			NewSize = 0;
		};

		_TempArray = new T[NewSize];

		if (NewSize < _Size)
			_Size = NewSize;

		//copy all the data from original array until the size 
		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_Size = NewSize;
		delete[] OriginalArray;
		OriginalArray = _TempArray;

	}

	T GetItem(int index)
	{
		return OriginalArray[index];
	}

	void Reverse()
	{


		_TempArray = new T[_Size];
		int counter = 0; 

		for (int i = _Size - 1; i >= 0; i--)
		{
			_TempArray[counter] = OriginalArray[i];
			counter++;
		}

		delete[] OriginalArray; 
		OriginalArray = _TempArray;

	}

	void Clear()
	{
		_Size = 0;
		_TempArray = new T[0];
		delete[] OriginalArray;
		OriginalArray = _TempArray;
		
	}

	bool DeleteItemAt(int index)
	{
		if (index >= _Size || index < 0)
		{
			return false; 
		}

		_Size--;

		_TempArray = new T[_Size]; 

		//copy all befor index
		for (int i = 0; i < index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}
		//copy all after index
		for (int i = index + 1; i < _Size + 1; i++)
		{
			_TempArray[i - 1] = OriginalArray[i];
		}

		delete[] OriginalArray; 
		OriginalArray = _TempArray; 
		return true;	
	}

	void DeleteFirstItem()
	{
		DeleteItemAt(0);
	}

	void DelelteLastItem()
	{
		DeleteItemAt(_Size - 1);
	}

	int Find(T value)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == value)
				return i;
		}

		return -1;
	}

	bool DeleteItem(int value)
	{
		int index = Find(value);

		if (index == -1)
		{
			return false;
		}
		
			DeleteItemAt(index);
			return true;
		
	}

	bool InsertAt(int index, T value)
	{
		if (index > _Size || index < 0)
		{
			return false;
		}

		_Size++;
		_TempArray = new T[_Size ];
		

		//copy all befor index
		for (int i = 0; i < index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_TempArray[index] = value;

		for (int i = index ; i < _Size -1 ; i++)
		{
			_TempArray[i + 1] = OriginalArray[i ];
		}


		
		delete[] OriginalArray; 
		OriginalArray = _TempArray; 
		return true;
		
		
	}

	void InserAtBeginning(T value)
	{
		InsertAt(0 , value);
	}

	bool InsertAfter(int index ,T value)
	{
		if (index >= _Size)
		{
			return InsertAt(_Size - 1, value);
		}
		else
		{
			return InsertAt(index + 1, value);
		}
		
	}

	bool InsertBefore(int index,T value)
	{
		if (index < 1)
		{
			return InsertAt(index - 1, value);

		}
		else
		{
			return InsertAt(index - 1, value);

		}
	}

	bool InsertAtEnd(T value)
	{
		return InsertAt(_Size, value);
	}

	void PrintList()
	{
		for (int i = 0; i < _Size; i++)
		{
			cout << OriginalArray[i] << " ";
		}

		cout << endl;
	}

};
