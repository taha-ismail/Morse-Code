#ifndef BSTClass
#define BSTClass
#include <string>

/*
Made with the help of BST code on blackboard.
 */

using namespace std;
 
class BST
{
        private:
                struct BTNode
                {
                         string letter;
                         string code;
                         BTNode *left;
                         BTNode *right;
                        
				};
                         BTNode *root;
 
         public:
                 BST()
                      {
                         root = nullptr;
                      }
                      void Insert(BTNode *&b, string letter, string code)
                      {
                           if(b == nullptr){
                              
                         b = new BTNode; b->letter = letter;
                         b->left = b->right = nullptr; b->code = code;
                       }
                         if(b->letter > letter) Insert(b->left, letter, code);
                         if(b->letter < letter) Insert(b->right, letter, code);
                        }
                        
			void Insert(string letter, string code){Insert(root, letter, code);}
                        void display_pre_order(BTNode *b)
                        {
                        if(b != nullptr)
                        {
                                        
                        cout << b->letter << "\t";
                        display_in_order(b->left);
                        display_in_order(b->right);
                        }
                        }
                        			
			void display_in_order(BTNode *b)
                        {
                        if(b!= nullptr)
                        {
   				display_in_order(b->left);
                                cout << b->letter << "\t";
                                display_in_order(b->right);
                                }
                        }
                        
                        void display_in_order(){display_in_order(root);}
                        void display_pre_order(){display_pre_order(root);}
                        void display_post_order(BTNode *b)
                        {
                                if(b!= nullptr)
                                {
                                        
                                        display_post_order(b->left);
                                        display_post_order(b->right);
                                        cout << b->letter << "\t";
                                }
                        }
                        void Encode(char x)
                        {
                                BTNode* b = search_and_return(root, x);
                                if(b!= nullptr) cout << b->code;
                                else cout << "Error.";
                        }
                        void Decode(string x)
                        {
                                BTNode* b = search_and_returnString(root, x);
                                if(b->code == x) cout << b->letter;
                                else cout << b->code << " with x being " << x << endl; cout << "Error.";
                        }
                        BTNode* search_and_return(BTNode *b, char x)
                        {
                                if(b!= nullptr)
                                {
                                        if(b->letter[0] == x) {return b;}
                                        else if(b->letter[0] > x) {search_and_return(b->left, x);}
                                        else {search_and_return(b->right, x);}
                                }
                                else return nullptr;
                        }
                        BTNode* search_and_returnString(BTNode *b, string x)
                        {
                                if(b!= nullptr)
                                {
                                        if(b->code == x) {cout << b->code << " matches " << x << endl; return b;}
                                        else if(b->code > x) {search_and_returnString(b->left, x);}
                                        else {search_and_returnString(b->right, x);}
                                }
                                else return nullptr;
                        }
};
#endif
