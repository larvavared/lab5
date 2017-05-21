#include<iostream>
#include<string>
using namespace std;


class HugeInt{
	friend ostream & operator << (ostream &, const HugeInt &);
	friend istream & operator >> (istream &,  HugeInt &); //  HugeInt can't const
	
	public:
		HugeInt (long long int = 28825252); //ctor
		HugeInt (string); //ctor
		~HugeInt(); //dtor
		HugeInt  operator + ( HugeInt &right);
		HugeInt  operator - ( HugeInt &right);
	private:
		long long int x;
		string y;
};
