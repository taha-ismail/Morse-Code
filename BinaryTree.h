#include <string>
#include <fstream>
#include <cctype>
#include <iostream>

#ifndef BinaryTree_H
#define BinaryTree_H

using namespace std;

class BinaryTree {
private:
	struct BinaryTreeNode {
	string morse_value;
	string char_value;
	BinaryTreeNode *left_child;
	BinaryTreeNode *right_child;
}; BinaryTreeNode *node_root;

public:
	// REQUIRED:
	 BinaryTree();
	~BinaryTree();

	// SETTERS:
	// Inserts only root node.
	void insert_code(char char_value, string morse_value); 
	// Inserts all non-root nodes.
	void insert_code(BinaryTreeNode *&new_node, char char_value, bool last_character); 

	// ENCODING AND DECODING FUNCTIONS:
	// Decodes morse code into english.
	string decode(string users_morse_string, bool added_node);
	// Encodes english into morse code.
	string encode(string users_morse_string, bool added_node);
	// Used to retrieve user input
	string get_input();
	// Validates if node is leafe node
	bool validate_leaf(BinaryTreeNode *node);
	// Validates length of node, if <=3.
	bool validate_length(unsigned int a);
};
#endif
