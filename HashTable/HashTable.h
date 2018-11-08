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
			hashedKey++;
		}

		nodesArr[hashedKey] = newNode;
	}

	 
private:
	int _tableSize;
	Node<T, K>** nodesArr;
};

#endif // HASHTABLE_H