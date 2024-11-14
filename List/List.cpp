#include "List.h"
#include <iostream>
using namespace std;

List::List()
	:head(nullptr), tail(nullptr), size(0)
{}


List::List(const List& other)
	:head(nullptr), tail(nullptr), size(0)
{
	if (other.size == 0)
		return;

	Node* current = other.head;
	Node* prevNode = nullptr;
	Node* curNode = nullptr;
	while (current)
	{
		prevNode = curNode;
		curNode = new Node(prevNode, current->value);

		size == 0 ? head = curNode : prevNode->next = curNode;

		tail = curNode;
		current = current->next;
		size++;
	}
}
void List::push_back(int value)
{

	if (head && tail)
	{
		Node* new_node = new Node(tail, value);
		tail->next = new_node;
		tail = new_node;
	}
	else
	{
		Node* new_node = new Node(value);
		head = new_node;
		tail = new_node;
	}
	size++;
}

void List::push_front(int value)
{
	if (head && tail)
	{
		Node* new_node = new Node(value);
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
	else
	{
		Node* new_node = new Node(value);
		head = new_node;
		tail = new_node;
	}
	size++;
}

void List::clear()
{
	Node* current = head;
	while (current != nullptr)
	{
		Node* temp = current->next;
		delete current;
		current = temp;
		size--;
	}
	head = nullptr;
	tail = nullptr;
}

//int List::operator[](int index)
//{
//	Node* current = head;
//	for (size_t i = 0; i < index; i++)
//	{
//		current = current->next;
//	}
//	return current->value;
//}

bool List::insert(int index, int value)
{
	if (index < 0 || index > size)
	{
		return false;
	}
	Node* current = head;
	Node* new_node = new Node(value);
	if (index == size)
	{
		new_node->prev = tail;
		tail->next = new_node;
		tail = new_node;
		size++;
		return true;
	}
	
	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}
	if (current->prev)
	{
		current->prev->next = new_node;
		new_node->prev = current->prev;
	}
	else
	{
		head = new_node;
	}
	new_node->next = current;
	current->prev = new_node;
	size++;
	return true;
}

int List::replace(int key, int value)
{
	Node* current = head;
	int count = 0;
	while (current)
	{
		if (current->value == key)
		{
			current->value = value;
			count++;
		}
		current = current->next;
	}
	return count;
}

int List::replace(bool(*predicate)(int value), int value)
{
	Node* current = head;
	int count = 0;
	while (current)
	{
		if (predicate(current->value))
		{
			current->value = value;
			count++;
		}
		current = current->next;
	}
	return count;
}

void List::show() const
{
	Node* current = head;
	while (current)
	{
		cout << current->value << " ";
		current = current->next;
	}
	cout << endl;
}

int List::front() const
{
	if (head)
	{
		return head->value;
	}
	else
	{
		return 0;
	}
}

int List::back() const
{
	if (tail)
	{
		return tail->value;
	}
	else
	{
		return 0;
	}
}

List& List::operator+(List& other)
{
	return *this;
}

List::~List()
{
	clear();
}