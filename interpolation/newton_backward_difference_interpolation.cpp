#include<iostream>
using namespace std;


float func(int t,float u)
{
	float mul = 1;
	for(int i=0;i<=t;i++)
	{
		mul *= (u+i);
	}
	return mul;
}

int f(int a)
{
	int factorial=1;
	for(int i=1;i<=a;i++)
	{
		factorial *= i;
	}
	return factorial;
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
			y[j][i] = y[j+1][i-1]-y[j][i-1];
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
	
	float h = x[1]-x[0];
	cout<<"\nh= "<<h;
	float u = (itpl_pt-x[n-1])/h;
	cout<<"\nu= "<<u;
	
	//interpolation formula
	
	float result = y[n-1][0];
	
	for(int i=1;i<n;i++)
	{
		
		result += ((func(i-1,u)/f(i))*y[n-(i+1)][i]);
	}
	cout<<"\nResult: "<<result;
}
