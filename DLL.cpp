
//Ashley Maddix
// CS 202, Fall Q2018, Prog2

//~main~
//add menu

//~transportation~
//--general
//--scooter
//--zipcar
//--bike

//*~DLL~
//--DLL
//--node
#include "DLL.h"

//-------------------------//
//--NODE CLASS--//

// DLL default constructor
DLL::DLL()
{
	head= NULL;
}

// dll copy constructor
DLL::DLL (const DLL & source)
{
	dll_cc(head, source.head);
} 

// dll destructor
DLL::~DLL()
{
	remove_all();
}

// function to to help copy constructor recusivly copy source into new DLL
int DLL::dll_cc(node * & head, node * source)
{
	if(!source)
		return 0;

	head->set_basevar(source);// set base var
	head->set_next(source->get_next()); // set next
	head->set_previous(source->get_previous()); // set previous

	head=head->get_next(); // traverse next
	source=source->get_next(); // traverse next for source
	dll_cc(head, source); // recall function

}

//function to add a vehicle to list
int DLL::add(int choice)
{
	// if we have nothing in our list
	if(!head)
	{
		head= new node;
		head->get_derived(choice);
		// set previous and next pointers no NULL
		head->set_next(NULL); 
		head->set_previous(NULL);
		return 1;
	}

	// if we have something in our list
	else
	{
		node * current= new node;
		current->get_derived(choice);
		head->set_previous(current);
		current->set_next(head);
		
		head=current;
		head->set_previous(NULL);
		return 1;

	}

	return 0;	
	

}
	
// function to remove any vehicle in need of repair 	
int DLL::remove_vehicle()
{
	
	if (head)
		remove_vehicle (head); 

/*
	if ( !head)
		return 0;

	while(head)
	{	
		if (!head->next && head->get_repair())
		{
			node * current= head;
			head=get_next();	
			delete current;
			current= NULL;	
		}

		else if (head->get_repair())
		{
			node * current= head;
			head;

		} 
	} */


}

// recursive function to remove a vehicle in need of repair
int DLL::remove_vehicle(node * & head)
{
	if (! head)
		return 0;
	
	if (!head->get_previous() && head->get_repair())
	{
		node * current= head;
		current=current->get_next();	
		head= NULL;	
		delete head;
		head=current;
	//	head->set_previous(NULL);
	}

	else if(head->get_repair())
	{
		node * current=head;
		current=current->get_previous();
		current->set_next(head->get_next());

		head=NULL;
		delete head;
	
		current=current->get_next();

	//	head->connect_nodes(head, head->get_next());

		//head=head->get_next();
		//	delete current;
	}

	else
		head=head->get_next();

	remove_vehicle(head);


}

// funcrtion to remove all vehicles from list
int DLL::remove_all()
{
	return remove_all(head);

}

// recursive function to delete all
int DLL::remove_all(node * & head)
{
	if (!head)
		return 0;
	
	node * current= head;
	current=current->get_next();
	
	head=NULL;
	delete head;

	remove_all(head);

}

// function to call recursive display
void DLL::display_all() const
{
	if (head)
	{
		display_all(head);
	}	

}

// recursivly display all vehicles in list
void DLL::display_all(node * head) const
{
	if(!head)
		return;

	cout<<"  ________________________________________________"<<'\n'<<'\n';

	head->display();
	head=head->get_next();

	display_all(head);

}

//function to call the recusive function to calculate total money made
float DLL::calculate_money()
{
	return calculate_money(head);

}

// recursive function to calculate the total money made
float DLL::calculate_money(node * head)
{
	float current_cost=0;
	float total=0;

	if (!head)
		return total;

	// call function to get the cost one vehicle made
	current_cost +=head->calculate_cost();
	head=head->get_next(); // get next

	// call function again, saving the amount vehicle made
	total +=calculate_money(head) + current_cost;

}

// funtion to call recursive function to traverse until a match is found
int DLL::find_loc(char * id)
{
	return find_loc(head,  id);
}

// function to recursivly traverse until a match is found
int DLL::find_loc( node * head, char * id)
{
	if (!head)
		return 0;

	if (strcmp(head->get_id(), id) == 0)
	{
		head->display();
		return 1;
	}

	head=head->get_next();

	find_loc(head, id);

}

// function to call recursive function to count the number of vehicles currently in use
int DLL::count_inuse()
{
	return count_inuse(head);

}

//  recursive function to count the number of vehicles currently in use
int DLL::count_inuse(node *)
{
	int count=0;

	if (!head)
		return count;

	if(head->get_inuse())
		++count;

	head=head->get_next();
	count+=count_inuse(head)+count;

}
//-------------------------//
//--NODE CLASS--//


// defult constructor
node::node()
{
	base_var= NULL;

	next=NULL;
	previous=NULL;

}

// copy constructor
node::node (const node & source)
{
	base_var=source.base_var;

	next=source.next;
	previous=source.previous;
}

// destuctor
node::~node ()
{
	if(base_var)
	{
		delete base_var;
		base_var=NULL;
	}
	if(next)
	{
		delete next;
		next=NULL;
	}
	if(previous)
	{
		delete previous;
		previous=NULL;
	}
}

// function to display vehicle info
void node::display() const
{
	base_var->display();

}

// function to set the base_var pointer
int node::get_derived(int choice)
{

	if (choice == 1)
		base_var=new scooter;

	else if (choice == 2)
		base_var= new zip;

	else if (choice == 3)
		base_var= new bike;

	base_var->add();
	return 1;

}

// function to return the cost earned
float node::calculate_cost()
{
	return base_var->calculate_total_cost();

}

// function to return repair status
bool node::get_repair()
{
	return base_var->get_repair();

}

// function to  return id
char * node::get_id()
{
	return base_var->get_id();

}

// function to return use status
bool node::get_inuse()
{
	return base_var->get_inuse();

}

// function re-assign the base var
int node::set_basevar(node * source)
{
	base_var=source->base_var;
	return 1;

} 

// function to set the next to a node passes in
int node::set_next(node * new_vehicle)
{
	next= new_vehicle;
	return 1;

}

// function to set previous to a node passed in
int node:: set_previous(node * new_vehicle)
{
	previous= new_vehicle;
	return 1;

}

// function to return next pointer
node * node::get_next()
{
	return next;
}

// funcrtion to return previous pointer
node * node :: get_previous()
{
	return previous;
}

// function to connect previous pointer to a next pointer
int node::connect_nodes(node * & head, node * head_next)
{
	if (head->previous)	
		head->previous->next=head->next;

	if (head->next)
		head->next->previous=head->previous;

	if (!head->previous)
		head=head->next;

	return 1;

}

