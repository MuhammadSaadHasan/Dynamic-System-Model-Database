#pragma once
#include <iostream>
#include<string>
#include<fstream>
#include<cstring>
#include"BLink_list.h"
using namespace std;




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class hehe>
class btnode
{
public:
    int min;
    int order;
    hehe* key;
    btnode** child;
    int count;
    bool leaf;
    int* line;
    string* filename;
    blinkedlist<hehe>** l;


    btnode(int min, bool flag)
    {
        this->min = min;
        leaf = flag;
        order = min * 2;
        key = new hehe[order - 1];
        child = new btnode<hehe>*[order];
        line = new int[order - 1];
        filename = new string[order - 1];
        l = new blinkedlist<hehe>*[order];
        for (int i = 0; i < order; i++)
        {
            l[i] = new blinkedlist<hehe>;
        }
        count = 0;
    }

    void notfull(hehe k, int ln, string fn)
    {
        int i = count - 1;

        if (leaf == true) {
            for (; i >= 0 && key[i] > k;)
            {
                key[i + 1] = key[i];
                line[i + 1] = line[i];
                filename[i + 1] = filename[i];
                i--;
            }

            key[i + 1] = k;
            line[i + 1] = ln;
            filename[i + 1] = fn;
            count++;
        }
        else
        {
            while (i >= 0 && key[i] > k)
                i--;

            if (child[i + 1]->count == (order)-1)
            {
                schild(i + 1, child[i + 1], ln, fn);

                if (key[i + 1] < k)
                    i++;
            }
            child[i + 1]->notfull(k, ln, fn);
        }
    }
    void savefile()  //printing function
    {
        int i;
        fstream fout;
        fout.open("file2.txt", ios::out | ios::app);
        fout << endl;
        for (i = 0; i < count; i++) {
            if (leaf == false)
            {

                child[i]->savefile();


            }
            fout << " " << key[i] << "-" << line[i] << "-" << filename[i];
            //l[i]->fileprint();
        }
        if (leaf == false)
            child[i]->savefile();

        fout << endl;
    }
    void traverse()  //printing function
    {
        int i;
        cout << endl;
        for (i = 0; i < count; i++) {
            if (leaf == false)
            {

                child[i]->traverse();


            }
            cout << key[i] << " - " << line[i] << " - " << filename[i] << endl;
            //selectionsearch(line[i], filename[i]);
            if (l[i] == NULL)
            {

            }
            //l[i]->print();

        }
        if (leaf == false)
            child[i]->traverse();

        cout << endl;
    }
    void schild(int i, btnode<hehe>* x, int ln, string fn)
    {
        btnode* temp = new btnode(x->min, x->leaf);
        temp->count = min - 1;
        for (int j = 0; j < min - 1; j++)
        {
            temp->key[j] = x->key[j + min];
            temp->line[j] = x->line[j + min];
            temp->filename[j] = x->filename[j + min];
        }
        if (x->leaf == false)
        {
            for (int j = 0; j < min; j++)
                temp->child[j] = x->child[j + min];
        }

        x->count = min - 1;
        for (int j = count; j >= i + 1; j--)
        {
            child[j + 1] = child[j];
        }
        child[i + 1] = temp;

        for (int j = count - 1; j >= i; j--)
        {
            key[j + 1] = key[j];
            line[j + 1] = line[j];
            filename[j + 1] = filename[j];
        }
        key[i] = x->key[min - 1];
        line[i] = x->line[min - 1];
        filename[i] = x->filename[min - 1];
        count++;
    }
    btnode* search(hehe val)
    {
        btnode* temp = NULL;
        int i = 0;
        while (i < count && key[i] < val)
            i++;

        int n = i;

        if (key[i] == val)
        {
            return this;
        }
        else if (leaf == true)
        {
            return temp;
        }
        return (child[i]->search(val));
    }
    btnode* update(hehe val)
    {
        btnode* temp = NULL;
        int i = 0;
        while (i < count && key[i] < val)
            i++;

        int n = i;

        if (key[i] == val)
        {

            return this;
        }
        else if (leaf == true)
        {
            return temp;
        }
        return (child[i]->update(val));
    }

    btnode* searchdata(hehe val)
    {
        int i;

        for (i = 0; i < count; i++)
        {
            if (leaf == false)
            {

                child[i]->searchdata(val);


            }
            if (key[i] == val)
            {
                //cout << key[i] << "||" << line[i] << "||" << filename[i] << endl;
                selectionsearch(line[i], filename[i]);
                //l[i]->print();

                
            }

            
        }
        if (leaf == false)
        {
            child[i]->searchdata(val);
        }
        //cout << endl;
        return NULL;
    }

    btnode* updatekey(string val, string val2)
    {
        int i;

        for (i = 0; i < count; i++)
        {
            if (leaf == false)
            {

                child[i]->updatekey(val, val2);


            }
            if (to_string(key[i]) == val)
            {
                updatequery(filename[i], line[i], val, val2);
                
            }


        }
        if (leaf == false)
        {
            child[i]->updatekey(val, val2);
        }
        return NULL;

    }
    btnode* updatekey1(string val, string val2)
    {
        int i;

        for (i = 0; i < count; i++)
        {
            if (leaf == false)
            {

                child[i]->updatekey1(val, val2);


            }
            if (key[i] == val)
            {
                updatequery(filename[i], line[i], val, val2);
                
            }


        }
        if (leaf == false)
        {
            child[i]->updatekey1(val, val2);
        }
        return NULL;
    }

    btnode* deletekey(hehe val)
    {
        int i;

        for (i = 0; i < count; i++)
        {
            if (leaf == false)
            {

                child[i]->deletekey(val);


            }
            if (key[i] == val)
            {
                //cout << key[i] << "||" << line[i] << "||" << filename[i] << endl;
                deletequery(line[i], filename[i]);
                //l[i]->print();

                
            }


        }
        if (leaf == false)
        {
            child[i]->deletekey(val);
        }
        //cout << endl;
        return NULL;
    }

    void rangesearch(hehe val, hehe val2)
    {
        int i;

        for (i = 0; i < count; i++)
        {
            if (leaf == false)
            {

                child[i]->rangesearch(val, val2);


            }
            if (key[i] >= val && key[i] <= val2)
            {
                //cout << key[i] << "||" << line[i] << "||" << filename[i] << endl;
                selectionsearch(line[i], filename[i]);
                //l[i]->print();


            }


        }
        if (leaf == false)
        {
            child[i]->rangesearch(val, val2);
        }
    }

    btnode insertdup(hehe val, int ln, string fn)
    {

        int i = 0;
        while (i < count && key[i] < val)
            i++;

        int n = i;

        if (key[n] == val)
        {

            l[i]->insert(val, ln, fn);
        }
        else
        {
            return child[i]->insertdup(val, ln, fn);
        }

    }



    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void deletion(hehe val, int ln, string fn)
    {
        int i = 0;
        while (i < count && key[i] < val)
            i++;

        int n = i;

        if (n < count && key[n] == val)
        {
            /*if (key[n] == val && l[n] != NULL)
            {
                l[n]->remove(t val);
            }*/
            if (leaf == true)
            {
                removeleaf(n, ln, fn);
            }
            else
            {
                removeinternal(n, ln, fn);
            }
        }
        else
        {
            bool check = false;
            if (leaf == true)
            {
                cout << val << " doesn't exist in tree\n";
                return;
            }

            if (n == count)
            {
                check == true;
            }
            else
            {
                check == false;
            }

            if (child[n]->count < min)
            {
                fill(n, ln, fn);
            }
            if (check == true && n > count)
            {
                child[n - 1]->deletion(val, ln, fn);
            }
            else
            {
                child[n]->deletion(val, ln, fn);
            }
        }
        return;
    }
    void removeleaf(int v, int ln, string fn)
    {
        for (int i = v + 1; i < count; i++)
        {
            key[i - 1] = key[i];
            line[i - 1] = line[i];
            filename[i - 1] = filename[i];
        }
        count--;
        return;
    }

    // Delete from non leaf node
    void removeinternal(int v, int ln, string fn)
    {
        hehe temp = key[v];

        if (child[v]->count >= min)
        {
            hehe pre = getPredecessor(v, ln, fn);
            key[v] = pre;
            child[v]->deletion(pre, ln, fn);
        }

        else if (child[v + 1]->count >= min)
        {
            hehe suc = getSuccessor(v, ln, fn);
            key[v] = suc;
            child[v + 1]->deletion(suc, ln, fn);
        }

        else
        {
            merge(v);
            child[v]->deletion(temp, ln, fn);
        }
        return;
    }

    hehe getPredecessor(int v, int ln, string fn)
    {
        btnode<hehe>* temp = child[v];
        while (!temp->leaf)
            temp = temp->child[temp->count];

        return temp->key[temp->count - 1];
    }

    hehe getSuccessor(int v, int ln, string fn) {
        btnode<hehe>* temp = child[v + 1];
        while (!temp->leaf)
            temp = temp->child[0];

        return temp->key[0];
    }

    void fill(int v, int ln, string fn) {
        if (v != 0 && child[v - 1]->count >= min)
            borrowFromPrev(v, ln, fn);

        else if (v != count && child[v + 1]->count >= min)
            borrowFromNext(v, ln, fn);

        else {
            if (v != count)
                merge(v);
            else
                merge(v - 1);
        }
        return;
    }

    // Borrow from previous
    void borrowFromPrev(int v, int ln, string fn)
    {
        btnode<hehe>* c = child[v];
        btnode<hehe>* s = child[v - 1];

        for (int i = c->count - 1; i >= 0; i--)
        {
            c->key[i + 1] = c->key[i];
            c->line[i + 1] = c->line[i];
            c->filename[i + 1] = c->filename[i];
        }
        if (!c->leaf) {
            for (int i = c->count; i >= 0; i--)
                c->child[i + 1] = c->child[i];
        }

        c->key[0] = key[v - 1];
        c->line[0] = line[v - 1];
        c->filename[0] = filename[v - 1];

        if (!c->leaf)
            c->child[0] = s->child[s->count];

        key[v - 1] = s->key[s->count - 1];
        line[v - 1] = s->line[s->count - 1];
        filename[v - 1] = s->filename[s->count - 1];

        c->count += 1;
        s->count -= 1;

        return;
    }

    void borrowFromNext(int v, int ln, string fn) {
        btnode<hehe>* c = child[v];
        btnode<hehe>* s = child[v + 1];

        c->key[(c->count)] = key[v];

        if (!(c->leaf))
        {
            c->child[(c->count) + 1] = s->child[0];
        }

        key[v] = s->key[0];
        line[v] = s->line[0];
        filename[v] = s->filename[0];

        for (int i = 1; i < s->count; i++)
        {
            s->key[i - 1] = s->key[i];
            s->line[i - 1] = s->line[i];
            s->filename[i - 1] = s->filename[i];
        }

        if (!s->leaf) {
            for (int i = 1; i <= s->count; i++)
            {
                s->child[i - 1] = s->child[i];
            }
        }

        c->count += 1;
        s->count -= 1;

        return;
    }

    //// Merge
    void merge(int v) {
        btnode* c = child[v];
        btnode* s = child[v + 1];

        c->key[min - 1] = key[v];
        c->line[min - 1] = line[v];
        c->filename[min - 1] = filename[v];

        for (int i = 0; i < s->count; i++)
        {
            c->key[i + min] = s->key[i];
            c->line[i + min] = s->line[i];
            c->filename[i + min] = s->filename[i];
        }

        if (!c->leaf)
        {
            for (int i = 0; i <= s->count; i++)
            {
                c->child[i + min] = s->child[i];
            }
        }

        for (int i = v + 1; i < count; i++)
        {
            key[i - 1] = key[i];
            line[i - 1] = line[i];
            filename[i - 1] = filename[i];
        }
        for (int i = v + 2; i <= count; i++)
        {
            child[i - 1] = child[i];
        }
        c->count += s->count + 1;
        count--;

        delete (s);
        return;
    }


};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class hehe>
class BTree
{
public:
    int min;
    btnode<hehe>* root;
    int order;


    BTree(int min)
    {
        this->min = min;
        root = NULL;
        this->order = min * 2;
    }

    void traverse()
    {
        if (root != NULL)
        {
            root->traverse();
            root->savefile();
        }

    }


    void insert(hehe k, int ln, string fn)
    {
        /*if (search(k))
        {

            root->insertdup(k, ln, fn);
            return;
        }*/
        if (root == NULL)
        {
            root = new btnode<hehe>(min, true);
            root->key[0] = k;
            root->line[0] = ln;
            root->filename[0] = fn;

            root->count = 1;
        }
        else {
            if (root->count == order - 1)
            {
                btnode<hehe>* temp = new btnode<hehe>(min, false);
                temp->child[0] = root;
                temp->schild(0, root, ln, fn);
                int i = 0;
                if (temp->key[0] < k)
                    i++;
                temp->child[i]->notfull(k, ln, fn);

                root = temp;
            }
            else
                root->notfull(k, ln, fn);
        }
    }

    ////search function
    BTree* search(hehe k)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else {
            if (root->search(k) == NULL)
                return NULL;
        }
    }
    BTree* update(hehe k)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else {
            if (root->update(k) == NULL)
                return NULL;
        }
    }
    BTree* selectsearch(hehe k)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else {
            if (root->searchdata(k) == NULL)
                return NULL;
        }
    }



    BTree* rangesearch(hehe k1, hehe k2)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else
        {
            root->rangesearch(k1, k2);
        }
    }

    BTree* updatekey(string val, string val2)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else
        {
            root->updatekey(val, val2);
            return NULL;
        }
    }
    BTree* updatekey1(string val, string val2)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else
        {
            root->updatekey1(val, val2);
            return NULL;
        }
    }
    BTree* deletekey(hehe k)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else
        {
            root->deletekey(k);
            return NULL;
        }
    }


    ////delete function in tree
    void deletion(hehe k, int ln, string fn)
    {
        if (root == NULL)
        {
            cout << "The tree is empty" << endl;
            return;
        }
        else
        {
            root->deletion(k, ln, fn);

            if (root->count == 0)
            {
                btnode<hehe>* temp = root;
                if (root->leaf == true)
                {
                    root = NULL;
                }
                else
                {
                    root = root->child[0];
                }
                delete temp;
            }
            return;
        }
    }

};