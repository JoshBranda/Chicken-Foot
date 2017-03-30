#ifndef MY_YARDS
#define MY_YARDS

#include"Bone.h"

const int DECK_SIZE = 45;

class chicken_yard {
    public:
        //Constructors
        chicken_yard();
        ~chicken_yard();

        //Accessors
        void print_deck();

        //Mutators
        int shuffle_deck();
        bone * remove_bone(); //Decrement the stack.  The bone remains allocated here in memory, with the player and field classes just pointing to these memory locations
		int reset_deck(); //Returns stack pointer to top of deck and reshuffles the deck for a new round

    private:
        bone *  deck;
        int     stack_top;

};


#endif
