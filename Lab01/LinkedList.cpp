// LinkedList.cpp : Defines the exported functions for the DLL application.
//

#include "LinkedList.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

ILinkedList::ILinkedList() : m_count(0)
{

}

Node::Node() : m_value(-1), m_next(nullptr)
{

}
Node::Node(int val) : m_value(val), m_next(nullptr)
{

}
Node::Node(int val, Node * nextNode) : m_value(val), m_next(nextNode)
{

}
void Node::setItem(const int& val)
{
	m_value = val;
}
void Node::setNext(Node* nextNodePtr)
{
	m_next = nextNodePtr;
}
int Node::getItem() const
{
	return m_value;
}
Node * Node::getNext() const
{
	return m_next;
}
Node::~Node()
{
	std::cout << "Deleting node with value " << m_value << std::endl;
	//checks to see if node currently points to to next value, ripple deletes existing chain of values
	if (m_next != nullptr)
	{
		std::cout << "Node deleted" << std::endl;
		delete m_next;
	}
}


PointerBasedLinkedList::PointerBasedLinkedList() : ILinkedList(), m_head(nullptr)
{

}


/** Returns true if list is empty, otherwise true */
bool PointerBasedLinkedList::isEmpty() const
{
	//Check to see if m_count of node is 0 or NULL
	//NULL inclusive as node can be constructed without setting m_count
	if (m_count == 0 || m_count == NULL)
	{
		return true;
	}
	else 
	{
		return false;
	}
}


/** Adds a value to the LinkedList.  Return true if able to, otherwise false */
bool PointerBasedLinkedList::add(int val)
{
	//init head with first node if empty
	if (m_head == nullptr)
	{
		m_head = new Node(val);
		m_count++;
		return true;
	}
	//Set local pointer to start of node
	Node* cur = m_head;

	//as long as cur is not null cur is updated to next node pinter value
	while (cur->getNext() != nullptr)
	{
		cur = cur->getNext();
	}

	//last node is reached and next node value is set to passed value
	cur->setNext( new Node(val));
	cur = nullptr;

	//node count is updated
	m_count++;
	return true;
}


/** Remove a value to the LinkedList.  Return true if able to, otherwise false.
Will only remove one entry if there are multiple entries with the same value */
bool PointerBasedLinkedList::remove(int val)
{
	//init ptr vars to beginning of list to traverse nodes
	Node* prev = nullptr;
	Node* cur = m_head;

	//as long as cur is not null and the node value is not the passed value, iterate through the node list
	while (cur != nullptr && cur->getItem() != val)
	{
		prev = cur;
		cur = cur->getNext();
	}

	//if end of list is reached without finding the value in a node, return false
	if (cur == nullptr)
	{
		return false;
	}
	else 
	{
		//If value is found, previous node is updated to point to next node after current
		//current node is set to null, then deleted
		prev->setNext(cur->getNext());
		cur->setNext(nullptr);
		delete cur;
		//}
		cur = nullptr;
		//total node count is reduced by one
		m_count--;
		return true;
	}
}


/** Remove  all elements from LinkedList */
void PointerBasedLinkedList::clear()
{
	//delete destructs each node from head, head is reassigned to null and count is updated to 0
	delete m_head;
	m_head = nullptr;
	m_count = 0;
}


PointerBasedLinkedList::~PointerBasedLinkedList()
{
	//TODO - maybe not depending on how you implement Node::~Node
	//implmented in ~Node
	delete m_head;
}


std::string PointerBasedLinkedList::toString() const
{
	//init local vars to return
	string str = "";

	//set current to head of list
	Node* cur = m_head;

	//as long as current is not null, string is appended with current node value and a space
	while (cur != nullptr)
	{
		str += to_string(cur->getItem()) + " ";
		cur = cur->getNext();
	}

	//trim extra space from string to suffice test
	if (m_count > 0)
	{
		str.pop_back();
	}

	return str;
}


ArrayBasedLinkedList::ArrayBasedLinkedList() : ILinkedList()
{
    m_count = 0;
	// you got it for free :)
}


bool ArrayBasedLinkedList::isEmpty() const
{
	//count is always initialized or returned to 0, true if equal
	if (m_count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool ArrayBasedLinkedList::add(int val)
{
	//if mcount is less than array size (array not full), pass value into array at mcount and increment count
	if (m_count < 10)
	{
		m_values[m_count] = val;
		m_count++;
		return true;
	}
	else
	{
		return false;
	}
}


bool ArrayBasedLinkedList::remove(int val)
{
	//iterate through array up to count
	for (int i = 0; i < m_count; i++)
	{
		//if value is found in array iterate from current position updating current index with next index, unless end of array is reached, which is then set to null
		if (val == m_values[i])
		{
			for (int x = i; x < m_count; x++)
			{
				if (x == 9)
				{
					m_values[9] = NULL;
				}
				else
				{
					m_values[x] = m_values[x+1];
				}
			}
			//decrement total count of values
			m_count--;
			return true;
		}
	}
	return false;
}


void ArrayBasedLinkedList::clear()
{
	//iterate through array setting all values up to total count to null, reset count to 0
	for (int i = 0; i < m_count; i++)
	{
		m_values[i] = NULL;
	}
	m_count = 0;
}

ArrayBasedLinkedList::~ArrayBasedLinkedList()
{

}


std::string ArrayBasedLinkedList::toString() const
{
	//init string to be returned
	string str = "";

	//iterate through array up to total count while appending string with current index value and sapce
	for(int i = 0; i < m_count; i++){
		
		str += to_string(m_values[i]) + " ";
		
	}

	//remove extra space if values exist to suffice test
	if (m_count > 0){
		str.pop_back();
	}
	return str;
}
