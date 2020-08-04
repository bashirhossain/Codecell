#include "guards.h"

#include<iostream>
Guards::Guards()
{

}
Guards::Guards(char* fname,char* lname,int A,char* g,char* ad,char* p,char* o,char* hs,char* r,	char* id, char* unit,char* rank,char* shift,char* post,char* ammunition_status,char* psyche_evaluation,double salary,int experience):guard_id(id),guard_rank(rank),guard_post(post),guard_unit(unit),guard_shift(shift),guard_salary(salary),guard_psyche_evaluation(psyche_evaluation),guard_ammunition_status(ammunition_status),guard_experience(experience),People(fname, lname, A, g, ad, p, o, hs, r)
{

}

//getters
char* Guards::guard_getid()
{
	return guard_id;
}
char* Guards::guard_getunit()
{
	return guard_unit;
}
char* Guards::guard_getrank()
{
	return guard_rank;
}
char* Guards::guard_getshift()
{
	return guard_shift;
}
char* Guards::guard_getpost()
{
	return guard_post;
}
char* Guards::guard_getammunition_status()
{
	return guard_ammunition_status;
}
char* Guards::guard_getpsyche_evaluation()
{
	return guard_psyche_evaluation;
}
double Guards::guard_getsalary()
{
	return guard_salary;
}
int Guards::guard_getexperience()
{
	return guard_experience;
}
void Guards::guard_getinfo()
{
	People::people_getInfo();
	std::cout<<"Guard ID: "<<guard_getid()<<"\nBelongs to: "<<guard_getunit()<<" Unit\nRank: "<<guard_getrank()<<"\nShift: "<<guard_getshift()<<"\nPost: "<<guard_getpost()<<"\nAmmunition: "<<guard_getammunition_status()<<"\nPsyche Evaluation: "<<guard_getpsyche_evaluation()<<"\nSalary: "<<guard_getsalary()<<"\nExperience here: "<<guard_getexperience()<<" days"<<std::endl;
}


//setters
void Guards::guard_setid(char* id)
{
	guard_id = id;
}
void Guards::guard_setunit(char* unit)
{
	guard_unit = unit;
}
void Guards::guard_setrank(char* rank)
{
	guard_rank = rank;
}
void Guards::guard_setshift(char* shift)
{
	guard_shift = shift;
}
void Guards::guard_setpost(char* post)
{
	guard_post = post;
}
void Guards::guard_setammunition_status(char* ammunition_status)
{
	guard_ammunition_status = ammunition_status;
}
void Guards::guard_setpsyche_evaluation(char* psyche_evaluation)
{
	guard_psyche_evaluation = psyche_evaluation;
}
void Guards::guard_setsalary(double salary)
{
	guard_salary = salary;
}

void Guards::guard_setexperience(int experience)
{
	guard_experience = experience;
}

void Guards::guards_setinfo(char* fname,char* lname,int A,char* g,char* ad,char* p,char* o,char* hs,char* r,	char* id, char* unit,char* rank,char* shift,char* post,char* ammunition_status,char* psyche_evaluation,double salary,int experience)
{
	People::people_setinfo(fname,lname,A,g,ad,p,o,hs,r);
	guard_setid( id);
	guard_setunit(unit);
	guard_setrank(rank);
	guard_setshift(shift);
	guard_setpost(post);
	guard_setammunition_status(ammunition_status);
	guard_setpsyche_evaluation(psyche_evaluation);
	guard_setsalary(salary);
	guard_setexperience(experience);
}
