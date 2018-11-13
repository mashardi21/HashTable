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
		_tableSize = sizeTable(size);
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

		while (nodesArr[hashedKey] != nullptr && nodesArr[hashedKey]->getKey() != key)
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

		while(nodesArr[hashedKey]->getKey() != keyToFind && nodesArr[hashedKey] != nullptr)
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

		if(nodesArr[hashedKey] == nullptr || nodesArr[hashedKey]->getIsDeleted() == true)
		{
			return nullptr;
		} 
		else
		{
			return nodesArr[hashedKey]->getData();
		}


		return foundNode;
	}

	void deleteNode(K keyToDelete)
	{
		Node<T, K>* delNode = retrieve(keyToDelete);

		if (delNode->getIsDeleted() == false)
		{
			delNode->setIsdeleted(true);
		}
	}

	int sizeTable(int size)
	{
		
	}

	/*void resizeTable(int tableSize)
	{
		
	}*/
	 
private:
	int _tableSize;
	Node<T, K>** nodesArr;
};

#endif // HASHTABLE_H