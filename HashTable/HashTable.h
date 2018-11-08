#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Node.h"
#include <cstddef>

template <typename T, typename K>
class HashTable
{
public:
	HashTable()
	{
		_tableSize = 5;
		nodesArr = new Node<T, K>*[_tableSize];
	}

	HashTable(int size)
	{
		_tableSize = size;
		nodesArr = new Node<T, K>*[_tableSize];
	}

	int hash (K key)
	{
		return key.length() % _tableSize;
	}

	void insert(K key, T data)
	{
		Node<T, K>* newNode = new Node<T, K>(key, data);

		int hashedKey = hash(newNode->getKey());

		while (nodesArr[hashedKey] != NULL && nodesArr[hashedKey]->getKey() != key)
		{
			if (hashedKey == _tableSize - 1)
			{
				hashedKey = 0;
			}
			else
			{
				hashedKey++;
			}
		}

		nodesArr[hashedKey] = newNode;
	}

	T retrieve(K keyToFind)
	{
		Node<T, K>* foundNode;

		int hashedKey = hash(keyToFind);

		while(nodesArr[hashedKey]->getKey() != keyToFind && nodesArr[hashedKey] != NULL)
		{
			if (hashedKey == _tableSize - 1)
			{
				hashedKey = 0;
			} 
			else
			{
				hashedKey++;
			}
		}

		if(nodesArr[hashedKey] == NULL)
		{
			return NULL;
		} 
		else
		{
			return nodesArr[hashedKey]->getData();
		}


		return foundNode;
	}

	/*void resizeTable(int tableSize)
	{
		
	}*/
	 
private:
	int _tableSize;
	Node<T, K>** nodesArr;
};

#endif // HASHTABLE_H