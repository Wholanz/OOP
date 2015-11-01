#ifndef _template_h_
#define _template_h_
#endif

#include<iostream>
#include<string.h>
using namespace std;


template <class T, int max_size = 100>
class List{
private:
	T element[max_size];
	int size;    //queue size
	int first;   //the first element
	int last;    //the last element
	
public:
	List(){  size = 0; first = 0; last = -1; }
	
	int get_size(){  //get size
		return size;
	}
	bool Is_empty(){  //if empty
		return size == 0;
	}

	T out(){   //dequeue and output function
		try{
			if (size <= 0) throw 0;  //if empty,throw 0
			size--;
			if ((first+1) == max_size){
				first = 0;
				cout << element[max_size - 1] << endl;
				return element[max_size-1];

			}
			else {
				cout << element[first] << endl;
				return element[first++];
			}
		}
		catch (int s){
			if (s == 0){ //if throw 0,output the result
				cout << "The queue is empty!" << endl;
				
			}
		}

	}
	void in(const T &x){  //input function
		try{
			if (size == max_size) throw max_size;  //if the queue is full,throw max_size
			size++;
			if (last == max_size - 1){
				last = 0;
				element[0] = x;
			}
			else{
					element[++last] = x;

			}
			
		}
		catch (int s){
			if (s == max_size)  //if throw max_size,output the result
				cout << "the queue is full!" << endl;
		}

	}
};