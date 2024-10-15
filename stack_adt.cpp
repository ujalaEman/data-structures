#include<iostream>
using namespace std;
template <typename T>
class Stack
{
	int capacity;
	int top;
	T* elements;
public:
	Stack(int n = 0)
	{
		capacity = n;
		 elements = new T[capacity];
		 top = -1;
	}
	int getTop()
	{
		return top;
	}
	bool isFull()
	{
		return top == capacity - 1;
	}
	 bool isEmpty()
	{
		return top == -1;
	}
	void push(T element)
	{
		if (!isFull())
		{
			elements[++top] = element;
		}
		else
		{
			cout << "Stack overflow!:(\n";
			exit(0); 
		}
	}
	T pop()
	{
		if (!isEmpty())
		{
			int temp = top;
			top--;
			return elements[temp];
		}
		else
		{
			cout << "Stack underflow!:(\n";
			exit(0);
		}
	}
	~Stack()
	{
		delete[] elements;
	}
};

int main()
{
	Stack<int> intStack(5); // Create a stack of integers with capacity 5
	intStack.push(10);
	intStack.push(20);
	cout << intStack.pop() << endl; 
	cout << intStack.pop() << endl; 
	cout << intStack.pop() << endl; 

	Stack<std::string> stringStack(3); // Create a stack of strings with capacity 3
	stringStack.push("Hello");
	stringStack.push("World");
	std::cout << stringStack.pop() << endl; // Output: World
	return 0;
}
