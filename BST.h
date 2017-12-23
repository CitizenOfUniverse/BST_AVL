/*
* BST.h - Contains descriptor of the class BST
*/

#include "node.h"
#include "stddef.h"

// Descriptor of the class BST
class BST{
private:
	node* top;//Pointer to the top node
	int size;//Size of the tree
	
	void BST::print_subtree_right_root_left(node* now_top);
public:
	BST();//Class constructor
	node* rotateright(node* p); // правый поворот вокруг p
	node* rotateleft(node* q); // левый поворот вокруг q
	node* balance(node* p);
	node* insert(node* p, int k);
	node* findmin(node* p);
	node* removemin(node* p);
	node* remove(node* p, int k);
	bool simple_insert(int k);
	bool simple_remove(int k);
	//Self-written methods
	~BST();//Class destructor
	//void insert(int);// Inserts an integer to a tree
	int get_size();//Returns size of the tree
	bool is_empty();//Returns true, if tree is empty, and false otherwise
	//void print_right_left_root();
	void print_right_root_left();
	//bool remove_one(int value);
	bool find(int value);
	
private:

	//Self-written methods
	//bool find_with_parent(int value, node** value_node, node** parent = NULL);
	//void insert_to_subtree(node* now_node, int data);
	void delete_subtree(node* top);
	//void print_subtree_right_left_root(node* top);
	//void print_subtree_right_root_left(node* top);
};
