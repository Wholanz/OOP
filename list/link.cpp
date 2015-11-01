#include <iostream>
#include <malloc.h>
#include <time.h>
#include <assert.h>
using namespace std;

class link{             //基类
	protected:
	         unsigned length;  //线性表长度
	public:
		link(){ length=0;}

		unsigned getlen(){   //返回长度
			   return length;
		}
		bool isempty(){      //判断是否为空
		       return length == 0;
		}
};


class arr_link: public link    //数组线性表
{
private:
       int x[100];   //最长为100的数组线性表
public:
	void renew(){    //初始化
		length=0;
		return;
	}

	unsigned find(int X) {    //查找某个数字并返回位置
		for(int i=0;i<length;i++){
		    if(x[i]==X) return i;
		return -1;
		}

	}
	void insert(unsigned i=0,int X=0){    //在i位置插入X
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
			for(int j=length;j>i;j--){    //插入位置开始数字后移一位
			    x[j]=x[j-1];
			}
			x[i] = X;
			length++;
		}
	}
	}
	void del(int X){          //删除某个数字
		if(find(X)==-1) return;
		else{
			for(int i=find(X);i<(length-1);i++)
		          x[i]=x[i+1];
		}
		length--;
	}
	void del_pos(unsigned X){  //删除指定位置的数字
		if(X<0||X>=length) {
			cout<<"not exsit"<<endl;
			return;
		}
		else{
           x[X] = -9999;
		}
		length--;
	}
	 int& operator[](const unsigned index){        //下标运算
	                                          assert(index>=0 && index<length);
											  return x[index];   //返回对应的数字
	   }
	 void stack_push(int num){       //栈的放入
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
	 void stack_pop(){  //栈的输出
	      length--;
		  return;
	 }
	 void heap_push(int num){   //堆的插入（本次不要求）
		 if(length==99){
		 cout<<"too many numbers"<<endl;
		 }
		 for(int i=length;x[i/2]<num,i>1;i/=2){
		     x[i] = x[i/2];
		 }
		 x[i] = num;
		 length++;
	 }
     
	 void heap_pop(){   //堆的输出（不要求）
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

class list_link: public link  //链表线性表
{
	int x;   //数字
	list_link* link_next;  //连接下一个节点的指针
	list_link* temp;
	list_link* current;   //当前位置
public:
	list_link(){x=0;link_next=NULL;temp=NULL;current=NULL;} //初始化
	void renew(){   
		x=0;link_next=NULL;temp=NULL;current=NULL;
	}
	list_link* findpre(int X) {   //找到某个数字节点的前一个节点
		for(int i=0;i<length;i++)
			if(x==X) return NULL;
			else if(link_next->x==X) return this;
			else return link_next->findpre(X);
	}
	list_link* find(int X) {   //找到某个数字的节点
		for(int i=0;i<length;i++)
			if(x==X) return this;
			else return link_next->find(X);
	}
	void insert(unsigned i=0,int X=0){   //在i位置插入X
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
	void del(int X){   //删除X
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
	void stack_push(int num){   //栈的插入
		if(current==NULL) current=this;   //一开始将起点作为当前位置
		else {  //插入新节点
			current->link_next = (list_link*)malloc(sizeof(list_link));
			current = current->link_next;
			current->x = 0;
			current->link_next = current->temp = current->current = NULL;
		}
		current ->x=num; //赋值
		length++;
        return;
	}
	void stack_pop(){ //栈的输出
		temp = current;      
	    current = findpre(current->x); //将当前位置置为倒数第二个节点
		if(temp==this) renew();  //如果返回到初始位置无法释放内存，则用renew函数刷新
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

   
   cout<<"1.stack use array"<<endl;  //测试用数组表示的线性表
   cout<<"2.stack use list"<<endl;   //测试用链表表示的线性表
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
