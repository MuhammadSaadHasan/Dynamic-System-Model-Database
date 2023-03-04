#include<iostream>
#include<string>
#include"AVL.h"
#include<cmath>
#include"FileHandling.h"
#include"Btree.h"
#include"RBTree.h"
#include"BLink_list.h"
#include <windows.h>
#include <MMSystem.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
int main() {
	char choice;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);						//colors from 1 - 15 are colors with black background you can go from 1 - 256 with multiple background colors too
	SetConsoleTextAttribute(hConsole, 11);
	cout << "****************************";
	SetConsoleTextAttribute(hConsole, 6);
	cout << "WELCOME ";
	SetConsoleTextAttribute(hConsole, 1);
	cout<<"TO ";
	SetConsoleTextAttribute(hConsole, 6);
	cout << "DATA";
	SetConsoleTextAttribute(hConsole, 1);
	cout << " BASE";
	SetConsoleTextAttribute(hConsole, 6);
	cout << " MANAGEMENT";
	SetConsoleTextAttribute(hConsole, 1);
	cout << " SYSTEM";


	SetConsoleTextAttribute(hConsole, 11);
	cout << " ****************************" << endl << endl << endl;
	SetConsoleTextAttribute(hConsole, 14);
	cout << "Select which tree do you want to use for indexing:" << endl;
	cout << "1. AVL Tree" << endl;
	cout << "2. B-Tree" << endl;
	cout << "3. Red-Black Tree" << endl;
	cin >> choice;
	if (choice=='1')
	{
		char index;
		cout << "Which indexing you want to chose?" << endl;
		cout << "1. Indexing by ID" << endl;
		cout << "2. Indexing by year" << endl;
		cout << "3. Indexing by cause" << endl;
		cout << "4. Indexing by State" << endl;
		cout << "5. Indexing by Total Deaths" << endl;
		cout << "6. Indexing by Death Rate" << endl;
		cin >> index;
		if (index == '1') {
			AVLTree<int> bst;
			filehandling(bst,index);
			bst.print2D(bst.root,10);
			//bst.printLevelOrderBFS(bst.root);
			char query_choice;
			cout << "Query Menu!!!!" << endl;
			cout << "1. Position Search" << endl;
			cout << "2. Range Search" << endl;
			cout << "3. Delete" << endl;
			cout << "4. Update" << endl;
			
			cin >> query_choice;
			if (query_choice=='1')
			{
				int id;
				cout << "Enter ID to search:" << endl;
				cin >> id;
				TreeNode<int>*temp =bst.pointSearch(id, bst.root);
				displayTuple(temp);
			}
			else if (query_choice=='2')
			{
				int s, e;
				cout << "Enter starting range:" << endl;
				cin >> s;
				cout << "Enter ending range:" << endl;
				cin >> e;
				RangeQuery(bst.root, s, e);
			}
			else if (query_choice =='3')
			{
				int id;
				cout << "Enter ID to delete:" << endl;
				cin >> id;
				bst.delete_index(id, bst.root);
				bst.root = bst.deleteNode(bst.root, id);
				bst.print2D(bst.root, 10);
				//bst.printInorder(bst.root);
			}
			else if (query_choice =='4')
			{
				int id;
				string n, o;
				cout << "Enter ID to modify:" << endl;
				cin >> id;
				cin.ignore();
				cout << "Enter old value:";
				getline(cin, o);
				cout << "Enter new value:";
				getline(cin, n);
				bst.modifyIndex(id, bst.root, o, n);
			}
			
		}
		else if (index=='2')
		{
			AVLTree<int> bst;
			filehandling(bst,index);
			//bst.printLevelOrderBFS(bst.root);
			//bst.printInorder(bst.root);
			char query_choice;
			cout << "Query Menu!!!!" << endl;
			cout << "1. Position Search" << endl;
			cout << "2. Range Search" << endl;
			cout << "3. Delete" << endl;
			cout << "4. Update" << endl;
			cout << "5. Position Search where" << endl;
			cout << "6. Delete Where" << endl;
			cout << "7. Range Query Where" << endl;
			cin >> query_choice;
			if (query_choice == '1')
			{
				int id;
				cout << "Enter year to search:" << endl;
				cin >> id;
				TreeNode<int>* temp = bst.pointSearch(id, bst.root);
				displayTuple(temp);
			}
			else if (query_choice == '2')
			{
				int s, e;
				cout << "Enter starting range:" << endl;
				cin >> s;
				cout << "Enter ending range:" << endl;
				cin >> e;
				RangeQuery(bst.root, s, e);
			}
			else if (query_choice == '3')
			{
				int id;
				cout << "Enter year to delete:" << endl;
				cin >> id;
				bst.delete_index(id, bst.root);
				bst.root = bst.deleteNode(bst.root, id);
				//bst.printInorder(bst.root);
			}
			else if (query_choice == '4')
			{
				int id;
				string n, o;
				cout << "Enter year to modify:" << endl;
				cin >> id;
				cin.ignore();
				cout << "Enter old value:" << endl;
				getline(cin, o);
				cout << "Enter new value:" << endl;
				getline(cin, n);
				bst.modifyIndex(id, bst.root, o, n);
			}
			else if (query_choice=='5')
			{
				string val;
				int id;
				cout << "Enter year to display:" << endl;
				cin >> id;
				cin.ignore();
				cout << "Where:" << endl;
				getline(cin, val);
				TreeNode<int>* temp = bst.pointSearch(id, bst.root);
				displayTuple_Where(temp,val);


			}
			else if (query_choice=='6')
			{
				string val;
				int id;
				cout << "Enter year to delete:" << endl;
				cin >> id;
				cin.ignore();
				cout << "Where:" << endl;
				getline(cin, val);
				bst.delete_index_where(id, bst.root, val);
			}
			else if (query_choice=='7')
			{
				string val;
				int s, e;
				cout << "Enter starting range:" << endl;
				cin >> s;
				cout << "Enter ending range:" << endl;
				cin >> e;
				cin.ignore();
				cout << "Where:" << endl;
				getline(cin, val);
				RangeQueryWhere(bst.root, s, e, val);

			}
		}
		else if (index=='5')
		{
			AVLTree<int> bst;
			filehandling(bst, index);
			//bst.printLevelOrderBFS(bst.root);
			char query_choice;
			cout << "Query Menu!!!!" << endl;
			cout << "1. Position Search" << endl;
			cout << "2. Range Search" << endl;
			cout << "3. Delete" << endl;
			cout << "4. Update" << endl;
			cout << "5. Position Search where" << endl;
			cout << "6. Delete Where" << endl;
			cout << "7. Range Query Where" << endl;
			cin >> query_choice;
			if (query_choice == '1')
			{
				int id;
				cout << "Enter deaths to search:" << endl;
				cin >> id;
				TreeNode<int>* temp = bst.pointSearch(id, bst.root);
				displayTuple(temp);
			}
			else if (query_choice == '2')
			{
				int s, e;
				cout << "Enter starting range:" << endl;
				cin >> s;
				cout << "Enter ending range:" << endl;
				cin >> e;
				RangeQuery(bst.root, s, e);
			}
			else if (query_choice == '3')
			{
				int id;
				cout << "Enter deaths to delete:" << endl;
				cin >> id;
				bst.delete_index(id, bst.root);
				bst.root = bst.deleteNode(bst.root, id);
				//bst.printInorder(bst.root);
			}
			else if (query_choice == '4')
			{
				int id;
				string n, o;
				cout << "Enter death to modify:" << endl;
				cin >> id;
				cin.ignore();
				cout << "Enter old value:" << endl;
				getline(cin, o);
				cout << "Enter new value:" << endl;
				getline(cin, n);
				bst.modifyIndex(id, bst.root, o, n);
			}
			else if (query_choice == '5')
			{
				string val;
				int id;
				cout << "Enter death to display:" << endl;
				cin >> id;
				cin.ignore();
				cout << "Where:" << endl;
				getline(cin, val);
				TreeNode<int>* temp = bst.pointSearch(id, bst.root);
				displayTuple_Where(temp, val);


			}
			else if (query_choice == '6')
			{
				string val;
				int id;
				cout << "Enter death to delete:" << endl;
				cin >> id;
				cin.ignore();
				cout << "Where:" << endl;
				getline(cin, val);
				bst.delete_index_where(id, bst.root, val);
			}
			else if (query_choice == '7')
			{
				string val;
				int s, e;
				cout << "Enter starting range:" << endl;
				cin >> s;
				cout << "Enter ending range:" << endl;
				cin >> e;
				cin.ignore();
				cout << "Where:" << endl;
				getline(cin, val);
				RangeQueryWhere(bst.root, s, e, val);

			}
		}
		else if (index=='3')
		{
			AVLTree<string> bst;
			filehandling(bst, index);
			//bst.printLevelOrderBFS(bst.root);
			char query_choice;
			cout << "Query Menu!!!!" << endl;
			cout << "1. Position Search" << endl;
			cout << "2. Range Search" << endl;
			cout << "3. Delete" << endl;
			cout << "4. Update" << endl;
			cout << "5. Position Search where" << endl;
			cout << "6. Delete Where" << endl;
			cout << "7. Range Query Where" << endl;
			cin >> query_choice;
			if (query_choice == '1')
			{
				string id;
				cout << "Enter cause to search:" << endl;
				cin.ignore();
				getline(cin, id);
				TreeNode<string>* temp = bst.pointSearch(id, bst.root);
				displayTuple(temp);
			}
			else if (query_choice == '2')
			{
				string s, e;
				cout << "Enter starting range:" << endl;
				cin.ignore();
				getline(cin, s);
				cout << "Enter ending range:" << endl;
				//cin.ignore();
				getline(cin, e);
				RangeQuery(bst.root, s, e);
			}
			else if (query_choice == '3')
			{
				string id;
				cout << "Enter cause to delete:" << endl;
				cin.ignore();
				getline(cin, id);
				bst.delete_index(id, bst.root);
				bst.root = bst.deleteNode(bst.root, id);
				//bst.printInorder(bst.root);
			}
			else if (query_choice == '4')
			{
				string id;
				string n, o;
				cout << "Enter cause to modify:" << endl;
				cin.ignore();
				getline(cin, id);
				cout << "Enter old value:" << endl;
				getline(cin, o);
				//cin.ignore();
				cout << "Enter new value:" << endl;
				getline(cin, n);

				bst.modifyIndex(id, bst.root, o, n);
			}
			else if (query_choice=='5')
			{
				string id,where;
				cout << "Enter cause to search:" << endl;
				cin.ignore();
				getline(cin, id);
				cout << "Where:" << endl;
				getline(cin, where);
				TreeNode<string>* temp = bst.pointSearch(id, bst.root);
				displayTuple_Where(temp,where);

			}
			else if (query_choice=='6')
			{
				string id,where;
				cout << "Enter cause to delete:" << endl;
				cin.ignore();
				getline(cin, id);
				cout << "Where:" << endl;
				getline(cin, where);
				bst.delete_index_where(id, bst.root, where);
			}
			else if (query_choice == '7') {
				string s, e,where;
				cout << "Enter starting range:" << endl;
				cin.ignore();
				getline(cin, s);
				cout << "Enter ending range:" << endl;
				//cin.ignore();
				getline(cin, e);
				cout << "Where:" << endl;
				getline(cin, where);
				RangeQueryWhere(bst.root, s, e, where);
			}
		}
		else if (index == '4') {
			AVLTree<string> bst;
			filehandling(bst, index);
			//bst.printLevelOrderBFS(bst.root);
			char query_choice;
			cout << "Query Menu!!!!" << endl;
			cout << "1. Position Search" << endl;
			cout << "2. Range Search" << endl;
			cout << "3. Delete" << endl;
			cout << "4. Update" << endl;
			cout << "5. Position Search where" << endl;
			cout << "6. Delete Where" << endl;
			cout << "7. Range Query Where" << endl;
			cin >> query_choice;
			if (query_choice == '1')
			{
				string id;
				cout << "Enter State to search:" << endl;
				cin.ignore();
				getline(cin, id);
				TreeNode<string>* temp = bst.pointSearch(id, bst.root);
				displayTuple(temp);
			}
			else if (query_choice == '2')
			{
				string s, e;
				cout << "Enter starting range:" << endl;
				cin.ignore();
				getline(cin, s);
				cout << "Enter ending range:" << endl;
				//cin.ignore();
				getline(cin, e);
				RangeQuery(bst.root, s, e);
			}
			else if (query_choice == '3')
			{
				string id;
				cout << "Enter State to delete:" << endl;
				cin.ignore();
				getline(cin, id);
				bst.delete_index(id, bst.root);
				bst.root = bst.deleteNode(bst.root, id);
				//bst.printInorder(bst.root);
			}
			else if (query_choice == '4')
			{
				string id;
				string n, o;
				cout << "Enter State to modify:" << endl;
				cin.ignore();
				getline(cin, id);
				cout << "Enter old value:" << endl;
				//cin.ignore();
				getline(cin, o);
				cout << "Enter new value:" << endl;
				//cin.ignore();
				getline(cin, n);
				bst.modifyIndex(id, bst.root, o, n);
			}
			else if (query_choice=='5')
			{
				string id;
				string where;
				cout << "Enter State to search:" << endl;
				cin.ignore();
				getline(cin, id);
				cout << "Where:" << endl;
				getline(cin, where);
				TreeNode<string>* temp = bst.pointSearch(id, bst.root);
				displayTuple_Where(temp, where);

			}
			else if (query_choice=='6')
			{
				string id,where;
				cout << "Enter State to delete:" << endl;
				cin.ignore();
				getline(cin, id);
				cout << "Where:" << endl;
				getline(cin, where);
				bst.delete_index_where(id, bst.root, where);
			}
			else if (query_choice == '7') {
				string s, e,where;
				cout << "Enter starting range:" << endl;
				cin.ignore();
				getline(cin, s);
				cout << "Enter ending range:" << endl;
				getline(cin, e);
				cout << "Where:" << endl;
				getline(cin, where);
				RangeQueryWhere(bst.root, s, e, where);
			}
		}
		else if (index == '6') {
			AVLTree<float> bst;
			filehandling(bst, index);
			//bst.printLevelOrderBFS(bst.root);
			char query_choice;
			cout << "Query Menu!!!!" << endl;
			cout << "1. Position Search" << endl;
			cout << "2. Range Search" << endl;
			cout << "3. Delete" << endl;
			cout << "4. Update" << endl;
			cout << "5. Position Search where" << endl;
			cout << "6. Delete Where" << endl;
			cout << "7. Range Query Where" << endl;
			cin >> query_choice;
			if (query_choice == '1')
			{
				float id;
				cout << "Enter Death Rate to search:" << endl;
				cin >> id;
				TreeNode<float>* temp = bst.pointSearch(id, bst.root);
				displayTuple(temp);
			}
			else if (query_choice == '2')
			{
				float s, e;
				cout << "Enter starting range:" << endl;
				cin >> s;
				cout << "Enter ending range:" << endl;
				cin >> e;
				RangeQuery(bst.root, s, e);
			}
			else if (query_choice == '3')
			{
				float id;
				cout << "Enter Death Rate to delete:" << endl;
				cin >> id;
				bst.delete_index(id, bst.root);
				bst.root = bst.deleteNode(bst.root, id);
			}
			else if (query_choice == '4')
			{
				float id;
				string n, o;
				cout << "Enter Death Rate to modify:" << endl;
				cin >> id;
				cin.ignore();
				cout << "Enter old value:" << endl;
				getline(cin, o);
				cout << "Enter new value:" << endl;
				getline(cin, n);
				bst.modifyIndex(id, bst.root, o, n);
			}
			else if (query_choice == '5')
			{
				string val;
				float id;
				cout << "Enter death rate to display:" << endl;
				cin >> id;
				cin.ignore();
				cout << "Where:" << endl;
				getline(cin, val);
				TreeNode<float>* temp = bst.pointSearch(id, bst.root);
				displayTuple_Where(temp, val);


			}
			else if (query_choice == '6')
			{
				string val;
				float id;
				cout << "Enter death rate to delete:" << endl;
				cin >> id;
				cin.ignore();
				cout << "Where:" << endl;
				getline(cin, val);
				bst.delete_index_where(id, bst.root, val);
			}
			else if (query_choice == '7')
			{
				string val;
				float s, e;
				cout << "Enter starting range:" << endl;
				cin >> s;
				cout << "Enter ending range:" << endl;
				cin >> e;
				cin.ignore();
				cout << "Where:" << endl;
				getline(cin, val);
				RangeQueryWhere(bst.root, s, e, val);

			}

		}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////
	else if (choice == '2')
	{
		float ord, x;
		cout << "Enter the order of tree: ";
		cin >> ord;
		x = ord / 2;
		//cout << "Min val accomodate can be: " << round(x) - 1 << endl;
		char index;
		cout << "Which indexing you want to chose?" << endl;
		cout << "1. Indexing by ID" << endl;
		cout << "2. Indexing by year" << endl;
		cout << "3. Indexing by cause" << endl;
		cout << "4. Indexing by State" << endl;
		cout << "5. Indexing by Total Deaths" << endl;
		cout << "6. Indexing by Death Rate" << endl;
		cin >> index;
		if (index == '1') {
			BTree<int> bst(round(ord));
			filehandling(bst, index);
			bst.traverse();
			cout << "Query Menu!!!!" << endl;
			cout << "1. Position Search" << endl;
			cout << "2. Range Search" << endl;
			cout << "3. Delete" << endl;
			cout << "4. Update" << endl;
			char query_choice;
			cin >> query_choice;

			if (query_choice == '1')
			{
				int qw;
				cout << "Enter ID : ";
				cin >> qw;
				bst.selectsearch(qw);
			}
			if (query_choice == '2')
			{
				int qw, qw2;
				cout << "Enter ID : ";
				cin >> qw;
				cout << "Enter ID : ";
				cin >> qw2;
				bst.rangesearch(qw, qw2);
			}
			if (query_choice == '3')
			{
				int qw, qw2;
				cout << "Enter ID : ";
				cin >> qw;

				bst.deletekey(qw);
			}
			if (query_choice=='4')
			{
				int id;
				string n, o;
				cout << "Enter ID to modify:" << endl;
				cin >> id;
				cin.ignore();
				cout << "Enter old value:";
				getline(cin, o);
				cout << "Enter new value:";
				getline(cin, n);
				bst.updatekey(o, n);
			}
		}
		else if (index == '2')
		{
			BTree<int> bst(round(ord));
			filehandling(bst, index);
			bst.traverse();
			cout << "Query Menu!!!!" << endl;
			cout << "1. Position Search" << endl;
			cout << "2. Range Search" << endl;
			cout << "3. Delete" << endl;
			cout << "4. Update" << endl;
			char query_choice;
			cin >> query_choice;

			if (query_choice == '1')
			{
				int qw;
				cout << "Enter year : ";
				cin >> qw;
				bst.selectsearch(qw);
			}
			if (query_choice == '2')
			{
				int qw, qw2;
				cout << "Enter year : ";
				cin >> qw;
				cout << "Enter year : ";
				cin >> qw2;
				bst.rangesearch(qw, qw2);
			}
			if (query_choice == '3')
			{
				int qw, qw2;
				cout << "Enter year : ";
				cin >> qw;

				bst.deletekey(qw);
			}
			if (query_choice == '4')
			{
				int id;
				string n, o;
				cout << "Enter year to modify:" << endl;
				cin >> id;
				cin.ignore();
				cout << "Enter old value:";
				getline(cin, o);
				cout << "Enter new value:";
				getline(cin, n);
				bst.updatekey(o, n);
			}
		}
		else if (index == '5')
		{
			BTree<int> bst(round(ord));
			filehandling(bst, index);
			bst.traverse();
			cout << "Query Menu!!!!" << endl;
			cout << "1. Position Search" << endl;
			cout << "2. Range Search" << endl;
			cout << "3. Delete" << endl;
			cout << "4. Update" << endl;
			char query_choice;
			cin >> query_choice;

			if (query_choice == '1')
			{
				int qw;
				cout << "Enter total death : ";
				cin >> qw;
				bst.selectsearch(qw);
			}
			if (query_choice == '2')
			{
				int qw, qw2;
				cout << "Enter deaths : ";
				cin >> qw;
				cout << "Enter deaths : ";
				cin >> qw2;
				bst.rangesearch(qw, qw2);
			}
			if (query_choice == '3')
			{
				int qw, qw2;
				cout << "Enter deaths : ";
				cin >> qw;

				bst.deletekey(qw);
			}
			if (query_choice == '4')
			{
				int id;
				string n, o;
				cout << "Enter deaths to modify:" << endl;
				cin >> id;
				cin.ignore();
				cout << "Enter deaths value:";
				getline(cin, o);
				cout << "Enter new deaths value:";
				getline(cin, n);
				bst.updatekey(o, n);
			}
		}
		else if (index == '3')
		{
			BTree<string> bst(round(ord));
			filehandling(bst, index);
			bst.traverse();
			cout << "Query Menu!!!!" << endl;
			cout << "1. Position Search" << endl;
			cout << "2. Range Search" << endl;
			cout << "3. Delete" << endl;
			cout << "4. Update" << endl;
			char query_choice;
			cin >> query_choice;

			if (query_choice == '1')
			{
				string qw;
				cout << "Enter causes : ";
				cin >> qw;
				bst.selectsearch(qw);
			}
			if (query_choice == '2')
			{
				string qw, qw2;
				cout << "Enter causes : ";
				cin >> qw;
				cout << "Enter causes : ";
				cin >> qw2;
				bst.rangesearch(qw, qw2);
			}
			if (query_choice == '3')
			{
				string qw, qw2;
				cout << "Enter causes : ";
				cin >> qw;

				bst.deletekey(qw);
			}
			if (query_choice == '4')
			{
				string id;
				string n, o;
				cout << "Enter causse to modify:" << endl;
				cin >> id;
				cin.ignore();
				cout << "Enter causes value:";
				getline(cin, o);
				cout << "Enter new causes value:";
				getline(cin, n);
				//bst.update(id);
				bst.updatekey1(o, n);
			}
		}
		else if (index == '4') {
			BTree<string> bst(round(ord));
			filehandling(bst, index);
			bst.traverse();
			cout << "Query Menu!!!!" << endl;
			cout << "1. Position Search" << endl;
			cout << "2. Range Search" << endl;
			cout << "3. Delete" << endl;
			cout << "4. Update" << endl;
			char query_choice;
			cin >> query_choice;

			if (query_choice == '1')
			{
				string qw;
				cout << "Enter States : ";
				cin >> qw;
				bst.selectsearch(qw);
			}
			if (query_choice == '2')
			{
				string qw, qw2;
				cout << "Enter States : ";
				cin >> qw;
				cout << "Enter states : ";
				cin >> qw2;
				bst.rangesearch(qw, qw2);
			}
			if (query_choice == '3')
			{
				string qw, qw2;
				cout << "Enter states : ";
				cin >> qw;

				bst.deletekey(qw);
			}
			if (query_choice == '4')
			{
				string id;
				string n, o;
				cout << "Enter states to modify:" << endl;
				cin >> id;
				cin.ignore();
				cout << "Enter states value:";
				getline(cin, o);
				cout << "Enter new states value:";
				getline(cin, n);
				//bst.update(id);
				bst.updatekey1(o, n);
			}
		}
		else if (index == '6') {
			BTree<float> bst(round(ord));
			filehandling(bst, index);
			bst.traverse();
			cout << "Query Menu!!!!" << endl;
			cout << "1. Position Search" << endl;
			cout << "2. Range Search" << endl;
			cout << "3. Delete" << endl;
			cout << "4. Update" << endl;
			char query_choice;
			cin >> query_choice;

			if (query_choice == '1')
			{
				float qw;
				cout << "Enter death rate : ";
				cin >> qw;
				bst.selectsearch(qw);
			}
			if (query_choice == '2')
			{
				float qw, qw2;
				cout << "Enter deathRate : ";
				cin >> qw;
				cout << "Enter deathRate : ";
				cin >> qw2;
				bst.rangesearch(qw, qw2);
			}
			if (query_choice == '3')
			{
				float qw, qw2;
				cout << "Enter deathRate : ";
				cin >> qw;

				bst.deletekey(qw);
			}
			if (query_choice == '4')
			{
				int id;
				string n, o;
				cout << "Enter ID to modify:" << endl;
				cin >> id;
				cin.ignore();
				cout << "Enter old value:";
				getline(cin, o);
				cout << "Enter new value:";
				getline(cin, n);
				bst.updatekey(o, n);
			}
			
			
		}
	}
	else if (choice=='3')
	{
		char index;
		cout << "Which indexing you want to chose?" << endl;
		cout << "1. Indexing by ID" << endl;
		cout << "2. Indexing by year" << endl;
		cout << "3. Indexing by cause" << endl;
		cout << "4. Indexing by State" << endl;
		cout << "5. Indexing by Total Deaths" << endl;
		cout << "6. Indexing by Death Rate" << endl;
		cin >> index;
		if (index == '1') {
			char query_choice;
			RedBlackTree<int> bst;
			filehandling(bst, index);
			//bst.inorderTraversal(bst.root);
			cout << "Query Menu!!!!" << endl;
			cout << "1. Position Search" << endl;
			cout << "2. Range Search" << endl;
			cout << "3. Delete" << endl;
			cout << "4. Update" << endl;
			cin >> query_choice;
			if (query_choice == '1')
			{
				int id;
				cout << "Enter ID to search:" << endl;
				cin >> id;
				RedBlackNode<int>* temp = bst.IfItExistsReturnNodeLocation(id, bst.root);
				if (temp)
				{
					displayTuple(temp);

				}
				else
				{
					cout << "Doesnt exist!" << endl;
				}
			}
			else if (query_choice == '2')
			{
				int s, e;
				cout << "Enter starting range:" << endl;
				cin >> s;
				cout << "Enter ending range:" << endl;
				cin >> e;
				RangeQuery(bst.root, s, e);
			}
			else if (query_choice == '3')
			{
				int id;
				cout << "Enter ID to delete:" << endl;
				cin >> id;
				RedBlackNode<int>* temp = bst.IfItExistsReturnNodeLocation(id, bst.root);
				deleteTupleHelper(temp);
				bst.deleteNode(id, bst.root);

			}
			else if (query_choice == '4')
			{
				int id;
				string n, o;
				cout << "Enter ID to modify:" << endl;
				cin >> id;
				cin.ignore();
				cout << "Enter old value:";
				getline(cin, o);
				cout << "Enter new value:";
				getline(cin, n);
				bst.modifyIndex(id, bst.root, o, n);

			}

		}


		else if (index == '2')
		{
			char query_choice;
			RedBlackTree<int> bst;
			filehandling(bst, index);
			//bst.inorderTraversal(bst.root);
			cout << "Query Menu!!!!" << endl;
			cout << "1. Position Search" << endl;
			cout << "2. Range Search" << endl;
			cout << "3. Delete" << endl;
			cout << "4. Update" << endl;
			cin >> query_choice;
			if (query_choice == '1')
			{
				int year;
				cout << "Enter YEAR to search:" << endl;
				cin >> year;
				RedBlackNode<int>* temp = bst.IfItExistsReturnNodeLocation(year, bst.root);
				if (temp)
				{
					displayTuple(temp);
				}
				else
				{
					cout << "Doesnt exist!" << endl;
				}
			}
			else if (query_choice == '2')
			{
				int s, e;
				cout << "Enter starting range:" << endl;
				cin >> s;
				cout << "Enter ending range:" << endl;
				cin >> e;
				RangeQuery(bst.root, s, e);
			}
			else if (query_choice == '3')
			{
				int year;
				cout << "Enter YEAR to delete:" << endl;
				cin >> year;
				RedBlackNode<int>* temp = bst.IfItExistsReturnNodeLocation(year, bst.root);
				deleteTupleHelper(temp);
				bst.deleteNode(year, bst.root);
			}
			else if (query_choice == '4')
			{
				int year;
				string n, o;
				cout << "Enter YEAR to modify:" << endl;
				cin >> year;
				cin.ignore();
				cout << "Enter old value:";
				getline(cin, o);
				cout << "Enter new value:";
				getline(cin, n);
				bst.modifyIndex(year, bst.root, o, n);
			}
		}



		else if (index == '5')
		{
			char query_choice;
			RedBlackTree<int> bst;
			filehandling(bst, index);
			//bst.inorderTraversal(bst.root);
			cout << "Query Menu!!!!" << endl;
			cout << "1. Position Search" << endl;
			cout << "2. Range Search" << endl;
			cout << "3. Delete" << endl;
			cout << "4. Update" << endl;
			cin >> query_choice;
			if (query_choice == '1')
			{
				int deaths;
				cout << "Enter YEAR to search:" << endl;
				cin >> deaths;
				RedBlackNode<int>* temp = bst.IfItExistsReturnNodeLocation(deaths, bst.root);
				if (temp)
				{
					displayTuple(temp);
				}
				else
				{
					cout << "Doesnt exist!" << endl;
				}
			}
			else if (query_choice == '2')
			{
				int s, e;
				cout << "Enter starting range:" << endl;
				cin >> s;
				cout << "Enter ending range:" << endl;
				cin >> e;
				RangeQuery(bst.root, s, e);
			}
			else if (query_choice == '3')
			{
				int deaths;
				cout << "Enter DEATH NUMBER to delete:" << endl;
				cin >> deaths;
				RedBlackNode<int>* temp = bst.IfItExistsReturnNodeLocation(deaths, bst.root);
				deleteTupleHelper(temp);
				bst.deleteNode(deaths, bst.root);
			}
			else if (query_choice == '4')
			{
				int deaths;
				string n, o;
				cout << "Enter DEATH NUMBER to modify:" << endl;
				cin >> deaths;
				cin.ignore();
				cout << "Enter old value:";
				getline(cin, o);
				cout << "Enter new value:";
				getline(cin, n);
				bst.modifyIndex(deaths, bst.root, o, n);
			}
		}



		else if (index == '3')
		{
			char query_choice;
			RedBlackTree<string> bst;
			filehandling(bst, index);
			//bst.inorderTraversal(bst.root);
			cout << "Query Menu!!!!" << endl;
			cout << "1. Position Search" << endl;
			cout << "2. Range Search" << endl;
			cout << "3. Delete" << endl;
			cout << "4. Update" << endl;
			cin >> query_choice;
			if (query_choice == '1')
			{
				string cause;
				cout << "Enter CAUSE to search:" << endl;
				cin >> cause;
				RedBlackNode<string>* temp = bst.IfItExistsReturnNodeLocation(cause, bst.root);
				if (temp)
				{
					displayTuple(temp);
				}
				else
				{
					cout << "Doesnt exist!" << endl;
				}
			}
			else if (query_choice == '2')
			{
				string s, e;
				cout << "Enter starting range:" << endl;
				cin.ignore();
				getline(cin, s);
				cout << "Enter ending range:" << endl;
				getline(cin, e);
				RangeQuery(bst.root, s, e);
			}
			else if (query_choice == '3')
			{
				string cause;
				cout << "Enter CAUSE to delete:" << endl;
				cin.ignore();
				getline(cin, cause);
				RedBlackNode<string>* temp = bst.IfItExistsReturnNodeLocation(cause, bst.root);
				deleteTupleHelper(temp);
				bst.deleteNode(cause, bst.root);
			}
			else if (query_choice == '4')
			{
				string cause;
				string n, o;
				cout << "Enter CAUSE to modify:" << endl;
				cin.ignore();
				getline(cin, cause);
				cout << "Enter old value:";
				getline(cin, o);
				cout << "Enter new value:";
				getline(cin, n);
				bst.modifyIndex(cause, bst.root, o, n);
			}
		}
		else if (index == '4') {
			char query_choice;
			RedBlackTree<string> bst;
			filehandling(bst, index);
			//bst.inorderTraversal(bst.root);
			cout << "Query Menu!!!!" << endl;
			cout << "1. Position Search" << endl;
			cout << "2. Range Search" << endl;
			cout << "3. Delete" << endl;
			cout << "4. Update" << endl;
			cin >> query_choice;
			if (query_choice == '1')
			{
				string cause;
				cout << "Enter STATE to search:" << endl;
				cin >> cause;
				RedBlackNode<string>* temp = bst.IfItExistsReturnNodeLocation(cause, bst.root);
				if (temp)
				{
					displayTuple(temp);
				}
				else
				{
					cout << "Doesnt exist!" << endl;
				}
			}
			else if (query_choice == '2')
			{
				string s, e;
				cout << "Enter starting range:" << endl;
				cin.ignore();
				getline(cin, s);
				cout << "Enter ending range:" << endl;
				getline(cin, e);
				RangeQuery(bst.root, s, e);
			}
			else if (query_choice == '3')
			{
				string cause;
				cout << "Enter STATE to delete:" << endl;
				cin.ignore();
				getline(cin, cause);
				RedBlackNode<string>* temp = bst.IfItExistsReturnNodeLocation(cause, bst.root);
				deleteTupleHelper(temp);
				bst.deleteNode(cause, bst.root);
				
			}
			else if (query_choice == '4')
			{
				string cause;
				string n, o;
				cout << "Enter STATE to modify:" << endl;
				cin.ignore();
				getline(cin, cause);
				cout << "Enter old value:";
				getline(cin, o);
				cout << "Enter new value:";
				getline(cin, n);
				bst.modifyIndex(cause, bst.root, o, n);
			}
		}
		else if (index == '6') {
			char query_choice;
			RedBlackTree<float> bst;
			filehandling(bst, index);
			//bst.inorderTraversal(bst.root);
			cout << "Query Menu!!!!" << endl;
			cout << "1. Position Search" << endl;
			cout << "2. Range Search" << endl;
			cout << "3. Delete" << endl;
			cout << "4. Update" << endl;
			cin >> query_choice;
			if (query_choice == '1')
			{
				float id;
				cout << "Enter DEATH RATE to search:" << endl;
				cin >> id;
				RedBlackNode<float>* temp = bst.IfItExistsReturnNodeLocation(id, bst.root);
				if (temp)
				{
					displayTuple(temp);

				}
				else
				{
					cout << "Doesnt exist!" << endl;
				}
			}
			else if (query_choice == '2')
			{
				float s, e;
				cout << "Enter starting range:" << endl;
				cin >> s;
				cout << "Enter ending range:" << endl;
				cin >> e;
				RangeQuery(bst.root, s, e);
			}
			else if (query_choice == '3')
			{
				float id;
				cout << "Enter DEATH RATE to delete:" << endl;
				cin >> id;
				RedBlackNode<float>* temp = bst.IfItExistsReturnNodeLocation(id, bst.root);
				deleteTupleHelper(temp);
				bst.deleteNode(id, bst.root);
			}
			else if (query_choice == '4')
			{
				float id;
				string n, o;
				cout << "Enter ID to modify:" << endl;
				cin >> id;
				cin.ignore();
				cout << "Enter old value:";
				getline(cin, o);
				cout << "Enter new value:";
				getline(cin, n);
				bst.modifyIndex(id, bst.root, o, n);
			}
		}

	}

	return 0;

}