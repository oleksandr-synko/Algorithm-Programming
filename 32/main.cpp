#include "employee1.h"
#include "employee1.cpp"
#include <iostream>
using namespace std;
int main()
{
	int currentyear=2025;
	int n,i;
	cout<<"Skiki potribno dodatu pracivnukiv ";
	cin>>n;
	Employee* employee=new Employee[n+2];
	employee[0]=Employee("Ivanov","Buhalter",2000,15000);
	employee[0].calculatebonus(currentyear);
	employee[1]=Employee("Petrov","Yurist",2010,25000);
	employee[1].calculatebonus(currentyear);
	
	for(int i=0;i<n;i++)
	{
		string name,dep;
		int year;
		double sal;
		cout<<"Employeer "<<i+1<<endl;
		cout<<"Lastname "<<endl;
		cin>>name;
		cout<<"Viddil "<<endl;
		cin>>dep;
		cout<<"Year "<<endl;
		cin>>year;
		cout<<"Salary "<<endl;
		cin>>sal;
		
		employee[i+2]=Employee(name,dep,year,sal);
		employee[i+2].calculatebonus(currentyear);
	}
	
	cout<<"All employeers "<<endl;
	for(i=0;i<n+2;i++)
	{
		employee[i].printinfo(currentyear);
	}
	double avgg=avg(employee,n+2,currentyear);
	cout<<"Seredna stazh job "<<avgg<<endl;
	cout<<"Sort za dosvidom "<<endl;
	sortexp(employee,n+2,currentyear);
	for(i=0;i<n+2;i++)
	{
		employee[i].printinfo(currentyear);
	}
	delete[]employee;
	return 0;
}
