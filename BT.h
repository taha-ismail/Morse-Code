#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#ifndef BT_H
#define BT_H


using namespace std;
class BT {
private:
	struct BTNode {
		BTNode *left_node;
		BTNode *right_node;
		string morse_code;
		string node_to_add;
	}; BTNode *tree_root_node;

public:
	BT();
	~BT();
	string decode(string user_input, bool added_node);
	string encode(string user_input, bool added_node);
	string text_entered();
	void insert_code(char node_to_add, string morse_code);
	void insert_code(BTNode *&new_node, char node_to_add, string morse_code, bool is_last);
	bool leafNode(BTNode *node);
	bool less_than_four(string::size_type a);
};
#endif
