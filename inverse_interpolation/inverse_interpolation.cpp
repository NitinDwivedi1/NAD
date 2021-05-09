#include<iostream>
using namespace std;

int main()
{
	int n;
	float itpl_pt;
	cout<<"Enter no. of values\n";
	cin>>n;
	float *x=new float[n];
	float *y = new float[n];
	
	cout<<"\nEnter "<<n<<" values for x:\n";
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	cout<<"\nEnter f(x) for each value of x:\n";
	for(int i=0;i<n;i++)
	{
			cin>>y[i];
	}
	cout<<"Enter f(x) to get it's point:\n";
	cin>>itpl_pt;
	
	//Lagrange's formula
	
	float result =0;
	
	for(int i=0;i<n;i++)
	{
		float mul1=1;
		float mul2=1;
		
		for(int j=0;j<n;j++)
		{
			if(i!=j)
			{
				mul1 *= (itpl_pt-y[j]);
				mul2 *= (y[i]-y[j]);
			}		
		}
		
		result += (mul1/mul2)*x[i];
	}
	cout<<"\nResult: "<<result;
}
