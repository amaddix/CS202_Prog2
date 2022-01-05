
//Ashley Maddix
// CS 202, Fall Q2018, Prog2

//~main~
//add menu

//*~transportation~
//--general
//--scooter
//--zipcar
//--bike

//~DLL~
//--DLL
//--node


#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>
#include <cstdlib>

using namespace std;

// a class for the general attributes of a rental vehicle (our abstract base class)
class general
{
	public:
		general(); //constructor
		general(const general & gen_var); // copy constructor

	
		virtual ~general(); //virtual destructor
		virtual void display() const; //virtual display function
		virtual int add(); //virtual add information
		virtual float calculate_total_cost()=0; // virtual function to calculate the total cost
		virtual bool get_repair()=0; // virtual function to get the repair status
		virtual char * get_id()=0; // virtual function to get the is of a vehicle
		virtual bool get_inuse()=0; // virtual function to get the current use status
		
	
	protected:	
	
		general * derived;  // pointer to a derived class
		char * id; // for the id # of item
		bool repair; // to tell whether item is in need of repair
		int total_min; // how many total min item was used
		float total_cost; // how much money was earned from item
		char * current_loc; //where the item is currently located
		bool in_use; // to tell whether item is currently being used
	
		

};

//class for one type of rental vehicle, a scooter
class scooter: public general
{
	public:
		scooter(); // constructor

		void display()const; // function to display info on a scooter
		int add(); // function to add information about a scooter
		float calculate_total_cost(); // function to calculate how much was earned on 
			// this scooter
		bool get_repair(); //function to get repair status
		char * get_id(); //function to return the id 
		bool get_inuse(); //function to return the use status
		
	protected:
		float cost_per_min;// how much it costs to rent a scooter per min
		int battery_level; // how much battery life is left 

};

//class for one type of rental vehicle, a zip car
class zip: public general
{
	public:
		zip(); //constructor
		zip(const zip & source); //copy constuctor
		~zip(); // destructor

		void display() const; // function to display data
		int add(); // function to add information
		float calculate_total_cost(); // function to calculate the total cost
		bool get_repair(); // function to return the repair status
		char * get_id(); // function to return the id status
		bool get_inuse(); // function to return the status of use 

	protected:
		float cost_per_min; // cost of zip car per min
		int gas_level; // gas level
		char * license; // license number

};

//class for one type of rental vehicle, a bike
class bike: public general
{
	public:
		bike(); // constructor
		void display() const;// function to display 
		int add(); // function to add a bike 
		float calculate_total_cost(); // function to calculate the amount of money a bike made
		bool get_repair(); // function to return repair status
		char * get_id(); // function to get id 
		bool get_inuse(); // function to get use status

	protected:
		float cost_per_min; //var for cost per min

};
