#include "BT.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;
BT::BT() {
	tree_root_node = NULL;
}

BT::~BT() {
}

void BT::insert_code(char node_to_add, string morse_code) { //function to insert the node in Binary search Tree
	if (!tree_root_node) {
		insert_code(tree_root_node, node_to_add, morse_code, true); //if there is no node in tree !st node will be added at root
	}
	else {      //if there is already one or more than one node is present 
		BTNode *node = tree_root_node; // rooot node will be that current node

		for (string::size_type i = 0; i < morse_code.length(); i++) { //adding node to the tree 
			if (morse_code[i] == '.') { //if charcter is '.' it will go to left side and add the node at the end , and if char is "-" it will go to right 
				if (!node->left_node) {
					if (i == morse_code.length() - 1) { //if last chracter 
						insert_code(node->left_node, node_to_add, morse_code.substr(0, i + 1), true);
					}
					else {
						insert_code(node->left_node, node_to_add, morse_code.substr(0, i + 1), false);
					}
				}
				node = node->left_node;
				if (node->left_node) {
					if (i == morse_code.length() - 1) {
						node->node_to_add = node_to_add;
					}
				}
				if (!node->left_node) {
					if (i == morse_code.length() - 1) {
						node->node_to_add = node_to_add;
					}
				}
			}
			else if (morse_code[i] == '-') {
				if (!node->right_node) {
					if (i == morse_code.length() - 1) {
						insert_code(node->right_node, node_to_add, morse_code.substr(0, i + 1), true);
					}
					else {
						insert_code(node->right_node, node_to_add, morse_code.substr(0, i + 1), false);
					}
				}

				node = node->right_node;
				if (node->right_node) {
					if (i == morse_code.length() - 1) {
						node->node_to_add = node_to_add;
					}
				}
				if (!node->right_node) {
					if (i == morse_code.length() - 1) {
						node->node_to_add = node_to_add;
					}
				}
			}
		}
	}
}

void BT::insert_code(BTNode *&node, char node_to_add, string morse_code, bool is_last) {
	if (is_last) {
		node = new BTNode();
		node->node_to_add = node_to_add;
		node->right_node = NULL;
		node->left_node = NULL;
		node->morse_code = morse_code;
	}
	if (!is_last) {
		node = new BTNode();
		node->node_to_add = '\0';
		node->right_node = NULL;
		node->left_node = NULL;
		node->morse_code = morse_code;
	}
}
bool BT::less_than_four(string::size_type a) {
	if (a < 4) {
		return true;
	}
	else {
		return false;
	}
}
bool BT::leafNode(BTNode *node) { //function to get leaf node
	if (!node->left_node && !node->right_node) {
		return true;
	}
	else {
		return false;
	}
}
string BT::decode(string user_input, bool added_node) {   //That function will decode the input using BST and searching algoriyhm 
	string the_output = "";
	BTNode *node = tree_root_node;
	for (string::size_type a = 0; a < user_input.length(); ++a) {
		if (user_input[a] == '.') { //if char is '.' next node for search will be left node
			if (node->left_node) {
				node = node->left_node;
				added_node = true;
			}
			if ((a == user_input.length() - 1 || user_input[a + 1] == ' ') && added_node) {

				the_output.append(node->node_to_add);
			}
		}
		if (user_input[a] == ' ') {
			node = tree_root_node;
			added_node = false;
		}
		if (user_input[a] == '-') {
			if (node->right_node) {
				node = node->right_node;
				added_node = true;
			}
			if ((a == user_input.length() - 1 || user_input[a + 1] == ' ') && added_node) {
				the_output.append(node->node_to_add);
			}
		}
		added_node = false;
	}
	return the_output;
}
