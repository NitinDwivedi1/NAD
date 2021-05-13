#include<iostream>
using namespace std;

inline float f(float x){
	return (1/(1+x*x));}

int main()
{
	float a,b;
	int n;
	cout<<"Enter upper limit and lower limit as 'a' and 'b': \n";
	cin>>a>>b;
	cout<<"Enter 'n': \n";
	cin>>n;
	
	float *x = new float[n+1];
	float *y = new float[n+1];
	
	float d = (b-a)/n;
	x[0] = a;
	x[n-1] = b;
	for(int i=0;i<=n;i++)
	{
		x[i+1] = x[i]+d;
	}
	cout<<"\nValues of x: \n";
	for(int i=0;i<=n;i++)
	{
		cout<<x[i]<<" ";
	}
	
	for(int i=0;i<=n;i++)
	{
		y[i] = f(i);
	}
	cout<<"\nValues of y: \n";
	for(int i=0;i<=n;i++)
	{
		cout<<y[i]<<" ";
	}
	
	float h = x[1]-x[0];
	
	float sum = y[0]+y[n-1];
	
	for(int i=1;i<n-1;i++)
	{
		if(i%3==0)
			sum += (2*y[i]);
		else
			sum += (3*y[i]);
	}
	
	float integral = (sum*3*h)/8;
	cout<<"Integral is: "<<integral;
}
