#ifndef NODE_H
#define NODE_H

template <typename T, typename K>
class Node
{
public:
	Node()
	{
		_isDeleted = false;
		_key = "default";
		_data = 0;
	}

	Node(K key, T data)
	{
		_isDeleted = false;
		_key = key;
		_data = data;
	}

	void setKey(K key)
	{
		_key = key;
	}

	void setData(T data)
	{
		_data = data;
	}

	 void setIsdeleted (bool isdeleted)
	{
		 _isDeleted = isdeleted;
	}

	K getKey()
	{
		return _key;
	}

	T getData()
	{
		return _data;
	}

	bool getIsDeleted() {
		return _isDeleted;
	}
private:
	K _key;
	T _data;
	bool _isDeleted;
};

#endif // NODE_H
