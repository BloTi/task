#include<iostream>
#include<stack>
using namespace std;


template<typename T>
class Stack
{
public:
	Stack();
	void push(T data);
	unsigned int size() { return Size; };
	T Top() { return top->data; };
	bool empty();
	void pop();
	void swap(Stack<T>& stack);
	~Stack();
	
private:

	template<typename T>
	class Node
	{
	public:
		T data;
		Node* pPrev;

		Node(T data = T(), Node* pPrev = nullptr)
		{
			this->data = data;
			this->pPrev = pPrev;
		}
	};

	Node<T> *top;
	unsigned int Size;
};

template<typename T>
Stack<T>::Stack()
{
	Size = 0;
	top = nullptr;
}

template<typename T>
void Stack<T>::push(T data)
{
	if(top == nullptr)
		top = new Node<T>(data);
	else
	{
		Node<T> *current = this->top;
		top = new Node<T>(data);
		top->pPrev = current;
	}
	++Size;
}


template<typename T>
bool Stack<T>::empty()
{
	if (top == nullptr)
		return true;

	return false;
}

template<typename T>
void Stack<T>::pop()
{
	Node<T>* current = this->top;
	top = nullptr;
	top = current->pPrev;

	--Size;
}

template<typename T>
void Stack<T>::swap(Stack<T>& stack)
{
	Stack<T> current = *this;
	*this = stack;
	stack = current;
}

template<typename T>
Stack<T>::~Stack()
{
	while (Size)
	{
		pop();
	}
}


int main()
{
	Stack<int> stc1;
	stc1.push(33);
	stc1.push(15);
	stc1.push(23);

	cout << stc1.Top() << endl;
	cout << stc1.size() << endl;

	Stack<int> stc2;
	stc2.push(10);
	stc2.push(20);

	stc1.swap(stc2);

	cout << stc1.Top() << endl;
	cout << stc1.size() << endl;



	system("pause");
	return 0;
}