#include<iostream>
#include"tem.h"   //the template class 
#include"person.h" //the new type
using namespace std;



int main(){
	List<int, 100> int_l;   //declaration of four types of queue with max size of 100
	List<char, 100> char_l;
	List<char*, 100> string_l;
	List<person, 100> person_l;

	person a("a", 1), b("b", 2), c("c", 3);   //initialization of the new type
	cout << "list of new type:" << endl;      //enqueue and dequeue of 4 types and output the result
	person_l.in(a);
	person_l.in(b);
	person_l.in(c);
	person_l.out();
	person_l.out();
	person_l.out();
	person_l.out();    //output the result when the queue is empty
	cout << "the list of string type:" << endl;
	string_l.in("one");
	string_l.in("two");
	string_l.in("three");
	string_l.out();
	string_l.out();
	string_l.out();
	string_l.out();
	cout << "the list of int type:" << endl;
	int_l.in(1);
	int_l.in(2);
	int_l.in(3);
	int_l.out();
	int_l.out();
	int_l.out();
	int_l.out();
	cout << "the list of char type:" << endl;
	char_l.in('a');
	char_l.in('b');
	char_l.in('c');
	
	char_l.out();
	char_l.out();
	char_l.out();
	char_l.out();


	return 0;
}