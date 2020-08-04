#ifndef MINIMUM_SECURITY_PRISONER_H
#define MINIMUM_SECURITY_PRISONER_H

#include"prisoner.h"


class Minimum_security_prisoner : public Prisoner
{
    public:
	//static char Location_of_cell[];

	Minimum_security_prisoner();
	Minimum_security_prisoner(char* fname,char* lname,int A,char* g,char* ad,char* p,char* o,char* hs,char* r,char* id,char* Crime,char* Sentence,char* Location_of_cell,char* Admission_date,char* Release_date,char* Guard_statement,char* Staff_statement,int solitary_confinement_visits,char* Overall_evaluation,char* Visitor_Info,char* General_request,char* Psychological_status,char* Job_status,char* Jailmate,char* Lawyer,char* Evidence_info,char* Conviction_date,int Bail_amount,char* Appeal_for_release_status,char* Utility_status,char* prescription,char* Visiting_status);

};

#endif // MINIMUM_SECURITY_PRISONER_H
