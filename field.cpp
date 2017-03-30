#include"Field.h"
#include"Bone.h"
#include"BST_ends.h"
#include<iostream>

using namespace std;

field::field()
{
	array = NULL;
}



field::~field()
{
	destroy_field();
}



void field::display_field()
{
	bone * current;

	for (int x = 0; x < field_size; x++)
	{
		current = array[x];
		
		while (current)
		{
			current->display();
			current = current->next;
		}	
		cout << endl;
	}
}



int field::check_for_foot()
{
	bone * current;

	for (int x = 0; x < field_size; x++)
	{
		current = array[x];

		if (!current->next)
			return current->side1;	
		
	}	

	return 0;
}



BST_ends * field::return_bst_address()
{
	return &my_bst;
}



int field::set_up(bone * to_start)
{
	field_size = INITIAL_FIELD_SIZE;
	array = new bone * [field_size];	
	
	for (int x = 0; x < field_size; x++)
	{
		array[x] = new bone(*to_start);
	}	

	return 1;
}



int field::add_to_field(bone * to_add)
{
	bone * current;

	for (int x = 0; x < field_size; x++)
	{
		current = array[x];
	
		while (current->next)
		{
			current = current->next;
		}
		
		if (current->side2 == to_add->side1)
		{
			current->next = to_add;
			my_bst.remove_node(to_add->side1);

			if (to_add->side1 == to_add->side2) //New bone is a chicken foot
			{
				return -1;	
			}

			my_bst.insert_node(to_add->side2);

			return 1;	
		}	
	}

	return 0;		
}



int field::add_to_foot(bone * to_add)
{
	bone * current;

	for (int x = 0; x < field_size; x++)
	{
		current = array[x];
	
		if (!current->next)
		{
			if (current->side2 == to_add->side1)
			{
				current->next = to_add;

				my_bst.insert_node(to_add->side2);

				return 1;	
			}	
	
			to_add->swap_sides();
			current->next = to_add;
			my_bst.insert_node(to_add->side2);

			return 1;
		}
		
	}

	return 0;		
}



int field::destroy_field()
{
	if (array)
	{
		for (int x = 0; x < field_size; ++x)
		{
			if (array[x])
			{
				delete array[x];
				array[x] = NULL;
			}
		}

		delete [] array;
		array = NULL;
	}
	return 1;
}



int field::expand_field(bone * to_start)
{

	bone ** temp = new bone * [field_size + 3]; //New field with 3 extra LLL's is created
	
	for (int x = 0; x < (field_size); x++)
	{
		temp[x] = new bone(*array[x]); //New heads are created and copied with the already existing info from the previous board
		temp[x]->next = array[x]->next; //The LLL's held by the previous heads are preserved
	}	

	destroy_field(); //Delete the memory from the old board
	field_size += 3; //Change the field size to reflect the newly added bone

	for (int y = (field_size - 3); y < field_size; y++)
	{
		temp[y] = new bone(*to_start); //The new heads are given to the newly added double
	}
	
	array = temp;	

	return 1;
}
