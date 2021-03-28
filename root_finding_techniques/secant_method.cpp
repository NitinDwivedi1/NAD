#include<iostream>
#include<cmath>
using namespace std;
#define E 0.0001

inline float f(float x)
{
	return x*x*x-x-1;
}

void roots(float a,float b)
{
	if(f(a)*f(b)<0)
	{
		int itr=1;
		float m=(a*f(b)-b*f(a))/(f(b)-f(a));
		cout<<"\nitr\t\ta\t\tb\t\tm\t\tf(m)\n";
		while(fabs(f(m))>=E)
		{
			cout<<"\n"<<itr<<"\t\t"<<a<<"\t\t"<<b<<"\t\t"<<m<<"\t\t"<<f(m);
				a=b;
				b=m;
			m=(a*f(b)-b*f(a))/(f(b)-f(a));
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
	cout<<"Enter range a,b : ";
	cin>>a>>b;
	roots(a,b);
}
