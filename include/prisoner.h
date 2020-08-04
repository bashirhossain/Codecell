#ifndef PRISONER_H
#define PRISONER_H
#include "people.h"

class Prisoner: public People
{
    protected:
	char* prisoner_id;
	char* prisoner_Crime;
	char* prisoner_Sentence;
	char* prisoner_Location_of_cell;
	char* prisoner_Admission_date;
	char* prisoner_Release_date;
	struct Conduct
	{
		char* Guard_statement;
		char* Staff_statement;
		int solitary_confinement_visits;
		char* Overall_evaluation;
		char* Visitor_Info;
	}prisoner_Conduct;

	char* prisoner_General_request;
	char* prisoner_Psychological_status;
	char* prisoner_Job_status;
	char* prisoner_Jailmate;
	struct Trial_info
	{
		char* Lawyer;
		char* Evidence_info;
		char* Conviction_date;
		int Bail_amount;
		char* Appeal_for_release_status;
	}prisoner_Trial_info;
	char* prisoner_Utility_status;
	char* prisoner_prescription;
	char* prisoner_Visiting_status;

public:
	// constructors
	Prisoner();
	Prisoner(char* fname,char* lname,int A,char* g,char* ad,char* p,char* o,char* hs,char* r,char* id,char* Crime,char* Sentence,char* Location_of_cell,char* Admission_date,char* Release_date,char* Guard_statement,char* Staff_statement,int solitary_confinement_visits,char* Overall_evaluation,char* Visitor_Info,char* General_request,char* Psychological_status,char* Job_status,char* Jailmate,char* Lawyer,char* Evidence_info,char* Conviction_date,int Bail_amount,char* Appeal_for_release_status,char* Utility_status,char* prescription,char* Visiting_status);

	// Getters
	char* get_prisoner_ID();
	char* get_prisoner_crime();
	char* get_prisoner_admission_date();
	char* get_prisoner_release_date();
	char* get_prisoner_Psychological_status();
	char* get_prisoner_Job_status();
	char* get_prisoner_jailmate();
	char* get_prisoner_utility_status();
	char* get_prisoner_visiting_status();
	char* get_prisoner_sentence();
	char* get_prisoner_cell_location();
	char* get_prisoner_conduct_guard_statement();
	char* get_prisoner_conduct_staff_statement();
	int get_prisoner_conduct_solitary_visits();
	char* get_prisoner_conduct_overall();
	char* get_prisoner_conduct_visitor_info();
	//char* get_prisoner_execution_date();
	//char* get_prisoner_execution_last_meal();
	char* get_prisoner_greq();
	char* get_prisoner_trial_lawyer();
	char* get_prisoner_trial_evi_info();
	char* get_prisoner_trial_conviction();
	int get_prisoner_trial_bail();
	char* get_prisoner_trial_release_appeal();
	char* get_prisoner_prescription();
	void get_prisoner_info();

	// Setter
	void set_prisoner_ID(char* prisoner_id);
	void set_prisoner_crime(char* prisoner_Crime);
	void set_prisoner_admission_date(char* prisoner_Admission_date);
	void set_prisoner_release_date(char* prisoner_Release_date);
	void set_prisoner_Psychological_status(char* prisoner_Psychological_status);
	void set_prisoner_Job_status(char* prisoner_Job_status);
	void set_prisoner_jailmate(char* prisoner_Jailmate);
	void set_prisoner_utility_status(char* prisoner_Utility_status);
	void set_prisoner_visiting_status(char* prisoner_Visiting_status);
	void set_prisoner_sentence(char* prisoner_Sentence);
	void set_prisoner_cell_location(char* prisoner_Location_of_cell);
	void set_prisoner_conduct_guard_statement(char* Guard_statement);
	void set_prisoner_conduct_staff_statement(char* Staff_statement);
	void set_prisoner_conduct_solitary_visits(int solitary_confinement_visits);
	void set_prisoner_conduct_overall(char* Overall_evaluation);
	void set_prisoner_conduct_visitor_info(char* Visitor_Info);
	//void set_prisoner_execution_date(char* execution_date);
	//void set_prisoner_execution_last_meal(char* last_meal);
	void set_prisoner_greq(char* prisoner_General_request);
	void set_prisoner_trial_lawyer(char* Lawyer);
	void set_prisoner_trial_evi_info(char* Evidence_info);
	void set_prisoner_trial_bail(int bail);
	void set_prisoner_trial_conviction(char* Conviction);
	void set_prisoner_trial_release_appeal(char* release_appeal);
	void set_prisoner_prescription(char* prescription);
	void set_prisoner_info(char* fname,char* lname,int A,char* g,char* ad,char* p,char* o,char* hs,char* r,char* id,char* Crime,char* Sentence,char* Location_of_cell,char* Admission_date,char* Release_date,char* Guard_statement,char* Staff_statement,int solitary_confinement_visits,char* Overall_evaluation,char* Visitor_Info,char* General_request,char* Psychological_status,char* Job_status,char* Jailmate,char* Lawyer,char* Evidence_info,char* Conviction_date,int Bail_amount,char* Appeal_for_release_status,char* Utility_status,char* prescription,char* Visiting_status);

};

#endif // PRISONER_H
