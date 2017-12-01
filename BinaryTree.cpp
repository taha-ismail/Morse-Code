#include "BinaryTree.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

BinaryTree::BinaryTree() {
	node_root = NULL;
}

BinaryTree::~BinaryTree() {
}

string BinaryTree::get_input() {
	string user_text;
	getline(cin, user_text);
	return user_text;
}

void BinaryTree::insert_code(BinaryTreeNode *&node, char char_value, string morse_value, bool last_character) {
	node = new BinaryTreeNode();
	node->morse_value = morse_value;
	node->right_child = NULL;
	node->left_child = NULL;
	if (last_character) {
		node->char_value = char_value;
	}else {
		node->char_value = '\0';
	}
}

bool BinaryTree::validate_length(unsigned int a) {
	if (a <= 3) {
		return true;
	}
	return false;
}

bool BinaryTree::validate_leaf(BinaryTreeNode *node) {
	if (!node->left_child && !node->right_child) {
		return true;
	}
	return false;
}

string BinaryTree::decode(string users_morse_string, bool added_node) {   //That function will decode the input using BST and searching algoriyhm 
	string result = "";
	BinaryTreeNode *node = node_root;
	for (int index = 0; index < users_morse_string.length(); ++index) {
		if (users_morse_string[index] == ' ') {
			// If character is blank, root node is NULL. 
			added_node = false;
			node = node_root;
		}
		if (users_morse_string[index] == '.') {
			if (node->left_child) {
				node = node->left_child;
				added_node = true;
			}
			if ((index == users_morse_string.length() - 1 || users_morse_string[index + 1] == ' ') && added_node) {
				result.append(node->char_value);
			}
		}
		if (users_morse_string[index] == '-') {
			if (node->right_child) {
				node = node->right_child;
				added_node = true;
			}
			if ((index == users_morse_string.length() - 1 || users_morse_string[index + 1] == ' ') && added_node) {
				result.append(node->char_value);
			}
		}
		added_node = false;
	}
	return result;
}

void BinaryTree::insert_code(char char_value, string morse_value) {
	//function to insert the node in Binary search Tree
	if (!node_root) {
		insert_code(node_root, char_value, morse_value, true); //if there is no node in tree !st node will be added at root
	}
	else {      //if there is already one or more than one node is present 
		BinaryTreeNode *node = node_root; // rooot node will be that current node
		for (int index = 0; index < morse_value.length(); index++) { //adding node to the tree 
			if (morse_value[index] == '.') { //if charcter is '.' it will go to left side and add the node at the end , and if char is "-" it will go to right 
				if (!node->left_child) {
					if (index == morse_value.length() - 1) { //if last chracter 
						insert_code(node->left_child, char_value, morse_value.substr(0, index + 1), true);
					}
					else {
						insert_code(node->left_child, char_value, morse_value.substr(0, index + 1), false);
					}
				}
				node = node->left_child;
				if (node->left_child) {
					if (index == morse_value.length() - 1) {
						node->char_value = char_value;
					}
				}
				if (!node->left_child) {
					if (index == morse_value.length() - 1) {
						node->char_value = char_value;
					}
				}
			}
			else if (morse_value[index] == '-') {
				if (!node->right_child) {
					if (index == morse_value.length() - 1) {
						insert_code(node->right_child, char_value, morse_value.substr(0, index + 1), true);
					}
					else {
						insert_code(node->right_child, char_value, morse_value.substr(0, index + 1), false);
					}
				}
				node = node->right_child;
				if (node->right_child) {
					if (index == morse_value.length() - 1) {
						node->char_value = char_value;
					}
				}
				if (!node->right_child) {
					if (index == morse_value.length() - 1) {
						node->char_value = char_value;
					}
				}
			}
		}
	}
}
