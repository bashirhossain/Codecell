#ifndef BOOKKEEPER_H
#define BOOKKEEPER_H
#include"prisoner.h"
#include"staff.h"
#include"to_be_executed.h"
#include"people.h"
#include"guards.h"
#include"Maximum_security_prisoner.h"
#include"medium_security_prisoner.h"
#include"minimum_security_prisoner.h"
#include"Finance.h"
#include<string>
#include<vector>
#include<iomanip>


class Bookkeeper
{
private:
    int role;
    public:
	//Init
	void login();
	void signup();
	void make_role();
	void Open_book();
	//inputters
	void input_Prisoner();
	void input_Staff();
	void input_Guard();
	void input_Finance();
	//finance specific functions
	int countExe();
	int countMin();
	int countMed();
	int countMax();
	int countFinancialEntry();

	double getCostPrediction();
	double getTotalCost();
	double getCostTimesX();
	double calcBail();
	double calcSalary();
	//checkers
	//bool lowerCompare(char s[], std::string toBeCompared);
	//bool isIn(char crime[], std::string cl[], int n);
	//writers
	void write_Staff_in_file(Staff P1,int mode);
	void write_Guard_in_file(Guards P1,int mode);

	void write_To_be_executed_in_file(To_be_Executed P1,int mode);
	void write_maximum_security_prisoner(Maximum_security_prisoner P1,int mode);
	void write_medium_security_prisoner(Medium_security_prisoner P1,int mode);
	void write_minimum_security_prisoner(Minimum_security_prisoner P1,int mode);
    void write_finance_in_file(Finance F1);
	//Readers
	void read_Staff_in_file(int mode);
	void read_Guard_in_file(int mode);

	void read_To_be_Executed_from_file(int mode);
	void read_maximum_security_prisoner(int mode);
	void read_medium_security_prisoner(int mode);
	void read_minimum_security_prisoner(int mode);
    void update_people(int *flag3,char fname[],int*A, char g[],char ad[],char p[],char o[],char hs[],char r[],char id[],int* u_i,char identification[],char att[],char attribute[]);
    void update_work(int *flag3,char rank[],char shift[],int*experience,int*u_i,double*salary,double*u_double,char attribute[],char id[],char u[],char att[]);
    void update_prisoner(int *flag3,char Crime[],char Sentence[],char Location_of_cell[],char Admission_date[],char Release_date[], char Guard_statement[],char Staff_statement[],int *solitary_confinement_visits,char Overall_evaluation[],char Visitor_Info[],char General_request[],char Psychological_status[],char Job_status[],char Jailmate[],char Lawyer[],char Evidence_info[],char Conviction_date[],int *Bail_amount,char Appeal_for_release_status[],char Utility_status[], char prescription[], char Visiting_status[],char att[],char attribute[],int*u_i,char u[],char id[]);
    void update_interface(char u[],char attribute[],char att[],int*u_i,double *u_double);
    enum type {none,normal,search,update};
    enum kind {null,admin,read,read_write,modify};

	void read_finance_in_file();

};

#endif // BOOKKEEPER_H
