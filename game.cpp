#include"Game.h"
#include"Player.h"
#include<iostream>

using namespace std;

game::game()
{
	my_players = NULL;
}



game::game(int num_players)
{
	total_players = num_players;

	my_players = new player[num_players];

	my_yard.shuffle_deck();	

	for (int x = 0; x < total_players; x++)
	{
		my_players[x].set_ends_list(my_field.return_bst_address());
	}
}



game::~game()
{
	if (my_players)
		delete [] my_players;
}



void game::turn_stats()
{
	cout << "The board looks like this: " << endl;
	my_field.display_field();
	cout << endl << endl;

	cout << "The players currently have these hands: " << endl;
	
	for (int x = 0; x < total_players; x++)
	{
		cout << "Player" << x + 1 << " has: ";
		my_players[x].show_hand();
	}
	cout << endl << endl;
}



int game::round_stats()
{
	cout << endl << "Scores after this round are as follows: " << endl;	

	for (int x = 0; x < total_players; x++)
	{
		cout << "Player" << x + 1 << "'s score: " << my_players[x].calculate_score() << endl;;
	}

	cout << endl;	
	
	return 1;
}



int game::display_hands()
{
	for (int x = 0; x < total_players; x++)
	{
		my_players[x].show_hand();
	}	

	return 1;
}



int game::run()
{
	char 	choice;
	int		round_end;
	int		turn;

	cout << endl << endl << "Welcome to the game! When you are ready to start, you will see each turn of the game in text." << endl << endl;
	cout << "Are you ready to begin? Press 't' to begin or any other key to exit" << endl;

	cin >> choice;

	if (choice != 't')
		return 0;

	while ( choice != 'e' && choice != 'E')
	{
		turn = 0;

		my_yard.reset_deck();	
		
		for (int x = 0; x < total_players; x++)
		{
			my_players[x].clear_hand();
		}
		
		deal_hands();
		set_field();

		while ( choice != 'e' && choice != 'E' && choice != 'r')
		{
			round_end = play_turn(turn);
			turn_stats();

			if (round_end == -1)
				choice = 'r';
		
			else	
			{
				cout << endl << "Enter 't' for next turn or 'e' exit" << endl;
				cin >> choice;
			}
		}
		
		round_stats();
		my_field.destroy_field();

		cout << "Would you like to playe another round?" << endl;
		cout << "Press 't' to begin next round, 'e' to exit" << endl;		
		cin >> choice;
			
	}		
	
	cout << endl << endl << "THANKS FOR PLAYING!" << endl;
	
	return 1;
}



int game::deal_hands()
{
	for (int x = 0; x < total_players; ++x)
	{
		for (int y = 0; y < INITIAL_HAND_SIZE; ++y)
		{	
			bone * temp = my_yard.remove_bone(); 
			my_players[x].draw_bone(temp);
		}
	}

	return 1;
}



int game::play_turn(int & turn)
{
	int 	check_chicken = my_field.check_for_foot();
	int		player_ready = 0; 
	bone * 	add_to_field;
	bone * 	player_got_lucky;

	while (player_ready < total_players)
	{
		if (check_chicken > 0) //This first if control checks to see if a chicken foot or starting bone is awaiting an addition
		{
			add_to_field = my_players[player_ready].place_bone(check_chicken);	
	
			if (!add_to_field) //Player cannot complete the chicken foot and needs to draw
			{
				add_to_field = my_yard.remove_bone();		

				if (!add_to_field) //The deck has nothing more to draw!  Game over!
					return -1;	

				player_got_lucky = my_players[player_ready].draw_foot_bone(add_to_field, check_chicken);
				
				if (player_got_lucky) //The player happened to draw something that fit the chicken foot
					my_field.add_to_foot(player_got_lucky);
			}

			else
			{
				my_field.add_to_foot(add_to_field);
				if (my_players[player_ready].check_for_empty_hand() == true) //The player played all of their bones! Round over!
					return -1;
			}
		}

		else //This second if control knows there are no pending chicken feet, and has the player check for any open end 
		{
			add_to_field = my_players[player_ready].place_bone();
			
		
			if (!add_to_field) //The player didn't have any matching bones in their hand
			{
				add_to_field = my_yard.remove_bone(); //They are dealt a new bone

				if (!add_to_field) //The deck has nothing more to draw!  Game over!
					return -1;
				player_got_lucky = my_players[player_ready].check_bone(add_to_field);
				
				if (player_got_lucky)
				{
					my_field.add_to_field(player_got_lucky); //The bone they drew matches a needed value and is immediately placed
				}
			}
			
			else
			{
				if (my_field.add_to_field(add_to_field) == -1) //The bone the player added is a chicken foot!
				{
					my_field.expand_field(add_to_field);	 //The board is expanded to include three new lines of the chicken foot
				}

				if (my_players[player_ready].check_for_empty_hand() == true) //The player played all of their bones! Round over!
					return -1;
			}
		}

		check_chicken = my_field.check_for_foot();
	 
		player_ready++;
	}
	turn++;

	return 1;
}



int game::set_field()
{
	int 	highest = 0;
	int 	player_index = 0;
	bone * 	first_bone = NULL;
	bone * 	highest_in_hand = NULL;

	for (int x = 0; x < total_players; x++)
	{
		highest_in_hand  = my_players[x].return_highest_double(highest); 	
	
		if (highest_in_hand)
		{
			first_bone = highest_in_hand;
			player_index = x;
		}
	}

	if (first_bone)
	{
		my_players[player_index].remove_highest_double(first_bone);
		my_field.set_up(first_bone);
		
			
		return 1;
	}		

	return 0;
}


