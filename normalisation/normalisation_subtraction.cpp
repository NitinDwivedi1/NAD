#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

void subtraction(float x1,int e1,float x2,int e2, float*x,int*e)
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
	*x=x1-x2;
	
	while(abs(*x)<0.1 && abs(*x)>0.0)
	{
		*x*=10;
		*e-=1;
	}
	
	if(*e<-99)
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
	subtraction(x1,e1,x2,e2,&x,&e);
	cout<<"\nResultant difference is: "<<x<<"E"<<e;
	
	return 0;
	
}
