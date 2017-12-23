/*
* BST.cpp - Describes methods of the stack class
*/
#include "BST.h"
//#include "stddef.h"
#include <iostream>

using std::cout;


// Binary search tree class constructor.
BST::BST(){
	size = 0;
	this->top = NULL;
}
node* BST::rotateright(node* p) // правый поворот вокруг p
{
	node* q = p->get_left_son();
	p->set_left_son(q->get_right_son());
	q->set_right_son(p);
	//q->right = p;
	p->fixheight();
	q->fixheight();
	/*fixheight(p);
	fixheight(q);*/
	return q;
}
node* BST::rotateleft(node* q) // левый поворот вокруг q
{
	node* p = q->get_right_son();
	q->set_right_son(p->get_left_son());
	//q->right = p->left;
	p->set_left_son(q);
	//p->left = q;
	q->fixheight();
	p->fixheight();
	/*fixheight(q);
	fixheight(p);*/
	return p;
}

node* BST::balance(node* p) // балансировка узла p
{
	p->fixheight();
	//fixheight(p);
	if (p->get_bfactor() == 2)
	{
		if (p->get_right_son()->get_bfactor() < 0) {
			p->set_right_son(rotateright(p->get_right_son()));
			
		}			
		return rotateleft(p);
	}
	if (p->get_bfactor() == -2)
	{
		if (p->get_left_son()->get_bfactor() > 0) {
			p->set_left_son(rotateleft(p->get_left_son()));
			//p->left = rotateleft(p->left);
		}
		return rotateright(p);
	}
	return p; // балансировка не нужна
}
node* BST::insert(node* p, int k) // вставка ключа k в дерево с корнем p
{
	if (p == NULL) {
		return new node(k);
	}
	//if (!p) 
	if (k < (p->getData())) {
		p->set_left_son(insert(p->get_left_son(), k));
	}
	else {
		p->set_right_son(insert(p->get_right_son(), k));
	}
	/*if (k<p->key)
		p->left = insert(p->left, k);
	else
		p->right = insert(p->right, k);*/
	return balance(p);
}
node* BST::findmin(node* p) // поиск узла с минимальным ключом в дереве p 
{
	if (p != NULL) {
		return p->get_left_son() ? findmin(p->get_left_son()) : p;
	}
	else {
		return NULL;
	}
}
node* BST::removemin(node* p) // удаление узла с минимальным ключом из дерева p
{
	if (p->get_left_son() == NULL) {
		return p->get_right_son();
	}
	else {
		p->set_left_son(removemin(p->get_left_son()));
		return balance(p);
	}
	/*if (p->left == 0)
		return p->right;
	p->left = removemin(p->left);
	return balance(p);*/
}
node* BST::remove(node* p, int k) // удаление ключа k из дерева p
{
	if (p == NULL) {
		return 0;
	}
	if (k < p->getData()) {
		p->set_left_son(remove(p->get_left_son(), k));
	}
	else if (k > (p->getData())) {
		p->set_right_son(remove(p->get_right_son(), k));
	}
	else //  k == p->key 
	{
		node* q = p->get_left_son();
		node* r = p->get_right_son();
		delete p;
		size--;
		//<Changed>
		if (r == NULL) {
			return q;
		}
		//</Changed>
		node* min = findmin(r);
		min->set_right_son(removemin(r));
		min->set_left_son(q);
		return balance(min);
	}
	return balance(p);
	/*if (!p) return 0;
	if (k < p->key)
		p->left = remove(p->left, k);*/
	/*else if (k > p->key)
		p->right = remove(p->right, k);*/
	//else //  k == p->key 
	//{
	//	node* q = p->left;
	//	node* r = p->right;
	//	delete p;
	//	if (!r) return q;
	//	node* min = findmin(r);
	//	min->right = removemin(r);
	//	min->left = q;
	//	return balance(min);
	//}
	//return balance(p);
}
bool BST::simple_insert(int k) {
	top = insert(top, k);
	size++;
	return top == NULL ? false : true;
}
bool BST::simple_remove(int k) {
	top = remove(top, k);
	if (top != NULL) {
		return true;
	}
	else {
		return false;
	}
}
// Binary search tree class destructor
BST::~BST(){
	if (this->top != NULL){
		this->delete_subtree(this->top);//Calling recursive function, deleting tree in Right-Left-Root order
	}
}
void BST::delete_subtree(node* top){
	if (top->get_right_son() == NULL){
		if (top->get_left_son() == NULL){
			delete top;
			this->size--;
			return;
		}
		else{
			delete_subtree(top->get_left_son());
			delete top;
			this->size--;
			return;
		}
	}
	else{
		delete_subtree(top->get_right_son());
		if (top->get_left_son() == NULL){
			delete top;
			this->size--;
			return;
		}
		else{
			delete_subtree(top->get_left_son());
			delete top;
			this->size--;
			return;
		}
	}
}
bool BST::find(int value){
	//New realisation
	node* now_node = top;
	//bool flag_found = false;
	while (now_node) {
		if (value < now_node->getData()) {
			now_node = now_node->get_left_son();
			continue;
		}
		else if (value >now_node->getData()) {
			now_node = now_node->get_right_son();
			continue;
		}
		else {
			return true;
		}
	}
	return false;
	//Old realisation
	//node** parent = new node*;
	////*parent = new node;
	//if (find_with_parent(value, &(this->top), parent)){
	//	return true;
	//}
	//else{
	//	return false;
	//}
}
// Returns size of a tree
int BST::get_size(){
	return this->size;
}
void BST::print_right_root_left(){
	this->print_subtree_right_root_left(this->top);
}
void BST::print_subtree_right_root_left(node* now_top){
	if (now_top == NULL) {
		return;
	}
	if (now_top->get_right_son() == NULL){
		cout << now_top->getData() << ' ';
		if (now_top->get_left_son() == NULL){
			//cout << now_top->getData() << " ";
			return;
		}
		else{
			this->print_subtree_right_root_left(now_top->get_left_son());
			return;
		}
	}
	else{
		this->print_subtree_right_root_left(now_top->get_right_son());
		cout << now_top->getData() << ' ';
		if (now_top->get_left_son() == NULL){
			//cout << now_top->getData() << " ";
			return;
		}
		else{
			this->print_subtree_right_root_left(now_top->get_left_son());
			//cout << now_top->getData() << " ";
			return;
		}
	}
}
// Returns true on an empty tree and false on non-empty
bool BST::is_empty(){
	if (this->size == 0){
		return true;
	}
	else{
		return false;
	}
}



//Self-written methods
//// Deletes tree in Right-Left-Root order
//// Inserts one element in a BST saving order
//void BST::insert(int data){
//	if (this->top == NULL){
//		this->top = new node(data);
//	}
//	else{
//		insert_to_subtree(this->top, data);//Calling recursive function, that will find needed leaf and insert element there
//	}
//	this->size++;
//	return;
//}
//
//bool BST::find_with_parent(int data, node** value_node, node** parent){
//	if (this->top == NULL){
//		return false;
//	}
//	*parent = NULL;
//	*value_node = this->top;
//	while (true){
//		if (*value_node == NULL){
//			return false;
//		}
//		if (data < (*value_node)->getData()){
//			*parent = *value_node;
//			*value_node = (*value_node)->get_left_son();
//			continue;
//		}
//		else if (data > (*value_node)->getData()){
//			*parent = *value_node;
//			*value_node = (*value_node)->get_right_son();
//			continue;
//		}
//		else{
//			return true;
//		}
//	}
//}
//
//// Finds position for a new element and insertes it to a tree
//// "<" elements are becoming left sons, ">=" elements are becoming right sons
//void BST::insert_to_subtree(node* now_node, int data){
//	if (data < now_node->getData()){
//		if (now_node->get_left_son() == NULL){
//			now_node->create_left_son(data);
//			return;
//		}
//		else{
//			this->insert_to_subtree(now_node->get_left_son(), data);
//		}
//	}
//	else{
//		if (now_node->get_right_son() == NULL){
//			now_node->create_right_son(data);
//			return;
//		}
//		else{
//			this->insert_to_subtree(now_node->get_right_son(), data);
//		}
//	}
//}
//void BST::print_right_left_root(){
//	this->print_subtree_right_left_root(this->top);
//}
//void BST::print_subtree_right_left_root(node* now_top){
//	if (now_top->get_right_son() == NULL){
//		if (now_top->get_left_son() == NULL){
//			cout << now_top->getData() << " ";
//			return;
//		}
//		else{
//			this->print_subtree_right_left_root(now_top->get_left_son());
//			cout << now_top->getData() << " ";
//			return;
//		}
//	}
//	else{
//		this->print_subtree_right_left_root(now_top->get_right_son());
//		if (now_top->get_left_son() == NULL){
//			cout << now_top->getData() << " ";
//			return;
//		}
//		else{
//			this->print_subtree_right_left_root(now_top->get_left_son());
//			cout << now_top->getData() << " ";
//			return;
//		}
//	}
//}
//bool BST::remove_one(int data){
//	node* parent = NULL;//was node* parent, value_node;
//	node* value_node = NULL;
//	/*find_with_parent(data, value_node, parent);
//	if (value_node == NULL){
//		return false;
//	}*/
//	if (!find_with_parent(data, &value_node, &parent)){
//		return false;
//	}
//	else{
//		if (value_node->get_right_son() == NULL){
//			//There is no right son, so we can move the left son to the position of a son of a parent
//			if (parent == NULL){
//				this->top = value_node->get_left_son();
//			}
//			else{
//				parent->set_left_son(value_node->get_left_son());
//			}
//			delete value_node;
//			this->size--;
//			return true;
//		}
//		else if (value_node->get_right_son()->get_left_son() == NULL){
//			value_node->get_right_son()->set_left_son(value_node->get_left_son());
//			if (parent == NULL){
//				this->top = value_node->get_right_son();
//			}
//			else{
//				if (parent->get_left_son() == value_node){
//					parent->set_left_son(value_node->get_right_son());
//				}
//				else{
//					parent->set_right_son(value_node->get_right_son());
//				}
//			}
//			delete value_node;
//			this->size--;
//			return true;
//		}
//		else{
//			//https://tproger.ru/translations/binary-search-tree-for-beginners/
//			//farthest left child of the right child of value_node
//			node* least_left_sub_parent, *least_left_leaf;
//			least_left_sub_parent = value_node->get_right_son();
//			least_left_leaf = value_node->get_right_son()->get_left_son();
//			while (true){
//				if (least_left_leaf->get_left_son() == NULL){
//					least_left_leaf->set_left_son(value_node->get_left_son());
//					least_left_leaf->set_right_son(value_node->get_right_son());
//					least_left_sub_parent->set_left_son(NULL);
//					if (parent == NULL){
//						this->top = least_left_leaf;
//					}
//					else{
//						if (parent->get_left_son() == value_node){
//							parent->set_left_son(least_left_leaf);
//						}
//						else{
//							parent->set_right_son(least_left_leaf);
//						}
//					}
//					delete value_node;
//					this->size--;
//					return true;
//				}
//				else{
//					least_left_sub_parent = least_left_leaf;
//					least_left_leaf = least_left_leaf->get_left_son();
//				}
//			}
//
//		}
//	}
//}
//
//void BST::print_right_root_left(){
//	this->print_subtree_right_root_left(this->top);
//}
//void BST::print_subtree_right_root_left(node* now_top){
//	if (now_top->get_right_son() == NULL){
//		cout << now_top->getData() << ' ';
//		if (now_top->get_left_son() == NULL){
//			//cout << now_top->getData() << " ";
//			return;
//		}
//		else{
//			this->print_subtree_right_root_left(now_top->get_left_son());
//			return;
//		}
//	}
//	else{
//		this->print_subtree_right_root_left(now_top->get_right_son());
//		cout << now_top->getData() << ' ';
//		if (now_top->get_left_son() == NULL){
//			//cout << now_top->getData() << " ";
//			return;
//		}
//		else{
//			this->print_subtree_right_root_left(now_top->get_left_son());
//			//cout << now_top->getData() << " ";
//			return;
//		}
//	}
//}