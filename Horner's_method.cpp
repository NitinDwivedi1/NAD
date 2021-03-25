//Horner's Method

#include<iostream>
using namespace std;

int func(int *arr,int x,int n,int first_coeff)
{
	int calc = first_coeff;
	for(int i=1;i<n+1;i++)
		calc=calc*x + arr[i];
	return calc;
}

int main()
{
	int n,x;
	cout<<"Enter degree of polynomial: ";
	cin>>n;
	int *arr=new int[n+1];
	cout<<"\nEnter coefficients: ";
	for(int i=0;i<n+1;i++)
		cin>>arr[i];
	cout<<"\nenter value of 'x': ";
	cin>>x;
		
	int first_coeff=arr[0];
	int result=func(arr,x,n,first_coeff);
	cout<<"Value of entered polynomial is: "<<result;
	
	return 0;
	
}
