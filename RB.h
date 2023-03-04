#pragma once
#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include <fstream>
using namespace std;
template <class X>
class RBNode
{
public:
	X data;
	RBNode* next;
	int linenum;
	string filename;

	RBNode()
	{
		data = 0;
		next = NULL;
	}

	RBNode(X d, RBNode* n)
	{
		data = d;
		next = n;
	}

	RBNode(X d, int l, string f)
	{
		data = d;
		linenum = l;
		filename = f;
	}

	void setData(X d)
	{
		data = d;
	}

	void setNext(RBNode* n)
	{

	}

	X getData()
	{
		return data;
	}

	RBNode* getNext()
	{
		return next;
	}

};

template <class X>
class RBLinkedList
{

public:

	RBNode<X>* head;


	RBLinkedList()
	{
		head = NULL;
	}
	void insert(X d, int ln, string fn) {
		RBNode<X>* n = new RBNode<X>(d, ln, fn);
		n->next = NULL;
		if (head == NULL)
		{
			head = n;
		}
		else
		{
			RBNode<X>* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = n;
		}
	}
	void insertAtHead(X d) {

		RBNode<X>* newnode = new RBNode<X>(d);
		newnode->next = head;
		head = newnode;
	}
	int InsertAtIndex(X d, int index) {
		if (index < 0)
		{
			return -1;
		}
		int c_index = 1;
		RBNode<X>* currNode = head;
		while (currNode && index > c_index)
		{
			currNode = currNode->next;
			c_index++;
		}
		if (index > 0 && currNode == NULL) {
			return -1;
		}

		RBNode<X>* newnode = new RBNode<X>(d);
		newnode->next = currNode->next;
		currNode->next = newnode;

		//return newnode;
	}
	int search(X d) {
		RBNode<X>* currnode = head;
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
	void update(int index, X d) {
		int c_index = 0;
		RBNode<X>* currNode = head;
		while (currNode && index > c_index)
		{
			currNode = currNode->next;
			c_index++;
		}
		currNode->setData(d);
	}
	void remove(int index) {

		RBNode<X>* prevNode = NULL;
		RBNode<X>* currNode = head;
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
		RBNode<X>* currNode = head;
		if (head != NULL)
		{
			cout << "Duplicates:";
			//cout << head->data << " ";
		}
		int count = 1;
		while (currNode != NULL)
		{
			cout << num + 1 << ")" << currNode->data << " Line:" << currNode->linenum << " ";
			currNode = currNode->next;
			num++;

		}

	}

	void PrintList()
	{

		RBNode<X>* temp = head;
		while (temp)
		{
			string key = "", end1 = ".csv", line, path = "NCHS_ - _Leading_Causes_of_Death__United_States_1.csv";  //!file path
			fstream myfile;
			myfile >> std::noskipws;
			char choice = '1', x;
			bool start = false, end = false, open = false;
			int cc = 0, count = 1, i = 0, linenum = 1;
			if (myfile)
			{
				if (choice == '1')
				{
					for (int l = 1; l <= 10; l++)
					{
						myfile.open(path, ios::in);
						while (getline(myfile, line)) {
							if (count != 1)
							{
								if (temp->linenum == linenum)
								{
									cout << line << endl;
								}

							}
							linenum++;
							count++;
						}
						myfile.close();
						linenum = 1;
						count = 1;
						if (l == 9)   //!this changes the file path to the next excel file
						{
							path[46] = '1';
							path[47] = '0';
							path[48] = '\0';
							path.erase(48);
							path += end1;
						}
						else
						{
							path[46] += 1;
						}
					}

				}

			}

















			temp = temp->next;
		}

	}








};