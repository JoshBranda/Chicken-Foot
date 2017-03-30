#include"BST_ends.h"
#include<iostream>


BST_ends::BST_ends()
{
	root = NULL;
}



BST_ends::~BST_ends()
{
	if (root)
		destroy_all(root);
}



int BST_ends::insert_node(int to_add)
{
	return insert_node(to_add, root);
}



int BST_ends::remove_node(int to_remove)
{
	if (!root)
		return -1;
	
	return remove_node(to_remove, root);
}



int BST_ends::insert_node(int to_add, end *& current)
{
	if (!current)
	{
		current = new end;
		current->data = to_add;
		return 1;
	}

	if (current->data > to_add)
	{
		return insert_node(to_add, current->left);
	}

	return insert_node(to_add, current->right);
}



int BST_ends::remove_node(int to_remove, end *& current)
{
	if (!current)
		return 0;

	if (current->data == to_remove)
	{
		if (!current->left && !current->right)
		{
			delete current;
			current = NULL;
			return 1;
		}

		if (current->left && !current->right)
		{
			end * temp = current;
			current = current->left;

			delete temp;
			temp = NULL;

			return 1;
		}

		if (!current->left && current->right)
		{
			end * temp = current;
			current = current->right;

			delete temp;
			temp = NULL;

			return 1;
		}

		delete_IOS(to_remove, current->right);
		current->data = to_remove;
		return 1;	
	}

	if (current->data > to_remove)
		return remove_node(to_remove, current->left); 

	return remove_node(to_remove, current->right);
}



int BST_ends::delete_IOS(int &to_remove, end *& current)
{
	if (!current->left)
	{
		to_remove = current->data;

		if (current->right)
		{
			end * temp = current;
			current = current->right;

			delete temp;
			temp = NULL;

			return 1;			
		}

		delete current;
		current = NULL;
		
		return 1;
	}

	return delete_IOS(to_remove, current->left);
}



int BST_ends::destroy_all(end *& current)
{
	if (!current)
		return 0;

	destroy_all(current->left);
	destroy_all(current->right);

	delete current;
	current = NULL;

	return 0;
}
