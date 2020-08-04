#include "staff.h"

#include<iostream>

Staff::Staff()
{

}

Staff::Staff(char* fname,char* lname,int A,char* g,char* ad,char* p,char* o,char* hs,char* r,char* id,char* rank,char* Profession, char* shift, char* psyche,char* requests, int experience,double salary):staff_id(id),staff_Rank(rank),staff_Profession_specific(Profession),staff_Psyche_evaluation(psyche),staff_Shift(shift),staff_Experience_in_days(experience),staff_Salary(salary),staff_Request(requests),People(fname, lname, A, g, ad, p, o, hs, r)
{

}

//Staff Getters

char* Staff::getstaff_id()
{
	return staff_id;
}
char* Staff::getstaff_rank()
{
	return staff_Rank;
}
char* Staff::getstaff_Profession()
{
	return staff_Profession_specific;
}
char* Staff::getstaff_shift()
{
	return staff_Shift;
}
char* Staff::getstaff_psyche()
{
	return staff_Psyche_evaluation;
}
char* Staff::getstaff_requests()
{
	return staff_Request;
}
int Staff::getstaff_experience()
{
	return staff_Experience_in_days;
}
double Staff::getstaff_salary()
{
	return staff_Salary;
}
void Staff::staff_getinfo()
{
	People::people_getInfo();
	std::cout<<"\nStaff ID: "<<getstaff_id()<<"\nProfession: "<<getstaff_Profession()<<"\nRank: "<<getstaff_rank()<<"Experience at work: "<<getstaff_experience()<<" days\nShift: "<<getstaff_shift()<<"\nPsyche Evaluation: "<<getstaff_psyche()<<"\nSalary: "<<getstaff_salary()<<std::endl;
}


//Staff setters

void Staff::setstaff_id(char* id)
{
	staff_id = id;
}
void Staff::setstaff_rank(char* rank)
{
	staff_Rank = rank;
}
void Staff::setstaff_Profession(char* Profession)
{
	staff_Profession_specific = Profession;
}
void Staff::setstaff_shift(char* shift)
{
	staff_Shift = shift;
}
void Staff::setstaff_psyche(char* psyche)
{
	staff_Psyche_evaluation = psyche;
}
void Staff::setstaff_requests(char* requests)
{
	staff_Request = requests;
}
void Staff::setstaff_experience(int experience)
{
	staff_Experience_in_days = experience;
}
void Staff::setstaff_salary(double salary)
{
	staff_Salary = salary;
}
void Staff::staff_setinfo(char* fname,char* lname,int A,char* g,char* ad,char* p,char* o,char* hs,char* r,char* id,char* rank,char* Profession, char* shift, char* psyche,char* requests, int experience,double salary)
{
	People::people_setinfo(fname,lname,A,g,ad,p,o,hs,r);
	setstaff_id(id);
	setstaff_rank( rank);
	setstaff_Profession( Profession);
	setstaff_shift( shift);
	setstaff_psyche( psyche);
	setstaff_requests( requests);
	setstaff_experience( experience);
	setstaff_salary( salary);
}

