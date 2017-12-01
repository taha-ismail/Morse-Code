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
	 BinaryTree();
	~BinaryTree();

	// SETTERS:
	void insert_code(char char_value, string morse_value); // Inserts only root node.
	void insert_code(BinaryTreeNode *&new_node, char char_value, string morse_value, bool last_character); // Inserts all non-root nodes.

	// ENCODING AND DECODING FUNCTIONS:
	string decode(string users_morse_string, bool added_node);
	string encode(string users_morse_string, bool added_node);
	string get_input();
	bool validate_leaf(BinaryTreeNode *node);
	bool validate_length(unsigned int a);
};
#endif
