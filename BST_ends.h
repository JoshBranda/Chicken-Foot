#ifndef MY_BST 
#define MY_BST

#include"End.h"

class BST_ends {
	public:
		//Constructors
		BST_ends();
		~BST_ends();

		//Accessors

		//Mutators
		int insert_node(int to_add); //New end is added to list
		int remove_node(int to_remove); //If corresponding number is found in ends list, the node is removed.  If not, the program is notified that the domino can't be played

	private:
		//Recursive functions
		int insert_node(int to_add, end *& current);
		int remove_node(int to_remove, end *& current);
		int delete_IOS(int &to_remove, end *& current);
		int destroy_all(end *& current);

		end * root;
};

#endif
