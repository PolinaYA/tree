  #pragma once
#include <iostream>
#include <vector>

using namespace std;

typedef double T;

class Tree {
public:
	struct Node {
		T Key;
		unsigned N;
		Node* parent;
		vector<Node*>children;

		Node(unsigned _N, T _Key, Node* _p = 0) {
			N = _N;
			Key = _Key;
			parent = _p;
		}
	} ;
	private :
	 unsigned N;

	Node* root;


public:
	Tree(unsigned _N) {
		N = _N;
		root= NULL;
	}

	Node* add(T val); // return new node with Key=val in proper place
	Node* find(T val); // return node with Key=val; or 0 if none found
	void print();
	bool has(T val) {
		return (find(val) != 0);
	}
	bool remove(T val); // delete node with Key=val, if it exists

private:
	Node* add(T val, Node* t_root);
	Node* find(T val, Node* t_root);
	bool remove(Node* node);
	void printdown(Node* t_root);
	void printup(Node* t_root);
	void print_special(Node* t_root);
	void sort(vector<Node*> &a, int size) // int t_root->children.size()
	{
	if (size==1) {
        return;
	}
		int i, j;
		double temp;
		for (i = size - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (a[j]->Key > a[j + 1]->Key) {
					temp = a[j]->Key;
					a[j]->Key = a[j + 1]->Key;
					a[j + 1]->Key = temp;
				}
			}
		}
	}

}  ;
