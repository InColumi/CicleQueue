#include <iostream>
#include <fstream>
#include <string>

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

	~Queue()
	{
		delete[] _memory;
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
		_memory = new string[_maxSize];
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
	setlocale(LC_ALL, "ru");
	Queue q1(3);

	q1.Enqueue("1");
	q1.Enqueue("22");
	
	cout << q1.GetSizeFront() << endl;
	
	q1.Dequeue();

	cout << q1.GetNumberOfElements() << endl;

	cout << q1.Peek() << endl;

	q1.Clear();

	string line;
	fstream fromFile("file.txt");

	Queue q3(100);
	if(fromFile.is_open())
	{
		while(getline(fromFile, line))
		{
			q3.Enqueue(line);
		}
	}
	else
	{
		cout << "File is not found!" << endl;
	}
	fromFile.close();

	q3.ShowInfo();
	return 0;
}