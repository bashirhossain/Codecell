#include"../include/prisoner.h"
#include"../include/staff.h"
#include"../include/to_be_executed.h"
#include"../include/bookkeeper.h"
#include"../include/People.h"
#include"../include/guards.h"
#include"../include/maximum_security_prisoner.h"
#include"../include/medium_security_prisoner.h"
#include"../include/minimum_security_prisoner.h"
#include"../include/Finance.h"
#include <fstream>
#include <ios>
#include <sstream>
#include <string>
#include <cstring>
#include<iostream>
#include<limits>
#include<algorithm>
using namespace std;
void Bookkeeper::Open_book()
{

	std::cout<<"\nDo you want to Read(1) or Write(2) or Search(3) or Finances(4) or update(5)"<<std::endl;
	int x;
	std::cin>>x;
	if(x==1)
	{
		std::cout<<"\nPrisoner(1), Guard(2) or Staff(3)"<<std::endl;
		std::cin>>x;
		if(x==1)
		{
			std::cout<<"\nMaximum security(1), Medium security(2), Minimum security(3) or Executee(4)"<<std::endl;
			cin>>x;
			if(x==1)
			{
				read_maximum_security_prisoner(type::normal);
			}
			else if(x==2)
			{
				read_medium_security_prisoner(type::normal);
			}
			else if(x==3)
			{
				read_minimum_security_prisoner(type::normal);
			}
			else if(x==4)
			{
				read_To_be_Executed_from_file(type::normal);
			}
		}
		else if(x==3)
		{
			read_Staff_in_file(type::normal);
		}
		else if(x==2)
		{
			read_Guard_in_file(type::normal);
		}
	}
	else if(x==2)
	{
		std::cout<<"\nPrisoner(1), Guard(2) or Staff(3)"<<std::endl;
		cin>>x;
		if(x==1)
		{
			input_Prisoner();
		}
		else if(x==2)
		{
			input_Guard();
		}
		else if(x==3)
		{
			input_Staff();
		}
	}
	else if(x==3)
    {
        std::cout<<"\nPrisoner(1), Guard(2) or Staff(3)"<<std::endl;
       cin>>x;
       if(x==2)
       {
           read_Guard_in_file(2);
       }
       else if(x==3)
       {
           read_Staff_in_file(2);
       }
       else if(x==1)
       {

			std::cout<<"\nMaximum security(1), Medium security(2), Minimum security(3) or Executee(4)"<<std::endl;
			cin>>x;

			if(x==4)
            {
              read_To_be_Executed_from_file(type::search);
            }
            if(x==1)
            {
                read_maximum_security_prisoner(type::search);
            }
            else if(x==2)
            {
                read_medium_security_prisoner(type::search);
            }
            else if(x==3)
            {
                read_minimum_security_prisoner(type::search);
            }

       }

    }
    else if(x == 4)
    {
        std::cout<<"\nWrite Financial data(1), Read Financial data(2), Get Prediction(3)"<<std::endl;
        std::cin>>x;
        if(x == 1)
        {
            Bookkeeper::input_Finance();
        }
        else if(x == 2)
        {
            Bookkeeper::read_finance_in_file();
        }
    }

    else if(x==5)
    {
        std::cout<<"\nPrisoner(1), Guard(2) or Staff(3)"<<std::endl;
       cin>>x;
       if(x==2)
       {
           read_Guard_in_file(type::update);
       }
       else if(x==3)
       {
           read_Staff_in_file(type::update);
       }
       else if(x==1)
       {

            std::cout<<"\nMaximum security(1), Medium security(2), Minimum security(3) or Executee(4)"<<std::endl;
            cin>>x;

            if(x==4)
            {
              read_To_be_Executed_from_file(type::update);
            }
            if(x==1)
            {
                read_maximum_security_prisoner(type::update);
            }
            else if(x==2)
            {
                read_medium_security_prisoner(type::update);
            }
            else if(x==3)
            {
                read_minimum_security_prisoner(type::update);
            }

       }


    }
}

// comparison functions & finance specific functions
bool lowerCompare(char s[], string toBeCompared)
{
    string temp = s;
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);  // converts all chars to lowercase
    return temp == toBeCompared;
}

bool isIn(char crime[], string cl[], int n)  // checks if crime is in list
{
    string crimeList[n];
    for(int i = 0; i < n; i++)
    {
        crimeList[i] = cl[i];
    }
    for(int i = 0; i < n; i++)
    {
        if(crime == crimeList[i])
        {
            return true;
        }
    }
    return false;
}

int Bookkeeper::countExe()
{
    int exe = 0;

    // read to_be_executed file
    ifstream read_executed("execution_list.txt");
    while(1)
    {
        string key_string;
        if(!getline (read_executed, key_string))
			break;
        for(int i = 0; i < 32; i++)
        {
            getline (read_executed, key_string);
        }
        exe++;
    }
    return exe - 1;
}

int Bookkeeper::countMax()
{
    int maxCount = 0;

    //read max security prisoner file
    ifstream read_executed("Maximum_security_list.txt");
    while(1)
    {
        string key_string;
        if(!getline (read_executed, key_string))
			break;
        for(int i = 0; i < 31; i++)
        {
            getline (read_executed, key_string);
        }
        maxCount++;
    }
    return maxCount - 1;
}

int Bookkeeper::countMed()
{
    int medCount = 0;

    //read med security prisoner file
    ifstream read_executed("Medium_security_list.txt");
    while(1)
    {
        string key_string;
        if(!getline (read_executed, key_string))
			break;
        for(int i = 0; i < 31; i++)
        {
            getline (read_executed, key_string);
        }
        medCount++;
    }
    return medCount - 1;
}

int Bookkeeper::countMin()
{
    int minCount = 0;

    //read med security prisoner file
    ifstream read_executed("Minimum_security_list.txt");
    while(1)
    {
        string key_string;
        if(!getline (read_executed, key_string))
			break;
        for(int i = 0; i < 31; i++)
        {
            getline (read_executed, key_string);
        }
        minCount++;
    }
    return minCount - 1;
}

double Bookkeeper::calcBail()
{
    double total_bail = 0.0;
    int exe = 0.0, maxBail = 0.0, minBail = 0.0, medBail = 0.0;

    // read to be executed file
    ifstream read_executed("execution_list.txt");
    while(1)
    {
        string key_string;
        if(!getline (read_executed, key_string))
			break;
        for(int i = 0; i < 27; i++)
        {
            getline (read_executed, key_string);
        }
        getline (read_executed, key_string);
		stringstream geek2(key_string);
		int Bail_amount = 0;
		geek2>>Bail_amount;

		exe += Bail_amount;

		for(int i = 0; i < 5; i++)
        {
            getline (read_executed, key_string);
        }
    }

    // read max sec file
    ifstream read_executed2("Maximum_security_list.txt");
    while(1)
    {
        string key_string;
        if(!getline (read_executed2, key_string))
			break;
        for(int  i = 0; i < 27; i++)
        {
            getline (read_executed2, key_string);
        }
        getline (read_executed2, key_string);
		stringstream geek2(key_string);
		int Bail_amount = 0;
		geek2>>Bail_amount;

		maxBail += Bail_amount;

		for(int i = 0; i < 3; i++)
        {
            getline (read_executed2, key_string);
        }
    }

    // read med sec file
    ifstream read_executed3("Medium_security_list.txt");
    while(1)
    {
        string key_string;
        if(!getline (read_executed3, key_string))
			break;
        for(int  i = 0; i < 27; i++)
        {
            getline (read_executed3, key_string);
        }
        getline (read_executed3, key_string);
		stringstream geek2(key_string);
		int Bail_amount = 0;
		geek2>>Bail_amount;

		medBail += Bail_amount;

		for(int i = 0; i < 3; i++)
        {
            getline (read_executed3, key_string);
        }
    }

    // read min sec file
    ifstream read_executed4("Minimum_security_list.txt");
    while(1)
    {
        string key_string;
        if(!getline (read_executed4, key_string))
			break;
        for(int  i = 0; i < 27; i++)
        {
            getline (read_executed4, key_string);
        }
        getline (read_executed4, key_string);
		stringstream geek2(key_string);
		int Bail_amount = 0;
		geek2>>Bail_amount;

		minBail += Bail_amount;

		for(int i = 0; i < 3; i++)
        {
            getline (read_executed4, key_string);
        }
    }

    return (exe * 0.13) + (maxBail * 0.08) + (medBail * 0.04) + (minBail * 0.02);
}

double Bookkeeper::calcSalary()
{
    //read through the staff and guards records to get salary info
    double totalSalary = 0.0;

    //read the staff file
    ifstream read_executed("Staff_list.txt");
    while(1)
    {
        // code copied from read_staff_in_file function
        string key_string;
		if(!getline (read_executed, key_string))
			break;

		for(int i = 0; i < 13; i++)
        {
            getline (read_executed, key_string);  // data that is irrelevant
        }

		getline (read_executed, key_string);
		stringstream geek(key_string);
		double salary = 0;
		geek>>salary;

		getline (read_executed, key_string);

		getline (read_executed, key_string);

		//total salary sum
		totalSalary += salary;
    }

    // read the guard file
    ifstream read_executed2("Guards_list.txt");
    while(1)
    {
        string key_string;

		if(!getline (read_executed2, key_string))
			break;
        for(int i = 0; i < 14; i++)
        {
            getline (read_executed2, key_string);
        }

		getline (read_executed2, key_string);
		stringstream geek(key_string);
		double salary = 0;
		geek>>salary;

		getline (read_executed2, key_string);

		getline (read_executed2, key_string);

		//total salary sum
		totalSalary += salary;
    }
    return totalSalary;
}


//Inputters

void Bookkeeper::input_Guard()
{
	std::cout<<"\nEnter First Name: ";
    char fname[20];
    cin>>fname;
    std::cout<<"\nEnter Last Name: ";
    char lname[20];
    cin>>lname;
    int A;
    /**For not letting the user input anything other than the intended output*/
    while (std::cout << "\nAge (Integer values): " && !(std::cin >> A))
    {
        std::cin.clear(); //clears bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discards problematic input stored in buffer
        std::cout << "Invalid input. Try again.\n";
    }
    std::cout<<"\nGender: ";
    char g[10];
    cin>>g;
    std::cout<<"\nEnter Address: ";
    char ad[50];
    getchar();
    gets(ad);
    //getchar();
    std::cout<<"\nEnter Phone number: ";
    char p[14];
    cin>>p;
    std::cout<<"\nOccupation: ";
    char o[15];
    getchar();
    gets(o);
    //getchar();
    std::cout<<"\nHealth Status: ";
    char hs[100];
    gets(hs);
    //getchar();
    std::cout<<"\nReligion: ";
    char r[25];
    gets(r);

    std::cout<<"\nEnter ID: ";
    char id[11];
    gets(id);
    std::cout<<"\nEnter Unit: ";
    char unit[20];
    gets(unit);
    std::cout<<"\nEnter Rank: ";
    char rank[20];
    gets(rank);
    std::cout<<"\nEnter Shift: ";
    char shift[10];
    gets(shift);
    std::cout<<"\nEnter Position: ";
    char post[30];
    gets(post);
    std::cout<<"\nEnter Ammunition Status: ";
    char ammunition_status[10];
    gets(ammunition_status);
    std::cout<<"\nEnter psyche evaluation: ";
    char psyche_evaluation[30];
    gets(psyche_evaluation);
    double salary;
    /**For not letting the user input anything other than the intended output*/
    while (std::cout << "\nEnter Salary (Double values): " && !(std::cin >> salary))
    {
        std::cin.clear(); //clears bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discards problematic input stored in buffer
        std::cout << "Invalid input. Try again.\n";
    }
    int experience;
    /**For not letting the user input anything other than the intended output*/
    while (std::cout << "\nEnter Number of days of experience (Integer values): " && !(std::cin >> experience))
    {
        std::cin.clear(); //clears bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discards problematic input stored in buffer
        std::cout << "Invalid input. Try again.\n";
    }

    Guards P1(fname,lname,A,g,ad,p, o,hs,r,	id, unit, rank,shift,post,ammunition_status,psyche_evaluation, salary, experience);
    write_Guard_in_file(P1,type::normal);

}

void Bookkeeper::input_Staff()
{    std::cout<<"\nEnter First Name: ";
    char fname[20];
    cin>>fname;
    std::cout<<"\nEnter Last Name: ";
    char lname[20];
    cin>>lname;
    int A;
    /**For not letting the user input anything other than the intended output*/
    while (std::cout << "\nAge (Integer values): " && !(std::cin >> A))
    {
        std::cin.clear(); //clears bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discards problematic input stored in buffer
        std::cout << "Invalid input. Try again.\n";
    }
    std::cout<<"\nGender: ";
    char g[10];
    cin>>g;
    std::cout<<"\nEnter Address: ";
    char ad[50];
    getchar();
    gets(ad);
    //getchar();
    std::cout<<"\nEnter Phone number: ";
    char p[14];
    cin>>p;
    std::cout<<"\nOccupation: ";
    char o[15];
    getchar();
    gets(o);
    //getchar();
    std::cout<<"\nHealth Status: ";
    char hs[100];
    gets(hs);
    //getchar();
    std::cout<<"\nReligion: ";
    char r[25];
    gets(r);


    std::cout<<"\nEnter ID: ";
    char id[11];
    gets(id);
    std::cout<<"\nEnter Profession: ";
    char Profession[20];
    gets(Profession);
    std::cout<<"\nEnter Rank: ";
    char rank[20];
    gets(rank);
    std::cout<<"\nEnter Shift: ";
    char shift[10];
    gets(shift);

    std::cout<<"\nEnter requests(If any): ";
    char requests[100];
    gets(requests);
    std::cout<<"\nEnter psyche evaluation: ";
    char psyche[30];
    gets(psyche);
    double salary;
    /**For not letting the user input anything other than the intended output*/
    while (std::cout << "\nEnter Salary (Double values): " && !(std::cin >> salary))
    {
        std::cin.clear(); //clears bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discards problematic input stored in buffer
        std::cout << "Invalid input. Try again.\n";
    }
    int experience;
    /**For not letting the user input anything other than the intended output*/
    while (std::cout << "\nEnter Number of days of experience (Integer values): " && !(std::cin >> experience))
    {
        std::cin.clear(); //clears bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discards problematic input stored in buffer
        std::cout << "Invalid input. Try again.\n";
    }


    Staff P1(fname,lname,A, g,ad,p,o,hs,r,id,rank,Profession, shift,  psyche,requests, experience,salary);
    write_Staff_in_file(P1,1);
    return;
    }


void Bookkeeper::input_Prisoner()
{
	std::cout<<"\nEnter First Name: ";
	char fname[20];
	cin>>fname;
	std::cout<<"\nEnter Last Name: ";
	char lname[20];
	cin>>lname;
	int A;
	/**For not letting the user input anything other than the intended output*/
	while (std::cout << "\nAge (Integer values): " && !(std::cin >> A))
    {
        std::cin.clear(); //clears bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discards problematic input stored in buffer
        std::cout << "Invalid input. Try again.\n";
    }
	std::cout<<"\nGender: ";
	char g[10];
	cin>>g;
	std::cout<<"\nEnter Address: ";
	char ad[50];
	getchar();
	gets(ad);
	//getchar();
	std::cout<<"\nEnter Phone number: ";
	char p[14];
	cin>>p;
	std::cout<<"\nOccupation: ";
	char o[15];
	getchar();
	gets(o);
	//getchar();
	std::cout<<"\nHealth Status: ";
	char hs[100];
	gets(hs);
	//getchar();
	std::cout<<"\nReligion: ";
	char r[25];
	gets(r);

	//People p1(fname,lname, A,g, ad,p,o,hs,r);
	//p1.people_getInfo();

	std::cout<<"\nEnter Prisoner ID: ";
	char id[11];
	cin>>id;
	std::cout<<"\nEnter Crime: ";
	char Crime[25];
	getchar();
	gets(Crime);
	char Sentence[50];
	std::cout<<"\nSentence: ";
	gets(Sentence);

	char Admission_date[20];
	std::cout<<"\nAdmission Date: ";
	gets(Admission_date);
	char Release_date[20];
	std::cout<<"\nRelease date: ";
	gets(Release_date);
	char Guard_statement[100];
	std::cout<<"\nEnter Guard statement: ";
	gets(Guard_statement);
	char Staff_statement[100];
	std::cout<<"\nEnter Staff statement: ";
	gets(Staff_statement);
	int solitary_confinement_visits;
	/**For not letting the user input anything other than the intended output*/
	while (std::cout << "\nSolitary Confinement visits (Integer values): " && !(std::cin >> solitary_confinement_visits))
    {
        std::cin.clear(); //clears bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discards problematic input stored in buffer
        std::cout << "Invalid input. Try again.\n";
    }
	getchar();
	char Overall_evaluation[150];
	std::cout<<"\nEnter Overall Evaluation: ";
	gets(Overall_evaluation);
	char Visitor_Info[20];
	std::cout<<"\nVisitor Information: ";
	gets(Visitor_Info);
	char General_request[100];
	std::cout<<"\nEnter General request: ";
	gets(General_request);
	char Psychological_status[40];
	std::cout<<"\nPsychological status: ";
	gets(Psychological_status);
	char Job_status[30];
	std::cout<<"\nJob in the prison: ";
	gets(Job_status);
	char Jailmate[20];
	std::cout<<"\nEnter Jailmate(If none, enter none): ";
	gets(Jailmate);
	char Lawyer[20];
	std::cout<<"\nLawyer: ";
	gets(Lawyer);
	char Evidence_info[150];
	std::cout<<"\nEvidence Information: ";
	gets(Evidence_info);
	char Conviction_date[20];
	std::cout<<"\nEnter Conviction date: ";
	gets(Conviction_date);
	int Bail_amount;
	/**For not letting the user input anything other than the intended output*/
	while (std::cout << "\nBail amount (Integer values): " && !(std::cin >> Bail_amount))
    {
        std::cin.clear(); //clears bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discards problematic input stored in buffer
        std::cout << "Invalid input. Try again.\n";
    }
    getchar();
	char Appeal_for_release_status[15];
	std::cout<<"\nAppeal for release status: ";
	gets(Appeal_for_release_status);
	char Utility_status[10];
	std::cout<<"\nEnter Utility status: ";
	gets(Utility_status);
	char prescription[50];
	std::cout<<"\nEnter prescription: ";
	gets(prescription);
	char Visiting_status[40];
	std::cout<<"\nEnter visiting status: ";
	gets(Visiting_status);


    /**List of crimes for easier & flexible classification*/
    /**These lists are not comprehensive. Pls add more crimes*/
    string whiteCollarCrimes[10] = {"fraud", "embezzlement", "bribery", "money laundering", "tax evasion"};
    string lessViolentCrimes[10] = {"selling narcotics", "drunk driving", "hit and run", "theft", "possession of narcotics"};
    string violentCrimes[10] = {"murder", "rape", "assault", "armed robbery", "human trafficking"};

	if(lowerCompare(Sentence, "death sentence"))
	{
		char last_meal[30];
		std::cout<<"\nRequested last meal: ";
		gets(last_meal);
		char execution_date[20];
		std::cout<<"\nExecution Date: ";
		gets(execution_date);

		char Location_of_cell[11] = "South Wing";

		To_be_Executed P1(fname,lname,A,g,ad,p,o,hs,r,id,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status,last_meal,execution_date);
		P1.To_be_Executed_getinfo();
		write_To_be_executed_in_file(P1,type::normal);

		return;
	}

	else if(isIn(Crime, whiteCollarCrimes, sizeof(whiteCollarCrimes) / sizeof(whiteCollarCrimes[0])) && !strcmp(g,"Male"))
	{
		char Location_of_cell[11] = "North Wing";

		Minimum_security_prisoner P1(fname,lname,A,g,ad,p,o,hs,r,id,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status);
		P1.get_prisoner_info();
		write_minimum_security_prisoner(P1,type::normal);

		return;
	}

	else if(isIn(Crime, violentCrimes, sizeof(violentCrimes) / sizeof(violentCrimes[0]))&&!strcmp(g,"Male"))
	{
		char Location_of_cell[11] = "South Wing";

		Maximum_security_prisoner P1(fname,lname,A,g,ad,p,o,hs,r,id,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status);
		P1.get_prisoner_info();
		write_maximum_security_prisoner(P1,type::normal);

		return;
	}

	else if(isIn(Crime, lessViolentCrimes, sizeof(lessViolentCrimes) / sizeof(lessViolentCrimes[0]))&&!strcmp(g,"Male"))
	{
		char Location_of_cell[11] = "East Wing";

		Medium_security_prisoner P1(fname,lname,A,g,ad,p,o,hs,r,id,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status);
		P1.get_prisoner_info();
		write_medium_security_prisoner(P1,type::normal);

		return;
	}

	else
    {
        //crime is not in list so defaults to white collar crimes
        std::cout<<"\n\nThe crime is not listed in database.";
        char Location_of_cell[11];
        std::cout<<"\nEnter Location of cell: ";
        gets(Location_of_cell);

        if(lowerCompare(Location_of_cell, "north wing"))
        {
            strcpy(Location_of_cell, "North Wing");
            Minimum_security_prisoner P1(fname,lname,A,g,ad,p,o,hs,r,id,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status);
            P1.get_prisoner_info();
            write_minimum_security_prisoner(P1,type::normal);
            return;
        }
        else if(lowerCompare(Location_of_cell, "south wing"))
        {
            strcpy(Location_of_cell, "South Wing");
            Maximum_security_prisoner P1(fname,lname,A,g,ad,p,o,hs,r,id,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status);
            P1.get_prisoner_info();
            write_maximum_security_prisoner(P1,type::normal);
            return;
        }
        else if(lowerCompare(Location_of_cell, "east wing"))
        {
            strcpy(Location_of_cell, "East Wing");
            Medium_security_prisoner P1(fname,lname,A,g,ad,p,o,hs,r,id,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status);
            P1.get_prisoner_info();
            write_medium_security_prisoner(P1,type::normal);
            return;
        }
        else
        {
            // defaults to north wing
            strcpy(Location_of_cell, "North Wing");
            Minimum_security_prisoner P1(fname,lname,A,g,ad,p,o,hs,r,id,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status);
            P1.get_prisoner_info();
            write_minimum_security_prisoner(P1,type::normal);
            return;
        }
    }
}


void Bookkeeper::input_Finance()
{
    std::cout<<"\nEnter Quarter Name: ";
    char qName[20];
	std::cin>>qName;
    double stipend;
	/**For not letting the user input anything other than the intended output*/
	while (std::cout << "\nEnter Government Stipend (Double values): " && !(std::cin >> stipend))
    {
        std::cin.clear(); //clears bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discards problematic input stored in buffer
        std::cout << "Invalid input. Try again.\n";
    }
    double sales;
	/**For not letting the user input anything other than the intended output*/
	while (std::cout << "\nEnter Sales Revenue (Double values): " && !(std::cin >> sales))
    {
        std::cin.clear(); //clears bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discards problematic input stored in buffer
        std::cout << "Invalid input. Try again.\n";
    }

    /** bail is not inputted by user*/
    double bail = Bookkeeper::calcBail();

    double lease;
	/**For not letting the user input anything other than the intended output*/
	while (std::cout << "\nEnter Lease (Double values): " && !(std::cin >> lease))
    {
        std::cin.clear(); //clears bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discards problematic input stored in buffer
        std::cout << "Invalid input. Try again.\n";
    }
    double maintenance;
	/**For not letting the user input anything other than the intended output*/
	while (std::cout << "\nEnter Maintenance cost (Double values): " && !(std::cin >> maintenance))
    {
        std::cin.clear(); //clears bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discards problematic input stored in buffer
        std::cout << "Invalid input. Try again.\n";
    }
    double food;
	/**For not letting the user input anything other than the intended output*/
	while (std::cout << "\nEnter Food cost (Double values): " && !(std::cin >> food))
    {
        std::cin.clear(); //clears bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discards problematic input stored in buffer
        std::cout << "Invalid input. Try again.\n";
    }

    /** salary is not inputted by user*/
    double salary = Bookkeeper::calcSalary();

    double edu;
	/**For not letting the user input anything other than the intended output*/
	while (std::cout << "\nEnter Education Program cost (Double values): " && !(std::cin >> edu))
    {
        std::cin.clear(); //clears bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discards problematic input stored in buffer
        std::cout << "Invalid input. Try again.\n";
    }
    double laundry;
	/**For not letting the user input anything other than the intended output*/
	while (std::cout << "\nEnter Laundry cost (Double values): " && !(std::cin >> laundry))
    {
        std::cin.clear(); //clears bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discards problematic input stored in buffer
        std::cout << "Invalid input. Try again.\n";
    }
    double misc;
	/**For not letting the user input anything other than the intended output*/
	while (std::cout << "\nEnter any other cost (Double values): " && !(std::cin >> misc))
    {
        std::cin.clear(); //clears bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discards problematic input stored in buffer
        std::cout << "Invalid input. Try again.\n";
    }

    Finance F1(stipend, sales, bail, lease, maintenance, food, salary, edu, laundry, misc, qName);
    Bookkeeper::write_finance_in_file(F1);
    return;
}


//Writers
void Bookkeeper::write_Staff_in_file(Staff P1,int mode)
{

	//execution_list.open("execution_list.txt");
	 ofstream execution_list;
    if(mode!=type::update) //normal write mode
        execution_list.open("Staff_list.txt",ios::app);
    else{
        execution_list.open("temp.txt",ios::app);//update write mode
         }
    //execution_list.open("execution_list.txt");
       if(mode==type::update)
       {
           execution_list<<P1.people_getFname();
       }
       else
       {
           execution_list<<P1.people_getFname()<<" ";
       }
    execution_list<<P1.people_getLname()<<"\n"<<
    P1.people_getAge()<<"\n"<<
    P1.people_getG()<<"\n"<<
    P1.people_getPh()<<"\n"<<
    P1.people_getAdd()<<"\n"<<
    P1.people_getOcc()<<"\n"<<
    P1.people_getHs()<<"\n"<<
    P1.people_getRel()<<"\n"<<
    P1.getstaff_id()<<"\n"<<
    P1.getstaff_Profession()<<"\n"<<
    P1.getstaff_rank()<<"\n"<<
    P1.getstaff_shift()<<"\n"<<
    P1.getstaff_psyche()<<"\n"<<
    P1.getstaff_requests()<<"\n"<<
    P1.getstaff_salary()<<"\n"<<
    P1.getstaff_experience()<<"\n"<<

    std::endl;
    execution_list.close();
}
void Bookkeeper::write_Guard_in_file(Guards P1,int mode)
{
	 ofstream execution_list;
    if(mode!=3)
        execution_list.open("Guards_list.txt",ios::app);//normal write mode
    else{
        execution_list.open("temp.txt",ios::app);//update write mode
        }
    //execution_list.open("execution_list.txt");
    if(mode==type::update)
       {
           execution_list<<P1.people_getFname();
       }
       else
       {
           execution_list<<P1.people_getFname()<<" ";
       }
    execution_list<< P1.people_getLname()<<"\n"<<
    P1.people_getAge()<<"\n"<<
    P1.people_getG()<<"\n"<<
    P1.people_getPh()<<"\n"<<
    P1.people_getAdd()<<"\n"<<
    P1.people_getOcc()<<"\n"<<
    P1.people_getHs()<<"\n"<<
    P1.people_getRel()<<"\n"<<
    P1.guard_getid()<<"\n"<<
    P1.guard_getunit()<<"\n"<<
    P1.guard_getrank()<<"\n"<<
    P1.guard_getshift()<<"\n"<<
    P1.guard_getpsyche_evaluation()<<"\n"<<
    P1.guard_getpost()<<"\n"<<
    P1.guard_getammunition_status()<<"\n"<<
    P1.guard_getsalary()<<"\n"<<
    P1.guard_getexperience()<<"\n"<<
    std::endl;
    execution_list.close();

}

void Bookkeeper:: write_To_be_executed_in_file(To_be_Executed P1,int mode)
{
	 ofstream execution_list;
    if(mode!=3)
        execution_list.open("execution_list.txt",ios::app);//normal write mode
    else{
        execution_list.open("temp.txt",ios::app);//update write mode
        }
//execution_list.open("execution_list.txt");
    if(mode==type::update)
       {
           execution_list<<P1.people_getFname();
       }
       else
       {
           execution_list<<P1.people_getFname()<<" ";
       }
    execution_list<<P1.people_getLname()<<"\n"<<
    P1.people_getAge()<<"\n"<<
    P1.people_getG()<<"\n"<<
    P1.people_getPh()<<"\n"<<
    P1.people_getAdd()<<"\n"<<
    P1.people_getOcc()<<"\n"<<
    P1.people_getHs()<<"\n"<<
    P1.people_getRel()<<"\n"<<
    P1.get_prisoner_ID()<<"\n"<<
    P1.get_prisoner_crime()<<"\n"<<
    P1.get_prisoner_admission_date()<<"\n"<<
    P1.get_prisoner_release_date()<<"\n"<<
    P1.get_prisoner_Psychological_status()<<"\n"<<
    P1.get_prisoner_Job_status()<<"\n"<<
    P1.get_prisoner_jailmate()<<"\n"<<
    P1.get_prisoner_utility_status()<<"\n"<<
    P1.get_prisoner_visiting_status()<<"\n"<<
    P1.get_prisoner_sentence()<<"\n"<<
    P1.get_prisoner_cell_location()<<"\n"<<
    P1.get_prisoner_conduct_guard_statement()<<"\n"<<
    P1.get_prisoner_conduct_staff_statement()<<"\n"<<
    P1.get_prisoner_conduct_solitary_visits()<<"\n"<<
    P1.get_prisoner_conduct_overall()<<"\n"<<
    P1.get_prisoner_conduct_visitor_info()<</*"\nExecution Information:\n\tExecution date: "<<get_prisoner_execution_date()<<"\n\tLast Meal: "<<get_prisoner_execution_last_meal()<<*/"\n"<<
    P1.get_prisoner_greq()<<"\n"<<
    P1.get_prisoner_trial_lawyer()<<"\n"<<
    P1.get_prisoner_trial_evi_info()<<"\n"<<
    P1.get_prisoner_trial_conviction()<<"\n"<<
    P1.get_prisoner_trial_bail()<<"\n"<<
    P1.get_prisoner_trial_release_appeal()<<"\n" <<
    P1.get_prisoner_prescription()<<"\n"<<
    P1.get_to_be_executed_last_meal()<<"\n"<<
    P1.get_to_be_executed_execution_date()<<"\n"<<
    std::endl;
    execution_list.close();

}

void Bookkeeper:: write_maximum_security_prisoner(Maximum_security_prisoner P1,int mode)
{

    ofstream execution_list;
    if(mode!=type::update)
        execution_list.open("Maximum_security_list.txt",ios::app);
    else{
        execution_list.open("temp.txt",ios::app);
        cout<<"temp opened"<<endl;
        }
 if(mode==type::update)
       {
           execution_list<<P1.people_getFname();
       }
       else
       {
           execution_list<<P1.people_getFname()<<" ";
       }
    execution_list<< P1.people_getLname()<<"\n"<<
    P1.people_getAge()<<"\n"<<
    P1.people_getG()<<"\n"<<
    P1.people_getPh()<<"\n"<<
    P1.people_getAdd()<<"\n"<<
    P1.people_getOcc()<<"\n"<<
    P1.people_getHs()<<"\n"<<
    P1.people_getRel()<<"\n"<<
    P1.get_prisoner_ID()<<"\n"<<
    P1.get_prisoner_crime()<<"\n"<<
    P1.get_prisoner_admission_date()<<"\n"<<
    P1.get_prisoner_release_date()<<"\n"<<
    P1.get_prisoner_Psychological_status()<<"\n"<<
    P1.get_prisoner_Job_status()<<"\n"<<
    P1.get_prisoner_jailmate()<<"\n"<<
    P1.get_prisoner_utility_status()<<"\n"<<
    P1.get_prisoner_visiting_status()<<"\n"<<
    P1.get_prisoner_sentence()<<"\n"<<
    P1.get_prisoner_cell_location()<<"\n"<<
    P1.get_prisoner_conduct_guard_statement()<<"\n"<<
    P1.get_prisoner_conduct_staff_statement()<<"\n"<<
    P1.get_prisoner_conduct_solitary_visits()<<"\n"<<
    P1.get_prisoner_conduct_overall()<<"\n"<<
    P1.get_prisoner_conduct_visitor_info()<</*"\nExecution Information:\n\tExecution date: "<<get_prisoner_execution_date()<<"\n\tLast Meal: "<<get_prisoner_execution_last_meal()<<*/"\n"<<
    P1.get_prisoner_greq()<<"\n"<<
    P1.get_prisoner_trial_lawyer()<<"\n"<<
    P1.get_prisoner_trial_evi_info()<<"\n"<<
    P1.get_prisoner_trial_conviction()<<"\n"<<
    P1.get_prisoner_trial_bail()<<"\n"<<
    P1.get_prisoner_trial_release_appeal()<<"\n" <<
    P1.get_prisoner_prescription()<<"\n"<<
    /*P1.get_to_be_executed_last_meal()<<"\n"<<
    P1.get_to_be_executed_execution_date()<<"\n"<<*/
    std::endl;
    execution_list.close();
}

void Bookkeeper:: write_medium_security_prisoner(Medium_security_prisoner P1,int mode)
{
    ofstream execution_list;
    if(mode!=type::update)
        execution_list.open("Medium_security_list.txt",ios::app);
    else{
        execution_list.open("temp.txt",ios::app);
        }
//execution_list.open("execution_list.txt");
if(mode==type::update)
       {
           execution_list<<P1.people_getFname();
       }
       else
       {
           execution_list<<P1.people_getFname()<<" ";
       }
    execution_list<<P1.people_getLname()<<"\n"<<
    P1.people_getAge()<<"\n"<<
    P1.people_getG()<<"\n"<<
    P1.people_getPh()<<"\n"<<
    P1.people_getAdd()<<"\n"<<
    P1.people_getOcc()<<"\n"<<
    P1.people_getHs()<<"\n"<<
    P1.people_getRel()<<"\n"<<
    P1.get_prisoner_ID()<<"\n"<<
    P1.get_prisoner_crime()<<"\n"<<
    P1.get_prisoner_admission_date()<<"\n"<<
    P1.get_prisoner_release_date()<<"\n"<<
    P1.get_prisoner_Psychological_status()<<"\n"<<
    P1.get_prisoner_Job_status()<<"\n"<<
    P1.get_prisoner_jailmate()<<"\n"<<
    P1.get_prisoner_utility_status()<<"\n"<<
    P1.get_prisoner_visiting_status()<<"\n"<<
    P1.get_prisoner_sentence()<<"\n"<<
    P1.get_prisoner_cell_location()<<"\n"<<
    P1.get_prisoner_conduct_guard_statement()<<"\n"<<
    P1.get_prisoner_conduct_staff_statement()<<"\n"<<
    P1.get_prisoner_conduct_solitary_visits()<<"\n"<<
    P1.get_prisoner_conduct_overall()<<"\n"<<
    P1.get_prisoner_conduct_visitor_info()<</*"\nExecution Information:\n\tExecution date: "<<get_prisoner_execution_date()<<"\n\tLast Meal: "<<get_prisoner_execution_last_meal()<<*/"\n"<<
    P1.get_prisoner_greq()<<"\n"<<
    P1.get_prisoner_trial_lawyer()<<"\n"<<
    P1.get_prisoner_trial_evi_info()<<"\n"<<
    P1.get_prisoner_trial_conviction()<<"\n"<<
    P1.get_prisoner_trial_bail()<<"\n"<<
    P1.get_prisoner_trial_release_appeal()<<"\n" <<
    P1.get_prisoner_prescription()<<"\n"<<
    /*P1.get_to_be_executed_last_meal()<<"\n"<<
    P1.get_to_be_executed_execution_date()<<"\n"<<*/
    std::endl;
    execution_list.close();

}

void Bookkeeper:: write_minimum_security_prisoner(Minimum_security_prisoner P1,int mode)
{
	ofstream execution_list;
    if(mode!=type::update)
        execution_list.open("Minimum_security_list.txt",ios::app);
    else{
        execution_list.open("temp.txt",ios::app);
        }
//execution_list.open("execution_list.txt");
if(mode==type::update)
       {
           execution_list<<P1.people_getFname();
       }
       else
       {
           execution_list<<P1.people_getFname()<<" ";
       }
    execution_list<<P1.people_getLname()<<"\n"<<
    P1.people_getAge()<<"\n"<<
    P1.people_getG()<<"\n"<<
    P1.people_getPh()<<"\n"<<
    P1.people_getAdd()<<"\n"<<
    P1.people_getOcc()<<"\n"<<
    P1.people_getHs()<<"\n"<<
    P1.people_getRel()<<"\n"<<
    P1.get_prisoner_ID()<<"\n"<<
    P1.get_prisoner_crime()<<"\n"<<
    P1.get_prisoner_admission_date()<<"\n"<<
    P1.get_prisoner_release_date()<<"\n"<<
    P1.get_prisoner_Psychological_status()<<"\n"<<
    P1.get_prisoner_Job_status()<<"\n"<<
    P1.get_prisoner_jailmate()<<"\n"<<
    P1.get_prisoner_utility_status()<<"\n"<<
    P1.get_prisoner_visiting_status()<<"\n"<<
    P1.get_prisoner_sentence()<<"\n"<<
    P1.get_prisoner_cell_location()<<"\n"<<
    P1.get_prisoner_conduct_guard_statement()<<"\n"<<
    P1.get_prisoner_conduct_staff_statement()<<"\n"<<
    P1.get_prisoner_conduct_solitary_visits()<<"\n"<<
    P1.get_prisoner_conduct_overall()<<"\n"<<
    P1.get_prisoner_conduct_visitor_info()<</*"\nExecution Information:\n\tExecution date: "<<get_prisoner_execution_date()<<"\n\tLast Meal: "<<get_prisoner_execution_last_meal()<<*/"\n"<<
    P1.get_prisoner_greq()<<"\n"<<
    P1.get_prisoner_trial_lawyer()<<"\n"<<
    P1.get_prisoner_trial_evi_info()<<"\n"<<
    P1.get_prisoner_trial_conviction()<<"\n"<<
    P1.get_prisoner_trial_bail()<<"\n"<<
    P1.get_prisoner_trial_release_appeal()<<"\n" <<
    P1.get_prisoner_prescription()<<"\n"<<
    /*P1.get_to_be_executed_last_meal()<<"\n"<<
    P1.get_to_be_executed_execution_date()<<"\n"<<*/
    std::endl;
    execution_list.close();
}

void Bookkeeper::write_finance_in_file(Finance F1)
{
    ofstream execution_list("finance.txt",ios::app);
    execution_list<<
    F1.getQuarter()<<"\n"<<
    F1.getStipend()<<"\n"<<
    F1.getSales()<<"\n"<<
    F1.getBail()<<"\n"<<
    F1.getLease()<<"\n"<<
    F1.getMaintenance()<<"\n"<<
    F1.getFood()<<"\n"<<
    F1.getSalary()<<"\n"<<
    F1.getEdu()<<"\n"<<
    F1.getLaundry()<<"\n"<<
    F1.getMisc()<<"\n"<<
    std::endl;
	execution_list.close();
}

void Bookkeeper::update_people(int *flag3,char fname[],int *A, char g[],char ad[],char p[],char o[],char hs[],char r[],char id[],int* u_i,char identification[],char att[],char attribute[])
{

     if(strcmp(attribute,"name")==0)
            {
            strcpy(fname,att);
            *flag3=1;
            }

            else if(strcmp(attribute,"age")==0)
            {*A=*u_i;
              *flag3=1;
            }

        else if(strcmp(attribute,"gender")==0)
            {      *flag3=1;
                strcpy(g,att);}
        else if(strcmp(attribute,"address")==0)
            {strcpy(ad,att);
              *flag3=1;
            }
        else if(strcmp(attribute,"phone")==0)
           {strcpy(p,att);
             *flag3=1;
           }
        else if(strcmp(attribute,"occupation")==0)
           {strcpy(o,att);
             *flag3=1;
           }
        else if(strcmp(attribute,"health status")==0)
           {strcpy(hs,att);
             *flag3=1;
           }
        else if(strcmp(attribute,"religion")==0)
            {strcpy(r,att);
              *flag3=1;
            }
        else if(strcmp(attribute,"id")==0)
            {strcpy(id,att);
              *flag3=1;
            }

}


void Bookkeeper::update_work(int *flag3,char rank[],char shift[],int*experience,int*u_i,double*salary,double*u_double,char attribute[],char id[],char u[],char att[])
{
    //cout<<"test"<<endl;

              if(strcmp(attribute,"rank")==0)
           {strcpy(rank,att);
             *flag3=1;
           }
        else if(strcmp(attribute,"shift")==0)
            {strcpy(shift,att);
              *flag3=1;
            }
        else if(strcmp(attribute,"experience")==0)
            {*experience=*u_i;
              *flag3=1;
            }
        else if(strcmp(attribute,"salary")==0)
            {*salary=*u_double;
              *flag3=1;
            }

}

void Bookkeeper::update_prisoner(int *flag3,char Crime[],char Sentence[],char Location_of_cell[],char Admission_date[],char Release_date[], char Guard_statement[],char Staff_statement[],int *solitary_confinement_visits,char Overall_evaluation[],char Visitor_Info[],char General_request[],char Psychological_status[],char Job_status[],char Jailmate[],char Lawyer[],char Evidence_info[],char Conviction_date[],int *Bail_amount,char Appeal_for_release_status[],char Utility_status[], char prescription[], char Visiting_status[],char att[],char attribute[],int*u_i,char u[],char id[])
{

              if(strcmp(attribute,"crime")==0)
               {strcpy(Crime,att);
                 *flag3=1;
               }
        else if(strcmp(attribute,"sentence")==0)
            {strcpy(Sentence,att);
              *flag3=1;
            }
        else if(strcmp(attribute,"location of cell")==0)
             {strcpy(Location_of_cell,att);
               *flag3=1;
             }
        else if(strcmp(attribute,"admission date")==0)
            {    //cout<<"success"<<endl;
                strcpy(Admission_date,att);
                *flag3=1;
            }
        else if(strcmp(attribute,"release date")==0)
             {strcpy(Release_date,att);
               *flag3=1;
             }
        else if(strcmp(attribute,"guard statement")==0)
             {strcpy(Guard_statement,att);
               *flag3=1;
             }
        else if(strcmp(attribute,"staff statement")==0)
             {strcpy(Staff_statement,att);
               *flag3=1;
             }
        else if(strcmp(attribute,"solitary confinement visits")==0)
                {*solitary_confinement_visits=*u_i;
                  *flag3=1;
                }
        else if(strcmp(attribute,"overall evaluation")==0)
             {strcpy(Overall_evaluation,att);
               *flag3=1;
             }
        else if(strcmp(attribute,"visitor info")==0)
             {strcpy(Visitor_Info,att);
               *flag3=1;
             }
        else if(strcmp(attribute,"general request")==0)
             {strcpy(General_request,att);
               *flag3=1;
             }
        else if(strcmp(attribute,"psychological status")==0)
             {strcpy(Psychological_status,att);
               *flag3=1;
             }
        else if(strcmp(attribute,"job status")==0)
             {strcpy(Job_status,att);
               *flag3=1;
             }
        else if(strcmp(attribute,"jail mate")==0)
             {strcpy(Jailmate,att);
               *flag3=1;
             }
        else if(strcmp(attribute,"lawyer")==0)
             {strcpy(Lawyer,att);
               *flag3=1;
             }
        else if(strcmp(attribute,"evidence info")==0)
             {strcpy(Evidence_info,att);
               *flag3=1;
             }
        else if(strcmp(attribute,"conviction date")==0)
             {strcpy(Conviction_date,att);
               *flag3=1;
             }
        else if(strcmp(attribute,"bail amount")==0)
             {*Bail_amount=*u_i;
             *flag3=1;
             }
        else if(strcmp(attribute,"appeal for release status")==0)
             {strcpy(Appeal_for_release_status,att);
             *flag3=1;
             }
        else if(strcmp(attribute,"utility status")==0)
             {strcpy(Utility_status,att);
             *flag3=1;
             }
        else if(strcmp(attribute,"prescription")==0)
             {strcpy(prescription,att);
             *flag3=1;
             }
        else if(strcmp(attribute,"visiting status")==0)
             {strcpy(Visiting_status,att);
             *flag3=1;
             }
        }


void Bookkeeper::update_interface(char u[],char attribute[],char att[],int*u_i,double *u_double)
{

      cout<<"ID or name : ";
      cin.getline(u,30);
      cout<<"Choose attribute (age, experience, bail amount, solitary confinement visits, salary): ";
      cin.getline(attribute,50);
      cout<<"\n new value :"<<endl;
      if(strcmp(attribute,"age")==0||strcmp(attribute,"experience")==0||strcmp(attribute,"bail amount")==0||strcmp(attribute,"solitary confinement visits")==0)
        {cin>>*u_i;
         cout<<*u_i<<endl;
        }
        else if(strcmp(attribute,"salary")==0)
        {
            cin>>*u_double;
        }
      else
        {
            cin.getline(att,150);
         //cin>>att;
        }

}


//Readers



void Bookkeeper::read_Staff_in_file(int mode)
{

	ifstream read_executed("Staff_list.txt");
   // cin.ignore();
    int flag=0;//id match search
    int flag2=0;//id match update
    int flag3=0;//attribute match update
    char identification[100];
    char u[100];

    char attribute[50]="";
    int u_i=0;double u_double=0;char att[150];
    //int identification;

    if (mode==type::search)
    {
        getchar();
        cout<<"ID: ";
        cin.getline(identification,100);
    }
    else if(mode==type::update)
    {
        getchar();
        update_interface(u,attribute,att,&u_i,&u_double);

    }
    while(1)
    {
        string key_string;


        if(!getline (read_executed, key_string))
            {
              break;
            }
    char fname[100]="";

        strcpy(fname,key_string.c_str());

        char lname[10]="";

        char x[3];
        getline (read_executed, key_string);
        stringstream geek1(key_string);
        int A = 0;
        geek1>>A;

        char g[10];
        getline (read_executed, key_string);
        strcpy(g,key_string.c_str());

        char p[14];
        getline (read_executed, key_string);
        strcpy(p,key_string.c_str());

        char ad[40];
        getline (read_executed, key_string);
        strcpy(ad,key_string.c_str());

        char o[30];
        getline (read_executed, key_string);
        strcpy(o,key_string.c_str());

        char hs[50];
        getline (read_executed, key_string);
        strcpy(hs,key_string.c_str());

        char r[15];
        getline (read_executed, key_string);
        strcpy(r,key_string.c_str());


        char id[11];
        getline (read_executed, key_string);
        strcpy(id,key_string.c_str());


        char Profession[50];
        getline (read_executed, key_string);
        strcpy(Profession,key_string.c_str());

        char rank[20];
        getline (read_executed, key_string);
        strcpy(rank,key_string.c_str());

        char shift[20];
        getline (read_executed, key_string);
        strcpy(shift,key_string.c_str());

        char psyche[50];
        getline (read_executed, key_string);
        strcpy(psyche,key_string.c_str());

        char requests[30];
        getline (read_executed, key_string);
        strcpy(requests,key_string.c_str());

        getline (read_executed, key_string);
        stringstream geek(key_string);
        double salary = 0;
        geek>>salary;

        getline (read_executed, key_string);
        stringstream geek2(key_string);
        int experience = 0;
        geek2>>experience;

        getline (read_executed, key_string);
//   cout<<fname<<endl;

        if((strcmp(u, fname) == 0)&&mode==type::update||strcmp(u, id) == 0&&mode==type::update)
        {  cout<<u<<endl;
        if(strcmp(attribute,"psyche")==0)
            {strcpy(psyche,att);
              flag3=1;
            }
        else if(strcmp(attribute,"requests")==0)
            { strcpy(requests,att);
              flag3=1;
            }
        else if(strcmp(attribute,"profession")==0)
            { strcpy(Profession,att);
              flag3=1;
            }
        update_people(&flag3,fname,&A,g,ad,p,o,hs,r,id,&u_i,u,att,attribute);
        update_work(&flag3,rank,shift,&experience,&u_i,&salary,&u_double,attribute,id,u,att);
        flag2=1;
         }



        Staff P1(fname,lname,A,g,ad,p,o,hs,r,id,rank,Profession, shift,psyche,requests, experience,salary);

        if(mode==type::normal)
        {P1.staff_getinfo();
          std::cout<<"\n\n"<<std::endl;
        }
        else if(mode==type::search)
        {
         if(strcmp(identification, id) == 0||strcmp(identification,fname)==0)
        {
           P1.staff_getinfo();
           flag=1;
          break;
        }

        }
        else if(mode==type::update)
        {
          write_Staff_in_file(P1,type::update);
        }


    }
    read_executed.close();
    if(mode==type::update)
    {
        remove("Staff_list.txt");
        rename("temp.txt","Staff_list.txt");
    }

    if(mode==type::search&&flag!=1)
        cout<<"Nothing found"<<endl;

     else if(mode==type::update&&flag2==0)
    cout<<"no account of this id or name exists"<<endl;
        if(mode==type::update&&flag3==0&&flag2!=0)
        cout<<"attribute does not exist"<<endl;

}

void Bookkeeper::read_Guard_in_file(int mode)
{
	ifstream read_executed("Guards_list.txt");
	cin.ignore();
    int flag=0;//id match search
    int flag2=0;//id match update
    int flag3=0;//attribute match update
    char identification[100]="";
    char u[100];//holds id for update

    char attribute[50]="";
    int u_i=0;double u_double=0;char att[150];

    if (mode==type::search)//search interface
    {

        cout<<"ID: ";
        cin.getline(identification,100);
    }
    else if(mode==type::update)//update interface
    {

        update_interface(u,attribute,att,&u_i,&u_double);
    }
    while(1)
    {
        string key_string;


        if(!getline (read_executed, key_string))
            {
              break;
            }
    char fname[100]="";

        strcpy(fname,key_string.c_str());

        char lname[10]="";

        char x[3];
        getline (read_executed, key_string);
        stringstream geek1(key_string);
        int A = 0;
        geek1>>A;

        char g[10];
        getline (read_executed, key_string);
        strcpy(g,key_string.c_str());

        char p[14];
        getline (read_executed, key_string);
        strcpy(p,key_string.c_str());

        char ad[40];
        getline (read_executed, key_string);
        strcpy(ad,key_string.c_str());

        char o[30];
        getline (read_executed, key_string);
        strcpy(o,key_string.c_str());

        char hs[50];
        getline (read_executed, key_string);
        strcpy(hs,key_string.c_str());

        char r[15];
        getline (read_executed, key_string);
        strcpy(r,key_string.c_str());

        char id[11];
        getline (read_executed, key_string);
        strcpy(id,key_string.c_str());

        char unit[50];
        getline (read_executed, key_string);
        strcpy(unit,key_string.c_str());

        char rank[20];
        getline (read_executed, key_string);
        strcpy(rank,key_string.c_str());

        char shift[20];
        getline (read_executed, key_string);
        strcpy(shift,key_string.c_str());


        char psyche_evaluation[40];
        getline (read_executed, key_string);
        strcpy(psyche_evaluation,key_string.c_str());

        char post[30];
        getline (read_executed, key_string);
        strcpy(post,key_string.c_str());

        char ammunition_status[30];
        getline (read_executed, key_string);
        strcpy(ammunition_status,key_string.c_str());


        getline (read_executed, key_string);
        stringstream geek(key_string);
        double salary = 0;
        geek>>salary;

        getline (read_executed, key_string);
        stringstream geek2(key_string);
        int experience = 0;
        geek2>>experience;

        getline (read_executed, key_string);


           if(strcmp(u, id) == 0&&mode==type::update||strcmp(u,fname)==0&&mode==type::update)
           {
               flag2=1;

        update_people(&flag3,fname,&A,g,ad,p,o,hs,r,id,&u_i,u,att,attribute);

        update_work(&flag3,rank,shift,&experience,&u_i,&salary,&u_double,attribute,id,u,att);

           if(strcmp(attribute,"unit")==0)
            {strcpy(unit,att);
            flag3=1;
            }
        else if(strcmp(attribute,"psyche_evaluation")==0)
            {strcpy(psyche_evaluation,att);
            flag3=1;
            }
        else if(strcmp(attribute,"post")==0)
            {strcpy(post,att);
            flag3=1;
            }
        else if(strcmp(attribute,"ammunition_status")==0)
            {strcpy(ammunition_status,att);
            flag3=1;
            }
           }

        Guards P1(fname,lname,A,g,ad,p, o,hs,r,	id, unit, rank,shift,post,ammunition_status,psyche_evaluation, salary, experience);

        if(mode==type::normal)
        {
            P1.guard_getinfo();
        std::cout<<"\n\n"<<std::endl;
        }
        else if(mode==type::search)
        {
         if(strcmp(identification, id) == 0||strcmp(identification,fname)==0)//searching for id
        {
         //cout<<fname<<" "<<strlen(fname)<<endl;
         P1.guard_getinfo();
         flag=1;
          break;
        }

        }
        else if(mode==type::update)
        {
           cout<<"hi"<<endl;
            write_Guard_in_file(P1,type::update); //writing updated version in file
        }
        }

    read_executed.close();
    if(mode==type::search&&flag!=1)
        cout<<"Nothing Found"<<endl;

    if(mode==type::update)//swap new temp file with guard file
     {
        remove("Guards_list.txt");
        rename("temp.txt","Guards_list.txt");
        //cout<<"mission impossible"<<endl;

     }
      if(mode==type::update&&flag2==0)
            cout<<"no account of this id or name exists"<<endl;
          if(mode==type::update&&flag3==0&&flag2!=0)
            cout<<"no attribute of this type exists"<<endl;

}


void Bookkeeper::read_To_be_Executed_from_file(int mode)
{
	char identification[100];
    char u[30];
    char attribute[50];
    char att[150];
    int u_i;
    double u_double;
    int flag=0;//id match search
    int flag2=0;//id match update
    int flag3=0;//attribute match update
   cin.ignore();
    ifstream read_executed("execution_list.txt");
    if (mode==2)
    {

        cout<<"ID: ";

  cin.getline(identification,100);
    }

     else if(mode==type::update)//update interface
    {

        update_interface(u,attribute,att,&u_i,&u_double);

    }

   while(1)
    {
        string key_string;

        char fname[100];
        if(!getline (read_executed, key_string))
            break;
        strcpy(fname,key_string.c_str());

        char lname[10]=" ";

        char x[3];
        getline (read_executed, key_string);
        stringstream geek1(key_string);
        int A = 0;
        geek1>>A;

        char g[10];
        getline (read_executed, key_string);
        strcpy(g,key_string.c_str());

        char p[14];
        getline (read_executed, key_string);
        strcpy(p,key_string.c_str());

        char ad[40];
        getline (read_executed, key_string);
        strcpy(ad,key_string.c_str());

        char o[30];
        getline (read_executed, key_string);
        strcpy(o,key_string.c_str());

        char hs[50];
        getline (read_executed, key_string);
        strcpy(hs,key_string.c_str());

        char r[15];
        getline (read_executed, key_string);
        strcpy(r,key_string.c_str());

        char id[11];
        getline (read_executed, key_string);
        strcpy(id,key_string.c_str());

        char Crime[50];
        getline (read_executed, key_string);
        strcpy(Crime,key_string.c_str());

        char Admission_date[20];
        getline (read_executed, key_string);
        strcpy(Admission_date,key_string.c_str());

        char Release_date[20];
        getline (read_executed, key_string);
        strcpy(Release_date,key_string.c_str());

        char Psychological_status[50];
        getline (read_executed, key_string);
        strcpy(Psychological_status,key_string.c_str());

        char Job_status[30];
        getline (read_executed, key_string);
        strcpy(Job_status,key_string.c_str());

        char Jailmate[25];
        getline (read_executed, key_string);
        strcpy(Jailmate,key_string.c_str());

        char Utility_status[40];
        getline (read_executed, key_string);
        strcpy(Utility_status,key_string.c_str());

        char Visiting_status[40];
        getline (read_executed, key_string);
        strcpy(Visiting_status,key_string.c_str());

        char Sentence[40];
        getline (read_executed, key_string);
        strcpy(Sentence,key_string.c_str());

        char Location_of_cell[20];
        getline (read_executed, key_string);
        strcpy(Location_of_cell,key_string.c_str());

        char Guard_statement[150];
        getline (read_executed, key_string);
        strcpy(Guard_statement,key_string.c_str());

        char Staff_statement[150];
        getline (read_executed, key_string);
        strcpy(Staff_statement,key_string.c_str());

        getline (read_executed, key_string);
        stringstream geek(key_string);
        int solitary_confinement_visits = 0;
        geek>>solitary_confinement_visits;

        char Overall_evaluation[150];
        getline (read_executed, key_string);
        strcpy(Overall_evaluation,key_string.c_str());

        char Visitor_Info[50];
        getline (read_executed, key_string);
        strcpy(Visitor_Info,key_string.c_str());

        char General_request[150];
        getline (read_executed, key_string);
        strcpy(General_request,key_string.c_str());

        char Lawyer[25];
        getline (read_executed, key_string);
        strcpy(Lawyer,key_string.c_str());

        char Evidence_info[150];
        getline (read_executed, key_string);
        strcpy(Evidence_info,key_string.c_str());

        char Conviction_date[20];
        getline (read_executed, key_string);
        strcpy(Conviction_date,key_string.c_str());

        getline (read_executed, key_string);
        stringstream geek2(key_string);
        int Bail_amount = 0;
        geek2>>Bail_amount;

        char Appeal_for_release_status[30];
        getline (read_executed, key_string);
        strcpy(Appeal_for_release_status,key_string.c_str());

        char prescription[60];
        getline (read_executed, key_string);
        strcpy(prescription,key_string.c_str());

        char last_meal[35];
        getline (read_executed, key_string);
        strcpy(last_meal,key_string.c_str());

        char execution_date[20];
        getline (read_executed, key_string);
        strcpy(execution_date,key_string.c_str());

        getline (read_executed, key_string);

        if(mode==type::update)
        {
            if((strcmp(u, id) == 0&&mode==3)||(strcmp(u, fname) == 0&&mode==3))
            {
                flag2=1;
                update_people(&flag3,fname,&A,g,ad,p,o,hs,r,id,&u_i,u,att,attribute);
                update_prisoner(&flag3,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,&solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,&Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status,att,attribute,&u_i,u,id);
                if(strcmp(attribute,"last meal")==0)
                    {strcpy(last_meal,att);
                    flag3=1;
                    }
                else if(strcmp(attribute,"execution date")==0)
                    {strcpy(execution_date,att);
                    flag3=1;
                    }
               }
               }

        To_be_Executed P1(fname,lname,A,g,ad,p,o,hs,r,id,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status,last_meal,execution_date);

    if(mode==type::normal)
        {P1.To_be_Executed_getinfo();
            std::cout<<"\n\n"<<std::endl;
        }


       else if(mode==type::search)
        {
            if(strcmp(identification, id) == 0||strcmp(identification,fname)==0)
                {P1.To_be_Executed_getinfo();
                  flag=1;
                  break;
                }
        }
        else if(mode==3&&flag2==1)
        {
          write_To_be_executed_in_file(P1,3);
        }
    }
    read_executed.close();

     if(mode==type::search&&flag!=1)
        cout<<"Nothing Found"<<endl;
        else if(mode==3&&flag2==1)
        {
            cout<<"done"<<endl;
            remove("execution_list.txt");
            rename("temp.txt","execution_list.txt");

        }
        else if(mode==type::update&&flag2==0)
            cout<<"no account of this id or name exists"<<endl;
       if(mode==type::update&&flag3==0&&flag2!=0)
            cout<<"no attribute of this type exists"<<endl;
}

void Bookkeeper::read_maximum_security_prisoner(int mode)
{
ifstream read_executed("Maximum_security_list.txt");
    char u[30];
    char attribute[50];
    char att[150];
    int u_i;
    double u_double;
    int flag2=0;//id match update
   cin.ignore();
    int flag3=0;//attribute match update
    char identification[100];
    int flag=0;//id match search
    if(mode==type::search)
    {
        cout<<"ID or name: ";
        cin.getline(identification,100);
    }

    else if(mode==type::update)//update interface
    {
    update_interface(u,attribute,att,&u_i,&u_double);
    }
    while(1)
    {
        string key_string;

        char fname[100];
        if(!getline (read_executed, key_string))
            break;
        strcpy(fname,key_string.c_str());

        char lname[10]="";

        char x[3];
        getline (read_executed, key_string);
        stringstream geek1(key_string);
        int A = 0;
        geek1>>A;

        char g[10];
        getline (read_executed, key_string);
        strcpy(g,key_string.c_str());

        char p[14];
        getline (read_executed, key_string);
        strcpy(p,key_string.c_str());

        char ad[40];
        getline (read_executed, key_string);
        strcpy(ad,key_string.c_str());

        char o[30];
        getline (read_executed, key_string);
        strcpy(o,key_string.c_str());

        char hs[50];
        getline (read_executed, key_string);
        strcpy(hs,key_string.c_str());

        char r[15];
        getline (read_executed, key_string);
        strcpy(r,key_string.c_str());

        char id[11];
        getline (read_executed, key_string);
        strcpy(id,key_string.c_str());

        char Crime[50];
        getline (read_executed, key_string);
        strcpy(Crime,key_string.c_str());

        char Admission_date[20];
        getline (read_executed, key_string);
        strcpy(Admission_date,key_string.c_str());

        char Release_date[20];
        getline (read_executed, key_string);
        strcpy(Release_date,key_string.c_str());

        char Psychological_status[50];
        getline (read_executed, key_string);
        strcpy(Psychological_status,key_string.c_str());

        char Job_status[30];
        getline (read_executed, key_string);
        strcpy(Job_status,key_string.c_str());

        char Jailmate[25];
        getline (read_executed, key_string);
        strcpy(Jailmate,key_string.c_str());

        char Utility_status[40];
        getline (read_executed, key_string);
        strcpy(Utility_status,key_string.c_str());

        char Visiting_status[40];
        getline (read_executed, key_string);
        strcpy(Visiting_status,key_string.c_str());

        char Sentence[40];
        getline (read_executed, key_string);
        strcpy(Sentence,key_string.c_str());

        char Location_of_cell[20];
        getline (read_executed, key_string);
        strcpy(Location_of_cell,key_string.c_str());

        char Guard_statement[150];
        getline (read_executed, key_string);
        strcpy(Guard_statement,key_string.c_str());

        char Staff_statement[150];
        getline (read_executed, key_string);
        strcpy(Staff_statement,key_string.c_str());

        getline (read_executed, key_string);
        stringstream geek(key_string);
        int solitary_confinement_visits = 0;
        geek>>solitary_confinement_visits;

        char Overall_evaluation[150];
        getline (read_executed, key_string);
        strcpy(Overall_evaluation,key_string.c_str());

        char Visitor_Info[50];
        getline (read_executed, key_string);
        strcpy(Visitor_Info,key_string.c_str());

        char General_request[150];
        getline (read_executed, key_string);
        strcpy(General_request,key_string.c_str());

        char Lawyer[25];
        getline (read_executed, key_string);
        strcpy(Lawyer,key_string.c_str());

        char Evidence_info[150];
        getline (read_executed, key_string);
        strcpy(Evidence_info,key_string.c_str());

        char Conviction_date[20];
        getline (read_executed, key_string);
        strcpy(Conviction_date,key_string.c_str());

        getline (read_executed, key_string);
        stringstream geek2(key_string);
        int Bail_amount = 0;
        geek2>>Bail_amount;

        char Appeal_for_release_status[30];
        getline (read_executed, key_string);
        strcpy(Appeal_for_release_status,key_string.c_str());

        char prescription[60];
        getline (read_executed, key_string);
        strcpy(prescription,key_string.c_str());

        /*char last_meal[35];
        getline (read_executed, key_string);
        strcpy(last_meal,key_string.c_str());

        char execution_date[20];
        getline (read_executed, key_string);
        strcpy(execution_date,key_string.c_str());*/

        //getline (read_executed, key_string);

        getline (read_executed, key_string);

        if(mode==type::update)
        {

            if((strcmp(u, id) == 0&&mode==3)||(strcmp(u, fname) == 0&&mode==3))
            {
                flag2=1;

                update_people(&flag3,fname,&A,g,ad,p,o,hs,r,id,&u_i,u,att,attribute);
                update_prisoner(&flag3,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,&solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,&Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status,att,attribute,&u_i,u,id);
                cout<<flag3<<endl;
            }
        }

        Maximum_security_prisoner P1(fname,lname,A,g,ad,p,o,hs,r,id,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status);

    if(mode==type::normal)
        {P1.get_prisoner_info();
         std::cout<<"\n\n"<<std::endl;
        }
        else if(mode==type::search)
        {
          if(strcmp(identification, id) == 0||strcmp(identification,fname)==0)
            {
             P1.get_prisoner_info();
             flag=1;
             break;
            }
        }
        else if(mode==type::update&&flag2==1)
        {
            write_maximum_security_prisoner(P1,type::update);
        }


        }

        read_executed.close();

     if(mode==type::search&&flag!=1)
        cout<<"Nothing Found"<<endl;
       if(mode==type::update&&flag2==1)
        {
            cout<<"done"<<flag3<<endl;

            remove("Maximum_security_list.txt");
            rename("temp.txt","Maximum_security_list.txt");

        }
        else if(mode==type::update&&flag2==0)
            cout<<"no account of this id or name exists"<<endl;
        if(mode==type::update&&flag3==0&&flag2!=0)
                cout<<"No attribute of this type found"<<endl;
}

void Bookkeeper::read_medium_security_prisoner(int mode)
{
	char identification[100];int flag=0,u_i,flag2=0;char u[30];char attribute[50];char att[150];double u_double;
    cin.ignore();
    int flag3=0;

    ifstream read_executed("Medium_security_list.txt");
    if(mode==type::search)
    {
        cout<<"ID or name: ";
        cin.getline(identification,100);
    }

    else if(mode==type::update)//update interface
    {
     update_interface(u,attribute,att,&u_i,&u_double);
    }

    while(1)
    {
        string key_string;

        char fname[100];
        if(!getline (read_executed, key_string))
            break;
        strcpy(fname,key_string.c_str());

        char lname[10]="";

        char x[3];
        getline (read_executed, key_string);
        stringstream geek1(key_string);
        int A = 0;
        geek1>>A;

        char g[10];
        getline (read_executed, key_string);
        strcpy(g,key_string.c_str());

        char p[14];
        getline (read_executed, key_string);
        strcpy(p,key_string.c_str());

        char ad[40];
        getline (read_executed, key_string);
        strcpy(ad,key_string.c_str());

        char o[30];
        getline (read_executed, key_string);
        strcpy(o,key_string.c_str());

        char hs[50];
        getline (read_executed, key_string);
        strcpy(hs,key_string.c_str());

        char r[15];
        getline (read_executed, key_string);
        strcpy(r,key_string.c_str());

        char id[11];
        getline (read_executed, key_string);
        strcpy(id,key_string.c_str());

        char Crime[50];
        getline (read_executed, key_string);
        strcpy(Crime,key_string.c_str());

        char Admission_date[20];
        getline (read_executed, key_string);
        strcpy(Admission_date,key_string.c_str());

        char Release_date[20];
        getline (read_executed, key_string);
        strcpy(Release_date,key_string.c_str());

        char Psychological_status[50];
        getline (read_executed, key_string);
        strcpy(Psychological_status,key_string.c_str());

        char Job_status[30];
        getline (read_executed, key_string);
        strcpy(Job_status,key_string.c_str());

        char Jailmate[25];
        getline (read_executed, key_string);
        strcpy(Jailmate,key_string.c_str());

        char Utility_status[40];
        getline (read_executed, key_string);
        strcpy(Utility_status,key_string.c_str());

        char Visiting_status[40];
        getline (read_executed, key_string);
        strcpy(Visiting_status,key_string.c_str());

        char Sentence[40];
        getline (read_executed, key_string);
        strcpy(Sentence,key_string.c_str());

        char Location_of_cell[20];
        getline (read_executed, key_string);
        strcpy(Location_of_cell,key_string.c_str());

        char Guard_statement[150];
        getline (read_executed, key_string);
        strcpy(Guard_statement,key_string.c_str());

        char Staff_statement[150];
        getline (read_executed, key_string);
        strcpy(Staff_statement,key_string.c_str());

        getline (read_executed, key_string);
        stringstream geek(key_string);
        int solitary_confinement_visits = 0;
        geek>>solitary_confinement_visits;

        char Overall_evaluation[150];
        getline (read_executed, key_string);
        strcpy(Overall_evaluation,key_string.c_str());

        char Visitor_Info[50];
        getline (read_executed, key_string);
        strcpy(Visitor_Info,key_string.c_str());

        char General_request[150];
        getline (read_executed, key_string);
        strcpy(General_request,key_string.c_str());

        char Lawyer[25];
        getline (read_executed, key_string);
        strcpy(Lawyer,key_string.c_str());

        char Evidence_info[150];
        getline (read_executed, key_string);
        strcpy(Evidence_info,key_string.c_str());

        char Conviction_date[20];
        getline (read_executed, key_string);
        strcpy(Conviction_date,key_string.c_str());

        getline (read_executed, key_string);
        stringstream geek2(key_string);
        int Bail_amount = 0;
        geek2>>Bail_amount;

        char Appeal_for_release_status[30];
        getline (read_executed, key_string);
        strcpy(Appeal_for_release_status,key_string.c_str());

        char prescription[60];
        getline (read_executed, key_string);
        strcpy(prescription,key_string.c_str());

        /*char last_meal[35];
        getline (read_executed, key_string);
        strcpy(last_meal,key_string.c_str());

        char execution_date[20];
        getline (read_executed, key_string);
        strcpy(execution_date,key_string.c_str());*/

        //getline (read_executed, key_string);

        getline (read_executed, key_string);

        if(mode==type::update)
        {
            if((strcmp(u, id) == 0&&mode==3)||(strcmp(u, fname) == 0&&mode==3))
            {
                flag2=1;
                update_people(&flag3,fname,&A,g,ad,p,o,hs,r,id,&u_i,u,att,attribute);
                update_prisoner(&flag3,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,&solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,&Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status,att,attribute,&u_i,u,id);

            }
        }


        Medium_security_prisoner P1(fname,lname,A,g,ad,p,o,hs,r,id,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status);

                if(mode==type::normal)
        {P1.get_prisoner_info();
         std::cout<<"\n\n"<<std::endl;
        }
        else if(mode==type::search)
        {

            if(strcmp(identification,id)==0||strcmp(identification,fname)==0)
                {P1.get_prisoner_info();
                 flag=1;
                 break;
                }
        }
        else if(mode==type::update)
        {
            write_medium_security_prisoner(P1,type::update);
        }

       }

      read_executed.close();
  if(mode==type::search&&flag!=1)
    cout<<"Nothing Found"<<endl;
    else if(mode==type::update&&flag2==1)
        {

            remove("Medium_security_list.txt");
            rename("temp.txt","Medium_security_list.txt");

        }
        else if(mode==type::update&&flag2==0)
            cout<<"no account of this id or name exists"<<endl;
            if(mode==type::update&&flag3==0&&flag2!=0)
            cout<<"No attribute of this type found"<<endl;
}

void Bookkeeper::read_minimum_security_prisoner(int mode)
{
	char identification[100];int flag=0,u_i,flag2=0;char u[30];char attribute[50];char att[150];double u_double;
    cin.ignore();
    int flag3=0;//attribute match update

    ifstream read_executed("Minimum_security_list.txt");
    if(mode==type::search)
    {
        cout<<"ID: ";
        cin.getline(identification,100);
    }
     else if(mode==type::update)//update interface
    {
     update_interface(u,attribute,att,&u_i,&u_double);
    }
    while(1)
    {
        string key_string;

        char fname[100];
        if(!getline (read_executed, key_string))
            break;
        strcpy(fname,key_string.c_str());

        char lname[10]="";

        char x[3];
        getline (read_executed, key_string);
        stringstream geek1(key_string);
        int A = 0;
        geek1>>A;

        char g[10];
        getline (read_executed, key_string);
        strcpy(g,key_string.c_str());

        char p[14];
        getline (read_executed, key_string);
        strcpy(p,key_string.c_str());

        char ad[40];
        getline (read_executed, key_string);
        strcpy(ad,key_string.c_str());

        char o[30];
        getline (read_executed, key_string);
        strcpy(o,key_string.c_str());

        char hs[50];
        getline (read_executed, key_string);
        strcpy(hs,key_string.c_str());

        char r[15];
        getline (read_executed, key_string);
        strcpy(r,key_string.c_str());

        char id[11];
        getline (read_executed, key_string);
        strcpy(id,key_string.c_str());

        char Crime[50];
        getline (read_executed, key_string);
        strcpy(Crime,key_string.c_str());

        char Admission_date[20];
        getline (read_executed, key_string);
        strcpy(Admission_date,key_string.c_str());

        char Release_date[20];
        getline (read_executed, key_string);
        strcpy(Release_date,key_string.c_str());

        char Psychological_status[50];
        getline (read_executed, key_string);
        strcpy(Psychological_status,key_string.c_str());

        char Job_status[30];
        getline (read_executed, key_string);
        strcpy(Job_status,key_string.c_str());

        char Jailmate[25];
        getline (read_executed, key_string);
        strcpy(Jailmate,key_string.c_str());

        char Utility_status[40];
        getline (read_executed, key_string);
        strcpy(Utility_status,key_string.c_str());

        char Visiting_status[40];
        getline (read_executed, key_string);
        strcpy(Visiting_status,key_string.c_str());

        char Sentence[40];
        getline (read_executed, key_string);
        strcpy(Sentence,key_string.c_str());

        char Location_of_cell[20];
        getline (read_executed, key_string);
        strcpy(Location_of_cell,key_string.c_str());

        char Guard_statement[150];
        getline (read_executed, key_string);
        strcpy(Guard_statement,key_string.c_str());

        char Staff_statement[150];
        getline (read_executed, key_string);
        strcpy(Staff_statement,key_string.c_str());

        getline (read_executed, key_string);
        stringstream geek(key_string);
        int solitary_confinement_visits = 0;
        geek>>solitary_confinement_visits;

        char Overall_evaluation[150];
        getline (read_executed, key_string);
        strcpy(Overall_evaluation,key_string.c_str());

        char Visitor_Info[50];
        getline (read_executed, key_string);
        strcpy(Visitor_Info,key_string.c_str());

        char General_request[150];
        getline (read_executed, key_string);
        strcpy(General_request,key_string.c_str());

        char Lawyer[25];
        getline (read_executed, key_string);
        strcpy(Lawyer,key_string.c_str());

        char Evidence_info[150];
        getline (read_executed, key_string);
        strcpy(Evidence_info,key_string.c_str());

        char Conviction_date[20];
        getline (read_executed, key_string);
        strcpy(Conviction_date,key_string.c_str());

        getline (read_executed, key_string);
        stringstream geek2(key_string);
        int Bail_amount = 0;
        geek2>>Bail_amount;

        char Appeal_for_release_status[30];
        getline (read_executed, key_string);
        strcpy(Appeal_for_release_status,key_string.c_str());

        char prescription[60];
        getline (read_executed, key_string);
        strcpy(prescription,key_string.c_str());

        /*char last_meal[35];
        getline (read_executed, key_string);
        strcpy(last_meal,key_string.c_str());

        char execution_date[20];
        getline (read_executed, key_string);
        strcpy(execution_date,key_string.c_str());*/

        //getline (read_executed, key_string);

        getline (read_executed, key_string);


            if((strcmp(u, id) == 0&&mode==type::update)||(strcmp(u, fname) == 0&&mode==type::update))
            {
                flag2=1;
                update_people(&flag3,fname,&A,g,ad,p,o,hs,r,id,&u_i,u,att,attribute);
                update_prisoner(&flag3,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,&solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,&Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status,att,attribute,&u_i,u,id);

            }


        Minimum_security_prisoner P1(fname,lname,A,g,ad,p,o,hs,r,id,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status);
        if(mode==type::normal)
        {P1.get_prisoner_info();
         std::cout<<"\n\n"<<std::endl;
        }

        else if(mode==type::search)
        {
            if(strcmp(identification,id)==0||strcmp(identification,fname)==0)
               {
                 P1.get_prisoner_info();
                 flag=1;
                 break;
               }
        }

 else if(mode==type::update)
        {
            write_minimum_security_prisoner(P1,type::update);
        }


        }
        read_executed.close();
cout<<"flag 3: "<<flag3<<endl;
        if(mode==type::search&&flag!=1)
            cout<<"Nothing found"<<endl;


      if(mode==type::update&&flag2==1)
        {
            cout<<"done"<<endl;
            remove("Minimum_security_list.txt");
            rename("temp.txt","Minimum_security_list.txt");

        }

    else if(mode==type::update&&flag2==0)
        cout<<"no account of this id or name exists"<<endl;

     if(mode==type::update&&flag3==0&&flag2!=0)
        cout<<"no attribute of this type exists"<<endl;



}

void Bookkeeper::read_finance_in_file()
{
    ifstream read_executed("finance.txt");
    while(1)
    {
        string key_string;
        char qName[100];
		if(!getline (read_executed, key_string))
			break;
		strcpy(qName,key_string.c_str());

		getline (read_executed, key_string);
		stringstream geek(key_string);
		double stipend = 0;
		geek>>stipend;

		getline (read_executed, key_string);
		stringstream geek2(key_string);
		double sales = 0;
		geek2>>sales;

		getline (read_executed, key_string);
		stringstream geek3(key_string);
		double bail = 0;
		geek3>>bail;

		getline (read_executed, key_string);
		stringstream geek4(key_string);
		double lease = 0;
		geek4>>lease;

		getline (read_executed, key_string);
		stringstream geek5(key_string);
		double maintenance = 0;
		geek5>>maintenance;

		getline (read_executed, key_string);
		stringstream geek6(key_string);
		double food = 0;
		geek6>>food;

		getline (read_executed, key_string);
		stringstream geek7(key_string);
		double salary = 0;
		geek7>>salary;

		getline (read_executed, key_string);
		stringstream geek8(key_string);
		double edu = 0;
		geek8>>edu;

		getline (read_executed, key_string);
		stringstream geek9(key_string);
		double laundry = 0;
		geek9>>laundry;

		getline (read_executed, key_string);
		stringstream geek10(key_string);
		double misc = 0;
		geek10>>misc;

		getline (read_executed, key_string);

		Finance F1(stipend, sales, bail, lease, maintenance, food, salary, edu, laundry, misc, qName);
		F1.getInfo();
		std::cout<<"\n\n"<<std::endl;
    }
}

