#include <iostream>

#include "Queue.h"

// constructor
Queue::Queue()
{
	head = nullptr;
	tail = nullptr;
}

Queue::~Queue()
{
	while (!is_empty())
		dequeue();
}

// push a node at the end of the queue
void Queue::enqueue(char c)
{
	// creating new queue node
	Q_Node* node = new Q_Node();
	node->character = c;
	node->next = nullptr;

	// cheking if tail is null
	if (tail == nullptr)
	{
		// add node to both tail and had
		head = tail = node;
		return;
	}

	// adding node at the end of queue
	tail->next = node;
	tail = node;
}

// pop the first node of the queue
char Queue::dequeue()
{
	// ckeck if queue is not empty
	if (head == nullptr)
		return ':'; // return a random char

	char operand = head->character; // get the operand 
	head = head->next; // change the top of the queue

	// if the head is null change the tail to be null
	if (head == nullptr)
		tail = nullptr;

	return operand;
}

void Queue::print()
{
	Q_Node* temp = head;
	while (temp != nullptr)
	{
		std::cout << "operand: " << temp->character << std::endl;
		temp = temp->next;
	}
}

bool Queue::is_empty()
{
	return head == nullptr;
}