#include "BinaryTree.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

bool checkerMorseString(string users_morse_string) { 
	//this function will use to validate the text that is enter by user
	bool validate = users_morse_string.size();

	// if string is empty:
	if (!validate) {
		return false;
	}

	// if string is not empty, check if it is a proper string that can be DECODED:
	for (int index = 0; index < users_morse_string.length(); ++index) {
		if (users_morse_string[index] != ' ' && users_morse_string[index] != '.' && users_morse_string[index] != '-') {
			return false;
		}
	}
	return true;
}

bool checkEncodeInput(string txt){
	/*
	input: string that needs to be encoded
	output: true/false

	This function walks through each character in the string and determines whether or not it is an alphabetical character. If it isn't, it returns false.
	*/

	bool validate = false;
	char character;
	for (int index = 0; index < txt.length(); index++) {
        character = txt.at(index); 
        // if it's NOT within these bounds, then it's not a character
        if (! ( (character >= 'a' && character <= 'z' )) ) {
			// validate is false by default
        }
        else {
			validate = true;
		}
     }
	// if string is valid:
     if(validate){
     	return true;
	 }
	 // if string contains incorrect character(s)  :
	 else{
	 	return false;
	 }
}

string to_lower_string(string string_to_lower) { 
	/* 
	Input: Text
	Output: completely lowercase string
	*/
	int size = string_to_lower.length();
	// Iterate through string and lower each character:
	for (int index = 0; index < size; index++) {
		tolower(string_to_lower[index]);
	}
	return string_to_lower;
}

int main() {
	// VARIABLES:
	BinaryTree tree;
	string text;
	string lowerCaseText;
	ifstream file_read;   
	file_read.open("morse-code.txt"); 
	string user_code;
	bool node_added = false;

	if (!file_read) { //if file not found it will return a error message.
		cout << "Unable to open the file: morse-code.txt" << endl;
	}
	else {
		// Insert morse code into a BinaryTree:
		tree.insert_code('0', "*"); //the first node of tree will null which we keep '*'
		while (getline(file_read, user_code)) { //line by line read the code from file and insert it into tree
			tree.insert_code(user_code[0], user_code.substr(2, user_code.length() - 2));
	}

	file_read.close();
	int option;
	while(true){
		// Menu created for easier debugging:
		cout <<"1. Encode a message" << endl
			<< "2. Decode a message" << endl
			<<"3. Quit" << endl;
		cin >> option;
		cin.ignore();
		switch(option){
				case 1:	// ENCODE:
				   cout << "Type a letter or words for encoding: " << endl;
				   text = tree.get_input(); //take input from user
				   lowerCaseText = to_lower_string(text); //convert it in to lower case
				   while(!checkEncodeInput(lowerCaseText)){
					   cout << "Type valid input for decoding: " << endl;
					   text = tree.get_input(); //take input from user
					   lowerCaseText = to_lower_string(text); //convert it in to lower case
				   }
				   cout<<"Encoded text is "<<tree.encode(lowerCaseText,node_added) <<endl;
						break;
				case 2:	// DECODE:
					cout << "Type in the morse code for decoding: " << endl;
					text = tree.get_input(); //take input from user
					while (!checkerMorseString(text)) { //validate input string , if it contain anyOther chracter expect '-' '.' and space , user will gain enter the text 
						cout << "Type valid morse code for decoding: " << endl;
						text = tree.get_input();
					}   
					cout << "The decoded text is " << tree.decode(text, node_added) << endl; // decode the user entered string and print it on string 
					break;
				case 3:	// QUIT:
					return 0;
				default:	// DEFAULT:
					cout <<"Invalid input" << endl;
    				break;
				}
			}
		}
	system("pause");
	return 0;
}
