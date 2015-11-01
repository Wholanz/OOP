#include <iostream>
#include <malloc.h>
#include <time.h>
#include <assert.h>
using namespace std;

class link{             //����
	protected:
	         unsigned length;  //���Ա���
	public:
		link(){ length=0;}

		unsigned getlen(){   //���س���
			   return length;
		}
		bool isempty(){      //�ж��Ƿ�Ϊ��
		       return length == 0;
		}
};


class arr_link: public link    //�������Ա�
{
private:
       int x[100];   //�Ϊ100���������Ա�
public:
	void renew(){    //��ʼ��
		length=0;
		return;
	}

	unsigned find(int X) {    //����ĳ�����ֲ�����λ��
		for(int i=0;i<length;i++){
		    if(x[i]==X) return i;
		return -1;
		}

	}
	void insert(unsigned i=0,int X=0){    //��iλ�ò���X
		if(find(X)==-1) {
		if(length>=100){
		    cout<<"too many numbers"<<endl;	
			return;
		}

		if(i>=getlen()) {
		   x[length]=X;
		   length++;
		}
		else{
			for(int j=length;j>i;j--){    //����λ�ÿ�ʼ���ֺ���һλ
			    x[j]=x[j-1];
			}
			x[i] = X;
			length++;
		}
	}
	}
	void del(int X){          //ɾ��ĳ������
		if(find(X)==-1) return;
		else{
			for(int i=find(X);i<(length-1);i++)
		          x[i]=x[i+1];
		}
		length--;
	}
	void del_pos(unsigned X){  //ɾ��ָ��λ�õ�����
		if(X<0||X>=length) {
			cout<<"not exsit"<<endl;
			return;
		}
		else{
           x[X] = -9999;
		}
		length--;
	}
	 int& operator[](const unsigned index){        //�±�����
	                                          assert(index>=0 && index<length);
											  return x[index];   //���ض�Ӧ������
	   }
	 void stack_push(int num){       //ջ�ķ���
		 if(length==100){
		 cout<<"too many numbers"<<endl;
		 return;
		 }
		 else {
			  length++;
			 x[length-1]=num;
		 }

		 return;
	 }
	 void stack_pop(){  //ջ�����
	      length--;
		  return;
	 }
	 void heap_push(int num){   //�ѵĲ��루���β�Ҫ��
		 if(length==99){
		 cout<<"too many numbers"<<endl;
		 }
		 for(int i=length;x[i/2]<num,i>1;i/=2){
		     x[i] = x[i/2];
		 }
		 x[i] = num;
		 length++;
	 }
     
	 void heap_pop(){   //�ѵ��������Ҫ��
		 int child;
		 if(isempty()){
		  cout<<"heap is empty"<<endl;
		  return;
		 }
		 else {
			 for(int i=1;i*2>length;i = child){
				 if(x[i*2]<=x[i*2+1]){
				   child = i*2;
				  if(x[child]<=x[length])
				   x[i]=x[i*2];
				  else {
				   x[i] = x[length];
				   break;
				  }
				 }
				 else{
					 child = i*2+1;
					 if(x[child<x[length]])
					 x[i] = x[i*2+1];
					 else{
					 x[i] = x[length];
					 break;
					 }
	
				 }
				 length--;
			 }
		 }
	 }

};

class list_link: public link  //�������Ա�
{
	int x;   //����
	list_link* link_next;  //������һ���ڵ��ָ��
	list_link* temp;
	list_link* current;   //��ǰλ��
public:
	list_link(){x=0;link_next=NULL;temp=NULL;current=NULL;} //��ʼ��
	void renew(){   
		x=0;link_next=NULL;temp=NULL;current=NULL;
	}
	list_link* findpre(int X) {   //�ҵ�ĳ�����ֽڵ��ǰһ���ڵ�
		for(int i=0;i<length;i++)
			if(x==X) return NULL;
			else if(link_next->x==X) return this;
			else return link_next->findpre(X);
	}
	list_link* find(int X) {   //�ҵ�ĳ�����ֵĽڵ�
		for(int i=0;i<length;i++)
			if(x==X) return this;
			else return link_next->find(X);
	}
	void insert(unsigned i=0,int X=0){   //��iλ�ò���X
		if(find(X)!=NULL) {
			cout<<"the number exists"<<endl;
			return;
		}
		else if(i==1) {
            temp = (list_link*)malloc(sizeof(list_link));
			temp->x = X;
			temp->link_next = this->link_next->link_next;
			length++;
			this->link_next=temp;
			return;
		}
		else if(i==0) {
            temp = (list_link*)malloc(sizeof(list_link));
			temp->x = X;
			temp->link_next = this->link_next;
			length++;
			link_next=NULL;
			return;
		}
		else link_next->insert(i-1,X);
		return;
	}
	void del(int X){   //ɾ��X
		if(find(X)==NULL){
		   cout<<"not exist"<<endl;
		   return;
		}
		else {
		  findpre(X)->link_next = find(X)->link_next;
		  free(find(X));
		  length--;
		}

	}
	void stack_push(int num){   //ջ�Ĳ���
		if(current==NULL) current=this;   //һ��ʼ�������Ϊ��ǰλ��
		else {  //�����½ڵ�
			current->link_next = (list_link*)malloc(sizeof(list_link));
			current = current->link_next;
			current->x = 0;
			current->link_next = current->temp = current->current = NULL;
		}
		current ->x=num; //��ֵ
		length++;
        return;
	}
	void stack_pop(){ //ջ�����
		temp = current;      
	    current = findpre(current->x); //����ǰλ����Ϊ�����ڶ����ڵ�
		if(temp==this) renew();  //������ص���ʼλ���޷��ͷ��ڴ棬����renew����ˢ��
		else free(temp);   
		length--;
	}
    


};



int main(){
   clock_t start,end;
   int  choose=-1;
   int i,j;
   arr_link a_test;
   list_link l_test;
   double time;

   
   cout<<"1.stack use array"<<endl;  //�����������ʾ�����Ա�
   cout<<"2.stack use list"<<endl;   //�����������ʾ�����Ա�
   cout<<"0.Exit"<<endl;

   while(choose!=0){
   cin>>choose;
 
   switch(choose) {
    case 0: 
	   exit(0);
	   break;
	case 1:

        a_test.renew();

		start = clock();
		for(j=0;j<1000;j++){	for( i=0;i<100;i++){
		       a_test.stack_push(i);
			}
			for(i=0;i<100;i++){
		      a_test.stack_pop();
			}
			a_test.renew();
		}
		end = clock();
		time = (end*1.0 - start*1.0)/1000;
		cout<<"time cost is ";
		cout<<time<<endl;
		break;

	case 2:
		l_test.renew();
		start = clock();
		for(j=0;j<1000;j++){
			for(i=0;i<100;i++){
		   l_test.stack_push(i);
		}
		for(i=0;i<100;i++){
		   l_test.stack_pop();
		}
		l_test.renew();
		}
		end = clock();
		time = (end*1.0 - start*1.0)/1000;
		cout<<"time cost is ";
		cout<<time<<endl;
		break;
 
	    default: cout<<"Wrong input!"<<endl;
   }
   }
		return 0;

}
