#include <iostream>

using namespace std;

class CicleQueue
{
	private:
	struct Node
	{
		public:
		string Value;
		Node* Next;
		public:
		Node(): Next(NULL) {}
		Node(const string& value): Value(value), Next(NULL) {}
	};
	
	private:
	int _size;
	int _countElements;
	int _currentIndex;
	Node* _head;
	Node* _tail;
	bool _isOwerflow;
	
	public:
	CicleQueue(int size)
	{
		_size = size;
		_countElements = 0;
		_currentIndex = -1;
		_head = _tail = NULL;
		_isOwerflow = false;
	}

	private:

	bool IsFull()
	{
		return _countElements == _size;
	}

	void Delete()
	{
		Node* newTail = _tail->Next;
		_tail = new Node();
		_tail = newTail;
	}

	void PushByNode(Node* headOrTail, const string& newElement)
	{
		Node* newNode = new Node(newElement);
		if(_head != NULL)
		{
			headOrTail->Next = newNode;
			headOrTail = newNode;
		}
		else
		{
			_head = _tail = newNode;
		}
		++_countElements;
	}

	void PushBack(const string& newElement)
	{
		PushByNode(_tail, newElement);
	}

	void PushFrot(const string& newElement)
	{
		PushByNode(_head, newElement);
	}

	void PushByIndex(int index)
	{
		Node* newElement = _head;
		while(index-- > 0)
		{
			newElement = newElement->Next;
		}

	}

	public:

	void Enqueue(const string& newElement)
	{
		if(IsFull() != NULL)
		{

		}
		else
		{
			cout << "Queue is full" << endl;
		}
	}

	int GetFrontSize()
	{
		return _head->Value.size();
	}

	void Dequeue()
	{
		Node* oldElement = _head;
		_head = _head->Next;
		delete oldElement;
		--_countElements;
	}

	void Clear()
	{
		while(_head)
		{
			Dequeue();
		}
	}

	void ShowInfo()
	{
		cout << "Size: " << _size << endl;
		cout << "Elements: " << _countElements << endl;
		if(_countElements > 0)
		{
			Node* temp = _head;
			while(temp->Next != NULL)
			{
				cout << temp->Value << endl;
				temp = temp->Next;
			}
			cout << temp->Value << endl;
		}
	}
	
	/*void CopyFromFront(string *value)
	{
		value = &_head->Value;
	}*/
};


int main()
{
	CicleQueue q(3);
	q.Enqueue("1123123");
	q.Enqueue("22");
	q.Enqueue("333");
	//q.ShowInfo();
	
	//cout << q.GetFrontSize() << endl;

	/*string* value;
	q.CopyFromFront(value);
	cout << value << endl;*/
	
	//q.Dequeue();

	q.Clear();

	//cout << << endl;
	return 0;
}