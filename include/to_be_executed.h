#ifndef TO_BE_EXECUTED_H
#define TO_BE_EXECUTED_H

#include "maximum_security_prisoner.h"


class To_be_Executed : public Maximum_security_prisoner
{
  protected:
	struct Execution
	{
		char* last_meal;
		char* execution_date;
	}prisoner_Execution;
public:
	//constructors
	To_be_Executed();
	To_be_Executed(char* fname,char* lname,int A,char* g,char* ad,char* p,char* o,char* hs,char* r,char* id,char* Crime,char* Sentence,char* Location_of_cell,char* Admission_date,char* Release_date,char* Guard_statement,char* Staff_statement,int solitary_confinement_visits,char* Overall_evaluation,char* Visitor_Info,char* General_request,char* Psychological_status,char* Job_status,char* Jailmate,char* Lawyer,char* Evidence_info,char* Conviction_date,int Bail_amount,char* Appeal_for_release_status,char* Utility_status,char* prescription,char* Visiting_status,char* last_meal,char* execution_date);

	//getters
	void To_be_Executed_getinfo();
	char* get_to_be_executed_last_meal();
	char* get_to_be_executed_execution_date();
};

#endif // TO_BE_EXECUTED_H
