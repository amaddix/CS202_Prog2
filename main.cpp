//Ashley Maddix
// CS 202, Fall Q2018, Prog2

//*~main~
//add menu

//~transportation~
//--general
//--scooter
//--zipcar
//--bike

//~DLL~
//--DLL
//--node


#include "DLL.h"

int add_menu(DLL & list);


int main()
{
	int choice;
	int being_used;
	char id_temp[100];
	float total;
	DLL list;

	cout<<"Please add a vehicle to your list?"<<'\n';

		add_menu(list);

		do
		{
			cout<<"	~Please choose an option~	"<<endl
			<<" 1.	add a vehicle to list of our rental vehicles"<<endl
			<<" 2.	find total money made through all rental vehicles"<<endl
			<<" 3.	display list of all rental vehicles"<<endl
			<<" 4.	take vehicles in need of repair to the shop"<<endl
			<<" 5.	check how many vehicles are currently in use"<<endl
			<<" 6.	check the current location of a vehicle based in their id #"<<endl
			<<" 7.	end program"<<'\n'<<'\n'<<endl;
			
			cin>>choice;
			cin.ignore(100, '\n');
			

			if (choice == 1)
				add_menu(list);
		
			if (choice == 2)
			{
				total=list.calculate_money();
				cout<<"HOW MUCH WE'VE MADE   "<<total<<endl;
			}

			if (choice == 3)
				list.display_all();
			
			if (choice == 4)
				list.remove_vehicle();

			if (choice == 5)
			{
				being_used=list.count_inuse();
				cout<<" The number of cars currently being used is :  "<<being_used<<endl;
			}
		
		
			if (choice == 6)
			{
				cout<<"	what is the id you're looking for?  "<<endl;
				cin.get(id_temp, 100, '\n');
				cin.ignore(100, '\n');
				
				if(!list.find_loc(id_temp))
					cout<<"no matching id numbers"<<endl;
			}
	
		}while( choice < 7);

		cout<<"TESTING CODE   :   "<<endl;
		DLL temp;
		temp=list;
		
		temp.display_all();

	return 0;
}

int add_menu(DLL & list)
{
	char action;
	int choice;
	
	do
	{
		cout<<"what kinda rental vehical is this?"<<endl;		
			
		cout<<" 1.	scooter"<<'\n'
		<<" 2.	zip car"<<'\n'
		<<"3.	bike"<<'\n';

		cin>>choice;
		cin.ignore(100,'\n');

		list.add(choice);

		cout<<"Would you like to add another vehicle to your list? (Y/N)"<<'\n';
		cin>>action;
		cin.ignore(100, '\n');
		action= toupper(action);

	}while(action == 'Y');
	

}
