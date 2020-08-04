#ifndef STAFF_H
#define STAFF_H
#include "people.h"

class Staff:public People
{
 protected:
	char* staff_id;
	char* staff_Rank;
	char* staff_Profession_specific;
	char* staff_Request;
	char* staff_Shift;
	int staff_Experience_in_days;
	char* staff_Psyche_evaluation;
	double	staff_Salary;
public:
	//constructors
	Staff();
	Staff(char* fname,char* lname,int A,char* g,char* ad,char* p,char* o,char* hs,char* r,char* id,char* rank,char* Profession, char* shift, char* psyche,char* requests, int experience,double salary);

	//getters
	char* getstaff_id();
	char* getstaff_rank();
	char* getstaff_Profession();
	char* getstaff_shift();
	char* getstaff_psyche();
	char* getstaff_requests();
	int getstaff_experience();
	double getstaff_salary();
	void staff_getinfo();

	//setters
	void setstaff_id(char* id);
	void setstaff_rank(char* rank);
	void setstaff_Profession(char* profession);
	void setstaff_shift(char* shift);
	void setstaff_psyche(char* psyche);
	void setstaff_requests(char* requests);
	void setstaff_experience(int experience);
	void setstaff_salary(double salary);
	void staff_setinfo(char* fname,char* lname,int A,char* g,char* ad,char* p,char* o,char* hs,char* r,char* id,char* rank,char* Profession, char* shift, char* psyche,char* requests, int experience,double salary);

};

#endif // STAFF_H
