#include<iostream>
using namespace std;
char stop;
int amount=0,count=0,r=0,c=0,b=0,m=0,rikshaw=0,car=0,motor_bike=0,bus=0,choice=0;
//display
void display(){
	cout<<"\n\n\n\n\t\t\t\t\tPARKING MANAGEMENT SYSTEM\n\n\n\n\n\n";
}
void price(){

cout<<"\t\tEnter the rate of rikshaw = ";
cin>>rikshaw;
cout<<"\t\tEnter the rate of car = ";
cin>>car;
cout<<"\t\tEnter the rate of bike = ";
cin>>motor_bike;
cout<<"\t\tEnter the rate of bus = ";
cin>>bus;
}
//interface
void interface(){
		while(true){
	cout<<"\t\t----------------------------------\n";
	cout<<"\t\tEnter 1 for rikshaw\n";
	cout<<"\t\tEnter 2 for car\n";
	cout<<"\t\tEnter 3 for bus\n";
	cout<<"\t\tEnter 4 for bike\n";
	cout<<"\t\tEnter 5 to see total\n";
	cout<<"\t\tEnter 6 to delete records \n";
	cin>>choice;
	cout<<"\t\t----------------------------------\n";
	//
	if(choice==1){
		r++;
		count++;
		amount+=rikshaw;
	}
	else if(choice==2){

		c++;
		count++;
		amount+=car;
	}
	else if(choice==3){
		b++;
		count++;
		amount+=bus;
	}
	else if(choice==4){
		m++;
		count++;
		amount+=motor_bike;
	}

	else if(choice==5){
		cout<<"\t\t----------------------------------\n";
		cout<<"\n\n\t\tTotal ammount = "<<amount<<endl;
		cout<<"\t\tTotal vehicals = "<<count<<endl;
		cout<<"\t\tNumber of rikshaws = "<<r<<endl;
		cout<<"\t\tNumber of car = "<<c<<endl;
		cout<<"\t\tNumber of bus = "<<b<<endl;
		cout<<"\t\tNumber of motor bikes = "<<m<<"\n\n\n";
	//	cout<<"\t\t----------------------------------\n";
	}
		else if(choice==6){
		amount=0;
		r=0;
		c=0;
		b=0;
		m=0;
		count=0;
		cout<<"\n\n\n\t\t\t-----RECORD DELETED-----\n\n\n\n";
		cout<<"\t\t----------------------------------\n";
		system("cls");
		display();
		}
		cout<<"you want to enter more records?---y\\n--- \n";
		cin>>stop;
		if(stop=='n'||stop=='N'){
		cout<<"----------------------------------\n";
		cout<<"\n\n---Total ammount = "<<amount<<endl;
		cout<<"---Total vehicals = "<<count<<endl;
		cout<<"---Number of rikshaws = "<<r<<endl;
		cout<<"---Number of car = "<<c<<endl;
		cout<<"---Number of bus = "<<b<<endl;
		cout<<"---Number of motor bikes = "<<m<<"\n\n\n";
		cout<<"----------------------------------\n";
		
		break;
		}
}
}
int main()
{

	
display();
price();

interface();

	return 0;
}

