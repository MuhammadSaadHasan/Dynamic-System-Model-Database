#pragma once
#include<iostream>
using namespace std;

void selectionsearch(int ln, string fn)
{
    string file = fn;
    int linenum = 1;
    string line;
    int x = ln;
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



}
void updatequery(string path, int linenum, string del, string replacement){
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

//template <class haha>
//void updateq(btnode<haha>* temp, string old, string x) {
//    updatequery(temp->filename, temp.line, old, x);
//}
void deletequery(int linenum, string path)
{
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

template <class haha>
class bnode
{
public:
    haha data;
    int lane;
    string fname;
    bnode* next;

    bnode()
    {
        data = 0;
        next = NULL;
    }

    bnode(haha d, bnode* n)
    {
        if (n == NULL)
        {
            //haha = n;
            return;
        }
        bnode* temp = n;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }

    bnode(haha d, int ln, string fn)
    {
        data = d;
        lane = ln;
        fname = fn;
        next = NULL;
    }

    void setData(haha d)
    {
        data = d;
    }

    void setNext(bnode* n)
    {
        next = n;
    }

    haha getData()
    {
        return data;
    }

    bnode* getNext()
    {
        return next;
    }

};

template <class haha>
class blinkedlist {

public:

    bnode<haha>* head;
    bnode<haha>* sorted = NULL;

    blinkedlist()
    {
        head = NULL;
    }
    void insert(haha val, int ln, string fn)
    {
        bnode<haha>* temp;
        temp = head;
        //bnode* n = new bnode(val);
        if (temp == NULL)
        {
            head = new bnode<haha>(val, ln, fn);
            return;
        }

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new bnode<haha>(val, ln, fn);

    }
    void insertAtHead(haha value)
    {
        bnode<haha>* n = new bnode<haha>(value);
        n->next = head;
        head = n;
    }
    void InsertAtIndex(haha value, int index)
    {
        bnode<haha>* temp = new bnode<haha>(value);
        for (int i = 0; temp->next != nullptr; i++)
        {
            temp = temp->next;
        }
        temp->next = new bnode<haha>(value);
    }

    haha search(haha n) {
        bnode<haha>* temp = head;
        while (temp->data != n || temp->next != NULL) {
            temp = temp->next;
        }
        if (temp->data == n)
        {
            return temp->data;
        }
        else {
            return -1;
        }
    }

    void update(int index, haha n) {
        bnode<haha>* temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        temp->setData(n);
    }

    void remove(haha n) {
        bnode<haha>* temp = head;
        bnode<haha>* temp1 = head->next;
        while (temp1->data != n && temp1->next != NULL) {
            temp = temp->next;
            temp1 = temp1->next;
        }
        if (temp1->data == n)
        {
            bnode<haha>* temp3 = temp1;
            temp->next = temp1->next;
            delete temp3;
        }
    }

    void print() {
        bnode<haha>* temp = head;
        while (temp->next != NULL)
        {
            selectionsearch(temp->lane, temp->fname);
            //cout << temp->data << "||" << temp->lane << "||" << temp->fname << endl;
            temp = temp->next;
        }
        selectionsearch(temp->lane, temp->fname);
        //cout << temp->data << "||" << temp->lane << "||" << temp->fname << endl;
    }
    void fileprint()
    {
        fstream fout;
        fout.open("file.txt", ios::out | ios::app);
        bnode<haha>* temp = head;
        while (temp->next != NULL)
        {
            fout << temp->data << "||" << temp->lane << "||" << temp->fname << endl;
            temp = temp->next;
        }
        fout << temp->data << "||" << temp->lane << "||" << temp->fname << endl;
    }

    void sortedInsert(bnode<haha>* node)
    {
        if (sorted == NULL || sorted->data >= node->data) {
            node->next = sorted;
            sorted = node;
        }
        else {
            bnode<haha>* current = sorted;

            while (current->next != NULL && current->next->data < bnode->data) {
                current = current->next;
            }
            node->next = current->next;
            current->next = bnode;
        }
    }


};