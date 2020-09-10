#include"include/prisoner.h"
#include"include/staff.h"
#include"include/to_be_executed.h"
#include"include/bookkeeper.h"
#include"include/People.h"
#include"include/guards.h"
#include"include/maximum_security_prisoner.h"
#include"include/medium_security_prisoner.h"
#include"include/minimum_security_prisoner.h"
#include <fstream>
#include <ios>
#include <sstream>
#include <string>
#include <cstring>
#include<iostream>
#include<windows.h>

using namespace std;

int main()
{
    Bookkeeper B1;
    string title = R"(
   ___         ___       ___    _____
  / __\___   __| | ___  / __\___| | |
 / /  / _ \ / _` |/ _ \/ /  / _ \ | |
/ /__| (_) | (_| |  __/ /__|  __/ | |
\____/\___/ \__,_|\___\____/\___|_|_|
                                     )";


    cout<<"\t\t\t"<<title<<endl<<endl;
    cout<<endl<<endl<<"                         Welcome"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
  B1.login();
  char j;

  cout<<"do you want to make a new account?(y:n)"<<endl;
  cin>>j;
  system("cls");
  if(j=='y')
  {
      B1.make_role();
      j='n';
      cout<<"want to login to your new account?(y:n)"<<endl;
      cin>>j;

      if(j=='y')
      {
          cin.ignore();
          B1.login();
      }
      system("cls");
  }

	while(1)
	{
		B1.Open_book();
		cout<<"More commands?(y/n)"<<endl;
		char x;
		cin>>x;
		if(x=='n')
        {
           cout<<"Want to connect to another account?(y/n)"<<endl;
           cin>>x;
           if(x=='n')
            break;
            else
          {system("cls");
          cin.ignore();
           B1.login();
           }
        }
        system("cls");  // this is a very bad way to do this and everybody hates it.
	}
	return 0;
}
