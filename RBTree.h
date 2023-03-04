#pragma once
#include"RB.h"
#include <iostream>
#include <string>
using namespace std;

void deleteRBTuple(string path, int linenum) {
	string line;
	ifstream obj;

	obj.open(path);

	ofstream temp;
	temp.open("temp.csv");
	int count = 1;
	while (getline(obj, line)) {

		if (count != linenum)
			temp << line << endl;
		else
		{
			temp << endl;
		}

		count++;
	}

	temp.close();
	obj.close();

	const char* p = path.c_str();
	remove(p);
	rename("temp.csv", p);
}
void modifyRBTuple(string path, int linenum, string del, string replacement) {
	string line;
	ifstream obj;

	obj.open(path);

	ofstream temp;
	temp.open("temp.csv");
	int count = 1;
	while (getline(obj, line)) {

		if (count != linenum)
			temp << line << endl;
		else
		{
			if (line.find(del) != std::string::npos) {
				line.replace(line.find(del), del.length(), replacement);
				temp << line << endl;
			}
			else {
				temp << line << endl;
				cout << "Not found" << endl;
			}
		}

		count++;
	}

	temp.close();
	obj.close();

	const char* p = path.c_str();
	remove(p);
	rename("temp.csv", p);
}
template <typename T1>
class RedBlackNode
{

public:
	int color;
	T1 data;
	RBLinkedList<T1> list;
	RedBlackNode<T1>* parent;
	RedBlackNode<T1>* left;
	RedBlackNode<T1>* right;


	RedBlackNode(T1 d)
	{
		data = d;
		parent = NULL;
		left = NULL;
		right = NULL;
		color = 1;
	}
	RedBlackNode(bool dummycode, int c)
	{
		//data = 0;
		color = c;
		parent = NULL;
		left = NULL;
		right = NULL;
	}
	RedBlackNode(T1 d, int c)
	{
		data = d;
		color = c;
		parent = NULL;
		left = NULL;
		right = NULL;
	}

	bool check = false;
};



template <typename T1>
class RedBlackTree
{

public:
	RedBlackNode<T1>* root;

	RedBlackTree()
	{
		//root = NULL;
		//*this = NULL;
	}

	RedBlackTree(T1 data)
	{
		root = new RedBlackNode<T1>(data);
		root->color = 0;
	}
	RedBlackNode<T1>* insert(RedBlackNode<T1>* rootNode, RedBlackNode<T1>* newNode)
	{
		if (rootNode == NULL)
		{
			return newNode;
		}
		if (rootNode->data < newNode->data)
		{
			rootNode->right = insert(rootNode->right, newNode);
			rootNode->right->parent = rootNode;
		}
		else if (rootNode->data > newNode->data)
		{
			rootNode->left = insert(rootNode->left, newNode);
			rootNode->left->parent = rootNode;
		}

		return rootNode;

	}
	RedBlackNode<T1>* getGrandParent(RedBlackNode<T1>* n)
	{
		if ((n != NULL) && (n->parent != NULL))
		{
			return n->parent->parent;
		}
		return NULL;

	}

	RedBlackNode<T1>* getUncle(RedBlackNode<T1>* n)
	{
		RedBlackNode<T1>* grandparent = getGrandParent(n);

		if (grandparent == NULL)
		{
			return NULL;
		}
		if (n->parent == grandparent->left)
		{
			return grandparent->right;
		}
		if (n->parent == grandparent->right)
		{
			return grandparent->left;
		}

	}

	void RL(RedBlackNode<T1>*& n)
	{
		RedBlackNode<T1>* right = n->right;
		RedBlackNode<T1>* Parent = n->parent;
		n->right = right->left;

		if (n->right != NULL)
		{
			n->right->parent = n;
		}
		right->parent = Parent;

		if (n->parent == NULL)
		{
			this->root = right;
		}
		else if (n == n->parent->left)
		{
			n->parent->left = right;
		}
		else
		{
			n->parent->right = right;
		}

		right->left = n;
		n->parent = right;
	}

	void RR(RedBlackNode<T1>*& n)
	{
		RedBlackNode<T1>* nodeLeft = n->left;
		n->left = nodeLeft->right;

		if (n->left != NULL)
		{
			n->left->parent = n;
		}


		nodeLeft->parent = n->parent;

		if (n->parent == NULL)
		{
			this->root = nodeLeft;
		}
		else if (n == n->parent->left)
		{
			n->parent->left = nodeLeft;
		}
		else
		{
			n->parent->right = nodeLeft;
		}

		nodeLeft->right = n;
		n->parent = nodeLeft;

	}

	void ReArrangeTreeAfterInsertion(RedBlackNode<T1>*& n)
	{

		RedBlackNode<T1>* parent = NULL;
		RedBlackNode<T1>* grandparent = NULL;

		while ((n != root) && (n->color != 0) && (n->parent->color == 1))
		{

			parent = n->parent;
			grandparent = getGrandParent(n);


			if (parent == grandparent->left)
			{

				RedBlackNode<T1>* uncle = getUncle(n);
				if (uncle != NULL && uncle->color == 1)
				{
					grandparent->color = 1;
					parent->color = 0;
					uncle->color = 0;
					n = grandparent;
				}

				else
				{
					if (n == parent->right)
					{
						RL(parent);
						n = parent;
						parent = n->parent;
					}
					RR(grandparent);

					bool temp = parent->color;
					parent->color = grandparent->color;
					grandparent->color = temp;

					n = parent;
				}
			}

			else
			{
				RedBlackNode<T1>* uncle = getUncle(n);
				if ((uncle != NULL) && (uncle->color == 1))
				{
					grandparent->color = 1;
					parent->color = 0;
					uncle->color = 0;
					n = grandparent;
				}
				else
				{
					if (n == parent->left)
					{
						RR(parent);
						n = parent;
						parent = n->parent;
					}
					RL(grandparent);

					bool temp = parent->color;
					parent->color = grandparent->color;
					grandparent->color = temp;


					n = parent;
				}
			}
		}

		root->color = 0;
	}


	RedBlackNode<T1>* IfItExistsReturnNodeLocation(T1 d, RedBlackNode<T1>* root)
	{

		RedBlackNode<T1>* temp = root;
		while (temp != NULL)
		{
			if (d < temp->data)
			{
				temp = temp->left;
			}
			else if (d > temp->data) {
				temp = temp->right;
			}
			else
			{
				return temp;
			}
		}
		return NULL;
	}

	RedBlackNode<T1>* IfItExistsReturnNodeLocationTwo(T1 d, RedBlackNode<T1>* root)
	{

		RedBlackNode<T1>* temp = root;
		while (temp != NULL)
		{
			if (d < temp->data)
			{
				temp = temp->left;
			}
			else if (d > temp->data) {
				temp = temp->right;
			}
			else
			{
				return temp;
			}
		}
		return NULL;
	}




	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





	RedBlackNode<T1>* insertNode(RedBlackNode<T1>* r, T1 data, int linenum, string path)
	{
		RedBlackNode<T1>* temp = IfItExistsReturnNodeLocation(data, this->root);
		if (temp != NULL)
		{
			temp->list.insert(data, linenum, path);
		}
		else
		{
			RedBlackNode<T1>* newNode = new RedBlackNode<T1>(data);

			this->root = insert(this->root, newNode);
			newNode->list.insert(data, linenum, path);
			ReArrangeTreeAfterInsertion(newNode);

		}

		return this->root;
	}


	void inorderTraversal(RedBlackNode<T1>* root)
	{
		if (root != NULL)
		{
			inorderTraversal(root->left);

			root->list.print();
			//cout << endl;
			//cout << root->data << " ";
			inorderTraversal(root->right);
		}
	}
	bool DoesItExist(T1 d)
	{
		if (root == NULL) {
			return root;
		}
		else {
			RedBlackNode<T1>* temp = root;
			while (temp != NULL) {
				if (d == temp->data) {

					//temp->list.insert(d);
					temp->check = true;
					return true;
				}
				else if (d < temp->data) {
					temp = temp->left;
				}
				else {
					temp = temp->right;
				}
			}
			return false;
		}
	}


	RedBlackNode<T1>* deleteNode(T1 d, RedBlackNode<T1>* r)
	{
		if (DoesItExist(d) != true)
		{
			return NULL;
		}
		else
		{
			RedBlackNode<T1>* NodeToDelete = GoToDeleteNode(this->root, d);
			if (!NodeToDelete->right)
			{
				NodeToDelete->right = new RedBlackNode<T1>(false, 0);
				NodeToDelete->right->parent = NodeToDelete;
			}
			if (!NodeToDelete->left)
			{
				NodeToDelete->left = new RedBlackNode<T1>(false, 0);
				NodeToDelete->left->parent = NodeToDelete;
			}

			ReArrangeTreeAfterDelete(NodeToDelete);

		}
		return root;
	}

	RedBlackNode<T1>* getMAX(RedBlackNode<T1>* root)
	{
		if (root == NULL)
		{
			return NULL;
		}
		else if (root->right == NULL)
		{
			return root;
		}
		else
		{
			return getMAX(root->right);
		}
	}
	RedBlackNode<T1>* GoToDeleteNode(RedBlackNode<T1>* root, T1 key)
	{
		if (root == NULL)
		{
			return root;
		}
		if (key < root->data)
		{
			return GoToDeleteNode(root->left, key);
		}

		else if (key > root->data)
		{
			return GoToDeleteNode(root->right, key);
		}


		if (root->left == NULL or root->right == NULL)
		{
			return root;

		}

		RedBlackNode<T1>* temp = getMAX(root->left);
		root->data = temp->data;
		return GoToDeleteNode(root->left, temp->data);
	}

	void ReArrangeTreeAfterDelete(RedBlackNode<T1>* n)
	{
		if (n == NULL)
		{
			return;
		}

		if (n == root)
		{
			root = NULL;
			return;
		}

		if (n->color == 1 || n->left->color == 1 || n->right->color == 1)
		{
			RedBlackNode<T1>* child;
			if (n->left != NULL)
			{
				child = n->left;
			}
			else
			{
				child = n->right;
			}

			if (n == n->parent->left)
			{
				n->parent->left = child;
				if (child != NULL)
				{
					child->parent = n->parent;
					child->color = 0;
				}
				delete (n);
			}
			else
			{
				n->parent->right = child;
				if (child != NULL)
				{
					child->parent = n->parent;
					child->color = 0;
				}
				delete (n);
			}
		}
		else
		{
			RedBlackNode<T1>* sibling = NULL;
			RedBlackNode<T1>* parent = NULL;
			RedBlackNode<T1>* temp = n;
			temp->color = 2;																	//double black
			while (temp != root && temp->color == 2)
			{
				parent = temp->parent;
				if (temp == parent->left)
				{
					sibling = parent->right;

					if (!sibling->right)
					{
						sibling->right = new RedBlackNode<T1>(false, 0);
						sibling->right->parent = sibling;
					}
					if (!sibling->left)
					{
						sibling->left = new RedBlackNode<T1>(false, 0);
						sibling->left->parent = sibling;
					}

					if (sibling->color == 1)
					{
						sibling->color = 0;
						parent->color = 1;
						RL(parent);

					}
					else
					{
						if (sibling->left->color == 0 && sibling->right->color == 0)
						{
							sibling->color = 1;
							if (parent->color == 1)
							{
								parent->color = 0;
							}
							else
							{
								parent->color = 2;
							}
							temp = parent;
						}
						else
						{
							if (sibling->right->color == 0)
							{
								sibling->left->color = 0;
								sibling->color = 1;
								RR(sibling);
								sibling = parent->right;
							}
							sibling->color = parent->color;
							parent->color = 0;
							sibling->right->color = 0;
							RL(parent);
							break;
						}
					}
				}
				else
				{
					sibling = parent->left;
					if (!sibling->right)
					{
						sibling->right = new RedBlackNode<T1>(false, 0);
						sibling->right->parent = sibling;
					}
					if (!sibling->left)
					{
						sibling->left = new RedBlackNode<T1>(false, 0);
						sibling->left->parent = sibling;
					}
					if (sibling->color == 1)
					{
						sibling->color = 0;
						parent->color = 1;
						RR(parent);
					}
					else {
						if (sibling->left->color == 0 && sibling->right->color == 0)
						{
							sibling->color = 1;
							if (parent->color == 1)
							{
								parent->color = 0;
							}
							else
							{
								parent->color = 2;
							}
							temp = parent;
						}
						else {
							if (sibling->left->color == 0)
							{
								sibling->right->color = 0;
								sibling->color = 1;
								RL(sibling);
								sibling = parent->left;
							}
							sibling->color = parent->color;
							parent->color = 0;
							sibling->left->color = 0;
							RR(parent);
							break;
						}
					}
				}
			}
			if (n == n->parent->left)
			{
				n->parent->left = NULL;
			}
			else
			{
				n->parent->right = NULL;
			}
			delete(n);
			root->color = 0;
		}

	}

	void modifyIndex(T1 key, RedBlackNode<T1>* r, string old_val, string new_val) {
		RedBlackNode<T1>* temp = IfItExistsReturnNodeLocation(key, r);
		if (temp)
		{
			cout << "Modifying index!" << endl;
			modifyTuple(temp->list.head->filename, temp->list.head->linenum, old_val, new_val);
			if (temp->list.head != NULL)
			{
				cout << "Modifying Duplicates!" << endl;
				RBNode<T1>* temp1 = temp->list.head;
				while (temp1)
				{
					cout << temp1->linenum << endl;
					modifyTuple(temp1->filename, temp1->linenum, old_val, new_val);
					temp1 = temp1->next;
				}
			}
			cout << "Modifiaction Successful!" << endl;
		}
		else
		{
			cout << "Index not found!" << endl;
		}
	}









};
template <typename T1>
void displayTuple(RedBlackNode<T1>* root) {
	string file = root->list.head->filename;
	int linenum = 1;
	string line;
	int x;//= root->line;
	int count = 0;
	fstream myfile;
	/*myfile.open(file, ios::in);
	while (getline(myfile, line))
	{
		if (linenum == x)
		{
			cout << line << endl;
		}
		linenum++;
	}*/
	//myfile.close();
	if (root->list.head != NULL)
	{

		RBNode<T1>* temp = root->list.head;
		while (temp)
		{
			file = temp->filename;
			linenum = 1;
			line = "";
			x = temp->linenum;
			myfile.open(file, ios::in);
			while (getline(myfile, line))
			{
				if (linenum == x)
				{
					cout << line << endl;
				}
				linenum++;
			}
			myfile.close();
			temp = temp->next;
		}

	}
	else
	{
		cout << "No duplicates" << endl;
	}
}
template <typename T1>
void RangeQuery(RedBlackNode<T1>* r, T1 key1, T1 key2) {
	if (r == NULL)
	{
		return;
	}
	if (key1 < r->data)
	{
		RangeQuery(r->left, key1, key2);
	}
	if (key1 <= r->data && key2 >= r->data)
	{
		displayTuple(r);
	}
	RangeQuery(r->right, key1, key2);
}
template <typename T1>
void deleteTupleHelper(RedBlackNode<T1>* root) {
	string file = root->list.head->filename;
	int linenum = 1;
	string line;
	int x;//= root->line;
	int count = 0;
	fstream myfile;
	/*myfile.open(file, ios::in);
	while (getline(myfile, line))
	{
		if (linenum == x)
		{
			cout << line << endl;
		}
		linenum++;
	}*/
	//myfile.close();

	cout << root->list.head->filename << endl;

	if (root->list.head != NULL)
	{
		RBNode<T1>* temp = root->list.head;
		while (temp)
		{
			cout << temp->filename << endl;
			cout << temp->linenum << endl;

			deleteRBTuple(temp->filename, temp->linenum);
			temp = temp->next;
		}

	}
	else
	{
		cout << "No duplicates" << endl;
	}
}



