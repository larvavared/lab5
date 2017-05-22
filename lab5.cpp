#include"lab5.h"
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

ostream & operator << (ostream &out, const HugeInt &a)
{	int i =0;
	while(i<=21){
		if(a.ptr[i]!=0)
		{ for(i;i<22;i++)
		{ out<<a.ptr[i]; } 
		break;} 
		else {i++;}//no 0000..00
	}
	return out;
}

istream & operator >> (istream &in,  HugeInt &a)
{ 	
	long long int f;
	cin >>f ;
	HugeInt m(f);
	for(int i=21;i>=0;i--){
	a.ptr[i] = m.ptr[i];
	}//
	return in; //conti or segment??
}  

//CTOR

HugeInt::HugeInt(long long int x)
{		int a[22];//the max only can have 22 num
	for(int i =0;i<22;i++){
		a[i]=0;
	}  
		ptr = new int[22];
		for(int i=0;i<22;++i)
		 ptr[i] = 0;
			for(int i=21;i>=0&&x!=0;i--){
			a[i]=(x%10);
			x= x/10;} //put x to an array
			for(int i=0;i<22;i++){
			ptr[i]=a[i];	}//put a[] into HugeInt's ptr
}  

HugeInt::HugeInt(string str)
{	int a[22];
	char c[str.length()];
		
		int s =str.length();
		
		for(int i=0; i<str.length(); i++){
          c[i] = str[i];
      }
      
		ptr = new int[22];//
		for(int i=0;i<22;++i)
		 ptr[i] = 0;//
		 
for(int i =0;i<22;i++){
		a[i]=0;
	}  
	for(int j=20;j>=0;j--){
		a[j+1]=c[j]-'0';// 
}		
			
	for(int i=0;i<22;i++){	
	ptr[i]=a[i];}//put a[] into HugeInt's ptr
	


}
//DTOR

HugeInt::~HugeInt() {
}

////
 HugeInt HugeInt ::operator + ( HugeInt &right)
{	
	HugeInt result;
	int temp[22];
	int a[22],b[22];
	memset(a,0,22); //initial a to 0
	memset(b,0,22); //initial b to 0
	memset(temp,0,22); //initial temp to 0
	memset(result.ptr,0,22);
	for(int i=0;i<22;i++){a[i]=this->ptr[i]; b[i]=right.ptr[i];}
	
	int carry=0;//initial carry 0
	
	for(int i=21;i>=0;i--){
	temp[i]=((a[i]+b[i]+carry)%10);
		 //temp 22 num
	carry=(a[i]+b[i]+carry)/10;
	}
	
	
	cout <<endl;
	
	for(int i=0;i<22;i++){result.ptr[i]=temp[i];}
	return result;	
}  // can't castcated



HugeInt HugeInt::operator - ( HugeInt &right)
{	
	HugeInt result;
	int temp[22];
	int a[22],b[22];
	memset(a,0,22); //initial a to 0
	memset(b,0,22); //initial b to 0
	memset(temp,0,22); //initial temp to 0
	memset(result.ptr,0,22);
	for(int i=0;i<22;i++){a[i]=this->ptr[i]; b[i]=right.ptr[i];}
	int borrow=0;//initial borrow 0
	for(int i=21;i>=0;i--){temp[i]=(a[i]-b[i]-borrow);
	if(temp[i]<0){temp[i]+=10; borrow=1;}else {borrow=0;}}
	for(int i=0;i<22;i++){result.ptr[i]=temp[i];}
	return result;	

}	



