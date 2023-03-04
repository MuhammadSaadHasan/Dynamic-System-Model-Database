#pragma once
#include<iostream>
#include"AVL.h"
#include"Btree.h"
#include"RBTree.h"
using namespace std;
#include<string>
#include<fstream>
//template <typename A>
void filehandling(AVLTree<int>& tree ,char c) {
	string path = "NCHS_-_Leading_Causes_of_Death__United_States_1.csv";  //!file path
	//cout << path[46];
	fstream myfile;
	string end1 = ".csv";
	myfile >> std::noskipws;
	//myfile.open(path, ios::in);
	char choice = c;
	char x;
	string key = "";
	bool start = false;
	bool end = false;
	bool open = false;
	string line;
	int cc = 0;
	int count = 1;
	int i = 0;
	int linenum = 1;
	if (choice == '1')
	{


		for (int l = 1; l <= 2; l++)  //!loop to extract data from all 10 files
		{
			//!extracting data
			cout << path << endl;
			myfile.open(path, ios::in);
			while (getline(myfile, line)) {
				if (line != "\0")
				{
					if (count != 1)
					{
						while (line[i] != ',')
						{
							key += line[i];
							i++;
						}
						//cout << key << endl;
						tree.root = tree.insert(tree.root, stoi(key), linenum, path); //!insert the key in ur tree over here 
						key = "";
						i = 0;

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
	else if (choice=='2')
	{
		for (int l = 1; l <= 2; l++)
		{

			cout << path << endl;
			myfile.open(path, ios::in);

			while (getline(myfile, line)) {
				if (line != "\0") {
					if (count != 1)
					{
						while (line[i] != '\0')
						{
							if (cc == 1 && line[i] != ',')
							{
								key += line[i];
							}
							if (line[i] == ',')
							{
								cc++;
							}
							if (cc == 2)
							{
								//cout << key << endl;
								tree.root = tree.insert(tree.root, stoi(key), linenum, path); //!insert in tree
								key = "";
								i = 0;
								cc = 0;

								break;

							}
							i++;
						}
					}
				}
				count++;
				linenum++;
			}
			myfile.close();
			linenum = 1;
			count = 1;
			if (l == 9)
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
	else if (choice=='5')
	{
		bool bracket_open = false;
		bool comma_open = false;
		int comma_count = 0;
		//string l = "C:/Users/Muhammad Younas/source/repos/DataStructures/DSA_Project/DSA_Project/AVLDeaths/";
		
		for (int l = 1; l <= 2; l++)
		{

			cout << path << endl;
			myfile.open(path, ios::in);
			while (getline(myfile, line)) {
				if (line != "\0") {
					if (count != 1)
					{

						while (line[i] != '\0')
						{

							if (line[i] == '(')
							{
								bracket_open = true;

							}
							if (line[i] == ')')
							{
								bracket_open = false;
							}
							if (line[i] == '"')
							{
								comma_count++;
							}
							if (line[i] == '"' && comma_count == 1)
							{
								bracket_open = true;

							}
							if (line[i] == '"' && comma_count == 2)
							{
								bracket_open = false;
								comma_count = 0;
							}
							if (cc == 5 && line[i] != ',')
							{
								key += line[i];
							}
							if (line[i] == ',')
							{
								/*if (line[i - 1] == '9' && line[i + 1] == 'Y')
								{
								}*/
								if (!bracket_open) {
									//if (i!=0 && line[i - 1] == ')' || (line[i - 1] >= '0' && line[i - 1] >= '9') ){
									cc++;
								}
								//}}
							}
							if (cc == 6)
							{
								//cout << key << endl;


								tree.root = tree.insert(tree.root, stoi(key), linenum, path);//!insert here
								key = "";
								i = 0;
								cc = 0;
								break;
							}
							i++;
						}
					}
				}
				count++;
				linenum++;
			}
			myfile.close();
			linenum = 1;
			count = 1;
			if (l == 9)
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
void filehandling(AVLTree<string>& tree, char c) {
	string path = "NCHS_-_Leading_Causes_of_Death__United_States_1.csv";  //!file path
	//cout << path[46];
	fstream myfile;
	string end1 = ".csv";
	myfile >> std::noskipws;
	//myfile.open(path, ios::in);
	char choice = c;
	char x;
	string key = "";
	bool start = false;
	bool end = false;
	bool open = false;
	string line;
	int cc = 0;
	int count = 1;
	int i = 0;
	int linenum = 1;
	if (choice=='3')
	{
		bool bracket_open = false;
		bool comma_open = false;
		int comma_count = 0;
		//string l = "C:/Users/Muhammad Younas/source/repos/DataStructures/DSA_Project/DSA_Project/AVLCause/";
		
		for (int l = 1; l <= 2; l++)
		{

			cout << path << endl;
			myfile.open(path, ios::in);
			while (getline(myfile, line)) {
				if (line != "\0") {
					if (count != 1)
					{
						while (line[i] != '\0')
						{
							if (l == 7 && linenum == 495) {
								//cout << "h" << endl;
							}
							if (line[i] == '(')
							{
								bracket_open = true;

							}
							if (line[i] == ')')
							{
								bracket_open = false;
							}
							if (line[i] == '"')
							{
								comma_count++;
							}
							if (line[i] == '"' && comma_count == 1)
							{
								bracket_open = true;

							}
							if (line[i] == '"' && comma_count == 2)
							{
								bracket_open = false;
								comma_count = 0;
							}

							if (cc == 3 && line[i] != ',')
							{
								key += line[i];
							}
							if (line[i] == ',')
							{
								/*if (line[i - 1] == '9' && line[i + 1] == 'Y')
								{
								}*/
								if (!bracket_open) {
									//if (i!=0 && line[i - 1] == ')' || (line[i - 1] >= '0' && line[i - 1] >= '9') ){
									cc++;
								}
								//}}
							}
							if (cc == 4)
							{
								//cout << key << endl;
								tree.root = tree.insert(tree.root, key, linenum, path); //!insert here
								key = "";
								i = 0;
								cc = 0;
								break;
							}
							i++;
						}
					}
				}
				count++;
				linenum++;

			}
			myfile.close();
			linenum = 1;
			count = 1;
			if (l == 9)
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
	else if (choice=='4')
	{
		bool bracket_open = false;
		bool comma_open = false;
		int comma_count = 0;
		//string l = "C:/Users/Muhammad Younas/source/repos/DataStructures/DSA_Project/DSA_Project/AVLState/";
		
		for (int l = 1; l <= 2; l++)
		{

			cout << path << endl;
			myfile.open(path, ios::in);
			while (getline(myfile, line)) {
				if (line != "\0") {
					if (count != 1)
					{
						while (line[i] != '\0')
						{
							if (line[i] == '(')
							{
								bracket_open = true;

							}
							if (line[i] == ')')
							{
								bracket_open = false;
							}
							if (line[i] == '"')
							{
								comma_count++;
							}
							if (line[i] == '"' && comma_count == 1)
							{
								bracket_open = true;

							}
							if (line[i] == '"' && comma_count == 2)
							{
								bracket_open = false;
								comma_count = 0;
							}
							if (cc == 4 && line[i] != ',')
							{
								key += line[i];
							}
							if (line[i] == ',')
							{

								//if ((line[i - 1] == '9' && line[i + 1] == 'Y')) //|| (line[i - 1] == '9' && line[i + 1] == 'I') || (line[i - 1] == '3' && line[i + 1] == 'I'))
								//{
								//}
								if (!bracket_open) {
									//if (i!=0 && line[i - 1] == ')' || (line[i - 1] >= '0' && line[i - 1] >= '9') ){
									cc++;
								}
								//}}
							}
							if (cc == 5)
							{
								//cout << key << endl;
								tree.root = tree.insert(tree.root, key, linenum, path); //!insert here
								key = "";
								i = 0;
								cc = 0;
								break;
							}
							i++;
						}
					}
				}
				count++;
				linenum++;
			}
			myfile.close();
			linenum = 1;
			count = 1;
			if (l == 9)
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
void filehandling(AVLTree<float>& tree, char c) {
	string path = "NCHS_-_Leading_Causes_of_Death__United_States_1.csv";  //!file path
	//cout << path[46];
	fstream myfile;
	string end1 = ".csv";
	myfile >> std::noskipws;
	//myfile.open(path, ios::in);
	char choice = c;
	char x;
	string key = "";
	bool start = false;
	bool end = false;
	bool open = false;
	string line;
	int cc = 0;
	int count = 1;
	int i = 0;
	int linenum = 1;
	if (choice == '6')
	{
		bool bracket_open = false;
		bool comma_open = false;
		int comma_count = 0;
		//string l = "C:/Users/Muhammad Younas/source/repos/DataStructures/DSA_Project/DSA_Project/AVLDeathRate/";

		for (int l = 1; l <= 2; l++)
		{

			cout << path << endl;
			myfile.open(path, ios::in);
			while (getline(myfile, line)) {
				if (line != "\0") {
					if (count != 1)
					{
						//cout << line << endl;
						while (line[i] != '\0')
						{
							if (line[i] == '(')
							{
								bracket_open = true;

							}
							if (line[i] == ')')
							{
								bracket_open = false;
							}
							if (line[i] == '"')
							{
								comma_count++;
							}
							if (line[i] == '"' && comma_count == 1)
							{
								bracket_open = true;

							}
							if (line[i] == '"' && comma_count == 2)
							{
								bracket_open = false;
								comma_count = 0;
							}
							if (cc == 6 && line[i] != ',')
							{
								key += line[i];
							}
							if (line[i] == ',')
							{
								/*if (line[i - 1] == '9' && line[i + 1] == 'Y')
								{
								}*/
								if (!bracket_open) {
									//if (i!=0 && line[i - 1] == ')' || (line[i - 1] >= '0' && line[i - 1] >= '9') ){
									cc++;
								}
								//}}
							}
							if (line[i + 1] == '\0')
							{
								//cout << key << endl;
								tree.root = tree.insert(tree.root, stof(key), linenum, path);//!insert here
								key = "";
								i = 0;
								cc = 0;
								break;
							}
							i++;
						}
					}
				}
				count++;
				linenum++;
			}
			myfile.close();
			linenum = 1;
			count = 1;
			if (l == 9)
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
void filehandling(BTree<int>& tree, char c) {
	string path = "NCHS_-_Leading_Causes_of_Death__United_States_1.csv";  //!file path
	//cout << path[46];
	fstream myfile;
	string end1 = ".csv";
	myfile >> std::noskipws;
	//myfile.open(path, ios::in);
	char choice = c;
	char x;
	string key = "";
	bool start = false;
	bool end = false;
	bool open = false;
	string line;
	int cc = 0;
	int count = 1;
	int i = 0;
	int linenum = 1;
	if (choice == '1')
	{


		for (int l = 1; l <= 2; l++)  //!loop to extract data from all 10 files
		{
			//!extracting data
			cout << path << endl;
			myfile.open(path, ios::in);
			while (getline(myfile, line)) {
				if (line != "\0") {
					if (count != 1)
					{
						while (line[i] != ',')
						{
							key += line[i];
							i++;
						}
						//cout << key << endl;
						tree.insert(stoi(key), linenum, path); //!insert the key in ur tree over here 
						key = "";
						i = 0;

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
	else if (choice == '2')
	{
		for (int l = 1; l <= 2; l++)
		{

			cout << path << endl;
			myfile.open(path, ios::in);

			while (getline(myfile, line)) {
				if (line != "\0") {
					if (count != 1)
					{
						while (line[i] != '\0')
						{
							if (cc == 1 && line[i] != ',')
							{
								key += line[i];
							}
							if (line[i] == ',')
							{
								cc++;
							}
							if (cc == 2)
							{
								//cout << key << endl;
								tree.insert(stoi(key), linenum, path); //!insert in tree
								key = "";
								i = 0;
								cc = 0;

								break;

							}
							i++;
						}
					}
				}
				count++;
				linenum++;
			}
			myfile.close();
			linenum = 1;
			count = 1;
			if (l == 9)
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
	else if (choice == '5')
	{
		bool bracket_open = false;
		bool comma_open = false;
		int comma_count = 0;
		//string l = "C:/Users/Muhammad Younas/source/repos/DataStructures/DSA_Project/DSA_Project/AVLDeaths/";

		for (int l = 1; l <= 2; l++)
		{

			cout << path << endl;
			myfile.open(path, ios::in);
			while (getline(myfile, line)) {
				if (line != "\0") {
					if (count != 1)
					{

						while (line[i] != '\0')
						{

							if (line[i] == '(')
							{
								bracket_open = true;

							}
							if (line[i] == ')')
							{
								bracket_open = false;
							}
							if (line[i] == '"')
							{
								comma_count++;
							}
							if (line[i] == '"' && comma_count == 1)
							{
								bracket_open = true;

							}
							if (line[i] == '"' && comma_count == 2)
							{
								bracket_open = false;
								comma_count = 0;
							}
							if (cc == 5 && line[i] != ',')
							{
								key += line[i];
							}
							if (line[i] == ',')
							{
								/*if (line[i - 1] == '9' && line[i + 1] == 'Y')
								{
								}*/
								if (!bracket_open) {
									//if (i!=0 && line[i - 1] == ')' || (line[i - 1] >= '0' && line[i - 1] >= '9') ){
									cc++;
								}
								//}}
							}
							if (cc == 6)
							{
								//cout << key << endl;


								tree.insert(stoi(key), linenum, path);//!insert here
								key = "";
								i = 0;
								cc = 0;
								break;
							}
							i++;
						}
					}
				}
				count++;
				linenum++;
			}
			myfile.close();
			linenum = 1;
			count = 1;
			if (l == 9)
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
void filehandling(BTree<string>& tree, char c) {
	string path = "NCHS_-_Leading_Causes_of_Death__United_States_1.csv";  //!file path
	//cout << path[46];
	fstream myfile;
	string end1 = ".csv";
	myfile >> std::noskipws;
	//myfile.open(path, ios::in);
	char choice = c;
	char x;
	string key = "";
	bool start = false;
	bool end = false;
	bool open = false;
	string line;
	int cc = 0;
	int count = 1;
	int i = 0;
	int linenum = 1;
	if (choice == '3')
	{
		bool bracket_open = false;
		bool comma_open = false;
		int comma_count = 0;
		//string l = "C:/Users/Muhammad Younas/source/repos/DataStructures/DSA_Project/DSA_Project/AVLCause/";

		for (int l = 1; l <= 2; l++)
		{

			cout << path << endl;
			myfile.open(path, ios::in);
			while (getline(myfile, line)) {
				if (line != "\0") {
					if (count != 1)
					{
						while (line[i] != '\0')
						{
							if (l == 7 && linenum == 495) {
								//cout << "h" << endl;
							}
							if (line[i] == '(')
							{
								bracket_open = true;

							}
							if (line[i] == ')')
							{
								bracket_open = false;
							}
							if (line[i] == '"')
							{
								comma_count++;
							}
							if (line[i] == '"' && comma_count == 1)
							{
								bracket_open = true;

							}
							if (line[i] == '"' && comma_count == 2)
							{
								bracket_open = false;
								comma_count = 0;
							}

							if (cc == 3 && line[i] != ',')
							{
								key += line[i];
							}
							if (line[i] == ',')
							{
								/*if (line[i - 1] == '9' && line[i + 1] == 'Y')
								{
								}*/
								if (!bracket_open) {
									//if (i!=0 && line[i - 1] == ')' || (line[i - 1] >= '0' && line[i - 1] >= '9') ){
									cc++;
								}
								//}}
							}
							if (cc == 4)
							{
								//cout << key << endl;
								tree.insert(key, linenum, path); //!insert here
								key = "";
								i = 0;
								cc = 0;
								break;
							}
							i++;
						}
					}
				}
				count++;
				linenum++;

			}
			myfile.close();
			linenum = 1;
			count = 1;
			if (l == 9)
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
	else if (choice == '4')
	{
		bool bracket_open = false;
		bool comma_open = false;
		int comma_count = 0;
		//string l = "C:/Users/Muhammad Younas/source/repos/DataStructures/DSA_Project/DSA_Project/AVLState/";

		for (int l = 1; l <= 2; l++)
		{

			cout << path << endl;
			myfile.open(path, ios::in);
			while (getline(myfile, line)) {
				if (line != "\0") {
					if (count != 1)
					{
						while (line[i] != '\0')
						{
							if (line[i] == '(')
							{
								bracket_open = true;

							}
							if (line[i] == ')')
							{
								bracket_open = false;
							}
							if (line[i] == '"')
							{
								comma_count++;
							}
							if (line[i] == '"' && comma_count == 1)
							{
								bracket_open = true;

							}
							if (line[i] == '"' && comma_count == 2)
							{
								bracket_open = false;
								comma_count = 0;
							}
							if (cc == 4 && line[i] != ',')
							{
								key += line[i];
							}
							if (line[i] == ',')
							{

								//if ((line[i - 1] == '9' && line[i + 1] == 'Y')) //|| (line[i - 1] == '9' && line[i + 1] == 'I') || (line[i - 1] == '3' && line[i + 1] == 'I'))
								//{
								//}
								if (!bracket_open) {
									//if (i!=0 && line[i - 1] == ')' || (line[i - 1] >= '0' && line[i - 1] >= '9') ){
									cc++;
								}
								//}}
							}
							if (cc == 5)
							{
								//cout << key << endl;
								tree.insert(key, linenum, path); //!insert here
								key = "";
								i = 0;
								cc = 0;
								break;
							}
							i++;
						}
					}
				}
				count++;
				linenum++;
			}
			myfile.close();
			linenum = 1;
			count = 1;
			if (l == 9)
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
void filehandling(BTree<float>& tree, char c) {
	string path = "NCHS_-_Leading_Causes_of_Death__United_States_1.csv";  //!file path
	//cout << path[46];
	fstream myfile;
	string end1 = ".csv";
	myfile >> std::noskipws;
	//myfile.open(path, ios::in);
	char choice = c;
	char x;
	string key = "";
	bool start = false;
	bool end = false;
	bool open = false;
	string line;
	int cc = 0;
	int count = 1;
	int i = 0;
	int linenum = 1;
	if (choice == '6')
	{
		bool bracket_open = false;
		bool comma_open = false;
		int comma_count = 0;
		//string l = "C:/Users/Muhammad Younas/source/repos/DataStructures/DSA_Project/DSA_Project/AVLDeathRate/";

		for (int l = 1; l <= 2; l++)
		{

			cout << path << endl;
			myfile.open(path, ios::in);
			while (getline(myfile, line)) {
				if (line != "\0") {
					if (count != 1)
					{
						//cout << line << endl;
						while (line[i] != '\0')
						{
							if (line[i] == '(')
							{
								bracket_open = true;

							}
							if (line[i] == ')')
							{
								bracket_open = false;
							}
							if (line[i] == '"')
							{
								comma_count++;
							}
							if (line[i] == '"' && comma_count == 1)
							{
								bracket_open = true;

							}
							if (line[i] == '"' && comma_count == 2)
							{
								bracket_open = false;
								comma_count = 0;
							}
							if (cc == 6 && line[i] != ',')
							{
								key += line[i];
							}
							if (line[i] == ',')
							{
								/*if (line[i - 1] == '9' && line[i + 1] == 'Y')
								{
								}*/
								if (!bracket_open) {
									//if (i!=0 && line[i - 1] == ')' || (line[i - 1] >= '0' && line[i - 1] >= '9') ){
									cc++;
								}
								//}}
							}
							if (line[i + 1] == '\0')
							{
								//cout << key << endl;
								tree.insert(stof(key), linenum, path);//!insert here
								key = "";
								i = 0;
								cc = 0;
								break;
							}
							i++;
						}
					}
				}
				count++;
				linenum++;
			}
			myfile.close();
			linenum = 1;
			count = 1;
			if (l == 9)
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
void filehandling(RedBlackTree<int>& tree, char c) {
	string path = "NCHS_-_Leading_Causes_of_Death__United_States_1.csv";  //!file path
	//cout << path[46];
	fstream myfile;
	string end1 = ".csv";
	myfile >> std::noskipws;
	//myfile.open(path, ios::in);
	char choice = c;
	char x;
	string key = "";
	bool start = false;
	bool end = false;
	bool open = false;
	string line;
	int cc = 0;
	int count = 1;
	int i = 0;
	int linenum = 1;
	if (choice == '1')
	{


		for (int l = 1; l <= 2; l++)  //!loop to extract data from all 10 files
		{
			//!extracting data
			cout << path << endl;
			myfile.open(path, ios::in);
			while (getline(myfile, line)) {
				if (line != "\0") {
					if (count != 1)
					{
						while (line[i] != ',')
						{
							key += line[i];
							i++;
						}
						//cout << key << endl;
						tree.root = tree.insertNode(tree.root, stoi(key), linenum, path); //!insert the key in ur tree over here 
						key = "";
						i = 0;

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
	else if (choice == '2')
	{
		for (int l = 1; l <= 2; l++)
		{

			cout << path << endl;
			myfile.open(path, ios::in);

			while (getline(myfile, line)) {
				if (line != "\0") {
					if (count != 1)
					{
						while (line[i] != '\0')
						{
							if (cc == 1 && line[i] != ',')
							{
								key += line[i];
							}
							if (line[i] == ',')
							{
								cc++;
							}
							if (cc == 2)
							{
								//cout << key << endl;
								tree.root = tree.insertNode(tree.root, stoi(key), linenum, path); //!insert in tree
								key = "";
								i = 0;
								cc = 0;

								break;

							}
							i++;
						}
					}
				}
				count++;
				linenum++;
			}
			myfile.close();
			linenum = 1;
			count = 1;
			if (l == 9)
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
	else if (choice == '5')
	{
		bool bracket_open = false;
		bool comma_open = false;
		int comma_count = 0;
		//string l = "C:/Users/Muhammad Younas/source/repos/DataStructures/DSA_Project/DSA_Project/AVLDeaths/";

		for (int l = 1; l <= 2; l++)
		{

			cout << path << endl;
			myfile.open(path, ios::in);
			while (getline(myfile, line)) {
				if (line != "\0") {
					if (count != 1)
					{

						while (line[i] != '\0')
						{

							if (line[i] == '(')
							{
								bracket_open = true;

							}
							if (line[i] == ')')
							{
								bracket_open = false;
							}
							if (line[i] == '"')
							{
								comma_count++;
							}
							if (line[i] == '"' && comma_count == 1)
							{
								bracket_open = true;

							}
							if (line[i] == '"' && comma_count == 2)
							{
								bracket_open = false;
								comma_count = 0;
							}
							if (cc == 5 && line[i] != ',')
							{
								key += line[i];
							}
							if (line[i] == ',')
							{
								/*if (line[i - 1] == '9' && line[i + 1] == 'Y')
								{
								}*/
								if (!bracket_open) {
									//if (i!=0 && line[i - 1] == ')' || (line[i - 1] >= '0' && line[i - 1] >= '9') ){
									cc++;
								}
								//}}
							}
							if (cc == 6)
							{
								//cout << key << endl;


								tree.root = tree.insertNode(tree.root, stoi(key), linenum, path);//!insert here
								key = "";
								i = 0;
								cc = 0;
								break;
							}
							i++;
						}
					}
				}
				count++;
				linenum++;
			}
			myfile.close();
			linenum = 1;
			count = 1;
			if (l == 9)
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
void filehandling(RedBlackTree<string>& tree, char c) {
	string path = "NCHS_-_Leading_Causes_of_Death__United_States_1.csv";  //!file path
	//cout << path[46];
	fstream myfile;
	string end1 = ".csv";
	myfile >> std::noskipws;
	//myfile.open(path, ios::in);
	char choice = c;
	char x;
	string key = "";
	bool start = false;
	bool end = false;
	bool open = false;
	string line;
	int cc = 0;
	int count = 1;
	int i = 0;
	int linenum = 1;
	if (choice == '3')
	{
		bool bracket_open = false;
		bool comma_open = false;
		int comma_count = 0;
		//string l = "C:/Users/Muhammad Younas/source/repos/DataStructures/DSA_Project/DSA_Project/AVLCause/";

		for (int l = 1; l <= 2; l++)
		{

			cout << path << endl;
			myfile.open(path, ios::in);
			while (getline(myfile, line)) {
				if (line != "\0") {
					if (count != 1)
					{
						while (line[i] != '\0')
						{
							if (l == 7 && linenum == 495) {
								//cout << "h" << endl;
							}
							if (line[i] == '(')
							{
								bracket_open = true;

							}
							if (line[i] == ')')
							{
								bracket_open = false;
							}
							if (line[i] == '"')
							{
								comma_count++;
							}
							if (line[i] == '"' && comma_count == 1)
							{
								bracket_open = true;

							}
							if (line[i] == '"' && comma_count == 2)
							{
								bracket_open = false;
								comma_count = 0;
							}

							if (cc == 3 && line[i] != ',')
							{
								key += line[i];
							}
							if (line[i] == ',')
							{
								/*if (line[i - 1] == '9' && line[i + 1] == 'Y')
								{
								}*/
								if (!bracket_open) {
									//if (i!=0 && line[i - 1] == ')' || (line[i - 1] >= '0' && line[i - 1] >= '9') ){
									cc++;
								}
								//}}
							}
							if (cc == 4)
							{
								//cout << key << endl;
								tree.root = tree.insertNode(tree.root, key, linenum, path); //!insert here
								key = "";
								i = 0;
								cc = 0;
								break;
							}
							i++;
						}
					}
				}
				count++;
				linenum++;

			}
			myfile.close();
			linenum = 1;
			count = 1;
			if (l == 9)
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
	else if (choice == '4')
	{
		bool bracket_open = false;
		bool comma_open = false;
		int comma_count = 0;
		//string l = "C:/Users/Muhammad Younas/source/repos/DataStructures/DSA_Project/DSA_Project/AVLState/";

		for (int l = 1; l <= 2; l++)
		{

			cout << path << endl;
			myfile.open(path, ios::in);
			while (getline(myfile, line)) {
				if (line != "\0") {
					if (count != 1)
					{
						while (line[i] != '\0')
						{
							if (line[i] == '(')
							{
								bracket_open = true;

							}
							if (line[i] == ')')
							{
								bracket_open = false;
							}
							if (line[i] == '"')
							{
								comma_count++;
							}
							if (line[i] == '"' && comma_count == 1)
							{
								bracket_open = true;

							}
							if (line[i] == '"' && comma_count == 2)
							{
								bracket_open = false;
								comma_count = 0;
							}
							if (cc == 4 && line[i] != ',')
							{
								key += line[i];
							}
							if (line[i] == ',')
							{

								//if ((line[i - 1] == '9' && line[i + 1] == 'Y')) //|| (line[i - 1] == '9' && line[i + 1] == 'I') || (line[i - 1] == '3' && line[i + 1] == 'I'))
								//{
								//}
								if (!bracket_open) {
									//if (i!=0 && line[i - 1] == ')' || (line[i - 1] >= '0' && line[i - 1] >= '9') ){
									cc++;
								}
								//}}
							}
							if (cc == 5)
							{
								//cout << key << endl;
								tree.root = tree.insertNode(tree.root, key, linenum, path); //!insert here
								key = "";
								i = 0;
								cc = 0;
								break;
							}
							i++;
						}
					}
				}
				count++;
				linenum++;
			}
			myfile.close();
			linenum = 1;
			count = 1;
			if (l == 9)
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
void filehandling(RedBlackTree<float>& tree, char c) {
	string path = "NCHS_-_Leading_Causes_of_Death__United_States_1.csv";  //!file path
	//cout << path[46];
	fstream myfile;
	string end1 = ".csv";
	myfile >> std::noskipws;
	//myfile.open(path, ios::in);
	char choice = c;
	char x;
	string key = "";
	bool start = false;
	bool end = false;
	bool open = false;
	string line;
	int cc = 0;
	int count = 1;
	int i = 0;
	int linenum = 1;
	if (choice == '6')
	{
		bool bracket_open = false;
		bool comma_open = false;
		int comma_count = 0;
		//string l = "C:/Users/Muhammad Younas/source/repos/DataStructures/DSA_Project/DSA_Project/AVLDeathRate/";

		for (int l = 1; l <= 2; l++)
		{

			cout << path << endl;
			myfile.open(path, ios::in);
			while (getline(myfile, line)) {
				if (line != "\0") {
					if (count != 1)
					{
						//cout << line << endl;
						while (line[i] != '\0')
						{
							if (line[i] == '(')
							{
								bracket_open = true;

							}
							if (line[i] == ')')
							{
								bracket_open = false;
							}
							if (line[i] == '"')
							{
								comma_count++;
							}
							if (line[i] == '"' && comma_count == 1)
							{
								bracket_open = true;

							}
							if (line[i] == '"' && comma_count == 2)
							{
								bracket_open = false;
								comma_count = 0;
							}
							if (cc == 6 && line[i] != ',')
							{
								key += line[i];
							}
							if (line[i] == ',')
							{
								/*if (line[i - 1] == '9' && line[i + 1] == 'Y')
								{
								}*/
								if (!bracket_open) {
									//if (i!=0 && line[i - 1] == ')' || (line[i - 1] >= '0' && line[i - 1] >= '9') ){
									cc++;
								}
								//}}
							}
							if (line[i + 1] == '\0')
							{
								//cout << key << endl;
								tree.root = tree.insertNode(tree.root, stof(key), linenum, path);//!insert here
								key = "";
								i = 0;
								cc = 0;
								break;
							}
							i++;
						}
					}
				}
				count++;
				linenum++;
			}
			myfile.close();
			linenum = 1;
			count = 1;
			if (l == 9)
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