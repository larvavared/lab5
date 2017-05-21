#include"lab5.h"
#include<string>
#include<sstream>

using namespace std;

ostream & operator << (ostream &out, const HugeInt &a)
{
	out<<a.x;
	return out;
}

istream & operator >> (istream &in,  HugeInt &a)
{ 
	long long int f ;
	in>>f;
	a.x = f ;
	return in;
}  // need a f // can't dirextly in>>a.x 

//CTOR

HugeInt::HugeInt(long long int a )
		:x(a){
		}  //initial llint x

HugeInt::HugeInt(string a)
{
	istringstream ss(a);
	ss>>x;   // initial string to int <sstring>
}

//DTOR

HugeInt::~HugeInt() {
}

////
HugeInt HugeInt:: operator + ( HugeInt &right)
{	
	HugeInt h;
	h.x = (this->x + right.x); 
	return  h;   
}  // can't castcated



HugeInt HugeInt:: operator - ( HugeInt &right)
{	
	HugeInt h;
	h.x = (this->x - right.x); 
	return h;

}	



