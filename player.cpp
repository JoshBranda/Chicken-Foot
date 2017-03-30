#include"Player.h"
#include"Bone.h"
#include"BST_ends.h"
#include<iostream>

using namespace std;



player::player()
{
    score = 0;
    head = NULL;
}



player::~player()
{
}



int player::show_hand()
{
    if (!head)
	{
		cout << endl;
        return 0;
	}

    return show_hand(head); 
}



int player::calculate_score()
{
	bone * 	current = head;

	while (current)
	{
		score += current->side1 + current->side2;
		current = current->next;
	}
			
	return score;
}



bool player::check_for_empty_hand()
{
	if (!head)
		return true;

	return false;		
}



bone* player::check_bone(bone * to_add)
{
	if (ends_bst->remove_node(to_add->side1) == 1) //Head has a needed end in the field
	{
		return to_add;
	}

	if (ends_bst->remove_node(to_add->side2) == 1)
	{
		to_add->swap_sides();
		return to_add;
	}

	draw_bone(to_add);	
	
	return NULL;
}



int player::draw_bone(bone * to_add)
{
	to_add->next = head;
	head = to_add;
	
	return 1;
}



bone* player::draw_foot_bone(bone * to_add, int value_needed)
{
	if (to_add->compare_sides(value_needed) != -1)
	{ 
		return to_add;
	}

	draw_bone(to_add);

	return NULL;
}



bone * player::place_bone()//This is for adding a bone after the start and no chicken feet in the field
{
	bone * current = head;
	bone * previous = head;


	if (ends_bst->remove_node(head->side1) == 1) //Head has a needed end in the field
	{
		head = head->next;
		current->next = NULL;
		return current;
	}

	if (ends_bst->remove_node(head->side2) == 1)
	{
		head->swap_sides();
		head = head->next;
		current->next = NULL;
		return current;
	}

	current = current->next;

	while (current)	
	{
		if (ends_bst->remove_node(current->side1) == 1) //Current bone has a needed end in the field
		{
			previous->next = current->next;
			current->next = NULL;
			return current;
		}

		if (ends_bst->remove_node(current->side2) == 1)
		{
			current->swap_sides();
			previous->next = current->next;
			current->next = NULL;
			return current;
		}

		current = current->next;
		previous = previous->next;
	}

	return NULL; //None of the bones in the players hand had a needed end
		
}



bone * player::place_bone(int value_needed)
{
	bone * 	current = head;
	bone * 	previous = head;
	int 	add_to_field;

	if (!head)
	{
		return NULL;
	}

	add_to_field = head->compare_sides(value_needed);


	if (add_to_field != -1)
	{
		head = head->next;
		current->next = NULL;
		return current;	
	}

	current = current->next;

	while (current)	
	{
		add_to_field = current->compare_sides(value_needed);

		if (add_to_field != -1)
		{
			previous->next = current->next;
			current->next = NULL;
			return current;	
		}

		current = current->next;
		previous = previous->next;
	}

	return NULL;
}




bone * player::return_highest_double(int & highest)
{
	bone * current = head;
	bone * to_return = NULL;

	while (current)
	{
		if (current->side1 > highest) 
		{
    		if (current->side1 == current->side2)
    		{
       			to_return = current; 
				highest = current->side1;
			}
    	}
		current = current->next;
	}

	return to_return;
}



int player::remove_highest_double(bone * to_remove)
{
	bone * 	current = head;
	bone * 	temp;

	if (head == to_remove)
	{
		head = head->next;
		current->next = NULL;
		return 1;
	}

	while (current->next != to_remove)
	{
		current = current->next;
	}

	if (current->next)
	{
		temp = current->next;
		current->next = current->next->next;	
		temp->next = NULL;
		return 1;
	}

	return 0;
}



void player::set_ends_list(BST_ends * to_copy)
{
	ends_bst = to_copy;
}



int player::show_hand(bone * current)
{
    if (!current)
    {
        cout << endl;
        return 1;
    }

    cout << current->side1 << "|" << current->side2 << " ";

    return show_hand(current->next);
}



int player::clear_hand()
{
	bone * temp = head;

	while (head)
	{
		head = head->next;
		temp->next = NULL;	
		temp = head;
	}

	return 1;
}
