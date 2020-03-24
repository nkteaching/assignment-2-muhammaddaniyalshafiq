#include<iostream>
#include<cmath>
using namespace std;


double s(double s1,int i,double sum)
{
	if(s1<i)
	{
	return sum;
	}
	else
	{
		if(i==1)
		{
			sum=1;
		}
	 else if(fmod(i,2)==0)
	{
		sum=sum+(1/i);
	}
	else 
	{
		sum=sum-1/i;
	}
	return s(s1,i+1,sum);
}}

 main()
{
	cout<<s(5,1,0);
}
