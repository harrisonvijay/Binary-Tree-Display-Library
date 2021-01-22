#ifndef display_tree
#define display_tree

//include the .h/.cpp file containing the declaration/definition of avl/bst
#include "bst.cpp"

//Implementation for trees having integer data type
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <iomanip>
#include <algorithm>


#define NOVAL1 -2147483648
#define NOVAL2 2147483647

using namespace std;

int max_level(Node<int> *root, int level)
{
    if (root==NULL)
        return level-1;
    else 
        return max(max_level(root->left, level+1), max_level(root->right, level+1));
}

void preorder_bst(Node<int> *root, int level, auto &map, int max_level)
{
    if (level>max_level)
        return;
	if (root == NULL)
	{
        map[level].push_back(NOVAL1);
        preorder_bst(NULL, level + 1, map, max_level);
	    preorder_bst(NULL, level + 1, map, max_level);
    }
    else
    {
        map[level].push_back(root->data);
        preorder_bst(root->left, level + 1, map, max_level);
	    preorder_bst(root->right, level + 1, map, max_level);
    }
}

vector<int> reorder(Node<int>* r)
{
    unordered_map<int, vector<int>> m;
    preorder_bst(r, 1, m, max_level(r, 1));
    vector<int> v;
    int start = max_level(r, 1);
    for (int i = start; i > 0; i--)
	{
		for (int j: m[i])
		   v.push_back(j);
	}
	return v;
	
}

int maxdigits(vector<int> v)
{
    int max = 0;
    for (auto x:v)
    {
        if (x!=NOVAL1 && x!=NOVAL2)
        {
            if (abs(x)>max)
            {
                max = abs(x);
            }
        }
    }
    return floor(log10(max))+1;
}

void display_bst(Node<int>* r)
{
    vector<int> v = reorder(r);
    int no_rows = ceil(log2(v.size()));
    int no_columns = 2*pow(2, no_rows-1)-1;
    int width = maxdigits(v)+1;
    int** matrix = new int*[no_rows];
    for (int i=0; i<no_rows; i++)
        matrix[i] = new int[no_columns];
    for (int i=0; i<no_rows; i++)
        for (int j=0; j<no_columns; j++)
            matrix[i][j] = NOVAL2;
    vector <int> lastpos;
    vector<int> v2;
    int a, b, c;
    int k=0;
    int x=-1, y=1;
    while (x<no_columns)
    {
        lastpos.push_back(x);
        lastpos.push_back(y);
        x+=2;
        y+=2;
    }
    for (int i=no_rows-1; i>=0; i--)
    {
        a = 0;
        b = 1;
        while (b<lastpos.size())
        {
            c = (lastpos.at(a)+lastpos.at(b))/2;
            matrix[i][c] = v[k++];
            v2.push_back(c);
            a+=2;
            b+=2;
        }
        lastpos = v2;
        v2.clear();
    }
    for (int i=0; i<no_rows; i++)
    {
        for (int j=0; j<no_columns; j++)
        {
            if (matrix[i][j]==NOVAL1)
                cout<<setfill(' ')<<setw(width)<<"x";
            else if(matrix[i][j]!=NOVAL2)
                cout<<setfill(' ')<<setw(width)<<matrix[i][j];                
            else
                cout<<setfill(' ')<<setw(width)<<" ";
            cout<<" ";
            
        }
        cout<<endl;
    }

}

#endif