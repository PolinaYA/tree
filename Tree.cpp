 #pragma once
#include <iostream>
#include "Tree.h"

using namespace std;
 typedef double T;
Tree::Node* Tree::add(T val) {
	Node* x = find(val);

	if (x != NULL)
		return x;

	if (root == NULL) {
		root = new Tree::Node(N, val);
		return root;
	}
	else if (val > root->Key) {
		// add key ABOVE current root
		Tree::Node* oldroot = root;
		root = new Tree::Node(N, val);
		root->children.push_back(oldroot);
		oldroot->parent = root;

	}
	else
	   {
		return Tree::add(val, root);} // иначе внидряем подфункцию
}

Tree::Node* Tree :: add(T val, Tree::Node* t_root)
	// описываем эту самую подфункцию
{

	if (t_root->children.size() < N) {
	// add to children

		Tree::Node* xmm = new Tree::Node(N, val, t_root); ; //
		t_root->children.push_back(xmm);
		sort(t_root->children, t_root->children.size());
		//for (int i = 0; i < t_root->children.size(); i++) {
		 //	cout << t_root->children[i]->Key << " "; // test
		//}

	}

	else // ==N
	{
		// look for first child that's greater than Val
		unsigned i = 0;
		while (i < N && t_root->children[i]->Key < val)
			++i;

		if (i < N) {
			return Tree::add(val, t_root->children[i]);
		}
		else // we have all on this level  да ещё и Key<val    ; i==N
		{
			Tree::Node* rchild = t_root->children[N - 1]; // save subtree

			t_root->children[N - 1] = new Tree::Node(N, val, t_root);
			// add new child

			// add back our subtree
			t_root->children[N - 1]->children.push_back(rchild);
			rchild->parent = t_root->children[N - 1];
		}

	}
}



Tree::Node* Tree::find(T val, Tree::Node* t_root) {
	if (val == t_root->Key) {
		return t_root;
	}
	else if (val > t_root->Key) {
		return NULL;
	}
	else { // val < t_root.key
		for (int i = 0; i < t_root->children.size(); i++) {
			Tree::Node* res = Tree::find(val, t_root->children[i]);
			if (res != NULL)
				return res;
		   //	i++;
		}

	 	return NULL;
	}
}

Tree::Node* Tree::find(T val) {
  if (root==NULL) {
	   return NULL;
  }
	return Tree::find(val, root);
}

bool Tree::remove(Tree::Node* node) {
	if (node->children.size() == 0) { // is leaf?
		// REMOVE NODE
		// find k | node->parent.children[k]==node
		int k = 0;

		if (node->parent!=NULL)
	   {	while (node->parent->children[k] != node)
			k++;
		node->parent->children.erase(node->parent->children.begin()+k);

		}
		else {    //если в дереве всего один узел
		delete node;
		root=NULL;
		}
		delete node;
		return true;

	}
	else { // has children

		node->Key = node->children[node->children.size() - 1]->Key;
		// replace with right child key
		Tree::remove(node->children[node->children.size() - 1]);
		// remove child, recursively
	}
	  return true;
}

bool Tree::remove(T val) {
	Tree::Node* n = Tree::find(val);
	if (n != NULL)
	  return Tree::remove(n);
	  return false;

}



void Tree::printdown(Tree::Node* t_root)  {
	if (t_root != NULL) {
		cout<<t_root->Key <<endl;

	  if (t_root->children.size() != NULL){
	 for (int i=t_root->children.size() - 1 ; i>=0; i--)
		Tree::printdown(t_root->children[i]);
	  }
	 }

	}

void Tree::printup(Tree::Node* t_root)  {
	if (t_root != NULL) {


	  if (t_root->children.size() != NULL){
	 for (int i=0 ; i<t_root->children.size(); i++)
		Tree::printup(t_root->children[i]);
	  }
		cout<<t_root->Key <<endl;
	 }

	}

 void Tree::print()
  {Tree::printdown(root);}







