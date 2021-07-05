#include<iostream>
using namespace std;

inline float f(float x, float y)
{
	return x+y;
}

int main()
{
	float x0, y0, n, xn, yn, k1, k2, k3, k4, k;
	cout<<"Enter initial values x0, y0\n";
	cin>>x0>>y0;
	cout<<"Enter calculation point xn\n";
	cin>>xn;
	cout<<"Enter no. of steps\n";
	cin>>n;
	float h = (xn-x0)/n;
	cout<<"h: "<<h<<endl;
	int i=0;
	cout<<"itr\tx\ty\n";
	do{
		k1 = h*f(x0,y0);
		k2 = h*f(x0+h/2,y0+k1/2);
		k3 = h*f(x0+h/2,y0+k2/2);
		k4 = h*f(x0+h,y0+k1);
		k = (k1+k2+k3+k4)/6;
		yn = y0+k;
		i+=1;
		x0+=h;
		cout<<i<<"\t"<<x0<<"\t"<<yn<<endl;
		y0=yn;
	}while(i<=n);
	
	cout<<"Result:"<<yn;
}
