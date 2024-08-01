//*****************************************************************************************************
//
//		File:					stach.h
//
//		This program program will use array based Stack and test a stack data stracture.
//	
//		Other files required: 
//			1.	rpn.cpp
//			
//*****************************************************************************************************

#ifndef STACK_H
#define STACK_H

//*****************************************************************************************************

template <typename TYPE>
class Stack
{
private:
	TYPE* stack;
	int top;
	int capacity;
public:
	Stack(int cap = 100);
	~Stack();
	bool push(const TYPE& datain);
	bool pop(TYPE& dataout);
	bool peek(TYPE& dataout)const;
	int getNumValues()const;
	bool isFull()const;
	bool isEmpty()const;


};

//*****************************************************************************************************

template<typename TYPE>
Stack<TYPE>::Stack(int cap)
{
	capacity = cap;
	top = -1;
	stack = new TYPE[capacity];

}

//*****************************************************************************************************

template<typename TYPE>
Stack<TYPE>::~Stack()
{
	delete[]stack;
	stack = nullptr;
	capacity = 0;
	top = -1;

}

//*****************************************************************************************************

template<typename TYPE>
bool Stack<TYPE>::push(const TYPE& datain)
{
	bool  success = false;

	if (top < capacity)
	{
		top++;
		stack[top] = datain;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool Stack<TYPE>::pop(TYPE& dataout)
{
	bool  success = false;

	if (top > -1)
	{
		dataout = stack[top];
		top--;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool Stack<TYPE>::peek(TYPE& dataout) const
{
	bool  success = false;

	if (top > -1)
	{
		dataout = stack[top];
		success = true;
	}

	return success;;
}

//*****************************************************************************************************

template<typename TYPE>
int Stack<TYPE>::getNumValues() const
{
	return (top + 1);

}

//*****************************************************************************************************

template<typename TYPE>
bool Stack<TYPE>::isFull() const
{
	return (top + 1 == capacity);

}

//*****************************************************************************************************

template<typename TYPE>
bool Stack<TYPE>::isEmpty() const
{
	return (top == -1);

}

//*****************************************************************************************************

#endif