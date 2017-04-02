#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;

template <class E>
class List
{
public:
	List(){} // Default constructor
	virtual ~List(){} // Base destructor
	virtual void clear() = 0;
	virtual void insert(const E& item) = 0;
	virtual void append(const E& item) = 0;
	virtual E remove() = 0;
	virtual void moveToStart() = 0;
	virtual void moveToEnd() = 0;
	virtual void prev() = 0;
	virtual void next() = 0;
	virtual int length() const = 0;
	virtual int currPos() const = 0;
	virtual void moveToPos(int pos) = 0;
	virtual const E& getValue() const = 0;
};

template <class E>
class AList : public List<E>
{
private:
	int current;
	int size;
	int count;
	E* array;

public:
	AList(int S)			// Default constructor
	{
		current = 0;		// from 0 onwards
		size = S;			// from 1 onwords
		count = 0;			// from 1 onwards
		array = new E[S];
	}
	
	~AList()		// Base destructor
	{
		delete []array;
	}
	
	void clear()
	{
		delete []array;
		current = 0;
		count = 0;
		array = new E[size];
	}

	void insert(const E& item)
	{
		if (count < size)
		{
			for (int i = count-1; i >= current; i--)
			{
				array[i+1] = array[i];
			}
			array[current] = item;
			count++;
		}
	}

	void append(const E& item)
	{
		if (count <= size)
		{
			array[count] = item;
			count++;
			current = count - 1;
		}
	}

	E remove()
	{
		
		if (count != 0)
		{
			E item = array[current];
			for (int i = current; i < count - 1; i++)
			{
				array[i] = array[i + 1];
			}
			if (current == count - 1)
				current--;
			count--;
			return item;
		}
		
	}

	void moveToStart()
	{
		current = 0;
	}

	void moveToEnd()
	{
		current = count - 1;
	}

	void prev()
	{
		if (current != 0)
			current--;
	}

	void next()
	{
		if (current != count-1)
			current++;
	}

	int length() const
	{
		return count;
	}

	int currPos() const
	{
		return current + 1;
	}

	void moveToPos(int pos)
	{
		if (pos >= 1 || pos <= count)
		{
			current = pos - 1;
		}
	}

	const E& getValue() const
	{
		return array[current];
	}

	void display()
	{
		for (int i = 0; i < count; i++)
		{
			cout << array[i] << " | ";
		}
		cout << endl << "Count " << count << "\tCurr " << current+1 << endl;
	}
};

int main() 
{
	int LENGTH = 10;
	AList <int> test(LENGTH);

	cout << "------------Append-----------------" << endl;
	for (int i = 1; i <= 5; i++)
	{
		test.append(i);
	}
	test.display();
	cout << "------------Display----------------" << endl;
	test.insert(5);
	test.display();
	cout << "------------Remove-----------------" << endl;
	test.remove();
	test.display();
	cout << "------------Cursor-----------------" << endl;
	test.moveToStart();
	test.moveToEnd();
	test.prev();
	test.next();
	test.display();
	cout << "------------Length-----------------" << endl;
	cout<<"Length : "<<test.length();
	system("PAUSE");
	return 0;
}