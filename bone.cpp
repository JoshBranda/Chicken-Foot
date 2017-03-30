#include"Bone.h"
#include<iostream>

using namespace std;

bone::bone()
{
    next = NULL;
}



bone::bone(const bone & to_copy)
{
	next = NULL;

	side1 = to_copy.side1;
	side2 = to_copy.side2;
}



bone::~bone()
{
}



void bone::display()
{
    cout << side1 << "|" << side2 << " ";
}



int bone::compare_sides(int to_compare)
{
    if ( (side1 != to_compare) && (side2 != to_compare) )
        return -1;

    if ( side1 == to_compare)
	{
        return 1;
	}

	swap_sides();	
    return 1;;
}   



int bone::set_values(int one, int two)
{
    if ( (one < LOW_VALUE) || (one > HIGH_VALUE) || (two < LOW_VALUE) || (two > HIGH_VALUE) )
        return 0;

    side1 = one;
    side2 = two;

    return 1;

}


int bone::swap_sides()
{
	int temp = side2;

	side2 = side1;
	side1 = temp;

	return 1;
}
