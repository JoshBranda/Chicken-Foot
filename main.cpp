/*
Joshua Sander
1-21-2016
CS261 Assignment 1

Notes: This main function just tests some of the functionality of the classes.
True completion of objects will not happen until game is designed.

*/

#include<iostream>
#include<algorithm>
#include"Game.h"

const int PLAYER_MIN = 2;
const int PLAYER_MAX = 5;

using namespace std;

int main()
{
	int players = 0;

	cout << endl << "Welcome! You are about to play Chicken Foot!  "  << endl << endl;

	cout << "How many players are there? (2-5)" << endl;

	cin >> players;

	while (players < PLAYER_MIN || players > PLAYER_MAX)
	{
		cout << endl << "That is not a valid number of players!" << endl;
		cout << "Please enter a valid number (2-5)" << endl;
		cin >> players;
	}
	
	game my_game(players);

	my_game.run();

    return 0;
}
