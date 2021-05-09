#include<iostream>
using namespace std;

float func(int t,float itpl_pt,float x[])
{
	float mul = 1;
	for(int i=0;i<=t;i++)
	{
		mul *= (itpl_pt-x[i]);
	}
	return mul;
}

int main()
{
	int n;
	float itpl_pt;
	cout<<"Enter no. of values\n";
	cin>>n;
	float *x=new float[n];
	float **y = new float*[n];
	for(int i=0;i<n;i++)
	{
		y[i]=new float[n+1];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			y[i][j]=0;
		}
	}
	cout<<"\nEnter "<<n<<" values for x:\n";
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	cout<<"\nEnter f(x) for each value of x:\n";
	for(int i=0;i<n;i++)
	{
			cin>>y[i][0];
	}
	cout<<"Enter interpolation point:\n";
	cin>>itpl_pt;
	
	//table formation
	
	for (int i=1;i<n;i++)
	{
		for (int j=0;j<n-i;j++)
		{
			y[j][i] = (y[j+1][i-1]-y[j][i-1])/(x[i+j]-x[j]);
		}
	}
	cout<<"\nDifference table-\n\n";
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			cout<<y[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
	//interpolation formula
	
	float result = y[0][0];
	
	for(int i=1;i<n;i++)
	{
		if(y[0][i]!=0)
			result += (func(i-1,itpl_pt,x)*y[0][i]);
	}
	cout<<"\nResult: "<<result;
	
}
