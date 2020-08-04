#include "to_be_executed.h"
#include<iostream>
To_be_Executed::To_be_Executed()
{

}
To_be_Executed::To_be_Executed(char* fname,char* lname,int A,char* g,char* ad,char* p,char* o,char* hs,char* r,char* id,char* Crime,char* Sentence,char* Location_of_cell,char* Admission_date,char* Release_date,char* Guard_statement,char* Staff_statement,int solitary_confinement_visits,char* Overall_evaluation,char* Visitor_Info,char* General_request,char* Psychological_status,char* Job_status,char* Jailmate,char* Lawyer,char* Evidence_info,char* Conviction_date,int Bail_amount,char* Appeal_for_release_status,char* Utility_status,char* prescription,char* Visiting_status,char* last_meal,char* execution_date):Maximum_security_prisoner(fname,lname,A,g,ad,p,o,hs,r,id,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status)
{
	prisoner_Execution.last_meal = last_meal;
	prisoner_Execution.execution_date = execution_date;
}

//getters

void To_be_Executed::To_be_Executed_getinfo()
{
	Maximum_security_prisoner::get_prisoner_info();
	std::cout<<"\nExecution Info:\n\tExecution date: "<<prisoner_Execution.execution_date<<"\n\tLast meal: "<<prisoner_Execution.last_meal<<"\n";
}

char* To_be_Executed::get_to_be_executed_last_meal()
{
	return prisoner_Execution.last_meal;
}
char* To_be_Executed::get_to_be_executed_execution_date()
{
	return prisoner_Execution.execution_date;
}
