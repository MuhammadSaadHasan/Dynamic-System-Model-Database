#pragma once
#pragma once
#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
template <class t>
class Node
{
public:
	t data;
	Node* next;
	int linenum;
	string filename;

	Node()
	{
		data = 0;
		next = NULL;
	}

	Node(t d, Node* n)
	{
		data = d;
		next = n;
	}

	Node(t d, int l, string f)
	{
		data = d;
		linenum = l;
		filename = f;
	}

	void setData(t d)
	{
		data = d;
	}

	void setNext(Node* n)
	{

	}

	t getData()
	{

	}

	Node* getNext()
	{

	}

};

template <class t>
class SLinkedList {

public:

	Node<t>* head;


	SLinkedList()
	{
		head = NULL;
	}
	void insert(t d, int ln, string fn) {
		Node<t>* n = new Node<t>(d, ln, fn);
		n->next = NULL;
		if (head == NULL)
		{
			head = n;
		}
		else
		{
			Node<t>* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = n;
		}
	}
	void insertAtHead(t d) {

		Node<t>* newnode = new Node<t>(d);
		newnode->next = head;
		head = newnode;
	}
	int InsertAtIndex(t d, int index) {
		if (index < 0)
		{
			return -1;
		}
		int c_index = 1;
		Node<t>* currNode = head;
		while (currNode && index > c_index)
		{
			currNode = currNode->next;
			c_index++;
		}
		if (index > 0 && currNode == NULL) {
			return -1;
		}

		Node<t>* newnode = new Node<t>(d);
		newnode->next = currNode->next;
		currNode->next = newnode;

		//return newnode;
	}
	int search(t d) {
		Node<t>* currnode = head;
		int c_index = 0;
		while (currnode && currnode->data != d)
		{
			currnode = currnode->next;
			c_index++;
		}
		if (currnode)
		{
			return c_index;
		}
	}
	void update(int index, t d) {
		int c_index = 0;
		Node<t>* currNode = head;
		while (currNode && index > c_index)
		{
			currNode = currNode->next;
			c_index++;
		}
		currNode->setData(d);
	}
	void remove(int index) {

		Node<t>* prevNode = NULL;
		Node<t>* currNode = head;
		int c_index = 0;
		while (currNode && currNode->data != index)
		{
			prevNode = currNode;
			currNode = currNode->next;
			c_index++;
		}
		if (currNode)
		{
			if (prevNode) {
				prevNode->next = currNode->next;
			}
		}
	}
	void print() {
		int num = 0;
		Node<t>* currNode = head;
		if (head != NULL)
		{
			cout << "Duplicates:";
		}
		int count = 1;
		while (currNode != NULL)
		{
			cout << num + 1 << ")" << currNode->data << " Line:" << currNode->linenum << " ";
			currNode = currNode->next;
			num++;

		}
	}



};