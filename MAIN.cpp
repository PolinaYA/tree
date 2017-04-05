#include <stdio.h>
#include <iostream>
#include <conio.h>
#include "Tree.h"


using namespace std;


int main()
{
int N;
cout<<"vvedite N"<<endl;
cin>>N;
Tree t(N);



 while (true)
	{
		int choice = 0;
		cout<<endl<<"<<<<<<<<<<<<<<<<<<"<<endl;
		cout<<"Menu:"<<endl;
		cout<<"1. Add new node"<<endl;
		cout<<"2. Delete node"<<endl;
		cout<<"3. Exit"<<endl;
		cout<<"4. Find"<<endl;
		cout<<"<<<<<<<<<<<<<<<<<<"<<endl;
		cout<<endl<<"Your choice: ";
		cin>>choice;
		switch (choice)
		{
		case 1:{
	double val = 0;
	cout<<endl<<"Node inserting..."<<endl;
	cout<<"Enter the key value of inserting node: ";
	cin>>val;
	t.add(val); //вызов функции добавления узла
	cout<<"New node has been inserted."<<endl;
	t.print();
				break;}
		case 2: {
	double val = 0;
	cout<<endl<<"Node deletion..."<<endl;
	cout<<"Enter the key value of the node to delete: ";
	cin>>val;
	if (t.remove(val) == false) //вызов функции удаления узла
		cout<<"Node can't be deleted!"<<endl;
	else
		cout<<"Node has been deleted."<<endl;
		t.print();
				break;
				 }
		case 3:{
				cout<<endl<<"Ending working session..."<<endl;
				return 0;
				}
		case 4:{
		double val=0;
		cin>>val;
		cout<<"find val?"<<endl;
		if (t.find(val)!= NULL){
		cout<<"Yep";     }
		else
		cout<<"nop";

		}
		default:
			cout<<endl<<"From 1 to 3, please..."<<endl;
		}
		getch();
		}
	return 0;
 }
