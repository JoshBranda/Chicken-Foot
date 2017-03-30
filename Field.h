#ifndef MY_FIELDS
#define MY_FIELDS

#include"Bone.h"
#include"BST_ends.h"

const int INITIAL_FIELD_SIZE = 4;

class field {
	public:
		//Constructors
		field();
		~field();

		//Accessors
		void display_field();
		int check_for_foot();
		BST_ends * return_bst_address();

		//Mutators
		int set_up(bone * to_start);
		int add_to_field(bone * to_add);
		int add_to_foot(bone * to_add);
		int destroy_field();
		int expand_field(bone * to_expand);

	private:

		bone ** 	array;	
		int 		field_size;	
		BST_ends	my_bst;
};



#endif
