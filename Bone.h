#ifndef MY_BONES
#define MY_BONES


const int LOW_VALUE = 1;
const int HIGH_VALUE = 9;

class bone {
    public:
        bone();
		bone(const bone & to_copy);
        ~bone();

        //Accessor
        void display();
        int compare_sides(int to_compare); //For when game is checking for a bone in players hand
        
        //Mutator
        int set_values(int one, int two); //Used for initializing the deck only, values don't change afterwards
		int swap_sides(); //Used to allign the domino to the correct side when adding to the field

    private:

        int     side1;
		int 	side2;
        bone *  next;

        friend  class   player;
		friend  class	field;
};

#endif
