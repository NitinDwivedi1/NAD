#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"Enter no. of equations to be entered\n";
	cin>>n;
	float **equations = new float*[n];
	for(int i=0;i<n;i++)
	{
		equations[i]=new float[n+1];
	}
	cout<<"Enter coefficients and RHS of equations as matrix entries row-wise\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			cin>>equations[i][j];
		}
	}
	cout<<"Augmented matrix is:\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			cout<<equations[i][j]<<"\t";
		}
		cout<<'\n';
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			float term = equations[j][i]/equations[i][i];
			int k=i;
			while(k<=n+1)
			{
				equations[j][k] -= equations[i][k]*term;
				k++;
			}
		}
	}
	
	cout<<"\nFinal matrix is: \n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			cout<<equations[i][j]<<"\t";
		}
		cout<<'\n';
	}
	
	float* x = new float[n];
	x[n-1] = equations[n-1][n]/equations[n-1][n-1];
	for (int i=n-2;i>=0;i--)
	{
		x[i] = equations[i][n];
		for(int j =i+1;j<n;j++)
		{
			x[i] = x[i] - equations[i][j]*x[j];
		}
		x[i] = x[i]/equations[i][i];
	}
	cout<<"\nSolution:\n";
	for(int i=0;i<n;i++)
	{
		cout<<"x"<<i+1<<" = "<<x[i]<<"\n";
	}
}
