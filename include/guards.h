#ifndef GUARDS_H
#define GUARDS_H
#include"people.h"


class Guards:public People
{
  protected:
	char* guard_id;
	char* guard_unit;
	char* guard_rank;
	char* guard_shift;
	char* guard_post;
	char* guard_ammunition_status;
	char* guard_psyche_evaluation;
	double guard_salary;
	int guard_experience;
public:
	//constructors
	Guards();
	Guards(char* fname,char* lname,int A,char* g,char* ad,char* p,char* o,char* hs,char* r,	char* id, char* unit,char* rank,char* shift,char* post,char* ammunition_status,char* psyche_evaluation,double salary,int experience);

	//getters
	char* guard_getid();
	char* guard_getunit();
	char* guard_getrank();
	char* guard_getshift();
	char* guard_getpost();
	char* guard_getammunition_status();
	char* guard_getpsyche_evaluation();
	double guard_getsalary();
	int guard_getexperience();
	void guard_getinfo();

	//setters
	void guard_setid(char* id);
	void guard_setunit(char* unit);
	void guard_setrank(char* rank);
	void guard_setshift(char* shift);
	void guard_setpost(char* post);
	void guard_setammunition_status(char* ammunition_status);
	void guard_setpsyche_evaluation(char* psyche_evaluation);
	void guard_setsalary(double salary);
	void guard_setexperience(int experience);
	void guards_setinfo(char* fname,char* lname,int A,char* g,char* ad,char* p,char* o,char* hs,char* r,	char* id, char* unit,char* rank,char* shift,char* post,char* ammunition_status,char* psyche_evaluation,double salary,int experience);
};

#endif // GUARDS_H
