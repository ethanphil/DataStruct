// StackQueues.cpp : Defines the exported functions for the DLL application.
//

#include "StackQueue.h"

ArrayBasedStack::ArrayBasedStack(){}
ArrayBasedStack::~ArrayBasedStack(){}

int ArrayBasedStack::peek()
{
	if (this->isEmpty())
	{
		throw "ADT is empty";
	}
	else
	{
		return values[count-1];
	}


}

bool ArrayBasedStack::isEmpty() const
{
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ArrayBasedStack::push(int val)
{
	if (count == sizeof(values))
	{
		throw "ADT is full";
	}
	else
	{
		values[count] = val;
		count++;
		return true;
	}
	
}

bool ArrayBasedStack::pop()
{
	if (count == 0)
	{
		return false;
	}
	else
	{
		count--;
		return true;
	}
} 

std::string ArrayBasedStack::toString()
{
	std::string outstr = "";
	if(count ==0)
		return outstr;

	for(int i = 0; i < count; i++)
	{
		outstr += std::to_string(values[i]) + " ";
	}
	//Remove Space at end of line
	if (count > 0)
	{
		outstr.pop_back();
	}
}

ArrayBasedQueue::ArrayBasedQueue(){}
ArrayBasedQueue::~ArrayBasedQueue(){}

std::string ArrayBasedQueue::peekFront()
{
	if (this->isEmpty())
	{
		throw "ADT is emtpy";
	}
	else
	{
		return values[front];
	}


}

bool ArrayBasedQueue::enQueue(std::string val)
{
	if (count == sizeof(values))
	{
		throw "ADT is full";
	}
	else
	{
		//Equals 0 if it's going to be outside of the array, iterates normally otherwise
		back = (back + 1)%sizeof(values);
		values[back] = val;
		count++;
		return true;
	}
}

bool ArrayBasedQueue::deQueue()
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		//Equals 0 if it's going to be outside of the array, iterates normally otherwise
		front = (front + 1)%sizeof(values);
		count--;
		return true;
	}
}

bool ArrayBasedQueue::isEmpty() const
{
	if (count > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int ArrayBasedQueue::getFront()
{
	return front;
}

int ArrayBasedQueue::getBack()
{
	return back;
}