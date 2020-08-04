#ifndef PEOPLE_H
#define PEOPLE_H


class People
{
   protected:
	char* First_Name;
	char* Last_Name;
	int Age;
	char* Gender;
	char* address;
	char* phone_nums;
	char* Occupation;
	char* health_status;
	char* Religion;
public:
	// constructors
	People();
    People(char* fname,char* lname,int A,char* g,char* ad,char* p,char* o,char* hs,char* r);

	// Getters
	char* people_getFname();
	char* people_getLname();
	int people_getAge();
	char* people_getG();
	char* people_getOcc();
	char* people_getAdd();
	char* people_getPh();
	char* people_getHs();
	char* people_getRel();
	void people_getInfo();

	//setters
	void people_setFname(char* fname);
	void people_setLname(char* lname);
	void people_setAge(int A);
	void people_setG(char* g);
	void people_setOcc(char* o);
	void people_setAdd(char* ad);
	void people_setPh(char* p);
	void people_setHs(char* hs);
	void people_setRel(char* r);
	void people_setinfo(char* fname,char* lname,int A,char* g,char* ad,char* p,char* o,char* hs,char* r);
};

#endif // PEOPLE_H
