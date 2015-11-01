#ifndef _person_h_
#define _person_h_
#endif


#include<string.h>


class person{
private:
	char name[20];
	int age;
public:
	person(){ strcpy_s(name,""); age = 0; }
	person(const char* c, const int a){
		strcpy_s(name,c);
		age = a;
	}
	void operator=(const person &p){
	    strcpy_s(name,p.name);
		age = p.age;
	}
	friend ostream& operator <<(ostream& os, const person& p){
		os << "name: " << p.name << ", age: "<<p.age<<endl;
			return os;
	}
};