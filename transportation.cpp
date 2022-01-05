
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

#include "DLL.h"



// defult constructor
general::general(): repair(0), total_min(0), total_cost(0), in_use(0)
{
	id=NULL;
	current_loc=NULL;

}

// copy constructor 	
general::general(const general & gen_var)
{
	repair=gen_var.repair;
	total_min= gen_var.total_min;
	total_cost=gen_var.total_cost;
	in_use=gen_var.in_use;

	id= new char[strlen(gen_var.id)+1];	
	strcpy(id, gen_var.id);
	
	current_loc= new char[strlen(gen_var.current_loc)+1];
	strcpy(current_loc, gen_var.current_loc);
}

// function to add the general vehicle info
int general::add()
{
	char choice;
	char temp[100];

	cout<<" ~ what is the ID number for this transportation vehicle? "<<'\n';
	cin.get(temp, 100, '\n');
	cin.ignore(100,'\n');

	id= new char[strlen(temp)+1];
	strcpy(id, temp);

	cout<<" ~what is the total amount of time the vehicle was used for? "<<'\n';
	cin>>total_min;
	cin.ignore(100,'\n');

	cout<<" ~where is the vehicle currently located? "<<'\n';
	cin.get(temp, 100, '\n');
	cin.ignore(100, '\n');
	
	current_loc= new char[strlen(temp)+1];
	strcpy(current_loc, temp);

	do
	{
		cout<<" ~is the vehicle in a repair shop? (Y/N)"<<'\n';
		cin>>choice;	
		cin.ignore(100, '\n');

		choice= toupper(choice);

		if (choice == 'Y')
			repair=1;

	}while (choice != 'Y' && choice!= 'N');

	do
	{

		cout<<" ~is the vehicle currently being used? (Y/N)"<<'\n';
		cin>>choice;	
		cin.ignore(100, '\n');

		choice= toupper(choice);

		if (choice == 'Y')
			in_use=1;	

	} while(choice!= 'Y' && choice!= 'N');
}

// destructor
general:: ~general()
{
	if(derived)
	{
		delete derived;
		derived=NULL;
	}
	if (id)
	{
		delete [] id;
		id=NULL;
	}

	repair =0;
	total_min=0;
	total_cost=0;

	if (current_loc)
	{
		delete [] current_loc;
		current_loc=NULL;
	}

	in_use=0;

	return;
}

// function to display a general vehicle info
void general::display() const
{

	cout<<" ID:	"<<id<<'\n'
		<<" TOTAL TIME RIDDEN TODAY:	"<<total_min<<'\n'
		<<" TOTAL MONEY EARNED FROM IT TODAY;	"<<total_cost<<'\n'
		<<" CURRENT LOCATION:	"<<current_loc<<'\n'<<'\n';	

	if (repair)
		cout<<"IN THE SHOP"<<endl;
	if (in_use)
		cout<<"CURRENTLY IN USE"<<endl;		
}

//---------------------------//
//--SCOOTER CLASS--

// defult constructor
scooter::scooter(): general(), cost_per_min(0.05), battery_level (0)
{

}

//display all scooter into
void scooter::display() const
{
	cout<<"		~SCOOTER~		"<<'\n';
	general::display();
	cout<<"COST PER MINUTE FOR A SCOOTER :	$"<<cost_per_min<<'\n'
		<<"CURRENT BATTERY LEVEL:	"<<battery_level<<'\n'<<'\n';

}

//add information on a scooter
int scooter::add()
{
	general::add();

	cout<<" ~what is the current battery level?"<<endl;
	cin>>battery_level;
	cin.ignore(100,'\n');

	calculate_total_cost();
}

//calculate total cost for the scooter
float scooter::calculate_total_cost()
{
	float total;

	total_cost=total_min*cost_per_min;

	cout<<"TOTAL COST  :  "<<total_cost<<endl;

	return total_cost;

}

// function to return the status of repair
bool scooter::get_repair()
{
	return repair;

}

// function to return the id
char * scooter::get_id()
{
	return id;
}

// function to return the use status
bool scooter::get_inuse()
{
	return in_use;

}


//-----------------------------//
//--ZIP CLASS--//

//defult constructor
zip::zip():general(), cost_per_min(1.0), gas_level(0), license(0)
{

}

// copy constructor
zip::zip(const zip & source): general(source) //copy constuctor
{
	cost_per_min=source.cost_per_min;
	gas_level=source.gas_level;
	
	license=source.license;

}

// destructor
zip::~zip() 
{
	cost_per_min=0;
	gas_level=0;
	
	if(license)
	{
		delete [] license;
		license=NULL;
	}
	
	return;
}

// function to display 
void zip::display() const
{
	cout<<"		~ZIP CAR~		"<<'\n';
	general::display();
	cout<<"COST PER MINUTE FOR A ZIP CAR :	$"<<cost_per_min<<'\n'
		<<"CURRENT GAS LEVEL:	"<<gas_level<<'\n'
		<<"ZIP CARS LICENSE NUMBER:  "<<license<<'\n'<<'\n';

}

// function to add a zip car
int zip::add()
{
	char temp[100];


	general::add();

	cout<<" ~what is the current gas level?"<<endl;
	cin>>gas_level;
	cin.ignore(100,'\n');

	cout<<" ~what is the cars license number?"<<endl;
	cin.get(temp, 100, '\n');
	cin.ignore(100, '\n');

	license= new char[strlen(temp)+1];
	strcpy(license, temp);

}

// function to calculate the money earned
float zip::calculate_total_cost()
{
	float total;

	total_cost=total_min*cost_per_min;

	cout<<"TOTAL COST  :  "<<total_cost<<endl;

	return total_cost;

}

// function to return repair status
bool zip::get_repair()
{
	return repair;

}

//function to return id
char * zip::get_id()
{
	return id;
}

// function to return use status
bool zip::get_inuse()
{
	return in_use;

}

//-------------------------//
//--BIKE CLASS--//

// defult constructor
bike::bike():cost_per_min(0.50)
{

}

// display function
void bike::display() const
{
	cout<<"		~BIKE~		"<<'\n';
	general::display();
	cout<<"COST PER MINUTE FOR A BIKE :	$"<<cost_per_min<<'\n'<<'\n';

}

// function to add a bike
int bike::add()
{
	general::add();

}

// function to calculate the money earned
float bike::calculate_total_cost()
{
	float total;

	total_cost=total_min*cost_per_min;

	cout<<"TOTAL COST  :  "<<total_cost<<endl;

	return total_cost;

}

// function to return the repair status
bool bike::get_repair()
{
	return repair;

}

// function to repair the id
char * bike::get_id()
{
	return id;
}

// function the repair use status
bool bike::get_inuse()
{
	return in_use;

}
