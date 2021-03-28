#include<iostream>
#include<cmath>
using namespace std;
#define E 0.0001

inline float f(float x)
{
	return x*x-25;
}
/*
void initializer(float &a,float &b)
{
	int i,v1,v2=0;
	while(!(v1>0&&v2<0 || v1<0&&v2>0))
	{
		a=i;
		b=i+1;
		v1=f(i);
		v2=f(i+1);
		i++;
	}
	
}
*/
void roots(float a,float b)
{
	if(f(a)*f(b)<0)
	{
		int itr=1;
		float m=(a+b)/2;
		cout<<"\nitr\t\ta\t\tb\t\tm\t\tf(m)\n";
		while(fabs(f(m))>=E)
		{
			cout<<"\n"<<itr<<"\t\t"<<a<<"\t\t"<<b<<"\t\t"<<m<<"\t\t"<<f(m);
			if((f(a)*f(m))>0)
				a=m;
			else
				b=m;
			m=(a+b)/2;
			itr++;
		}
		cout<<"\n"<<itr<<"\t\t"<<a<<"\t\t"<<b<<"\t\t"<<m<<"\t\t"<<f(m);
		cout<<"\n\nRoot: "<<m;
	}
	else
		cout<<"Wrong value of a,b entered!!";
}

int main()
{
	float a,b=0;
	//initializer(a,b);
	cout<<"Enter range a,b : ";
	cin>>a>>b;
	roots(a,b);
}
