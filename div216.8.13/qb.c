#include<stdio.h>
int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
	int min,c1,d1,calc1,calc,calc2,a,b,c,d,e,f,cnt=1,a1,b1,oa,ob,oc,od,min1=0,min2=0;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	e=gcd(a,b);
	f=gcd(c,d);
	a/=e;b/=e;
	c/=f;d/=f;
	oa=a;ob=b;oc=c;od=d;
	a1=a;b1=b;
	c1=c;d1=d;
	e=gcd(a,c);
	e=(a*c)/e;
	a1=e;
	b1=(e/a)*b1;
	c1=e;
	d1=(e/c)*d1;
	a=a1;b=b1;c=c1;d=d1;
	calc1=b-d;
	calc2=b;
	if(calc1>=0)
	{
		e=gcd(calc1,calc2);
		calc1/=e;
		calc2/=f;
		//printf("%d %d %d %d  %d %d\n",a,b,c,d,calc1,calc2);
		min1=calc1;
		min2=calc2;
	}
	a=oa;b=ob;c=oc;d=od;
	//printf("%d %d %d %d\n",a,b,c,d);
	e=gcd(ob,od);
	e=(ob*od)/e;
	//printf("%d\n",e);
	b1=e;
	a1=(e/b)*a;
	d1=e;
	c1=(e/d)*c;
	a=a1;b=b1;c=c1;d=d1;
	//printf("%d %d %d %d  %d %d  %d\n",a,b,c,d,calc1,calc2,e);
	calc1=a-c;
	calc2=a;
	e=gcd(calc1,calc2);
	calc1/=e;
	calc2/=f;
	//printf("%d %d %d %d  %d %d %d\n",a,b,c,d,calc1,calc2,min1);
	if(calc2<0)
		printf("%d/%d\n",min1,min2);
	else if(min2<0)
		printf("%d/%d\n",calc1,calc2);
	else
	{
		e=(min2*calc2)/gcd(min2,calc2);
		min=(e/min2)*min1;
		calc=(e/calc2)*calc1;
		if(min<calc)
		{
			printf("%d/%d\n",min1,min2);
		}
		else
		{ printf("%d/%d\n",calc1,calc2);
		}
	}
	return 0;
}
