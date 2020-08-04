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
#include<string>


class Bookkeeper
{
    public:
	//Init
	void Open_book();
	//inputters
	void input_Prisoner();
	void input_Staff();
	void input_Guard();
	//checkers
	//bool lowerCompare(char s[], std::string toBeCompared);
	//bool isIn(char crime[], std::string cl[], int n);
	//writers
	void write_Staff_in_file(Staff P1);
	void write_Guard_in_file(Guards P1);

	void write_To_be_executed_in_file(To_be_Executed P1);
	void write_maximum_security_prisoner(Maximum_security_prisoner P1);
	void write_medium_security_prisoner(Medium_security_prisoner P1);
	void write_minimum_security_prisoner(Minimum_security_prisoner P1);
	//Readers
	void read_Staff_in_file(int mode);
	void read_Guard_in_file(int mode);

	void read_To_be_Executed_from_file(int mode);
	void read_maximum_security_prisoner(int mode);
	void read_medium_security_prisoner(int mode);
	void read_minimum_security_prisoner(int mode);

};

#endif // BOOKKEEPER_H
