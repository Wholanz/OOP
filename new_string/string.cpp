#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>

class new_string             //string��
{
private:
	    unsigned length;
		char *   str;
public:
	   new_string(){                         //���캯��
		            length = 0;
					str = NULL;
	   }

	   new_string(const new_string& pstr){
                                         length = pstr.length;
										 str = new char[length+1];
										 strcpy(str,pstr.str);
	   }
	   new_string(const char* pstr) {
	                                length = strlen(pstr);
									str = new char[length+1];
									strcpy(str,pstr);
	   }

	   ~new_string(){                 //��������
		             delete[] str;
	   }
	   unsigned getlength(){          //����ַ�������
	                     return length;
	   }
	   char*  getstr(){              //����ַ���
		   return str;
	   }
	   char& operator[](const unsigned index){        //�±�����
	                                          assert(index>=0 && index<=length);
											  return str[index];
	   }
	   const char& operator[](const unsigned index)const{
	                                          assert(index>=0 && index<=length);
											  return str[index];
	   }
	   new_string& operator=(const new_string& pstr){      //��ֵ
		                                        delete[] str;
												length = pstr.length;
												str = new char[pstr.length+1];
												strcpy(str,pstr.str);
												return *this;
	   }
	   new_string substring(unsigned pos,unsigned n){     //�Ӵ���ȡ
	                                                 new_string temp;
													 assert((pos+n)<=length);
													 temp.length = n ;
													 temp.str = new char[n+1];
													 for(unsigned i=0;i<n;i++){
													             (temp.str)[i] = (this->str)[n+i];
													 }
													 (temp.str)[n] ='\0';
													 return temp;
	   }
       friend bool operator==(const new_string& op1,const new_string& op2){     //�ַ����Ƚ�
	                                                               return strcmp(op1.str,op2.str)==0;
	   }
       friend bool operator!=(const new_string& op1,const new_string& op2){
	                                                               return strcmp(op1.str,op2.str)!=0;
	   }
       friend bool operator >(const new_string& op1,const new_string& op2){
	                                                               return strcmp(op1.str,op2.str)>0;
	   }
       friend bool operator >=(const new_string& op1,const new_string& op2){
	                                                               return strcmp(op1.str,op2.str)>=0;
	   }
       friend bool operator <(const new_string& op1,const new_string& op2){
	                                                               return strcmp(op1.str,op2.str)<0;
	   }
       friend bool operator <=(const new_string& op1,const new_string& op2){
	                                                               return strcmp(op1.str,op2.str)<=0;
	   }



};  



main (){
        FILE *fp;
		new_string word[1000];
		new_string temp;
		char* store;
		int i=0,j=0,count;
		
		fp = fopen("t.txt","r");
		
		store = new char[100];
        fscanf(fp,"%s",store);
        while(!feof(fp)){
		word[i++] = store;
		fscanf(fp,"%s",store);
		}
		count=i;
		for(i=0;i<count;i++){      //����
			for(j=0;j<count-i-1;j++){
				if(word[j]>word[j+1]){
				       temp = word[j+1];
					   word[j+1] = word[j];
					   word[j] = temp;
				}
			}
		}
		fclose(fp);

		fp = fopen("out.txt","w");
		for(i=0;i<count;i++){
		   if(i==0) fprintf(fp,"%s\n",word[i].getstr());
		   else if(word[i]!=word[i-1])
		   fprintf(fp,"%s\n",word[i].getstr());
		}  

return 0;
}