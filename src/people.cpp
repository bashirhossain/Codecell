#include"people.h"
#include<iostream>
People::People()
{

}
People::People(char* fname,char* lname,int A,char* g,char* ad,char* p,char* o,char* hs,char* r):First_Name(fname),Last_Name(lname),Age(A),Gender(g),address(ad),phone_nums(p),health_status(hs),Religion(r),Occupation(o)
{

}

//Getters
char* People::people_getFname()
{
	return First_Name;
}
char* People::people_getLname()
{
	return Last_Name;
}
int People::people_getAge()
{
	return Age;
}
char* People::people_getG()
{
	return Gender;
}
char* People::people_getOcc()
{
	return Occupation;
}
char* People::people_getAdd()
{
	return address;
}
char* People::people_getPh()
{
	return phone_nums;
}
char* People::people_getHs()
{
	return health_status;
}
char* People::people_getRel()
{
	return Religion;
}
void People::people_getInfo()
{

	std::cout<<"Name: "<<people_getFname()<<" "<<people_getLname()<<"\nAge: "<<people_getAge()<<"\nGender: "<<people_getG()<<"\nContact Info:\n\tPhone: "<<people_getPh()<<"\n\tAddress: "<<people_getAdd()<<"\nOccupation: "<<people_getOcc()<<"\nHealth: "<<people_getHs()<<"\nReligion: "<<people_getRel()<<std::endl;

}

//setters
void People::people_setFname(char* fname)
{
	First_Name = fname;
}
void People::people_setLname(char* lname)
{
	Last_Name = lname;
}
void People::people_setAge(int A)
{
	Age = A;
}
void People::people_setG(char* g)
{
	Gender = g;
}
void People::people_setOcc(char* o)
{
	Occupation = o;
}
void People::people_setAdd(char* ad)
{
	address = ad;
}
void People::people_setPh(char* p)
{
	phone_nums = p;
}
void People::people_setHs(char* hs)
{
	health_status = hs;
}
void People::people_setRel(char* r)
{
	Religion = r;
}
void People::people_setinfo(char* fname,char* lname,int A,char* g,char* ad,char* p,char* o,char* hs,char* r)
{
	people_setFname(fname);
	people_setLname(lname);
	people_setAge(A);
	people_setG(g);
	people_setAdd(ad);
	people_setPh(p);
	people_setOcc(o);
	people_setHs(hs);
	people_setRel(r);
}
