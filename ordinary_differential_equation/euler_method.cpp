#include<iostream>

using namespace std;

inline float f(float x, float y)
{
	return x+y;
}

int main()
{
	float x0,y0,xf,h,x,y;
	cout<<"Enter x0, y0, xf\n";
	cin>>x0>>y0>>xf;
	cout<<"Enter value of h\n";
	cin>>h;
	x=x0;
	y=y0;
	int itr=1;
	cout<<"itr\tx\ty\n";
	while(x<=xf)
	{
		cout<<itr<<"\t"<<x<<"\t"<<y<<"\n";
		y = y+h*f(x,y);
		x = x+h;
		itr+=1;
	}
}
