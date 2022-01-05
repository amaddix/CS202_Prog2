
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
#include "transportation.h"
class node;

class DLL
{

	public:
		DLL(); //default constructor
		DLL (const DLL & source); // copy constuctor for DLL
		~DLL(); // DLL destructor

		int dll_cc(node * &, node * ); // function to recursivly copy a DLL
		int add(int choice); // function to add a vehicle
		int remove_vehicle(); // function to add remove a vehicle that needs to be repair
		int remove_vehicle(node * &); // recursivly remove any vehicles to be repaired
		int remove_all(); // function to remove all vehicles in a list
		int remove_all(node * &); //recursivly to delete all vehicles in list
		void display_all() const; // function to display all vehicles in list
		void display_all(class node *)const; // recursivly display all 
		float calculate_money(); // function to calculate the money made
		float calculate_money(node *); // function recursivly calculate all money made
		int find_loc(char * id); // function to display tbhe info found mathcing an id passed in
		int find_loc( node * , char * id); //recursivly traverse until we find an id match
		int count_inuse(); // function to count how many vehicles are in use
		int count_inuse(node *); // recusivly traverse and count vehicle sin use

	private:
		class node * head; // head pointer to a list of vehicles


};

// class to hold a vehicle and a pointer to another node
class node
{
	public:
		node(); // default destructor
		node (const node & source); // node copy constructor
		~node (); // node destructor

		void display() const; // function to display a node

		int get_derived(int); // function to set the vehicle type
		float calculate_cost(); // function to calculate cost a vehicle made
		bool get_repair(); // function to return repair status
		char * get_id(); // function to return the id
		bool get_inuse(); // function to repair the use status
		int set_next(node * ); // function to set next node
		int set_previous(node *); // function to set the previous node
		int set_basevar(node * source);
		node * get_next(); // function to return the next
		node * get_previous(); // function to return the previous
		int connect_nodes(node * & head, node * head_next); 
		// function to connect a previous and a next around a node sent in
		

	private:
		general * base_var; // a pointer to a derived vehicle

		node * next; // pointer to a next pointer
		node * previous; // pointer to e precious pointer
	
};

