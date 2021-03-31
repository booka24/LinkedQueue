#ifndef _QUEUELIST_
#define _QUEUELIST_
#include <iostream>
using namespace std;
template<class t>
class linkedQueue
{
private:
	struct Node
	{
		t item;
		Node* next;
	};
	int length;
	Node* frontPtr, * rearPtr;

public:

	linkedQueue() :frontPtr(0),rearPtr(0), length(0){}

	linkedQueue(linkedQueue<t>& v) {
		frontPtr = rearPtr = NULL;
		length = 0;
		Node* cur = new Node;
		cur = v.frontPtr;
		while (cur != NULL) {
			this->enqueue(cur->item);
			cur = cur->next;
		}
	}

	bool isEmpty()
	{
		return (length == 0);
	}

	void dequeue()
	{
		if (isEmpty())
			cout << "Empty Queue" << endl;
		else if (length == 1)
		{
			delete frontPtr;
			rearPtr = NULL;
			length = 0;
		}
		else
		{
			Node* current = frontPtr;
			frontPtr = frontPtr->next;
			delete current;//free(current)
			length--;
		}
	}

	void enqueue(t item)
	{
		Node* newNode = new Node;
		newNode->item = item;
		newNode->next = NULL;

		if (length == 0)
			rearPtr = frontPtr = newNode;
		else
		{
			rearPtr->next = newNode;
			rearPtr = newNode;
		}
		length++;
	}

	t front()
	{
		if (!isEmpty())
		return frontPtr->item;
		throw "Empty queue";
	}

	t rear()
	{
		assert(!isEmpty());
		return rearPtr->item;
	}

	void clearQueue()
	{
		Node* current;

		while (frontPtr != NULL)
		{
			current = frontPtr;
			frontPtr = frontPtr->next;
			delete current;
		}
		rearPtr = NULL;
		length = 0;
	}

	bool search(t item)
	{
		Node* cur = frontPtr;
		while (cur != NULL)
		{
			if (cur->item == item)
			{
				return true;
			}
			cur = cur->next;
		}
		return false;
	}
	int GetLength() {
		return length;
	}
	t get_max() {
		t temp = frontPtr->item;
		Node* cur = frontPtr->next;
		while (cur !=NULL)
		{
			if (temp < cur->item)
				temp = cur->item;
			cur = cur->next;
		}
		return temp;
	}

	t get_min() {
		t temp = frontPtr->item;
		Node* cur = frontPtr->next;
		while (cur != NULL)
		{
			if (temp > cur->item)
				temp = cur->item;
			cur = cur->next;
		}
		return temp;
	}
	void operator=(linkedQueue<t>& v) {
		Node* cur = v.frontPtr;
		this->clearQueue();
		while (cur != NULL) {
			this->enqueue(cur->item);
			cur = cur->next;
		}
	}
};

#endif