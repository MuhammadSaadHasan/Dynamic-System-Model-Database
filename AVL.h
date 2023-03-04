#pragma once
#pragma once
#include<fstream>
#include<queue>
#include<iostream>
#include"LinkedList.h"
using namespace std;
#define SPACE 10
template <typename A>
class TreeNode {
public:
    A value;
    TreeNode<A>* left;
    TreeNode<A>* right;
    SLinkedList<A> list;
    int line;
    string filename;

    TreeNode() {
        //value = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(A v) {
        value = v;
        left = NULL;
        right = NULL;
    }
};
void deleteTuple(string path, int linenum) {
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
void deleteTuplewhere(string path, int linenum,string x) {
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
            if (line.find(x) != std::string::npos)
            {
                temp << endl;
            }
            else {
                temp << line << endl;
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
void modifyTuple(string path, int linenum, string del, string replacement) {
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
template <typename A>
class AVLTree {
public:
    TreeNode<A>* root;
    AVLTree() {
        root = NULL;
    }
    bool isTreeEmpty() {
        if (root == NULL) {
            return true;
        }
        else {
            return false;
        }
    }
    
    int height(TreeNode<A>* r) {
        if (r == NULL)
            return -1;
        else {
           
            int lheight = height(r->left);
            int rheight = height(r->right);

            
            if (lheight > rheight)
                return (lheight + 1);
            else return (rheight + 1);
        }
    }

     
    int getBalanceFactor(TreeNode<A>* n) {
        if (n == NULL)
            return -1;
        return height(n->left) - height(n->right);
    }

    TreeNode<A>* rightRotate(TreeNode<A>* y) {
        TreeNode<A>* x1 = y->left;
        TreeNode<A>* T2 = x1->right;

          
        x1->right = y;
        y->left = T2;

        return x1;
    }

    TreeNode<A>* leftRotate(TreeNode<A>* X) {
        TreeNode<A>* y = X->right;
        TreeNode<A>* T2 = y->left;

          
        y->left = X;
        X->right = T2;

        return y;
    }

    TreeNode<A>* insert(TreeNode<A>* r, A X, int ln, string fn) {

        if (r == NULL) {
            TreeNode<A>* new_node = new TreeNode<A>();
            new_node->value = X;
            new_node->filename = fn;
            new_node->line = ln;
            r = new_node;
            
            return r;
        }

        if (X < r->value) {
            r->left = insert(r->left, X, ln, fn);
        }
        else if (X > r->value) {
            r->right = insert(r->right, X, ln, fn);
        }
        else {
            r->list.insert(X, ln, fn);

           
            return r;
        }

        int bf = getBalanceFactor(r);
         
        if (bf > 1 && X < r->left->value)
            return rightRotate(r);

       
        if (bf < -1 && X > r->right->value)
            return leftRotate(r);

        
        if (bf > 1 && X > r->left->value) {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }

        
        if (bf < -1 && X < r->right->value) {
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }

       
        return r;

    }

    TreeNode<A>* minValueNode(TreeNode<A>* node) {
        TreeNode<A>* current = node;
       
        while (current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    TreeNode<A>* deleteNode(TreeNode<A>* r, A v) {
       
        if (r == NULL) {
            return NULL;
        }
        
        else if (v < r->value) {
            r->left = deleteNode(r->left, v);
        }
        
        else if (v > r->value) {
            r->right = deleteNode(r->right, v);
        }
       
        else {
            
            if (r->left == NULL) {
                TreeNode<A>* temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL) {
                TreeNode<A>* temp = r->left;
                delete r;
                return temp;
            }
            else {
                
                TreeNode<A>* temp = minValueNode(r->right);
                
                r->value = temp->value;
                
                r->right = deleteNode(r->right, temp->value);
                
            }
        }

        int bf = getBalanceFactor(r);
        
        if (bf == 2 && getBalanceFactor(r->left) >= 0)
            return rightRotate(r);
         
        else if (bf == 2 && getBalanceFactor(r->left) == -1) {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }
        	
        else if (bf == -2 && getBalanceFactor(r->right) <= -0)
            return leftRotate(r);
      
        else if (bf == -2 && getBalanceFactor(r->right) == 1) {
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }

        return r;
    }

    void print2D(TreeNode<A>* r, int space) {
        if (r == NULL) 
            return;
        space += SPACE; 
        print2D(r->right, space); 
        cout << endl;
        for (int i = SPACE; i < space; i++) 
            cout << " "; // 5.1  
        cout << r->value << "\n";
        print2D(r->left, space); 
    }
    void printPreorder(TreeNode<A>* r) 
    {
        if (r == NULL)
            return;
        
        cout << r->value << " ";
       
        printPreorder(r->left);
      
        printPreorder(r->right);
    }

    void printInorder(TreeNode<A>* r) 
    {
        if (r == NULL)
            return;
        
        printInorder(r->left);
        
        cout << r->value << " ";
       
        printInorder(r->right);
    }
    void printPostorder(TreeNode<A>* r)
    {
        if (r == NULL)
            return;
        
        printPostorder(r->left);
       
        printPostorder(r->right);
        
        cout << r->value << " ";
    }

    
    void printGivenLevel(TreeNode<A>* r, int level) {
        if (r == NULL)
            return;
        else if (level == 0) {
            cout << "!!" << r->value << " ";
            r->list.print();
        }
        else 
        {
            printGivenLevel(r->left, level - 1);
            printGivenLevel(r->right, level - 1);
        }
    }
    void printLevelOrderBFS(TreeNode<A>* r) {
        int h = height(r);
        for (int i = 0; i <= h; i++)
            printGivenLevel(r, i);
    }

    TreeNode<A>* iterativeSearch(A v) {
        if (root == NULL) {
            return root;
        }
        else {
            TreeNode<A>* temp = root;
            while (temp != NULL) {
                if (v == temp->value) {
                    return temp;
                }
                else if (v < temp->value) {
                    temp = temp->left;
                }
                else {
                    temp = temp->right;
                }
            }
            return NULL;
        }
    }

    TreeNode<A>* recursiveSearch(TreeNode<A>* r, A val) {
        if (r == NULL || r->value == val)
            return r;

        else if (val < r->value)
            return recursiveSearch(r->left, val);

        else
            return recursiveSearch(r->right, val);
    }
    void saveFile(string path, TreeNode<A>* a) {
        if (a == NULL)
        {
            return;
        }
        string aa;

        string b = ".txt";
        aa = to_string(a->value);
        string x;
        //l += path;
        string l = path;
        l += aa;
        l += b;
        //cout << l;
        fstream myfile;
        myfile.open(l, ios::out);
        if (myfile)
        {
            myfile << a->value << endl;
            myfile << a->filename << endl;
            myfile << a->line << endl;
            Node<A>* temp = a->list.head;
            while (temp)
            {
                myfile << temp->data << " " << temp->filename << " " << temp->linenum << endl;
                temp = temp->next;
            }
            saveFile(path, a->left);
            saveFile(path, a->right);

        }
        else
        {
            cout << "File not opened!" << endl;
        }

    }
    void saveFile1(string path, TreeNode<A>* a) {
        if (a == NULL)
        {
            return;
        }
        string aa;

        string b = ".txt";
        aa = a->value;
        string x;
        //l += path;
        string l = path;
        l += aa;
        l += b;
        //cout << l;
        fstream myfile;
        myfile.open(l, ios::out);
        if (myfile)
        {
            myfile << a->value << endl;
            myfile << a->filename << endl;
            myfile << a->line << endl;
            Node<A>* temp = a->list.head;
            while (temp)
            {
                myfile << temp->data << " " << temp->filename << " " << temp->linenum << endl;
                temp = temp->next;
            }
            saveFile1(path, a->left);
            saveFile1(path, a->right);

        }
        else
        {
            cout << "File not opened!" << endl;
        }

    }

    TreeNode<A>* pointSearch(A key, TreeNode<A>* r) {
        if (r == NULL || r->value == key)
            return r;

        else if (key < r->value)
            return pointSearch(key, r->left);

        else
            return pointSearch(key, r->right);
    }
    void delete_index(A key, TreeNode<A>* r) {

        TreeNode<A>* temp = pointSearch(key, r);
        if (temp) {
            cout << "Deleting index!" << endl;
            cout << temp->line << endl;
            deleteTuple(temp->filename, temp->line);
            if (temp->list.head != NULL)
            {
                cout << "Deleting Duplicates!" << endl;
                Node<A>* temp1 = temp->list.head;
                while (temp1)
                {
                    cout << temp1->linenum << endl;
                    deleteTuple(temp1->filename, temp1->linenum);
                    temp1 = temp1->next;
                }
            }
            cout << "Deletion Successful!" << endl;
        }
        else
        {
            cout << "Index not found!" << endl;
        }
    }
    void delete_index_where(A key, TreeNode<A>* r,string val) {

        TreeNode<A>* temp = pointSearch(key, r);
        if (temp) {
            cout << "Deleting index!" << endl;
            cout << temp->line << endl;
            deleteTuplewhere(temp->filename, temp->line,val);
            if (temp->list.head != NULL)
            {
                cout << "Deleting Duplicates!" << endl;
                Node<A>* temp1 = temp->list.head;
                while (temp1)
                {
                    cout << temp1->linenum << endl;
                    deleteTuplewhere(temp1->filename, temp1->linenum,val);
                    temp1 = temp1->next;
                }
            }
            cout << "Deletion Successful!" << endl;
        }
        else
        {
            cout << "Index not found!" << endl;
        }
    }
    void modifyIndex(A key, TreeNode<A>* r, string old_val, string new_val) {
        TreeNode<A>* temp = pointSearch(key, r);
        if (temp)
        {
            cout << "Modifying index!" << endl;
            modifyTuple(temp->filename, temp->line, old_val, new_val);
            if (temp->list.head != NULL)
            {
                cout << "Modifying Duplicates!" << endl;
                Node<A>* temp1 = temp->list.head;
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
template <typename A>
void displayTuple(TreeNode<A>* root) {
    if (root)
    {
        string file = root->filename;
        int linenum = 1;
        string line;
        int x = root->line;
        int count = 0;
        fstream myfile;
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
        if (root->list.head != NULL)
        {

            Node<A>* temp = root->list.head;
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
    else
    {
        cout << "Index not found!" << endl;
    }
}
template <typename A>
void displayTuple_Where(TreeNode<A>* root,string value) {
    if (root)
    {
        string file = root->filename;
        int linenum = 1;
        string line;
        int x = root->line;
        int count = 0;
        fstream myfile;
        myfile.open(file, ios::in);
        while (getline(myfile, line))
        {
            if (linenum == x && line.find(value) != std::string::npos)
            {
                cout << line << endl;
            }
            linenum++;
        }
        myfile.close();
        if (root->list.head != NULL)
        {

            Node<A>* temp = root->list.head;
            while (temp)
            {
                file = temp->filename;
                linenum = 1;
                line = "";
                x = temp->linenum;
                myfile.open(file, ios::in);
                while (getline(myfile, line))
                {
                    if (linenum == x && line.find(value) != std::string::npos)
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
    else
    {
        cout << "Index not found!" << endl;
    }
}
template <typename A>
void RangeQuery(TreeNode<A>* r, A key1, A key2) {
    if (r == NULL)
    {
        return;
    }
    if (key1 < r->value)
    {
        RangeQuery(r->left, key1, key2);
    }
    if (key1 <= r->value && key2 >= r->value)
    {
        displayTuple(r);
    }
    RangeQuery(r->right, key1, key2);
}
template <typename A>
void RangeQueryWhere(TreeNode<A>* r, A key1, A key2,string val) {
    if (r == NULL)
    {
        return;
    }
    if (key1 < r->value)
    {
        RangeQueryWhere(r->left, key1, key2,val);
    }
    if (key1 <= r->value && key2 >= r->value)
    {
        displayTuple_Where(r, val);
    }
    RangeQueryWhere(r->right, key1, key2,val);
}