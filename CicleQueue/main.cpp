#include <iostream>

using namespace std;

class Queue
{
	private:
	int _maxSize;
	int _currentIndex;
	int _countElements;
	int _indexIfQueueIsFull;
	string* _memory;

	public:
	Queue(int maxSize)
	{
		_maxSize = maxSize;
		_countElements = 0;
		_currentIndex = 0;
		_indexIfQueueIsFull = 0;
		_memory = new string[_maxSize];
	}
	
	Queue(const Queue& q)
	{
		_maxSize = q._maxSize;
		_countElements = q._countElements;
		_currentIndex = q._currentIndex;
		_indexIfQueueIsFull = q._indexIfQueueIsFull;
		_memory = q._memory;
	}

	~Queue()
	{
		Clear();
	}

	public:

	void Enqueue(const string & element)
	{
		if(IsFull() && _currentIndex == 0)
		{
			AddNewElement(++_indexIfQueueIsFull, element);
		}
		else if(IsFull())
		{
			_currentIndex = 0;
			AddNewElement(_currentIndex, element);
		}
		else
		{
			AddNewElement(_currentIndex, element);
			++_countElements;
			++_currentIndex;
		}
		
	}

	void Dequeue()
	{
		if(IsEmpty() == false)
		{
			DeleteFront();
			_currentIndex;
		}
	}

	void ShowInfo()
	{
		cout << "Size: " << _maxSize << endl;
		cout << "Elements: " << _countElements << endl;
		if(_countElements > 0)
		{
			for(int i = 0; i < _countElements; i++)
			{
				cout << _memory[i] << endl;
			}
		}
	}

	int GetSizeFront()
	{	
		if(IsEmpty() == false)
		{
			return _memory[0].size();
		}
	}

	int GetNumberOfElements()
	{
		return _countElements;
	}

	void Clear()
	{
		_maxSize = 0;
		_countElements = 0;
		_currentIndex = 0;
		_indexIfQueueIsFull = 0;
		delete _memory;
	}
	
	string Peek()
	{
		if(IsEmpty() == false)
		{
			string temp = _memory[0];
			DeleteFront();
			return temp;
		}
	}
	
	private:

	bool IsEmpty()
	{
		return _countElements == 0;
	}

	bool IsFull()
	{
		return _countElements == _maxSize;
	}

	void AddNewElement(int index, string element)
	{
		_memory[index] = element;
	}

	void DeleteFront()
	{
		for(int i = 1; i < _countElements; i++)
		{
			_memory[i - 1] = _memory[i];
		}
		--_countElements;
	}
};

int main()
{
	Queue q1(3);

	q1.Enqueue("1");
	q1.Enqueue("22");
	
	cout << q1.GetSizeFront() << endl;

	Queue q2(q1);
	
	q1.Dequeue();

	cout << q1.GetNumberOfElements() << endl;

	cout << q1.Peek() << endl;

	q1.Clear();





















	//CicleQueue q(3);
	//q.Enqueue("1123123");
	//q.Enqueue("22");
	//q.Enqueue("333");
	////q.ShowInfo();
	//
	////cout << q.GetFrontSize() << endl;

	///*string* value;
	//q.CopyFromFront(value);
	//cout << value << endl;*/
	//
	////q.Dequeue();

	//q.Clear();

	//cout << << endl;
	return 0;
}