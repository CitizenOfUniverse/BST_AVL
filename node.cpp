/*
* node.cpp - Describes methods of the node class
*/

#include "BST.h"
// Here "stddef.h" is needed to define NULL constant
//#include "stddef.h"

unsigned char node::get_height() {
	return height;
}
//Returns balance factor - difference between the height of right and height of left tree
int node::get_bfactor() {
	if (left != NULL) {
		if (right != NULL) {
			return right->get_height() - left->get_height();
		}
		else {
			return -(left->get_height());
		}
	}
	else {
		if (right != NULL) {
			return right->get_height();
		}
		else {
			return 0;
		}
	}
}
void node::fixheight()
{
	unsigned char h_left = 0;
	unsigned char h_right = 0;
	if (left != NULL) {
		h_left = left->get_height();
	}
	if (right != NULL) {
		h_right = right->get_height();
	}
	//unsigned char h_left = left->get_height();
	//unsigned char h_right = right->get_height();
	set_height((h_left > h_right ? h_left : h_right) + 1);
	return;
}


// node class constructor
//node::node(){
//	this->left = NULL;
//	this->right = NULL;
//}
node::node(int data){
	this->left = NULL;
	this->right = NULL;
	this->height = 1;
	this->data = data;
}
// "Get" method for field prev of class node
node* node::get_left_son(){
	if (this == NULL) {
		return NULL;
	}
	else {
		return this->left;
	}
}
node* node::get_right_son(){
	if (this == NULL) {
		return NULL;
	}
	else {
		return this->right;
	}
}
// "Get" method for field data of class node
int node::getData(){
	if (this == NULL) {
		return -999999999;
	}
	else {
		return this->data;
	}
}
son_create_status node::create_left_son(int data){
	if (this->left == NULL){
		this->left = new node(data);
		if (this->left == NULL) {
			return ERR_ALLOCATING_MEMORY_FOR_NODE;
		}
		return OK;
	}
	else{
		return LEFT_SON_ALREADY_EXISTS;
	}
}
son_create_status node::create_right_son(int data){
	if (this->right == NULL){
		this->right = new node(data);
		if (this->right == NULL) {
			return ERR_ALLOCATING_MEMORY_FOR_NODE;
		}
		return OK;
	}
	else{
		return LEFT_SON_ALREADY_EXISTS;
	}
}
void node::set_left_son(node* new_left_son){
	this->left = new_left_son;
	return;
}
void node::set_right_son(node* new_right_son){
	this->right = new_right_son;
	return;
}
