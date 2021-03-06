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

	std::cout<<"\nDo you want to Read(1) or Write(2) or Search(3) or Finances(4)"<<std::endl;
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
				read_maximum_security_prisoner(1);
			}
			else if(x==2)
			{
				read_medium_security_prisoner(1);
			}
			else if(x==3)
			{
				read_minimum_security_prisoner(1);
			}
			else if(x==4)
			{
				read_To_be_Executed_from_file(1);
			}
		}
		else if(x==3)
		{
			read_Staff_in_file(1);
		}
		else if(x==2)
		{
			read_Guard_in_file(1);
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
              read_To_be_Executed_from_file(2);
            }
            if(x==1)
            {
                read_maximum_security_prisoner(2);
            }
            else if(x==2)
            {
                read_medium_security_prisoner(2);
            }
            else if(x==3)
            {
                read_minimum_security_prisoner(2);
            }

       }

    }
    else if(x == 4)
    {
        std::cout<<"\nWrite Financial data(1), Read Financial data(2)"<<std::endl;
        std::cin>>x;
        if(x == 1)
        {
            /** if the text file is empty, then user is prompted to enter old data before entering present financial data*/
            std::ifstream ifs("finance.txt", std::ios::ate); // std::ios::ate means open at end
            if(ifs.tellg() == 0)
            {
                // file is empty
                std::cout<<"It appears that there are no records of previous data.\nPlease enter some previous data before entering new data.\n";
                std::cout<<"\nHow many instances of old data would you like to enter?\n";
                int n;
                std::cin>>n;
                for(int i = 0; i < n; i++)
                {
                    Bookkeeper::input_old_Finance();
                }
            }
            std::cout<<"\nPlease enter current data";
            Bookkeeper::input_Finance();
        }
        else if(x == 2)
        {
            Bookkeeper::read_finance_in_file();
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
	write_Guard_in_file(P1);
}

void Bookkeeper::input_Staff()
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
	write_Staff_in_file(P1);
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
		write_To_be_executed_in_file(P1);

		return;
	}

	else if(isIn(Crime, whiteCollarCrimes, sizeof(whiteCollarCrimes) / sizeof(whiteCollarCrimes[0])) && !strcmp(g,"Male"))
	{
		char Location_of_cell[11] = "North Wing";

		Minimum_security_prisoner P1(fname,lname,A,g,ad,p,o,hs,r,id,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status);
		P1.get_prisoner_info();
		write_minimum_security_prisoner(P1);

		return;
	}

	else if(isIn(Crime, violentCrimes, sizeof(violentCrimes) / sizeof(violentCrimes[0]))&&!strcmp(g,"Male"))
	{
		char Location_of_cell[11] = "South Wing";

		Maximum_security_prisoner P1(fname,lname,A,g,ad,p,o,hs,r,id,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status);
		P1.get_prisoner_info();
		write_maximum_security_prisoner(P1);

		return;
	}

	else if(isIn(Crime, lessViolentCrimes, sizeof(lessViolentCrimes) / sizeof(lessViolentCrimes[0]))&&!strcmp(g,"Male"))
	{
		char Location_of_cell[11] = "East Wing";

		Medium_security_prisoner P1(fname,lname,A,g,ad,p,o,hs,r,id,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status);
		P1.get_prisoner_info();
		write_medium_security_prisoner(P1);

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
            write_minimum_security_prisoner(P1);
            return;
        }
        else if(lowerCompare(Location_of_cell, "south wing"))
        {
            strcpy(Location_of_cell, "South Wing");
            Maximum_security_prisoner P1(fname,lname,A,g,ad,p,o,hs,r,id,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status);
            P1.get_prisoner_info();
            write_maximum_security_prisoner(P1);
            return;
        }
        else if(lowerCompare(Location_of_cell, "east wing"))
        {
            strcpy(Location_of_cell, "East Wing");
            Medium_security_prisoner P1(fname,lname,A,g,ad,p,o,hs,r,id,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status);
            P1.get_prisoner_info();
            write_medium_security_prisoner(P1);
            return;
        }
        else
        {
            // defaults to north wing
            strcpy(Location_of_cell, "North Wing");
            Minimum_security_prisoner P1(fname,lname,A,g,ad,p,o,hs,r,id,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status);
            P1.get_prisoner_info();
            write_minimum_security_prisoner(P1);
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

void Bookkeeper::input_old_Finance()
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

    double bail;
	/**For not letting the user input anything other than the intended output*/
	while (std::cout << "\nEnter Total Bail (Double values): " && !(std::cin >> bail))
    {
        std::cin.clear(); //clears bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discards problematic input stored in buffer
        std::cout << "Invalid input. Try again.\n";
    }

    double lease;
	/**For not letting the user input anything other than the intended output*/
	while (std::cout << "\nEnter Sales Revenue (Double values): " && !(std::cin >> lease))
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

    double salary;
	/**For not letting the user input anything other than the intended output*/
	while (std::cout << "\nEnter Total Salary cost (Double values): " && !(std::cin >> salary))
    {
        std::cin.clear(); //clears bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discards problematic input stored in buffer
        std::cout << "Invalid input. Try again.\n";
    }

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
void Bookkeeper::write_Staff_in_file(Staff P1)
{
	ofstream execution_list("Staff_list.txt",ios::app);
	//execution_list.open("execution_list.txt");
	execution_list<<
	P1.people_getFname()<<" "<<
	P1.people_getLname()<<"\n"<<
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
void Bookkeeper::write_Guard_in_file(Guards P1)
{
	ofstream execution_list("Guards_list.txt",ios::app);
	//execution_list.open("execution_list.txt");
	execution_list<<
	P1.people_getFname()<<" "<<
	P1.people_getLname()<<"\n"<<
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

void Bookkeeper:: write_To_be_executed_in_file(To_be_Executed P1)
{
	ofstream execution_list("execution_list.txt",ios::app);
	//execution_list.open("execution_list.txt");
	execution_list<<
	P1.people_getFname()<<" "<<
	P1.people_getLname()<<"\n"<<
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

void Bookkeeper:: write_maximum_security_prisoner(Maximum_security_prisoner P1)
{
	ofstream execution_list("Maximum_security_list.txt",ios::app);
	//execution_list.open("execution_list.txt");
	execution_list<<
	P1.people_getFname()<<" "<<
	P1.people_getLname()<<"\n"<<
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

void Bookkeeper:: write_medium_security_prisoner(Medium_security_prisoner P1)
{
	ofstream execution_list("Medium_security_list.txt",ios::app);
	//execution_list.open("execution_list.txt");
	execution_list<<
	P1.people_getFname()<<" "<<
	P1.people_getLname()<<"\n"<<
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

void Bookkeeper:: write_minimum_security_prisoner(Minimum_security_prisoner P1)
{
	ofstream execution_list("Minimum_security_list.txt",ios::app);
	//execution_list.open("execution_list.txt");
	execution_list<<
	P1.people_getFname()<<" "<<
	P1.people_getLname()<<"\n"<<
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


//Readers



void Bookkeeper::read_Staff_in_file(int mode)
{

	ifstream read_executed("Staff_list.txt");
	int flag=0;
	char identification[11];

	if (mode==2)
    {
        cout<<"ID: ";

  cin>>identification;
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

		Staff P1(fname,lname,A, g,ad,p,o,hs,r,id,rank,Profession, shift,  psyche,requests, experience,salary);

		if(mode==1)
		{P1.staff_getinfo();
		  std::cout<<"\n\n"<<std::endl;
		}
        else if(mode==2)
        {
         if(strcmp(identification, id) == 0)
		{P1.staff_getinfo();
		   flag=1;
		  break;
		}

        }


	}
	if(mode==2&&flag!=1)
        cout<<"Nothing found"<<endl;

}

void Bookkeeper::read_Guard_in_file(int mode)
{
	char identification[11];
	int flag=0;
	ifstream read_executed("Guards_list.txt");
	if (mode==2)
    {
        cout<<"ID: ";

  cin>>identification;
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

		Guards P1(fname,lname,A,g,ad,p, o,hs,r,	id, unit, rank,shift,post,ammunition_status,psyche_evaluation, salary, experience);

		if(mode==1)
		{P1.guard_getinfo();
		std::cout<<"\n\n"<<std::endl;
		}
        else if(mode==2)
        {
         if(strcmp(identification, id) == 0)
		{
         P1.guard_getinfo();
		 flag=1;
		  break;
		}

        }


	}
	if(mode==2&&flag!=1)
        cout<<"Nothing Found"<<endl;

}


void Bookkeeper::read_To_be_Executed_from_file(int mode)
{
	char identification[11];
	int flag=0;
	ifstream read_executed("execution_list.txt");
	if (mode==2)
    {
        cout<<"ID: ";

  cin>>identification;
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

		To_be_Executed P1(fname,lname,A,g,ad,p,o,hs,r,id,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status,last_meal,execution_date);

	if(mode==1)
		{P1.To_be_Executed_getinfo();
		 	std::cout<<"\n\n"<<std::endl;
        }


        if(mode==2)
        {
            if(strcmp(identification, id) == 0)
                {P1.To_be_Executed_getinfo();
                  flag=1;
                  break;
                }
        }
	}
     if(mode==2&&flag!=1)
        cout<<"Nothing Found"<<endl;
}

void Bookkeeper::read_maximum_security_prisoner(int mode)
{
ifstream read_executed("Maximum_security_list.txt");
	char identification[11];
	int flag=0;
	if(mode==2)
    {
        cout<<"ID: ";
        cin>>identification;
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

		/*char last_meal[35];
		getline (read_executed, key_string);
		strcpy(last_meal,key_string.c_str());

		char execution_date[20];
		getline (read_executed, key_string);
		strcpy(execution_date,key_string.c_str());*/

		//getline (read_executed, key_string);

		getline (read_executed, key_string);

		Maximum_security_prisoner P1(fname,lname,A,g,ad,p,o,hs,r,id,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status);

	if(mode==1)
		{P1.get_prisoner_info();
		 std::cout<<"\n\n"<<std::endl;
		}
        else if(mode==2)
        {
          if(strcmp(identification, id) == 0)
            {P1.get_prisoner_info();
             flag=1;
             break;
            }
        }


		}

     if(mode==2&&flag!=1)
        cout<<"Nothing Found"<<endl;
}

void Bookkeeper::read_medium_security_prisoner(int mode)
{
	char identification[11];
	int flag=0;
	ifstream read_executed("Medium_security_list.txt");
	if(mode==2)
    {
        cout<<"ID: ";
        cin>>identification;
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

		/*char last_meal[35];
		getline (read_executed, key_string);
		strcpy(last_meal,key_string.c_str());

		char execution_date[20];
		getline (read_executed, key_string);
		strcpy(execution_date,key_string.c_str());*/

		//getline (read_executed, key_string);

		getline (read_executed, key_string);
		Medium_security_prisoner P1(fname,lname,A,g,ad,p,o,hs,r,id,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status);

         		if(mode==1)
        {P1.get_prisoner_info();
         std::cout<<"\n\n"<<std::endl;
        }
        else if(mode==2)
        {
            if(strcmp(identification,id)==0)
                {P1.get_prisoner_info();
                 flag=1;
                 break;
                }
        }
	}
  if(mode==2&&flag!=1)
    cout<<"Nothing Found"<<endl;
}

void Bookkeeper::read_minimum_security_prisoner(int mode)
{
	char identification[11];
	int flag=0;
	ifstream read_executed("Minimum_security_list.txt");
	if(mode==2)
    {
        cout<<"ID: ";
        cin>>identification;
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

		/*char last_meal[35];
		getline (read_executed, key_string);
		strcpy(last_meal,key_string.c_str());

		char execution_date[20];
		getline (read_executed, key_string);
		strcpy(execution_date,key_string.c_str());*/

		//getline (read_executed, key_string);

		getline (read_executed, key_string);
		Minimum_security_prisoner P1(fname,lname,A,g,ad,p,o,hs,r,id,Crime,Sentence,Location_of_cell,Admission_date,Release_date, Guard_statement,Staff_statement,solitary_confinement_visits,Overall_evaluation,Visitor_Info,General_request,Psychological_status,Job_status,Jailmate,Lawyer,Evidence_info,Conviction_date,Bail_amount,Appeal_for_release_status,Utility_status, prescription, Visiting_status);
        if(mode==1)
		{P1.get_prisoner_info();
		std::cout<<"\n\n"<<std::endl;
		}

        else if(mode==2)
        {
            if(strcmp(identification,id)==0)
               {
                 P1.get_prisoner_info();
                 flag=1;
                 break;
               }
        }

        }
        if(mode==2&&flag!=1)
            cout<<"Nothing found"<<endl;

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

