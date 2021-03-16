#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

void division(float x1,int e1,float x2,int e2, float &x,int &e)
{
	
	x=x1/x2;
	e=e1-e2;
	
	if(abs(x)>=1.0)
	{
		x/=10;
		e+=1;
	}
	else if(abs(x)<0.1)
	{
		x*=10;
		e-=1;
	}
	if(e>99)
	{	
		cout<<"\nOverflow!";
		exit(0);
	}
	else if(e<-99)
	{
		cout<<"\nUnderflow!";
		exit(0);
	}
}



int main()
{
	float x1,x2,x;
	int e1,e2,e;
	cout<<"Enter 1st number(mantissa) and its exponential: ";
	cin>>x1>>e1;
	cout<<"\nEntered no. is: "<<x1<<"E"<<e1;
	cout<<"\nEnter 2nd number(mantissa) and its exponential: ";
	cin>>x2>>e2;
	cout<<"\nEntered no. is: "<<x2<<"E"<<e2;
	division(x1,e1,x2,e2,x,e);
	cout<<"\nResultant division is: "<<setprecision(4)<<x<<"E"<<e;
	
	return 0;
	
}
