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
	if (m_next != nullptr){
		std::cout << "Node deleted" << std::endl;
		delete m_next;
	}
}

PointerBasedLinkedList::PointerBasedLinkedList() : ILinkedList(), m_head(nullptr)
{

}
/** Returns true  if list is empty, otherwise true */
bool PointerBasedLinkedList::isEmpty() const
{
	if (m_count == 0 || m_count == NULL){
		return true;
	}else {
		return false;
	}
}
/** Adds a value to the LinkedList.  Return true if able to, otherwise false */
bool PointerBasedLinkedList::add(int val)
{
	if (m_head == nullptr){
		m_head = new Node(val);
		m_count++;
		return true;
	}
	Node* cur = m_head;
	while (cur->getNext() != nullptr){
		cur = cur->getNext();
	}
	cur->setNext( new Node(val));
	cur = nullptr;
	m_count++;
	return true;
}
/** Remove a value to the LinkedList.  Return true if able to, otherwise false.
Will only remove one entry if there are multiple entries with the same value */
bool PointerBasedLinkedList::remove(int val)
{
	Node* prev = nullptr;
	Node* cur = m_head;
	while (cur != nullptr && cur->getItem() != val){
		prev = cur;
		cur = cur->getNext();
	}
	if (cur == nullptr){
		return false;
	}else {
		if (cur == m_head){
			m_head = cur->getNext();
			cur->setNext(nullptr);
			delete cur;
		}else{
			prev->setNext(cur->getNext());
			cur->setNext(nullptr);
			delete cur;
		}
		cur = nullptr;
		m_count--;
		return true;
	}
}

/** Remove  all elements from LinkedList */
void PointerBasedLinkedList::clear()
{
	delete m_head;
	m_head = nullptr;
	m_count = 0;
}
PointerBasedLinkedList::~PointerBasedLinkedList()
{
	//TODO - maybe not depending on how you implement Node::~Node
	delete m_head;
}

std::string PointerBasedLinkedList::toString() const
{
	string str = "";


    //TODO
	Node* cur = m_head;
	while (cur != nullptr){
		str += to_string(cur->getItem()) + " ";
		cur = cur->getNext();
	}
	if (m_count > 0){
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
	if (m_count == 0){
		return true;
	}else{
		return false;
	}
}
bool ArrayBasedLinkedList::add(int val)
{
	//TODO
	if (m_count < 10){
		m_values[m_count] = val;
		m_count++;
		return true;
	}
	else{
		return false;
	}
}
bool ArrayBasedLinkedList::remove(int val)
{
	//TODO
	for (int i = 0; i < m_count; i++){
		if (val == m_values[i]){
			for (int x = i; x < m_count; x++){
				if (x == 9){
					m_values[9] = NULL;
				}else{
					m_values[x] = m_values[x+1];
				}
			}
			m_count--;
			return true;
		}
	}
	return false;
}
void ArrayBasedLinkedList::clear()
{
	for (int i = 0; i < m_count; i++){
		m_values[i] = NULL;
	}
	m_count = 0;
}
ArrayBasedLinkedList::~ArrayBasedLinkedList()
{

}

std::string ArrayBasedLinkedList::toString() const
{
	string str = "";

	for(int i = 0; i < m_count; i++){
		
		str += to_string(m_values[i]) + " ";
		
	}
	if (m_count > 0){
		str.pop_back();
	}
	return str;
}
