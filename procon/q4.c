#include<stdio.h>
int main()
{
	float x1,y1,x2,y2,x3,y3,x4,y4;
	float c1,c2,c3,c4,c5,d1,d2,d3,d4,d5,d6,m1,m2,m3,m4,m5,m6;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%f %f",&x1,&y1);
		scanf("%f %f",&x2,&y2);
		scanf("%f %f",&x3,&y3);
		scanf("%f %f",&x4,&y4);
		if(x2==x1)
			m1=1000000;
		else
			m1=(y2-y1)/(x2-x1);
		if(x3==x2)
			m2=1000000;
		else
			m2=(y3-y2)/(x3-x2);
		if(x4==x3)
			m3=1000000;
		else
			m3=(y4-y3)/(x4-x3);
		if(x4==x1)
			m4=1000000;
		else
			m4=(y4-y1)/(x4-x1);
		if(!(m1!=m2 && m2!=m3 && m3!=m4 && m1!=m4))
			printf("NONE\n");
		else
		{
			d1=(y2-y1)*(y2-y1)+(x2-x1)*(x2-x1);
			d2=(y3-y2)*(y3-y2)+(x3-x2)*(x3-x2);
			d3=(y4-y3)*(y4-y3)+(x4-x3)*(x4-x3);
			d4=(y4-y1)*(y4-y1)+(x4-x1)*(x4-x1);
			d5=(y1-y3)*(y1-y3)+(x1-x3)*(x1-x3);
			d6=(y4-y2)*(y4-y2)+(x4-x2)*(x4-x2);
			c1=m1*m2;c2=m2*m3;c3=m3*m4;c4=m1*m4;
			if(x3==x1)
				m5=1000000;
			else
				m5=(y3-y1)/(x3-x1);
			if(x4==x2)
				m6=1000000;
			else
				m6=(y4-y2)/(x4-x2);
			c5=m5*m6;
			//printf("%f %f\n",m5,m6);
			//printf("%f %f %f %f %f %f\n",d1,d2,d3,d4,d5,d6);
			//printf("%f %f %f %f %f %f\n",m1,m2,m3,m4,m5,m6);
			//printf("%f %f %f %f %f\n",c1,c2,c3,c4,c5);
			if(d1==d2 && d2==d3 && d3==d4 && d4==d1 && d5==d6 && (c1==0.0 || c1==-1.0) && (c2==0.0 || c2==-1.0) && 
					(c3==0.0 || c3==-1.0) && (c4==0.0 || c4==-1.0) && (c5==0.0 || c5==-1.0))
				printf("SQUARE\n");
			else if(d1==d2 && d2==d3 && d3==d4 && d4==d1 && (c5==0.0 || c5==-1.0))
				printf("RHOMBOUS\n");
			else if(d1==d2 && d2==d3 && d3==d4 && d4==d1 && d5==d6 && (c1==0.0 || c1==-1.0) && (c2==0.0 || c2==-1.0) &&
				(c3==0.0 || c3==-1.0) && (c4==0.0 || c4==-1.0))
				printf("RECTANGLE\n");
			else if(d1==d2 && d2==d3 && d3==d4 && d4==d1 && m1==m3 && m2==m4)
				printf("PARALLELOGRAM\n");
			else
				printf("QUADRILATERAL\n");
			
		}
	}
	return 0;
}
