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
		string code;
		string the_message;
	}; BTNode *root_node;

public:
	BT();
	~BT();
	string decode(string input, bool added);
	string encode(string input, bool added);
	string inputtedText();
	void insert_code(char message, string code);
	void insert_code(BTNode *&new_node, char message, string code, bool is_last);
	bool leafNode(BTNode *node);
	bool lessFour(string::size_type a);
};
#endif
