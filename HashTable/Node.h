#ifndef NODE_H
#define NODE_H

template <typename T, typename K>
class Node
{
public:
	Node()
	{
		_key = "default";
		_data = 0;
	}

	Node(K key, T data)
	{
		_key = key;
		_data = data;
	}

	void setKey(K key)
	{
		_key = key;
	}

	void setdata(T data)
	{
		_data = data;
	}

	K getKey()
	{
		return _key;
	}

	T getData()
	{
		return _data;
	}
private:
	K _key;
	T _data;
};

#endif // NODE_H
