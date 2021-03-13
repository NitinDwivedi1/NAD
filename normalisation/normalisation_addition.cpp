#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

void addition(float x1,float e1,float x2,float e2, float*x,float*e)
{
	float k=abs(e1-e2);
	if(e1>e2)
	{
		x2=x2/pow(10,k);
		*e=e1;
	}
	else
	{
		x1=x1/pow(10,k);
		*e=e2;
	}
	*x=x1+x2;
	
	if(*x>=1.0)
	{
		*x/=10;
		*e+=1;
	}
	if(*e>99)
	{
		cout<<"\nOverflow!";
		exit(0);
	}
}



int main()
{
	float x1,e1,x2,e2,x,e;
	cout<<"Enter 1st number(mantissa) and its exponential: ";
	cin>>x1>>e1;
	cout<<"\nEntered no. is: "<<x1<<"E"<<e1;
	cout<<"\nEnter 2nd number(mantissa) and its exponential: ";
	cin>>x2>>e2;
	cout<<"\nEntered no. is: "<<x2<<"E"<<e2;
	addition(x1,e1,x2,e2,&x,&e);
	cout<<"\nResultant sum is: "<<setprecision(4)<<x<<"E"<<e;
	
	return 0;
	
}
