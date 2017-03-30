#include"Chicken_yard.h"
#include<iostream>
#include<algorithm>
#include<random>
#include<chrono>

using namespace std;



chicken_yard::chicken_yard()
{
	deck = new bone[DECK_SIZE];

    stack_top = DECK_SIZE - 1;

    int     iteration = 0;

    for (int x = LOW_VALUE; x <= HIGH_VALUE; ++x)
    {
	
        for (int y = x; y <= HIGH_VALUE; ++y)
        {
            deck[iteration].set_values(x, y);
            ++iteration;
        }
    }
}



chicken_yard::~chicken_yard()
{
	if (deck)
	{
		delete [] deck;
		deck = NULL;
	}

}



void chicken_yard::print_deck()
{
    for (int x = 0; x <= stack_top; ++x)
    {
        deck[x].display();
    }
    cout << endl;
}



int chicken_yard::shuffle_deck()
{
    unsigned random = chrono::system_clock::now().time_since_epoch().count();

    shuffle(&deck[0], &deck[stack_top], default_random_engine(random)); 

    return 1;
}



bone * chicken_yard::remove_bone()
{
    if (stack_top < 0)
        return NULL;

    return  &deck[stack_top--];
}   



int chicken_yard::reset_deck()
{
	stack_top = DECK_SIZE - 1;
	shuffle_deck();

	return 1;	
}

