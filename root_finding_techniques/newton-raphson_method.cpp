#include<iostream>
#include<cmath>
using namespace std;
#define E 0.0001

inline float f(float x)
{
	return x*x-x-1;
}
inline float fd(float x)
{
	return 2*x-1;
}

void roots(float b)
{
		int itr=1;
		float m=b-(f(b)/fd(b));
		cout<<"\nitr\t\tb\t\tm\t\tf(m)\n";
		while(fabs(f(m))>=E)
		{
			cout<<"\n"<<itr<<"\t\t"<<b<<"\t\t"<<m<<"\t\t"<<f(m);
			
			b=m;
			m=b-(f(b)/fd(b));
			itr++;
		}
		cout<<"\n"<<itr<<"\t\t"<<b<<"\t\t"<<m<<"\t\t"<<f(m);
		cout<<"\n\nRoot: "<<m;
}

int main()
{
	float b=0;
	cout<<"Enter value of b : ";
	cin>>b;
	roots(b);
}
