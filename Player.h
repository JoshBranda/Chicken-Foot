#ifndef MY_PLAYER_INFO
#define MY_PLAYER_INFO

#include"Bone.h"
#include"BST_ends.h"

class player {
    public:
        //Constructors
        player();
        ~player();

        //Accessors
        int 	show_hand(); //Wrapper function for LLL traversal   
		int 	calculate_score();
		bool 	check_for_empty_hand();

        //Mutators
		bone* 	check_bone(bone * to_add); //Check to see if the newly drawn bone has a match in the ends
        int 	draw_bone(bone * to_add); //Wrapper
		bone* 	draw_foot_bone(bone * to_add, int value_needed);
		bone* 	place_bone();
		bone* 	place_bone(int value_needed);
		bone * 	return_highest_double(int & highest);
		int 	remove_highest_double(bone * to_remove);
		void 	set_ends_list(BST_ends * to_copy);
		int 	clear_hand();

    private:

        int show_hand(bone * current); //Recursive call for LLL 
        int draw_bone(bone * to_add, bone * current); //Recursive call

        int     	score;
        bone *  	head; //Hand manifested as LLL of bones
		BST_ends * 	ends_bst;
};



#endif
