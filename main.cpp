#include "mat.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;
using namespace ariel;

int main() {
	int c; int r; char s1; char s2;
	cout<<"enter a odd number for the columns:"<<endl;
	cin>>c;
	cout<<"enter a odd number for the rows:"<<endl;
	cin>>r;
	cout<<"enter the first sign:"<<endl;
	cin>>s1;
	cout<<"enter the second sign:"<<endl;
	cin>>s2;
	cout<<"*****output*****"<<endl;
	cout<<mat(c,r,s1,s2)<<endl;
	return 0;
}