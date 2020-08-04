
#include "people.h"
#include"prisoner.h"
#include<iostream>
Prisoner::Prisoner()
{}
Prisoner::Prisoner(char* fname,char* lname,int A,char* g,char* ad,char* p,char* o,char* hs,char* r,char* id,char* Crime,char* Sentence,char* Location_of_cell,char* Admission_date,char* Release_date,char* Guard_statement,char* Staff_statement,int solitary_confinement_visits,char* Overall_evaluation,char* Visitor_Info,char* General_request,char* Psychological_status,char* Job_status,char* Jailmate,char* Lawyer,char* Evidence_info,char* Conviction_date,int Bail_amount,char* Appeal_for_release_status,char* Utility_status,char* prescription,char* Visiting_status):prisoner_id( id),prisoner_Crime( Crime),prisoner_Sentence( Sentence),prisoner_Location_of_cell( Location_of_cell),prisoner_Admission_date( Admission_date),prisoner_Release_date( Release_date),prisoner_General_request( General_request),prisoner_Psychological_status( Psychological_status),prisoner_Job_status( Job_status),prisoner_Jailmate( Jailmate),prisoner_Utility_status( Utility_status),prisoner_prescription( prescription),prisoner_Visiting_status( Visiting_status),People(fname, lname, A, g,ad,p,o, hs, r)
{
	prisoner_Conduct.Guard_statement = Guard_statement;
	prisoner_Conduct.Staff_statement = Staff_statement;
	prisoner_Conduct.solitary_confinement_visits = solitary_confinement_visits;
	prisoner_Conduct.Overall_evaluation = Overall_evaluation;
	prisoner_Conduct.Visitor_Info =  Visitor_Info;
	//prisoner_Execution.last_meal = last_meal;
	//prisoner_Execution.execution_date = execution_date;

	prisoner_Trial_info.Lawyer = Lawyer;
	prisoner_Trial_info.Evidence_info = Evidence_info;
	prisoner_Trial_info.Conviction_date = Conviction_date;
	prisoner_Trial_info.Bail_amount = Bail_amount;
	prisoner_Trial_info.Appeal_for_release_status = Appeal_for_release_status;
}
// Getters
char* Prisoner::get_prisoner_ID()
{
	return prisoner_id;
}
char* Prisoner::get_prisoner_crime()
{
	return prisoner_Crime;
}
char* Prisoner::get_prisoner_admission_date()
{
	return prisoner_Admission_date;
}
char* Prisoner::get_prisoner_release_date()
{
	return prisoner_Release_date;
}
char* Prisoner::get_prisoner_Psychological_status()
{
	return prisoner_Psychological_status;
}
char* Prisoner::get_prisoner_Job_status()
{
	return prisoner_Job_status;
}
char* Prisoner::get_prisoner_jailmate()
{
	return prisoner_Jailmate;
}
char* Prisoner::get_prisoner_utility_status()
{
	return prisoner_Utility_status;
}
char* Prisoner::get_prisoner_visiting_status()
{
	return prisoner_Visiting_status;
}
char* Prisoner::get_prisoner_sentence()
{
	return prisoner_Sentence;
}
char* Prisoner::get_prisoner_cell_location()
{
	return prisoner_Location_of_cell;
}
char* Prisoner::Prisoner::get_prisoner_conduct_guard_statement()
{
	return prisoner_Conduct.Guard_statement;
}
char* Prisoner::get_prisoner_conduct_staff_statement()
{
	return prisoner_Conduct.Staff_statement;
}
int Prisoner::get_prisoner_conduct_solitary_visits()
{
	return prisoner_Conduct.solitary_confinement_visits;
}
char* Prisoner::get_prisoner_conduct_overall()
{
	return prisoner_Conduct.Overall_evaluation;
}
char* Prisoner::get_prisoner_conduct_visitor_info()
{
	return prisoner_Conduct.Visitor_Info;
}
/*char* Prisoner::get_prisoner_execution_date()
{
	return prisoner_Execution.execution_date;
}
char* Prisoner::get_prisoner_execution_last_meal()
{
	return prisoner_Execution.last_meal;
}*/
char* Prisoner::get_prisoner_greq()
{
	return prisoner_General_request;
}
char* Prisoner::get_prisoner_trial_lawyer()
{
	return prisoner_Trial_info.Lawyer;
}
char* Prisoner::get_prisoner_trial_conviction()
{
	return prisoner_Trial_info.Conviction_date;
}
char* Prisoner::get_prisoner_trial_evi_info()
{
	return prisoner_Trial_info.Evidence_info;
}
int Prisoner::get_prisoner_trial_bail()
{
	return prisoner_Trial_info.Bail_amount;
}
char* Prisoner::get_prisoner_trial_release_appeal()
{
	return prisoner_Trial_info.Appeal_for_release_status;
}
char* Prisoner::get_prisoner_prescription()
{
	return prisoner_prescription;
}
void Prisoner::get_prisoner_info()
{
	People::people_getInfo();
	std::cout<<"Prisoner ID: "<<get_prisoner_ID()<<"\nCommitted offense: "<<get_prisoner_crime()<<"\nAdmitted to the Correction Facility: "<<get_prisoner_admission_date()<<"\nTo be released on: "<< get_prisoner_release_date()<<"\nPsychological status: "<< get_prisoner_Psychological_status()<<"\nCorrectional service: "<<get_prisoner_Job_status()<<
	"\nCellmate: "<<get_prisoner_jailmate()<<
	"\nUtility status: "<<get_prisoner_utility_status()<<
	"\nVisiting Status: "<<get_prisoner_visiting_status()<<
	"\nSentenced to: "<<get_prisoner_sentence()<<
	"\nCell location: "<<get_prisoner_cell_location()<<
	"\nPrisoner's conduct while in custody:\n\tGuards statement:\n\t\t "<<get_prisoner_conduct_guard_statement()<<
	"\n\tStaff Statement:\n\t\t"<<get_prisoner_conduct_staff_statement()<<
	"\n\tNo. of Solitary Confinement visits: "<<get_prisoner_conduct_solitary_visits()<<
	"\n\tOverall Evaluation:\n\t\t"<<get_prisoner_conduct_overall()<<
	"\n\tVisitor Info:\n\t\t"<<get_prisoner_conduct_visitor_info()<<
	/*"\nExecution Information:\n\tExecution date: "<<get_prisoner_execution_date()<<
	"\n\tLast Meal: "<<get_prisoner_execution_last_meal()<<*/
	"\nGeneral Request:\n\t"<<get_prisoner_greq()<<
	"\nTrial info:\n\tLawyer: "<<get_prisoner_trial_lawyer()<<
	"\n\tEvidences:\n\t\t"<<get_prisoner_trial_evi_info()<<
	"\n\tConvicted of: "<<get_prisoner_trial_conviction()<<
	"\n\tAmount of decided bail: "<<get_prisoner_trial_bail()<<
	"\n\tOutcome of appeal to release: "<<get_prisoner_trial_release_appeal()<<
	"\nDoctor's prescription:\n\t" <<get_prisoner_prescription()<<std::endl;
}


// Setter
void Prisoner::set_prisoner_ID(char* id)
{
	prisoner_id = id;
}
void Prisoner::set_prisoner_crime(char* Crime)
{
	prisoner_Crime = Crime;
}
void Prisoner::set_prisoner_admission_date(char* Admission_date)
{
	prisoner_Admission_date = Admission_date;
}
void Prisoner::set_prisoner_release_date(char* Release_date)
{
	prisoner_Release_date = Release_date;
}
void Prisoner::set_prisoner_Psychological_status(char* Psychological_status)
{
	prisoner_Psychological_status = Psychological_status;
}
void Prisoner::set_prisoner_Job_status(char* Job_status)
{
	prisoner_Job_status = Job_status;
}
void Prisoner::set_prisoner_jailmate(char* Jailmate)
{
	prisoner_Jailmate = Jailmate;
}
void Prisoner::set_prisoner_utility_status(char* Utility_status)
{
	prisoner_Utility_status = Utility_status;
}
void Prisoner::set_prisoner_visiting_status(char* Visiting_status)
{
	prisoner_Visiting_status = Visiting_status;
}
void Prisoner::set_prisoner_sentence(char* Sentence)
{
	prisoner_Sentence = Sentence;
}
void Prisoner::set_prisoner_cell_location(char* Location_of_cell)
{
	prisoner_Location_of_cell = Location_of_cell;
}
void Prisoner::set_prisoner_conduct_guard_statement(char* Guard_statement)
{
	prisoner_Conduct.Guard_statement = Guard_statement;
}
void Prisoner::set_prisoner_conduct_staff_statement(char* Staff_statement)
{
	prisoner_Conduct.Staff_statement = Staff_statement;
}
void Prisoner::set_prisoner_conduct_solitary_visits(int solitary_confinement_visits)
{
	prisoner_Conduct.solitary_confinement_visits = solitary_confinement_visits;
}
void Prisoner::set_prisoner_conduct_overall(char* Overall_evaluation)
{
	prisoner_Conduct.Overall_evaluation = Overall_evaluation;
}
void Prisoner::set_prisoner_conduct_visitor_info(char* Visitor_Info)
{
	prisoner_Conduct.Visitor_Info = Visitor_Info;
}
/*void Prisoner::set_prisoner_execution_date(char* execution_date)
{
	prisoner_Execution.execution_date = execution_date;
}
void Prisoner::set_prisoner_execution_last_meal(char* last_meal)
{
	prisoner_Execution.last_meal = last_meal;
}*/
void Prisoner::set_prisoner_greq(char* General_request)
{
	prisoner_General_request = General_request;
}
void Prisoner::set_prisoner_trial_lawyer(char* Lawyer)
{
	prisoner_Trial_info.Lawyer = Lawyer;
}
void Prisoner::set_prisoner_trial_evi_info(char* Evidence_info)
{
	prisoner_Trial_info.Evidence_info = Evidence_info;
}
void Prisoner::set_prisoner_trial_bail(int Bail_amount)
{
	prisoner_Trial_info.Bail_amount = Bail_amount;
}
void Prisoner::set_prisoner_trial_conviction(char* Conviction)
{
	prisoner_Trial_info.Conviction_date = Conviction;
}
void Prisoner::set_prisoner_trial_release_appeal(char* Appeal_for_release_status)
{
	prisoner_Trial_info.Appeal_for_release_status = Appeal_for_release_status;
}
void Prisoner::set_prisoner_prescription(char* prescription)
{
	prisoner_prescription = prescription;
}
void Prisoner::set_prisoner_info(char* fname,char* lname,int A,char* g,char* ad,char* p,char* o,char* hs,char* r,char* id,char* Crime,char* Sentence,char* Location_of_cell,char* Admission_date,char* Release_date,char* Guard_statement,char* Staff_statement,int solitary_confinement_visits,char* Overall_evaluation,char* Visitor_Info,char* General_request,char* Psychological_status,char* Job_status,char* Jailmate,char* Lawyer,char* Evidence_info,char* Conviction_date,int Bail_amount,char* Appeal_for_release_status,char* Utility_status,char* prescription,char* Visiting_status)
{
	set_prisoner_ID( id);
	set_prisoner_crime( Crime);
	set_prisoner_sentence( Sentence);
	set_prisoner_cell_location( Location_of_cell);
	set_prisoner_admission_date( Admission_date);
	set_prisoner_release_date( Release_date);
	set_prisoner_conduct_guard_statement( Guard_statement);
	set_prisoner_conduct_staff_statement( Staff_statement);
	set_prisoner_conduct_solitary_visits( solitary_confinement_visits);
	set_prisoner_conduct_overall( Overall_evaluation);
	set_prisoner_conduct_visitor_info( Visitor_Info);
	//set_prisoner_execution_last_meal( last_meal);
	//set_prisoner_execution_date( execution_date);
	set_prisoner_greq( General_request);
	set_prisoner_Psychological_status( Psychological_status);
	set_prisoner_Job_status( Job_status);
	set_prisoner_jailmate( Jailmate);
	set_prisoner_trial_lawyer( Lawyer);
	set_prisoner_trial_evi_info( Evidence_info);
	set_prisoner_trial_conviction( Conviction_date);
	set_prisoner_trial_bail( Bail_amount);
	set_prisoner_trial_release_appeal( Appeal_for_release_status);
	set_prisoner_utility_status( Utility_status);
	set_prisoner_prescription( prescription);
	set_prisoner_visiting_status( Visiting_status);
	People::people_setinfo(fname, lname, A, g, ad, p, o, hs, r);
}
