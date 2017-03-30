#ifndef MY_GAME
#define MY_GAME

#include"Player.h"
#include"Field.h"
#include"Chicken_yard.h"

const int INITIAL_HAND_SIZE = 7;
const int FIRST_BONE_SIDES = 4;



class game {
	public:
		//Constructors
		game();
		game(int num_players);	
		~game();

		//Accessors
		void turn_stats();
		int round_stats();
		int display_hands();
		int check_for_foot(bone * current);
		
		//Mutators
		int run();
		int deal_hands();
		int deal_bone();
		int play_turn(int & turn);
		int set_field();
		int expand_field(bone * new_foot);

	private:
		
		int				total_players;
		chicken_yard 	my_yard;
		player * 		my_players;
		field 			my_field;
};
#endif
