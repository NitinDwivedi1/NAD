#include<iostream>
using namespace std;

int main()
{
	int a,b,n;
	cout<<"Enter upper limit and lower limit as 'a' and 'b': \n";
	cin>>a>>b;
	cout<<"Enter 'n': \n";
	cin>>n;
	float *x = new float[n];
	float *y = new float[n];
	cout<<"Enter values of X: \n";
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	cout<<"Enter corresponding values of Y: \n";
	for(int i=0;i<n;i++)
	{
		cin>>y[i];
	}
	
	float h = x[1]-x[0];
	
	float sum = y[0]+y[n-1];
	
	for(int i=1;i<n-1;i++)
	{
		if(i%2==0)
			sum += (2*y[i]);
		else
			sum += (4*y[i]);
	}
	
	float integral = (sum*h)/3;
	cout<<"Integral is: "<<integral;
}
