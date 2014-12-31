#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		char c,d;
		int sum=0,flag=0;
		cin >> c;
		cin >> d;
		if(c=='2')
			sum+=2;	
		else if(c=='3')
			sum+=3;
		else if(c=='4')
			sum+=4;
		else if(c=='5')
			sum+=5;
		else if(c=='6')
			sum+=6;
		else if(c=='7')
			sum+=7;
		else if(c=='8')
			sum+=8;
		else if(c=='9')
			sum+=9;
		else if(c=='A')
		{
			if(d=='A')
				sum+=2;
			else
				sum=0;
		}	
		else if(c=='Q')
			sum+=10;
		else if(c=='J')
			sum+=10;
		else if(c=='K')
			sum+=10;
		else 
			flag=1;
		if(d=='2')
			sum+=2;	
		else if(d=='3')
			sum+=3;
		else if(d=='4')
			sum+=4;
		else if(d=='5')
			sum+=5;
		else if(d=='6')
			sum+=6;
		else if(d=='7')
			sum+=7;
		else if(d=='8')
			sum+=8;
		else if(d=='9')
			sum+=9;
		else if(d=='A')
		{
			if(c=='A')
				sum+=12;
			else
				sum=0;
		}
		else if(d=='Q')
			sum+=10;
		else if(d=='J')
			sum+=10;
		else if(d=='K')
			sum+=10;
		else 
			flag=1;
		if(flag==1)
			printf("INVALID\n");
		else
		{
			if(sum<=11)
				printf("HIT\n");
			else
				printf("STAND\n");
		}

	}
	return 0;
}
