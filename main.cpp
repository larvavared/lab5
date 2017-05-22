#include<iostream>
#include<string>
#include"lab5.h"
using namespace std;

int main (){
	
HugeInt x;
HugeInt y(28825252);
HugeInt z("314159265358979323846"); // BOOM  (Overflow long long int of my computer)
HugeInt result;

cin >> x;
result = x+y;
cout << x << "+" << y << " = " << result << endl;
result = z - x;
cout << result << endl;
return 0;
} 
