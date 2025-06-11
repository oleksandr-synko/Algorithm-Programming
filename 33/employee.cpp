#include "employee.h"
#include <iostream>
using namespace std;

Employee::Employee()
{
	lastname="Ivanov";
	department="Buhalter";
	hireyear=2000;
	salary=15000;
	bonus=0;	
}
Employee::Employee(string ln,string dp,int hy,double sal)
{
	lastname=ln;
	department=dp;
	hireyear=hy;
	salary=sal;
	bonus=0;
}

		string Employee::getlastname() const
		{
		return lastname;
		}
		string Employee::getdepartment() const
		{
			return department;
		}
		int Employee::gethireyear() const
		{
			return hireyear;
		}
		double Employee::getsalary() const
		{
			return salary;
		}
		double Employee::getbonus() const
		{
			return bonus;
		}
		int Employee::getexp(int currentyear) const
		{
			return currentyear-hireyear;
		}
		
		
		void Employee::setlastname(string ln)
		{
			lastname=ln;
		}
		void Employee::setdepartment(string dp)
		{
			department=dp;
		}
		void Employee::sethireyear(int hy)
		{
			hireyear=hy;
		}
		void Employee::setsalary(double sal)
		{
			salary=sal;
		}
		void Employee::calculatebonus(int currentyear)
		{
			int exp=getexp(currentyear);
			if(exp<10)
			bonus=salary*0.1;
			else if(exp<=25)
			bonus=salary*0.25;
			else
			bonus=salary*0.4;
		}
		void Employee::printinfo(int currentyear) const
		{
		cout<< "Lastname: " << lastname<< ", Department: " << department<< ", Hire Year: " << hireyear
        << ", Stazh: " << getexp(currentyear)<< ", Salary: " << salary<< ", Bonus: " << bonus << endl;
		}
		
		double avg(Employee* employee,int size,int currentyear)
		{
			int total=0;
			for(int i=0;i<size;i++)
			{
				total+=employee[i].getexp(currentyear);
			}
			return (double)total/size;
		}
		
		void sortexp(Employee* employee,int size,int currentyear)
		{
			for(int i=0;i<size-1;i++)
			{
				for(int j=i+1;j<size;j++)
				{
					if(employee[i].getexp(currentyear)>employee[j].getexp(currentyear))
					swap(employee[i],employee[j]);
				}
			}
		}

		void analyzdepartment(Employee* employee,int size)
		{
			string departments[100];
			int counts[100]={0};
			double salaries[100]={0};
			int uniquecount=0;
			
			for(int i=0;i<size;i++)
			{
				string dep=employee[i].getdepartment();
				bool found=false;
			
				for(int j=0;j<uniquecount;j++)
				{
					if(departments[j]==dep)
					{
						counts[j]++;
						salaries[j]+=employee[i].getsalary();
						found=true;
						break;
					}
				}
				if(!found)
				{
					departments[uniquecount]=dep;
					counts[uniquecount]=1;
					salaries[uniquecount]=employee[i].getsalary();
					uniquecount++;
				}
			}
			for(int i=0;i<uniquecount;i++)
			{
				cout<<"Department "<<departments[i]<<", employeers "<<counts[i]<<", total salaries "<<salaries[i]<<endl;
			}
		}
		
	Vacation::Vacation() 
	{
    startday=1;
    startmonth=7;
    startyear=2021;
    duration=0;
    endday=0;
    endmonth=0;
    endyear=0;
    
}

Vacation::Vacation(Employee emp, int currentyear) 
{
    employee=emp;
    startday=1;
    startmonth=7;
    startyear=2021;
    calculateduration(currentyear);
    calculateenddate();
}


void Vacation::calculateduration(int currentyear) 
{
    int exp=employee.getexp(currentyear);
    double sal=employee.getsalary();
    if (exp<10&&sal<12000)
        duration=14;
    else if (exp>25&&sal>25000)
        duration=28;
    else
        duration=21;
}

    void Vacation::calculateenddate() 
	{
    if(duration==14)
    {
	endday=15;
    endmonth=7;
    endyear=2021;
	}
	else if(duration==21)
    {
    endday=22;
    endmonth=7;
    endyear=2021;
	}
	else
    {
	endday=29;
    endmonth=7;
    endyear=2021;
    }
	}

	void Vacation::printvacationinfo() const 
	{
		int totalday=duration;
		int years=totalday/365;
		totalday%=365;
		int month=totalday/30;
		int days=totalday%30;	
			
			
        cout<<"Employee: "<<employee.getlastname()<<", Department: "<<employee.getdepartment()<<endl;
        cout<<"Vacation starts: "<<startday<<"."<<startmonth<<"."<<startyear<<
		", Duration: "<<duration<<" days, Ends: "<<endday<<"."<<endmonth<<"."<<endyear<<endl;
    }
