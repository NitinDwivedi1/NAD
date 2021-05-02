#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	int cnt=0;
	int max_itr;
	float E;
	float sum;
	float temp=0;
	float* new_x = new float[n];
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
	//main process
	cout<<"Enter maximum iterations and tolerable error\n";
	cin>>max_itr>>E;
	for(int i=0;i<n;i++)
	{
		new_x[i]=0;
	}
	while(cnt<=max_itr)
	{
		for(int j=0;j<n;j++)
		{
			sum=equations[j][n];
			for(int k=0;k<n;k++)
			{
				if(j!=k)
				{
					sum -= equations[j][k]*new_x[j];
					new_x[j]= sum/equations[j][j];
				}
			}
				
			if(fabs(new_x[j]-temp/temp)<=E)
			{
				for(int c=0;c<n;c++)
					cout<<"x"<<c+1<<" = "<<new_x[c]<<"\t";
				cout<<"\n";
				return(0);
			}
			else
				temp = new_x[j];
			
		}
		cnt++;
	}
	cout<<"\nSolution does not converges in given steps";	
}
