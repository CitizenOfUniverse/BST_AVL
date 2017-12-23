/*
* main.cpp - Main project file. Contains only main function 
*/

//#include "BST.h"
#include <iostream>
#include "menu.h"

using std::cout;
using std::endl;

int main(){
	setlocale(LC_ALL, "Russian");
	//Debug code
	BST int_tree;
	menu_BST(int_tree);
	//menu_BST(int_tree);
	int_tree.simple_insert(10);
	int_tree.simple_insert(10);
	int_tree.simple_insert(15);
	int_tree.simple_insert(2);
	int_tree.simple_insert(8);
	int_tree.simple_insert(6);
	int_tree.simple_insert(9);
	int_tree.simple_insert(12);
	int_tree.simple_insert(13);
	int_tree.simple_insert(19);
	int_tree.simple_insert(18);
	int_tree.simple_insert(23);
	int_tree.simple_insert(1);
	int_tree.simple_insert(11);
	int_tree.simple_insert(25);
	int_tree.simple_insert(24);
	int_tree.simple_insert(30);

	/*int_tree.simple_remove(13);
	int_tree.simple_remove(18);
	int_tree.simple_remove(19);
	int_tree.simple_remove(25);
	int_tree.simple_remove(9);
	int_tree.simple_remove(12);
	int_tree.simple_remove(11);
	int_tree.simple_remove(10);
	int_tree.simple_remove(2);
	int_tree.simple_remove(1);
	int_tree.simple_remove(23);

	int_tree.simple_remove(24);
	int_tree.simple_remove(30);
	int_tree.simple_remove(8);
	int_tree.simple_remove(15);
	int_tree.simple_remove(6);*/

	/*int_tree.print_right_left_root();
	cout << endl;
	int_tree.print_right_root_left();
	cout << endl;
	int_tree.remove_one(10);
	int_tree.print_right_left_root();*/
	bool a;
	a = int_tree.find(1);
	a = int_tree.find(1);
	a = int_tree.find(2);
	a = int_tree.find(2);
	a = int_tree.find(6);
	a = int_tree.find(6);
	a = int_tree.find(8);
	a = int_tree.find(8);
	a = int_tree.find(9);
	a = int_tree.find(9);
	a = int_tree.find(11);
	a = int_tree.find(11);
	a = int_tree.find(11);
	a = int_tree.find(10);
	a = int_tree.find(10);
	a = int_tree.find(12);
	a = int_tree.find(12);
	a = int_tree.find(13);
	a = int_tree.find(13);
	a = int_tree.find(15);
	a = int_tree.find(15);
	a = int_tree.find(19);
	a = int_tree.find(19);
	a = int_tree.find(23);
	a = int_tree.find(23);
	a = int_tree.find(24);
	a = int_tree.find(24);
	a = int_tree.find(25);
	a = int_tree.find(25);
	a = int_tree.find(30);
	a = int_tree.find(30);
	return 0;
}
